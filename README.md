# client_server_c_cpp
It's a simple example of client -server application via c/c++ based on sockets.

# build

To build server app use:
	make server

To build client app use:
	make client

# usage

To run server app use:
	make run_server

To run client app use:
	make run_server

# description

It's a simple example how to send-resieve message via sockets. This example is working on localhost(127.0.0.1) and port 9991.

Cliend send message from keyboard, wait answer and print it.
Server wait request (while(true)), read messagem print it and send response to client. But just one time. After one request loop will stop.
