var config = require('./sModule.config.js');
var fs = require('fs');

function sModule(){
    this.source = {};
    this.source.length = 0;

}

var _proto = sModule.prototype;

// 检查输入输出路径是否正常，并读取文件，保存为特定对象
_proto.checkIO = function () {
    console.log('Checkout IO !');
    var _this = this;
    var dirPath = config.appConfig.input.path;
    fs.readdir(dirPath,function (err, files) {
        if (err){
           throw err;
        } else {
            files.forEach(function (file) {
                fs.readFile(dirPath+ '/' +file, 'utf-8', function (err, data) {
                    if (err) {
                        throw err;
                    }
                    var indexKey =  _this.source.length;
                    var fileData = {
                        // 可能还要补充其它的数据
                        data: data
                    };
                    _this.source[String(indexKey)] = fileData;
                    _this.source.length++;
                });
            });
        }
    });
    return this;
};

// 初始化打包工具实例，完成配置和一些中间状态的生成
_proto.initInstance = function () {
    console.log('Init instance !');
    console.log(JSON.stringify(this.source));
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
    .compileApp()
    .generateApp();
