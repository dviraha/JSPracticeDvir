(() => {
    let a = 5;
    console.log(a);
   })()
   
function whoAmI(arg1) {
    if (arg1 > 0) {
        console.log('+');
    } else if (arg1 < 0) {
        console.log('-');
    } else {
        console.log('?');
    }
}
whoAmI(3);
whoAmI(-3);
whoAmI(0);