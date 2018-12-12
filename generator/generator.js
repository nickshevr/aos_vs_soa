const nameGen = require('node-random-name');
const crypto = require('crypto');
const lorem = require('lorem-ipsum');
const MonthFirstLetter = [65, 68, 74, 79, 78, 83];
const MothFristPrefix = ['jun', 'jan', 'oct', 'jul', 'feb', 'sep', 'nov', 'dec', 'aug', 'ap'];

function getRandomElemFromArr(arr) {
    return arr[Math.floor(Math.random()*arr.length)];
}

exports.createUserObj = function () {
    const gender = Math.random() > 0.4 ? 'female' : 'male';
    const name = nameGen({ gender });

    return {
        gender,
        firstName: name.split(' ')[0],
        lastName: name.split(' ')[1],
        password: crypto.createHmac('sha1', lorem({ count: 1, units: 'words'}) + Date.now().toString()).digest('hex').slice(0, 11),
        month: getRandomElemFromArr(MothFristPrefix),
        email: name.split(' ').join(`${lorem({ count: 1, units: 'words'})}`) + '@somemail.ru',
        day: Math.floor(Math.random()*27 + 1),
        year: Math.floor(Math.random()*30) + 1970
    }
};