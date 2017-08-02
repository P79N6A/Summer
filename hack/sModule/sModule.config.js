module.exports = {
    packCongif: {},
    appConfig: {
        // 下面字段配置要打包应用的源文件（包括路径和入口文件在内）
        input:{
            path: './demo',// 待打包app的路径
            main: 'index.js'// 入口文件
        },
        // 下面字段配置的是输出相关（包括路径在内）
        output:{
            path: './dst',
            singleFile: true// 是否强制输出结果为单文件 
        }
    }
}