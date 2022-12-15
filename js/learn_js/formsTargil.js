// const { format } = require("path")

const aName = document.getElementById('name')
const aPassword = document.getElementById('password')
const aSubmit = document.getElementById('submit')
const aList = document.getElementById('list')

// form.addEventListener('submit' => {
//     if (name.value === 'dvir' && password === 1234) {
//         return true
//     } else {
//         return false
//     }
// })

    // let activated = true;
    // const button = document.getElementById('myButton');
    // const input = document.getElementById('myInput'); 
    // const list = document.getElementById('list');
    aSubmit.addEventListener('click', (event) => { 
        //console.log('clickssss'  + " " + input.value); 
        const myListItem = document.createElement('li'); 
        // console.log(input.value);
        myListItem.innerHTML = aName.value + " " + aPassword.value;
        if ((aName.value == 'dvir') && (aPassword.value == '1234')) {
            myListItem.style.color = "green";
        } else {
           myListItem.style.color = "red";
        }
        // const style = document.createElement('style');
        // style.innerHTML = `
        // .note {
        //     background-color: red;
        // }
        // `;
        // aList.head.appendChild(style);
        aList.appendChild(myListItem);
        event.preventDefault();
    })
