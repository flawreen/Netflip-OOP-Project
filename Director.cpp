//
// Created by flawreen on 3/15/23.
//

#include <iostream>
#include "Director.h"

using namespace std;

int Director::movieCount = 0;

Director::Director() : Person() {}

Director::Director(string name, string mail, string phone, string university) : Person(name, mail, phone),
																				university(university) {}


Director::Director(const Director &cpy) : university(cpy.university) {
	name = cpy.name;
	mail = cpy.name;
	phone = cpy.phone;
}

Director &Director::operator=(const Director &cpy) {
	name = cpy.name;
	mail = cpy.name;
	phone = cpy.phone;
	university = cpy.university;
	return *this;
}

Director::~Director() {
	university.clear();
	filmography.clear();
	Director::movieCount = 0;
}

string Director::getName() const {
	return name;
}

void Director::increaseMovieCount() {
	++Director::movieCount;
}

void Director::addMovie(Movie &movie) {
	filmography.push_back(movie);
	increaseMovieCount();
}

int Director::getMovieCount() {
	return Director::movieCount;
}

void Director::whoAmI() {
	cout << "I am a movie director. No I'm not Quentin Tarantino.";
	cout << " My name is " << name << ". Call me if ready for business: " << phone << ".\n";
}


