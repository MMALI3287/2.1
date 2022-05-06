package main

import "fmt"

func main() {
	i := 1
	for i <= 3 {
		fmt.Println(i)
		i = i + 1
	}
	for j := 7; j <= 9; j++ {
		fmt.Println(j)
	}
	//FizzBuzz
	for k := 1; k <= 100; k++ {
		if k%15 == 0 {
			fmt.Println("FizzBuzz")
		} else if k%3 == 0 {
			fmt.Println("Fizz")
		} else if k%5 == 0 {
			fmt.Println("Buzz")
		} else {
			fmt.Println(k)
		}
	}
}
