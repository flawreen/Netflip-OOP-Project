//
// Created by flawreen on 4/14/23.
//

#include "Person.h"

#include <utility>

Person::Person() = default;

Person::Person(string name, string mail, string phone) : name(std::move(name)), mail(std::move(mail)), phone(std::move(phone)) {}

Person::~Person() = default;


