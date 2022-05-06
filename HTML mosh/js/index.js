console.log('Hello World');

let person = {
    name: 'Tabia',
    age: 21,
    location: 'Lagos',
    hobbies: ['Sports', 'Cooking'],
    address: {
        city: 'Lagos',
        state: 'Lagos'
    }
};
console.log(person);
console.log(person.name.split(' '));
const arr = ['apple', 'banana', 'orange', 'pineapple', 'grapes', 100, 200, 300, 1000];
arr.push(2000);
arr.unshift(1000);
arr.pop();
console.log(arr);
let arr2 = [...arr];
for (let i = 0; i < arr2.length; i++) {
    console.log(arr2[i]);
}