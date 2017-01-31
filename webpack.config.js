const path = require('path');

module.exports = {
  entry: {
    simple: './lib/js/examples/simple/root.js',
    logo: './lib/js/examples/logo/index.js',
    todomvc: './lib/js/examples/todomvc/todoApp.js',
    nodomvc: './lib/js/examples/nodomvc/start.js',
  },
  output: {
    path: path.join(__dirname, "finalOutput"),
    filename: '[name].js',
  },
};
