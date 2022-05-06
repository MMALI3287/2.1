package main

import "fmt"

func main() {
	x := 5
	y := 6
	if x < y {
		fmt.Println("x is less than y")
	} else {
		fmt.Println("x is not less than y")
	}
	if x <= y { // x is less than or equal to y
		fmt.Println("x is less than or equal to y")
	}
	color := "red"
	if color == "red" {
		fmt.Println("color is red")
	} else if color == "blue" {
		fmt.Println("color is blue")
	} else {
		fmt.Println("color is not red or blue")
	}
	switch color {
	case "red":
		fmt.Println("color is red")
	case "blue":
		fmt.Println("color is blue")
	default:
		fmt.Println("color is not red or blue")
	}

}
