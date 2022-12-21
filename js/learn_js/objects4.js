let getCarModel4 = function (name4, color4, engine4) {
    this.name4 = name4;
    this.color4 = color4;
    this.engine4 = engine4;
    const answer4 = this.name4 + this.color4 + this.engine4;
    this.getModel4 = () => {
        return answer4;
    }
};
let carModel4 = new getCarModel4("Mazda3", "Gray", "1400");
model4 = carModel4.getModel4();
console.log(model4);