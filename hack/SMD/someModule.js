var obj={
    name:'Sheng',
    age:23,
    sayName:function(){
        console.log('My name is ' + this.name + '.');
    },
    sayAge:function(){
        console.log('My age is ' + this.name + ' years old.');
    }
}

global.SMD.exports=obj;