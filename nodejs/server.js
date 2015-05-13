var router = require('./router.js');
var express = require('express');
var app = express();
app.use('/',router);

var server = app.listen(8888, function() {
	    console.log('Listening on port %d', server.address().port);
});
