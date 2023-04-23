//
// Created by flawreen on 4/23/23.
//

#include "SuperUser.h"

Subscription SuperUser::god = Subscription("God Mode Subscription", "", "8K", 9999.99);

void SuperUser::whoAmI() {
	cout << "I am a movie director. No I'm not Quentin Tarantino.";
	cout << "My name is " << name << ". Call me if ready for business: " << phone << ".\n";
}

SuperUser::SuperUser(string nume, string maill, string phonee, string universiti) {
	name = nume;
	mail = maill;
	phone = phonee;
	university = universiti;
	userPlan = &god;
	balance = 999999999.99;
}

SuperUser::~SuperUser() {
	delete &god;
}

void SuperUser::buyMovie(Movie &movie) {
	cout << "Super users have access to all movies.\n";
}

void SuperUser::watchMovie(Movie &movie) {
	movie.increaseViewCount();
	cout << "You are now watching " << movie.getTitle() << " in ";
	cout << userPlan->getStreamingQuality() << " resolution.\n";
}

void SuperUser::checkBoughtMovies() {
	cout << "You own every movie possible on our platform.\n";
}



