const path = require("path");
const outputDir = path.join(__dirname, "build/");

const isProd = process.env.NODE_ENV === "production";

module.exports = {
  entry: {
    IndexReact: "./src/Index.react.js",
    Index: "./src/Index.bs.js"
  },
  mode: isProd ? "production" : "development",
  module: {
    rules: [
      {
        test: /\.react.js$/,
        exclude: /node_modules/,
        use: {
          loader: "babel-loader"
        }
      }
    ]
  },
  output: {
    path: path.join(__dirname, "build"),
    filename: "[name].js"
  }
};
