var config = require('./sModule.config.js');

function sModule(){
    //
}

var _proto = sModule.prototype;

// 检查输入输出路径是否正常，以及入口文件是否存在
_proto.checkIO = function () {
    console.log('Checkout IO !');
    return this;
};

// 初始化打包工具实例，完成配置和一些中间状态的生成
_proto.initInstance = function () {
    console.log('Init instance !');
    return this;
};

 // 读取输入文件，并保存为特定的对象
_proto.readInput = function () {
    console.log('Read Input !');
    return this;
};

// 处理输入文件，生成在浏览器环境中模拟node的代码，并和模块拼装在一起
_proto.compileApp = function () {
    console.log('Compile APP !');
    return this;
};

// 后处理，按照配置文件输出，生成打包后的App
_proto.generateApp = function () {
    console.log('Generate App !');
    return this;
};

new sModule(config)
    .checkIO()
    .initInstance()
    .readInput()
    .compileApp()
    .generateApp();
