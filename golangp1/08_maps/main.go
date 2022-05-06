package main

import "fmt"

func main() {
	emails := make(map[string]string)
	emails["Bob"] = "bob@gmail.com"
	emails["Alice"] = "alice@yahoo.com"
	emails["Cindy"] = "cindy@hotmail.com"
	fmt.Println(emails)
	fmt.Println(len(emails))
	fmt.Println(emails["Bob"])
	delete(emails, "Bob")
	fmt.Println(emails)
	fmt.Println(len(emails))
	fmt.Println(emails["Bob"])
	fmt.Println(emails["Alice"])
	email := map[string]string{"Erfan": "erfan@gamil.com", "Ali": "ali@gamil.com"}
	fmt.Println(email)
	fmt.Println(len(email))
	fmt.Println(email["Erfan"])
	delete(email, "Erfan")
	fmt.Println(email)
	fmt.Println(len(email))
	fmt.Println(email["Erfan"])
	fmt.Println(email["Ali"])

}
