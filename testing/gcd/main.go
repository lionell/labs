package main

var Gcd = func(x, y int) int {
	if x < y {
		x, y = y, x
	}
	for y > 0 {
		x = x - y
		if x < y {
			x, y = y, x
		}

	}
	return x
}

func Lcm(x, y int) int {
	return x * y / Gcd(x, y)
}
