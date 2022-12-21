let myObject3 = {
    print3: (fung) => {
        console.log(fung);
    },
    returnObject3: () => {
        object3 = {
            id3: 1,
            name3: "moshe",
        
        }
        return object3;
    },
};
myObject3.print3("hello!");
let fung3 = myObject3.returnObject3();
console.log(fung3);