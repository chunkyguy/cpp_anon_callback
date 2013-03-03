//
//  Created by Sid on 03/03/13.
//  Copyright (c) 2013 whackylabs. All rights reserved.
//

#ifndef __WL_CLIENT_H__
#define __WL_CLIENT_H__

#include "Server.h"
#include "ICB.h"

class Client{
public:
	~Client();
	Client();
	void connect();

	void hello(int a);
	void bind(double a, double b);
	void talk(int a, double b);
	void bye(double a);

private:
	Server *s;
	ICB *cb;
};
#endif
///EOF
