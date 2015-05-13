var express = require('express');
var zmq = require('zmq');
var app = express();
var router = express.Router();

router.use(function logs(req,res,next){
	console.log('Time: ',Date.now());	
	next();
})

router.get('/aa',function(req,res){
	var socket = zmq.socket('req');

	socket.identitiy = '1';

	socket.connect('tcp://localhost:5555');

	socket.send('lala');

	socket.on('message',function(data){
		console.log(data.toString());
		res.send(data.toString());
	})
	

});

router.get('/bb',function(req,res){
	res.send('2');
})
module.exports = router;
