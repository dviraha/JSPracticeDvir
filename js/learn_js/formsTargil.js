const { format } = require("path")

const name = document.getElementById('name')
const password = document.getElementById('password')
const form = document.getElementById('form')

form.addEventListener('submit' => {
    if (name.value === 'dvir' && password === 1234) {
        return true
    } else {
        return false
    }
})