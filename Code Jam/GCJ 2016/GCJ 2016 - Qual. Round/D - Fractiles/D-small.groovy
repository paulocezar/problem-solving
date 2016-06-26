
Scanner sc = new Scanner(System.in)

int T = sc.nextInt()

for (int tc = 1; tc <= T; ++tc) {

    int K = sc.nextInt()
    int C = sc.nextInt()
    long S = sc.nextLong()
    long step = 1

    for (int i = 1; i < C; ++i) {
        step *= K;
    }

    print "Case #$tc:"
    if (step == 1) step = 0
    for (int i = 0; i < K; ++i) {
        long pos = i*step + i + 1
        print " $pos"
    }
    println ""
}
