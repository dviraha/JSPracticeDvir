(() => {
    let a = 5;
    console.log(a);
   })()
   
function whoAmI(num) {
    if (typeof num !== 'number') {
        console.log('n/a');
        return;
    }
    if (num % 2 === 0) {
        return true;
    } else {
        return false;
    }
}
let foo = whoAmI(3);
console.log(foo);
foo = whoAmI(-4);
console.log(foo);
foo = whoAmI('bahah');
console.log(foo);