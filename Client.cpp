//
//  Created by Sid on 03/03/13.
//  Copyright (c) 2013 whackylabs. All rights reserved.
//

#include "Client.h"

#include <iostream>

////////////////////////////////////////////////////
//	Assumptions:
//
//	All the Callbacks are expected. They could be
//	a well-known format of Server protocol.
//	That's why they are so strongly implemented.
////////////////////////////////////////////////////

////////////////////////////////////////////////////
//	Hello Callback
////////////////////////////////////////////////////

class HelloCB : public ICB{
public:
	~HelloCB(){
		std::cout << "~HelloCB()" << std::endl;
	}
	HelloCB(Client *c) : ICB(c){
		std::cout << "HelloCB()" << std::endl;
	}
	
	void fire(int argc, ...){
		int a;
		
		va_list args;
		va_start(args, argc);

		a = va_arg(args, int);

		va_end(args);
		
		static_cast<Client *>(delegate)->hello(a);
	}
};

////////////////////////////////////////////////////
//	Bind Callback
////////////////////////////////////////////////////

class BindCB : public ICB{
public:
	~BindCB(){
		std::cout << "~BindCB()" << std::endl;
	}
	BindCB(Client *c) : ICB(c){
		std::cout << "~BindCB()" << std::endl;
	}
	
	void fire(int argc, ...){
		double a[2];
		
		va_list args;
		va_start(args, argc);
		
		for(int i = 0; i < argc; ++i){
			a[i] = va_arg(args, double);
		}
		
		va_end(args);
		
		static_cast<Client *>(delegate)->bind(a[0],a[1]);
	}
};

////////////////////////////////////////////////////
//	talk Callback
////////////////////////////////////////////////////

class TalkCB : public ICB{
public:
	~TalkCB(){
		std::cout << "~TalkCB()" << std::endl;
	}
	TalkCB(Client *c) : ICB(c){
		std::cout << "~TalkCB()" << std::endl;
	}
	
	void fire(int argc, ...){
		int a;
		double b;
		
		va_list args;
		va_start(args, argc);
		
		a = va_arg(args, int);
		b = va_arg(args, double);
		
		va_end(args);
		
		static_cast<Client *>(delegate)->talk(a,b);
	}
};

////////////////////////////////////////////////////
//	Bye Callback
////////////////////////////////////////////////////

class ByeCB : public ICB{
public:
	~ByeCB(){
		std::cout << "~ByeCB()" << std::endl;
	}
	ByeCB(Client *c) : ICB(c){
		std::cout << "ByeCB()" << std::endl;
	}
	
	void fire(int argc, ...){
		double a;
		
		va_list args;
		va_start(args, argc);
		
		a = va_arg(args, double);
		
		va_end(args);
		
		static_cast<Client *>(delegate)->bye(a);
	}
};


////////////////////////////////////////////////////
//	Client
////////////////////////////////////////////////////
Client::~Client(){
	delete s;
	if(cb){
		delete cb;
	}
	std::cout << "~Client()" << std::endl;
}

Client::Client(){
	std::cout << "Client()" << std::endl;
	s = new Server;
}

void Client::connect(){
	std::cout << "Client: connect" << std::endl;
		
	//create hello
	cb = new HelloCB(this);
	s->registerCallback(cb);
	s->hello();
}

////////////////////////////////////////////////////
//	Assumptions:
//
//	All these mehods are expected to be called
//	asynchronously by the server.
//	All the data is going to be sent from the server.
//	The number of arguments in each case are already
//	known.
////////////////////////////////////////////////////

void Client::hello(int a){
	std::cout << "Client: hello [" << a << "]" << std::endl;
	
	//delete hello
	delete cb;
	cb = 0;
	
	//create bind
	cb = new BindCB(this);
	s->registerCallback(cb);
	s->bind();
}
void Client::bind(double a, double b){
	std::cout << "Client: bind [" << a << "," << b << "]"  << std::endl;

	//delete bind
	delete cb;
	cb = 0;
	
	//create talk
	cb = new TalkCB(this);
	s->registerCallback(cb);
	s->talk();
}

void Client::talk(int a, double b){
	std::cout << "Client: talk [" << a << "," << b << "]" << std::endl;
	
	//delete talk
	delete cb;
	cb = 0;
	
	//create bye
	cb = new ByeCB(this);
	s->registerCallback(cb);
	s->bye();
}

void Client::bye(double a){
	std::cout << "Client: bye [" << a << "]" << std::endl;

	//delete bye
	delete cb;
	cb = 0;
	
	//set clean
	s->registerCallback(0);
}
///EOF
