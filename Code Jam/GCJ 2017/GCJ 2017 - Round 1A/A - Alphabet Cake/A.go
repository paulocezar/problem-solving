package main

import "fmt"

func main() {
	var T int
	fmt.Scanf("%d", &T)
	for tc := 1; tc <= T; tc++ {
		var R, C int
		fmt.Scanf("%d %d", &R, &C)

		grid := make([][]byte, R, R)
		fix := make([][]bool, R, R)
		for i := 0; i < R; i++ {
			var s string
			fmt.Scanf("%s", &s)
			grid[i] = []byte(s)
			fix[i] = make([]bool, C, C)
		}

		for i := 0; i < R; i++ {
			for j := 0; j < C; j++ {
				if fix[i][j] {
					continue
				}

				ri := R - i
				rj := C - j
				bi, bj, l := 0, 0, '?'

				for li := 0; li < ri; li++ {
					for lj := 0; lj < rj; lj++ {
						cur := '?'

						for r := i; r <= i+li; r++ {
							for c := j; c <= j+lj; c++ {
								if grid[r][c] != '?' {
									if cur == '?' {
										cur = rune(grid[r][c])
									} else {
										cur = '!'
									}
								}
							}
						}

						if cur != '?' && cur != '!' {
							bi, bj, l = li, lj, cur
						}
					}
				}

				for r := i; r <= i+bi; r++ {
					for c := j; c <= j+bj; c++ {
						grid[r][c] = byte(l)
						fix[r][c] = true
					}
				}

			}
		}

		fmt.Printf("Case #%d:\n", tc)
		for _, r := range grid {
			fmt.Printf("%s\n", string(r))
		}
	}
}
