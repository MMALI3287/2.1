package main

import "fmt"

func main() {
	var a [2]string
	a[0] = "Hello"
	a[1] = "World"
	fmt.Println(a[0], a[1])
	fmt.Println(a)
	fmt.Println(len(a))
	b := [2]string{"Hello", "World"}
	fmt.Println(b)
	c := [...]string{"Hello", "World"}
	fmt.Println(c)
	d := [2]string{}
	fmt.Println(d)
	fruitSlice := []string{"apple", "banana", "orange"}
	fmt.Println(fruitSlice)
}
