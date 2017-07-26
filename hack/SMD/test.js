/**
 * SMD 的测试文件，运行：> node test.js
 * --------------------------------------------------------------
 * @ author -- Vincent Sheng
 * --------------------------------------------------------------
 */

var SMD=require('./SMD.js');

SMD.init();
var myImport=SMD.myRequire('./someModule.js');

myImport.sayName();
myImport.sayAge();