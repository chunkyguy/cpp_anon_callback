//
//  Created by Sid on 03/03/13.
//  Copyright (c) 2013 whackylabs. All rights reserved.
//

#ifndef __WL_ICB_H__
#define __WL_ICB_H__
#include <iostream>

//	The base class to all the callbacks.

class ICB{
public:
	virtual ~ICB(){
		std::cout << "~ICB()" << std::endl;
	}

	ICB(void *d) : delegate(d){
		std::cout << "ICB()" << std::endl;
	}
	
	virtual void fire(int argc, ...){};
	
protected:
	void *delegate;
};

#endif

///EOF
