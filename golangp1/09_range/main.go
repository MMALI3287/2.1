package main

import "fmt"

func main() {
	ids := []int{1, 2, 3, 4, 5}
	for i, id := range ids {
		fmt.Printf("%d - ID: %d\n", i, id)
	}
	for _, id := range ids {
		fmt.Printf("ID: %d\n", id)
	}
	sum := 0
	for _, id := range ids {
		sum += id
	}
	fmt.Println("Sum:", sum)
	email := map[string]string{"Erfan": "erfan@gamil.com", "Ali": "ali@gamil.com"}
	for k, v := range email {
		fmt.Printf("%s: %s\n", k, v)
	}

	for k := range email {
		fmt.Println("Name:", k)
	}
}
