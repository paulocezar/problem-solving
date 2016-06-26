package main

import "fmt"

func main() {
	var T int
	fmt.Scanf("%d", &T)
	for tc := 1; tc <= T; tc++ {
		var s string
		fmt.Scanf("%s ", &s)
		ans := ""
		for _, c := range s {
			if len(ans) == 0 {
				ans += string(c)
			} else if c < rune(ans[0]) {
				ans += string(c)
			} else {
				ans = string(c) + ans
			}
		}
		fmt.Printf("Case #%d: %s\n", tc, ans)
	}
}
