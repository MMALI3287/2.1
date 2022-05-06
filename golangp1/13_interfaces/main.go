package main

import (
	"fmt"
	"math"
)

type Shape interface {
	Area() float64
}

type Circle struct {
	x, y, radius float64
}

type Rectangle struct {
	width, height float64
}

func (c Circle) Area() float64 {
	return c.radius * c.radius * math.Pi
}

func (r Rectangle) Area() float64 {
	return r.width * r.height
}

func getArea(s Shape) float64 {
	return s.Area()
}

func main() {
	Circle := Circle{x: 0, y: 0, radius: 5}
	Rectangle := Rectangle{width: 10, height: 5}
	fmt.Println(getArea(Circle))
	fmt.Println(getArea(Rectangle))

}
