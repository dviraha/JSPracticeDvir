const aName = document.getElementById('name')
const aPassword = document.getElementById('password')
const aSubmit = document.getElementById('submit')
const aList = document.getElementById('list')
    aSubmit.addEventListener('click', (event) => { 
        const myListItem = document.createElement('li'); 
        myListItem.innerHTML = aName.value + " " + aPassword.value;
        if ((aName.value == 'dvir') && (aPassword.value == '1234')) {
            myListItem.style.color = "green";
        } else {
           myListItem.style.color = "red";
        }
        aList.appendChild(myListItem);
        event.preventDefault();
    })
