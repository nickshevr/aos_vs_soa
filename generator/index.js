const fs = require('fs');
const generator = require('./generator');

const NEDED_KEYS = ['firstName', 'lastName', 'password', 'email', 'gender', 'year'];

const makeCSVString = userObj => NEDED_KEYS.reduce((acc, key) => (
    `${acc}${userObj[key]}, `
), '');

const users = [];

for (let i=0; i < 1000; i++) {
    const str = generator.createUserObj();
    users.push(str);
}

const strData = users.reduce((acc, userObj) => {
    return acc + makeCSVString(userObj) + '\n';
}, '');

fs.writeFile('users.txt', strData, (err) => {
    if (err) {
        console.log(err);
    }

    return;
})
