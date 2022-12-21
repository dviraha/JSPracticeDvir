function addName3(object2, name2, value2) {
    object2[name2] = value2;
    return object2
    }
myObject22 = {};
myObject22 = addName3(myObject22, "id2", 1);
myObject22 = addName3(myObject22, "number2", 2);
myObject22 = addName3(myObject22, "pass2", 3);
console.log(myObject22);
