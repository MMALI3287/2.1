package main

import "fmt"

func main() {
	a := 5
	b := &a
	fmt.Println(a, *b, b)
	*b = 10
	fmt.Println(a, *b, b)
	fmt.Printf("%T\n", b)
}
