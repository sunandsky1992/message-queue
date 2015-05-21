var express = require('express');
var app = express();
var url = require('url');
var router = express.Router();
var zmq = require('./zmq');
router.use(function logs(req,res,next){
	next();
})

router.put('/mq/create',function(req,res){
	var putData="";
	req.on("data",function(data){
		putData+=data;
	})
	req.on("end",function(){
		try{
			var resArr = JSON.parse(putData);
			console.log(putData);
			zmq.sendMessage('localhost:5555',putData,res);
		}
		catch(e){
			res.send('1');
		}
	})
})

router.get('/mq/receive',function(req,res){
	var queueName = url.parse(req.url,true).query.queue;
        var message = "{\"queue\":\""+queueName+"\"}" 	
	try{
		console.log(message);
		zmq.sendMessage('localhost:5556',message,res);
	}
	catch(e){
	
	}
})
module.exports = router;
