//
// Created by flawreen on 4/23/23.
//

#include "SuperUser.h"

#include <utility>

Subscription SuperUser::god = Subscription("God Mode Subscription", "", "8K", 9999.99);

void SuperUser::whoAmI() const {
	cout << "I am a movie director. No I'm not Quentin Tarantino.";
	cout << "My name is " << name << ". Call me if ready for business: " << phone << ".\n";
}

SuperUser::SuperUser(string nume, string maill, string phonee, string universiti) {
	name = std::move(nume);
	mail = std::move(maill);
	phone = std::move(phonee);
	university = std::move(universiti);
	userPlan = &god;
	balance = 999999999.99;
}

SuperUser::~SuperUser() = default;

void SuperUser::buyMovie(const Movie* movie) const {
	cout << "Super users have access to all movies.\n";
}

void SuperUser::watchMovie(Movie* movie) const {
	movie->increaseViewCount();
	cout << "You are now watching " << movie->getTitle() << " in ";
	cout << userPlan->getStreamingQuality() << " resolution.\n";
}

void SuperUser::checkBoughtMovies() const {
	cout << "You own every movie possible on our platform.\n";
}



