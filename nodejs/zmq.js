var zmq = require('zmq');

function sendMessage(addr,message,res)
{
	var socket = zmq.socket('req');
	console.log('tcp://'+addr);
	socket.connect('tcp://'+addr);
	socket.send(message);
	socket.on('message',function(data){
		res.send(data.toString());
	});
}

function receiveMessage(addr,message,res)
{
	var socket = zmq.socket('req');
	socket.connect('tcp://'+addr);
	socket.send(message);
	socket.on('message',function(data){
		res.send(data.toString());
	});
}

exports.sendMessage = sendMessage;
exports.receiveMessage = receiveMessage;
