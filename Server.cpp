//
//  Created by Sid on 03/03/13.
//  Copyright (c) 2013 whackylabs. All rights reserved.
//

#include "Server.h"

#include <iostream>

Server::~Server(){
	std::cout << "~Server()" << std::endl;
}

Server::Server(){
	std::cout << "Server()" << std::endl;
}

////////////////////////////////////////////////////
//	Assumptions:
//
//	All these methods are part of Server protocol.
//	The Server known nothing about the Client,
//	or whoever is implementing these protocols.
//	Notice, that the Server has no include files,
//	except the Callback Interface.
////////////////////////////////////////////////////

void Server::hello(){
	std::cout << "Server: hello "<< std::endl;
	callback->fire(1, 1);
}
void Server::bind(){
	std::cout << "Server: bind " << std::endl;
	callback->fire(2, 2.1f, 2.8);
}
void Server::talk(){
	std::cout << "Server: talk " << std::endl;
	callback->fire(2, 3, 3.5);
}
void Server::bye(){
	std::cout << "Server: bye " << std::endl;
	callback->fire(1, 4.9);
}

void Server::registerCallback(ICB *cb){
	callback = cb;
}
///EOF
