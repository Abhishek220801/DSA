const users = [
    {name: 'Simmi', age: 26},
    {name: 'Abhishek', age: 24},
    {name: 'Papa', age: 67},
    {name: 'Madhu', age: 44},
]

function sortByAge(users) {
    users.sort((a, b) => a.age - b.age);
    return users;
}

sortByAge(users);

users.forEach(user => console.log(user));
