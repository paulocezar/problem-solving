object C extends App {
  import collection.mutable.HashMap

  def solve(k: Long, free: HashMap[Long, Long]): (Long, Long) = {

    val (cur, cnt) = free.max
    free.remove(cur)

    val mn = (cur - 1l)/2
    val mx = cur - 1l - mn

    if (cnt >= k) (mn, mx)
    else {

      free += (mn -> (free.getOrElse(mn, 0l) + cnt))
      free += (mx -> (free.getOrElse(mx, 0l) + cnt))
      solve(k - cnt, free)
    }
  }

  val T = io.StdIn.readInt
  for (tc <- 1 to T) {
    val in = io.StdIn.readLine.split(" ").map(x => x.toLong)
    val (n, k) = (in(0), in(1))
    val free = HashMap[Long,Long](n -> 1l)

    val (mn, mx) = solve(k, free)

    println(s"Case #$tc: $mx $mn")
	}
}
