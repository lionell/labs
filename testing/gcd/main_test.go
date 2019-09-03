package main

import "testing"

func TestGcdWithUnitTest(t *testing.T) {
	if gcd := Gcd(10, 3); gcd != 1 {
		t.Errorf("Gcd was incorrect, got: %d, want: %d.", gcd, 1)
	}
}

func TestGcdWithTableTest(t *testing.T) {
	table := []struct {
		x, y, res int
	}{
		{10, 3, 1},
		{3, 10, 1},
		{9, 3, 3},
		{21, 14, 13},
	}
	for _, test := range table {
		if gcd := Gcd(test.x, test.y); gcd != test.res {
			t.Errorf("Gcd of (%d and %d) was incorrect, got: %d, want: %d.", test.x, test.y, gcd, test.res)
		}
	}
}

var dummy int

func benchmarkGcd14(x int, b *testing.B) {
	for n := 0; n < b.N; n++ {
		dummy += Gcd(x, 14)
	}
}

func BenchmarkGcdBillion(b *testing.B)  { benchmarkGcd14(1242342342, b) }
func BenchmarkGcdMillion(b *testing.B)  { benchmarkGcd14(1959295, b) }
func BenchmarkGcdThousand(b *testing.B) { benchmarkGcd14(1429, b) }
func BenchmarkGcdTen(b *testing.B)      { benchmarkGcd14(19, b) }

func TestLcmWithMock(t *testing.T) {
	oldGcd := Gcd
	Gcd = func(x, y int) int {
		if x == 144 && y == 20 {
			return 4
		}
		return -1
	}

	if lcm := Lcm(144, 20); lcm != 720 {
		t.Errorf("Lcm was incorrect, got: %d, want: %d.", lcm, 720)
	}
	Gcd = oldGcd
}

var oldGcd = Gcd

func setup(gcd func(x, y int) int) {
	Gcd = gcd
}

func restore() {
	Gcd = oldGcd
}

func TestLcmWithMockAndOrder(t *testing.T) {
	setup(func(x, y int) int {
		if x == 144 && y == 20 {
			return 4
		}
		return -1
	})
	if lcm := Lcm(144, 20); lcm != 257 {
		t.Errorf("Lcm was incorrect, got: %d, want: %d.", lcm, 257)
	}
	restore()
}
