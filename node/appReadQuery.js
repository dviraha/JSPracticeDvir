var http = require('http');

const hostname = '127.0.0.1';
const port = 8080;

// sample of printing query
const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
  res.write("The query: " + req.url);
  res.end();
}).listen(port);

