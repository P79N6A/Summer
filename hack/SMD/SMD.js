/**
 * SMD = simple module definition 简单模块定义
 * --------------------------------------------------------------
 * @ author -- Vincent Sheng
 * @ version -- 0.0.1
 * --------------------------------------------------------------
 */

var fs = require('fs');

var myRequire= function(path){
    var handle = null; 
    var code=fs.readFileSync(path,'utf-8');
    eval(code);
    handle = global.SMD.exports;
    return handle;
}

var init=function(){
    global.SMD={};
    global.SMD.exports={};
}

module.exports ={
    init:init,
    myRequire:myRequire
}


