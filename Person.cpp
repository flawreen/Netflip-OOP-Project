//
// Created by flawreen on 4/14/23.
//

#include "Person.h"

Person::Person() = default;

Person::Person(string name, string mail, string phone) : name(name), mail(mail), phone(phone) {}

Person::~Person() {
	name.clear();
	mail.clear();
	phone.clear();
}


