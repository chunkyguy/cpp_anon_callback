//
//  Created by Sid on 03/03/13.
//  Copyright (c) 2013 whackylabs. All rights reserved.
//

#ifndef __WL_SERVER_H__
#define __WL_SERVER_H__
#include "ICB.h"
//	All methods are assumed async

class Server{
public:
	~Server();
	Server();
	
	void hello();
	void bind();
	void talk();
	void bye();
	
	void registerCallback(ICB *cb);
private:
	ICB *callback;
};
#endif

///EOF
