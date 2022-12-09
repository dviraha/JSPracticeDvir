let kuku = Symbol();
let kukuType = typeof kuku; //symbol
console.log(kukuType);

kuku = true;
kukuType = typeof kuku; //boolian
console.log(kukuType);

kuku = undefined;
kukuType = typeof kuku; //undefinded
console.log(kukuType);

kuku = null;
kukuType = typeof kuku; //null
console.log(kukuType);

kuku = 1;
kukuType = typeof kuku; //number
console.log(kukuType);

kuku = ('hello');
kukuType = typeof kuku; //string
console.log(kukuType);