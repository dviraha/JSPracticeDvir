var http = require('http');
var url = require('url');

const hostname = '127.0.0.1';
const port = 8080;

// sample of parsing the url
const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader('Content-Type', 'text/plain');
    
  var q = url.parse(req.url, true);
  console.log(q.host); //returns 'localhost:8080'
  console.log(q.pathname); //returns '/default.htm'
  console.log(q.search); //returns '?year=2017&month=february'

  res.write(q.search);
  res.end();
}).listen(port);

