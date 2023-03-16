//
// Created by flawreen on 3/16/23.
//

#ifndef NETFLIP_USER_H
#define NETFLIP_USER_H


#include "String.h"
#include "Subscription.h"
#include "Movie.h"

class User {
	Movie* boughtMovie;
	String *name, *mail, *phone;
	Subscription* userPlan;
	double balance;
	int boughtMoviesCounter;

public:
	User();
	User(const char* name, const char* mail, const char* phone);
	// TODO creare de cont
	void buyMovie(Movie& movie);
	void watchMovie();
	void addBalance(double money);
	void buySubscription(Subscription& plan);
	void buySubscription(Subscription& plan, const char* discount);

};


#endif //NETFLIP_USER_H
