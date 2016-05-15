/*
Change Log:
2016-05-11 : Intial release
2016-05-11 : Fix "if (ufoParm[j*2]==ship[i] && ufoParm[j*2+1]==ret[i])" to be "if (ufoParm[j*3]==ship[i] && ufoParm[j*3+1]==ret[i])"
*/


import java.awt.*;
import java.awt.event.*;
import java.awt.image.*;
import java.io.*;
import java.util.*;
import java.security.*;
import javax.swing.*;
import javax.imageio.ImageIO;

// ------------- class Point ------------------------------
class Pnt {
    public int x,y;
    public boolean visited;
    public Pnt() {};
    public Pnt(int x1, int y1) {
        x = x1;
        y = y1;
        visited = false;
    }
    public boolean equals(Pnt other) {
        return (x == other.x && y == other.y);
    }
}

// ------------- class StarTraveller itself --------------
public class StarTravellerVis {
    final int SZ = 1024;            // space size
    int NStar, NShip, NUfo;         // number of stars, ships and ufo's
    Pnt[] star;                     // coordinates of stars (fixed)
    int[] ship;                     // Position of ships
    int[] ufoParm;                  // Parameter array for ufo's
    int[] starParm;                 // Parameter array for stars
    int visited;                    // Number of stars visited
    double energy;                  // Energy used
    int[] ufoRange;                 // Number of random stars selected for each ufo when determining next star
    ArrayList<Integer> progress = new ArrayList<Integer>(); // Used to visualize path progress
    public static int delay = 100;
    public static boolean startPaused = true;
    public static boolean drawUfo = true;
    final Object worldLock = new Object();
    SecureRandom rnd = null;

    // ---------------------------------------------------
    void calculateNextStar(int idx)
    {
        for (int i=0;i<NUfo;i++)
        {
            int from = ufoParm[i*3+idx-1];
            int bdst = 1<<30;
            int bj = rnd.nextInt(NStar);
            // Pick [range] random stars and select the nearest one to travel to.
            for (int j=0;j<ufoRange[i];j++)
            {
                int p = rnd.nextInt(NStar);
                int dst = (star[p].x-star[from].x)*(star[p].x-star[from].x) + (star[p].y-star[from].y)*(star[p].y-star[from].y);
                if (dst<bdst && dst>0)
                {
                    bdst = dst;
                    bj = p;
                }
            }
            ufoParm[i*3+idx] = bj;
        }
    }
    // ---------------------------------------------------
    void generate(String seed)
    {
      try {
        rnd = SecureRandom.getInstance("SHA1PRNG");
        rnd.setSeed(Long.parseLong(seed));

        int NG;
        if (seed.equals("1"))
        {
            NStar = 20;
            NShip = 1;
            NUfo = 4;
            NG = 3;
        } else {
            NStar = 100 + rnd.nextInt(1901);
            NShip = 1 + rnd.nextInt(10);
            NUfo = rnd.nextInt(NStar/100);
            NG = 1 + rnd.nextInt(16);
        }

        star = new Pnt[NStar];
        ship = new int[NShip];
        ufoParm = new int[3 * NUfo];
        starParm = new int[2 * NStar];

        System.out.println("NStar = " + NStar + " NShip = " + NShip + " NUfo = " + NUfo + " NGalaxy = "+NG);

        // Generate stars
        // Generate galaxy center positions
        Pnt[] galaxy = new Pnt[NG];
        for (int i=0;i<NG;i++)
        {
            galaxy[i] = new Pnt(rnd.nextInt(SZ), rnd.nextInt(SZ));
        }
        // Generate star locations
        for (int i=0;i<NStar;i++)
        {
            // Pick a random gaussian location centered at a random galaxy
            int x = 0, y = 0;
            int g = rnd.nextInt(NG);
            do
            {
                x = (int)(rnd.nextGaussian()*100) + galaxy[g].x;
                y = (int)(rnd.nextGaussian()*100) + galaxy[g].y;
            } while (x<0 || y<0 || x>=SZ || y>=SZ);
            star[i] = new Pnt(x,y);
        }
        // Assign initial space ship locations
        for (int i=0;i<NShip;i++)
        {
            ship[i] = rnd.nextInt(NStar);
        }
        // Generate UFO
        ufoRange = new int[NUfo];
        for (int i=0;i<NUfo;i++)
        {
            ufoRange[i] = 10+rnd.nextInt(NStar/10);
            ufoParm[i*3] = rnd.nextInt(NStar);
        }
        calculateNextStar(1);
        calculateNextStar(2);

        // convert to parameter array
        for (int i=0;i<NStar;i++)
        {
            starParm[i*2] = star[i].x;
            starParm[i*2+1] = star[i].y;
        }
        energy = 0;
        visited = 0;
      }
      catch (Exception e) { 
        addFatalError("An exception occurred while generating test case.");
        e.printStackTrace(); 
      }
    }
    // ---------------------------------------------------
    public double runTest(String seed)
    {
      try {
        generate(seed);
        double score = -1;
        int turns = 0;
        if (proc != null)
        {
            int iret;
            try
            {
                iret  = init(starParm);
            }
            catch (Exception e)
            {
                addFatalError("Failed to get result from init.");
                return -1.0;
            }

            if (vis)
            {
                // draw the image
                jf.setSize(SZX,SZY);
                jf.setVisible(true);
                draw();
                if (startPaused)
                {
                    v.pauseMode = true;
                }
                v.processPause();
            }

            // Perform moves until all stars visited or number of maximum turns reached.
            while (turns<NStar*4 && visited<NStar)
            {
                int[] ret;
                try
                {
                    ret = makeMoves(ufoParm, ship);
                }
                catch (Exception e)
                {
                    addFatalError("Move #"+turns+": Failed to get result from makeMoves.");
                    return -1.0;
                }
                // move ship
                if (ret.length!=NShip)
                {
                    addFatalError("Move #"+turns+": Return should have one move for each ship. Length is "+ret.length+" and should be "+NShip+".");
                    return -1.0;
                }
                for (int i=0;i<NShip;i++)
                {
                    if (ret[i]<0 || ret[i]>=NStar)
                    {
                        addFatalError("Move #"+turns+": Return values should in the range of [0,"+(NStar-1)+"]. Your value was "+ret[i]+".");
                        return -1.0;
                    }
                    synchronized (worldLock)
                    {
                        // only add energy if the ship actually moved in space
                        if (star[ship[i]].x!=star[ret[i]].x || star[ship[i]].y!=star[ret[i]].y)
                        {
                            double dst = (double)(star[ship[i]].x - star[ret[i]].x)*(star[ship[i]].x - star[ret[i]].x);
                            dst += (double)(star[ship[i]].y - star[ret[i]].y)*(star[ship[i]].y - star[ret[i]].y);
                            dst = Math.sqrt(dst);
                            progress.add(ship[i]); // for visualization only
                            progress.add(ret[i]); // for visualization only
                            // Flying with ufo ?
                            int withUFO = 0;
                            for (int j=0;j<NUfo;j++)
                            {
                                // Reduce the energy when travelling with UFO's
                                if (ufoParm[j*3]==ship[i] && ufoParm[j*3+1]==ret[i])
                                {
                                    dst *= 0.001;
                                    withUFO = 1;
                                }
                            }
                            progress.add(withUFO); // for visualization only
                            energy += dst;
                        }
                        ship[i] = ret[i];
                        if (!star[ship[i]].visited)
                        {
                            star[ship[i]].visited = true;
                            visited++;
                        }
                     }
                }
                // move UFO's
                for (int i=0;i<NUfo*3;i+=3)
                {
                    ufoParm[i] = ufoParm[i+1];
                    ufoParm[i+1] = ufoParm[i+2];
                }
                calculateNextStar(2);

                turns++;
                if (vis)
                {
                    // update vis
                    draw();
                    v.processPause();
                    try {
                        Thread.sleep(delay);
                    } catch (Exception e) {
                        // do nothing
                    }
                }
            }
            signalEnd();
            if (visited!=NStar)
            {
                addFatalError("All stars not visited after "+(NStar*4)+" turns.");
                return -1.0;
            }
        }
        if (vis) {
            // draw the image
            jf.setSize(SZX,SZY);
            jf.setVisible(true);
            draw();
        }

        if (saveFile!=null)
            saveCase(saveFile);

        System.out.println("Ended at turn "+turns+" out of a maximum of "+(NStar*4)+".");
        return energy;
      }
      catch (Exception e) { 
        addFatalError("An exception occurred while trying to process your program's results.");
        e.printStackTrace(); 
        return -1.0;
      }
    }
// ------------- visualization part ----------------------
    static String exec;
    static boolean vis;
    static Process proc;
    static String saveFile = null;
    JFrame jf;
    Vis v;
    InputStream is;
    OutputStream os;
    BufferedReader br;
    // problem-specific drawing params
    final int SZX = SZ+2,SZY=SZ+2;
    volatile boolean ready;
    volatile int Ncur;
    volatile int[] Pcur;
    int[][] coordToPoint;
    // ---------------------------------------------------
    int init(int[] stars_) throws IOException
    {
        StringBuffer sb = new StringBuffer();
        sb.append(stars_.length).append('\n');
        for (int i=0; i<stars_.length; i++)
            sb.append(stars_[i]).append('\n');
        os.write(sb.toString().getBytes());
        os.flush();
        // get the return
        int ret = Integer.parseInt(br.readLine());
        //System.out.println(ret);
        return ret;
    }
    // ---------------------------------------------------
    int[] makeMoves(int[] ufos_, int[] ships_) throws IOException
    {
        StringBuffer sb = new StringBuffer();
        sb.append(ufos_.length).append('\n');
        for (int i = 0; i < ufos_.length; ++i)
            sb.append(ufos_[i]).append('\n');
        sb.append(ships_.length).append('\n');
        for (int i = 0; i < ships_.length; ++i)
            sb.append(ships_[i]).append('\n');
        os.write(sb.toString().getBytes());
        os.flush();
        // get the return - an array of ints
        int nret = Integer.parseInt(br.readLine());
        //System.out.println(nret);
        int[] ret = new int[nret];
        for (int i = 0; i < nret; ++i)
            ret[i] = Integer.parseInt(br.readLine());
        return ret;
    }
    // ---------------------------------------------------
    void signalEnd() throws IOException
    {
        StringBuffer sb = new StringBuffer();
        sb.append("-1").append('\n');
        os.write(sb.toString().getBytes());
        os.flush();
    }
    // ---------------------------------------------------
    void draw() {
        if (!vis) return;
        v.repaint();
    }
    // ---------------------------------------------------
    BufferedImage drawCase(boolean showUfo)
    {
        BufferedImage bi = new BufferedImage(SZX+10,SZY+10,BufferedImage.TYPE_INT_RGB);
        Graphics2D g2 = (Graphics2D)bi.getGraphics();
        synchronized (worldLock)
        {
            //background
            g2.setColor(new Color(0xD3D3D3));
            g2.fillRect(0,0,SZX+10,SZY+10);
            g2.setColor(Color.BLACK);
            g2.fillRect(0,0,SZ+1,SZ+1);
            //frame
            g2.setColor(Color.WHITE);
            g2.drawRect(0,0,SZ+1,SZ+1);

            // draw flown paths
            for (int i=0;i<progress.size();i+=3)
            {
                g2.setColor(progress.get(i+2)==0 ? Color.GRAY : Color.GREEN);
                int v1 = progress.get(i);
                int v2 = progress.get(i+1);
                g2.drawLine(star[v1].x, star[v1].y, star[v2].x, star[v2].y);
            }
            // draw stars
            for (int i=0;i<NStar;i++)
            {
                if (star[i].visited)
                {
                    g2.setColor(Color.GREEN);
                    g2.fillOval(star[i].x-1, star[i].y-1, 3, 3);
                } else
                {
                    g2.setColor(Color.WHITE);
                    g2.fillOval(star[i].x-2, star[i].y-2, 5, 5);
                }
            }
            // draw ufos
            if (showUfo)
            {
                for (int i=0;i<NUfo;i++)
                {
                    g2.setColor(new Color(1.f, 1.f, 0));
                    g2.fillOval(star[ufoParm[i*3]].x-3, star[ufoParm[i*3]].y-3, 7, 7);
                    g2.drawLine(star[ufoParm[i*3]].x, star[ufoParm[i*3]].y, star[ufoParm[i*3+1]].x, star[ufoParm[i*3+1]].y);
                    g2.setColor(new Color(0.5f, 0.5f, 0));
                    g2.drawLine(star[ufoParm[i*3+1]].x, star[ufoParm[i*3+1]].y, star[ufoParm[i*3+2]].x, star[ufoParm[i*3+2]].y);
                }
            }
            // draw ships
            for (int i=0;i<NShip;i++)
            {
                float hue = (float)(i) / NShip;
                g2.setColor(Color.getHSBColor(hue, 0.9f, 1.0f));
                g2.drawOval(star[ship[i]].x-5, star[ship[i]].y-5, 11, 11);
                g2.setColor(Color.RED);
                g2.drawOval(star[ship[i]].x-3, star[ship[i]].y-3, 7, 7);
            }
        }
        return bi;
    }
    // ---------------------------------------------------
    void saveCase(String filename)
    {
        try {
            BufferedImage bi = drawCase(false);
            File outputfile = new File(filename);
            ImageIO.write(bi, "png", outputfile);
        } catch (IOException e) {
            addFatalError("An exception occurred while trying to save the image.");
            e.printStackTrace();
        }
    }
    // ---------------------------------------------------
    public class Vis extends JPanel implements WindowListener {
        final Object keyMutex = new Object();
        boolean keyPressed;
        public boolean pauseMode = false;

        class DrawerKeyListener extends KeyAdapter {
            public void keyPressed(KeyEvent e) {
                synchronized (keyMutex) {
                    if (e.getKeyChar() == ' ') {
                        pauseMode = !pauseMode;
                    }
                    keyPressed = true;
                    keyMutex.notifyAll();
                }
            }
        }

        public void paint(Graphics g)
        {
          try {
            BufferedImage bi = drawCase(drawUfo);
            g.drawImage(bi,0,0,SZX+10,SZY+10,null);
          }
          catch (Exception e) { e.printStackTrace(); }
        }

        public Vis()
        {
            jf.addWindowListener(this);
            jf.addKeyListener(new DrawerKeyListener());
        }

        public void processPause() {
            synchronized (keyMutex)
            {
                if (!pauseMode) {
                    return;
                }
                keyPressed = false;
                while (!keyPressed) {
                    try {
                        keyMutex.wait();
                    } catch (InterruptedException e) {
                        // do nothing
                    }
                }
            }
        }

    // ---------------------------------------------------
        //WindowListener
        public void windowClosing(WindowEvent e) { 
            if(proc != null)
                try { proc.destroy(); } 
                catch (Exception ex) { ex.printStackTrace(); }
            System.exit(0); 
        }
        public void windowActivated(WindowEvent e) { }
        public void windowDeactivated(WindowEvent e) { }
        public void windowOpened(WindowEvent e) { }
        public void windowClosed(WindowEvent e) { }
        public void windowIconified(WindowEvent e) { }
        public void windowDeiconified(WindowEvent e) { }
    }
    // ---------------------------------------------------
    public StarTravellerVis(String seed) {
        //interface for runTest
        if (vis)
        {
            jf = new JFrame();
            v = new Vis();
            jf.getContentPane().add(v);
        }
        if (exec != null) {
            try {
                Runtime rt = Runtime.getRuntime();
                proc = rt.exec(exec);
                os = proc.getOutputStream();
                is = proc.getInputStream();
                br = new BufferedReader(new InputStreamReader(is));
                new ErrorReader(proc.getErrorStream()).start();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        System.out.println("Score = "+runTest(seed));
        if (proc != null)
            try { proc.destroy(); } 
            catch (Exception e) { e.printStackTrace(); }
    }
    // ---------------------------------------------------
    public static void main(String[] args) {
        String seed = "1";
        vis = false;
        for (int i = 0; i<args.length; i++)
        {
            if (args[i].equals("-seed"))
                seed = args[++i];
            if (args[i].equals("-exec"))
                exec = args[++i];
            if (args[i].equals("-save"))
                saveFile = args[++i];
            if (args[i].equals("-vis"))
                vis = true;
            if (args[i].equals("-delay"))
                delay = Integer.parseInt(args[++i]);
            if (args[i].equals("-noufo"))
                drawUfo = false;
        }
        StarTravellerVis f = new StarTravellerVis(seed);
    }
    // ---------------------------------------------------
    void addFatalError(String message) {
        System.out.println(message);
    }
}

class ErrorReader extends Thread{
    InputStream error;
    public ErrorReader(InputStream is) {
        error = is;
    }
    public void run() {
        try {
            byte[] ch = new byte[50000];
            int read;
            while ((read = error.read(ch)) > 0)
            {   String s = new String(ch,0,read);
                System.out.print(s);
                System.out.flush();
            }
        } catch(Exception e) { }
    }
}
