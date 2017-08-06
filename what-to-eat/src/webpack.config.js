module.exports = {
    entry: './main.js',
    output: {
        path: __dirname,
        filename: 'index.js'
    },
    devServer:{
        inline: true,
        port: 8000
    },
    module: {
        loaders: [
            {
                test: /\.jsx?$/,
                exclude: /node_modules/,
                loader: 'babel-loader',
                query: {
                    presets:['react', 'es2015']
                }
            },
            {
                test: /\.css$/,
                loader: 'style-loader!css-loader'
            }
        ]
    }
};