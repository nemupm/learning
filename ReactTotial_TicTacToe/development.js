import path from 'path'

const src  = path.resolve(__dirname, 'src')
const dist = path.resolve(__dirname, 'dist')

export default {
  entry: src + '/index.jsx',

  output: {
    path: dist,
    filename: 'bundle.js'
  },

  module: {
    loaders: [
      {
        test: /\.jsx$/,
        exclude: /node_modules/,
        loader: 'babel-loader'
      }
    ]
  },

  plugins: []
}
