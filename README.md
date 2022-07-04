# client_server_c_cpp
It's a simple example of client -server application via c/c++ based on sockets.

	
# build

To build server app use:  
- make server

To build client app use:  
- make client

# usage

To run server app use:  
- make run_server

To run client app use:  
- make run_server

# description

It's a simple example how to send-resieve message via sockets. This example is working on localhost(127.0.0.1) and port 9991.  
There are a few branches:  
- "Basic" - include basic functions. The server listens to just one request and gives just one response. The same thing does the client. It just sends a request to the server and waits for one response.  
- "Endless work(main)" - includes basic functions, but the server works till it gets a "stop"(you need to send @ symbol) request. The client sends requests till the user doesn't type the "stop" command.
