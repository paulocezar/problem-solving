
Scanner sc = new Scanner(System.in)

int T = sc.nextInt()

for (int tc = 1; tc <= T; ++tc) {

    String s = sc.next()
    int k = sc.nextInt()


    int flips = 0
    for (int i = s.size()-1; i >= k-1; --i) {
        if (s[i] == '-') {
            flips++
            s = (i-k >= 0 ? s[0..i-k] : "") +
                s[i-k+1..i].tr ('+-', '-+') +
                (i+1 < s.size() ? s[i+1..-1] : "")
        }
    }

    print "Case #$tc: "
    if (s.contains('-')) print "IMPOSSIBLE"
    else print flips
    println ""
}
