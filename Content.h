//
// Created by flawreen on 4/14/23.
//

#ifndef NETFLIP_CONTENT_H
#define NETFLIP_CONTENT_H

#include <string>
using namespace std;

class Content {
protected:
	virtual void contentDescription()=0;
	virtual void increaseViewCount()=0;
public:
	virtual ~Content();
};


#endif //NETFLIP_CONTENT_H
