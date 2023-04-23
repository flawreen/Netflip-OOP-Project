//
// Created by flawreen on 4/14/23.
//

#ifndef NETFLIP_CONTENT_H
#define NETFLIP_CONTENT_H

#include <string>
using namespace std;

class Content {
protected:
	virtual void addAward(const string &award);
	virtual void increaseViewCount();
};


#endif //NETFLIP_CONTENT_H
