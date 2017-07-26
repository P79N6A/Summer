/**
 * 这个文件用来测试JavaScript作用域相关特性，后续会完善。并且加上注释
 */
console.log('This is scope demo!');

let name = 'xv';

{
    let name = 'sheng';
    console.log('In block : I\'m ' + name);
}

console.log('Out of block : I\'m ' + name);


var obj={
    a:1,
    b:2
}

with(obj){
    console.log(a);
    console.log(b);
    c ='sheng';
    console.log(global.c);
}

console.log(c);

try{
    throw 'hello';
}catch(err){
    console.log(err + ' - 1');
}
try{
    throw 'hi';
}catch(err){
    console.log(err + ' - 1');
}

var err = '123';

console.log(err + ' - 1');


