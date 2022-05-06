package main

import (
	"fmt"
	"strconv"
)

type Person struct {
	// name   string
	// age    int
	// city   string
	// gender string
	name, city, gender string
	age                int
}

func (p Person) greet() string {
	return "Hello, my name is " + p.name + " and I am " + strconv.Itoa(p.age)
}

func (p *Person) hasBirthday() {
	p.age++
}

func (p *Person) getMarried(spouseName string) {
	p.name = p.name + " " + spouseName
}

func main() {
	person1 := Person{name: "Erfan", age: 21, city: "Dhaka", gender: "b"}
	person2 := Person{"Tabia", "Dhaka", "g", 21}
	fmt.Println(person1)
	fmt.Println(person2)
	person2.hasBirthday()
	person2.getMarried("Erfan")
	fmt.Println(person2.greet())
}
