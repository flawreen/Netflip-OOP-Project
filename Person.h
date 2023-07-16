//
// Created by flawreen on 4/14/23.
//

#ifndef NETFLIP_PERSON_H
#define NETFLIP_PERSON_H

#include <iostream>
using namespace std;


class Person {
protected:
	string name, mail, phone;
public:
	Person();
	Person(string name, string mail, string phone);
	virtual ~Person();
	virtual void whoAmI() const = 0;
};


#endif //NETFLIP_PERSON_H
