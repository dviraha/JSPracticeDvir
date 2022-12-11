var http = require('http');
var url = require('url');
var fs = require('fs');
const hostname = '127.0.0.1';
const port = 8080;

// ser two urls: summer.html, winter.html
// all other return 404
const server = http.createServer((req, res) => {
  res.statusCode = 200;
  var q = url.parse(req.url, true);
  var filename = "." + q.pathname;
  console.log(filename);
  fs.readFile(filename, function(err, data) {
    if (err) {
      res.writeHead(404, {'Content-Type': 'text/html'});
      return res.end("404 Not Found");
    } 
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.write(data);
    return res.end();
  });
}).listen(port);

