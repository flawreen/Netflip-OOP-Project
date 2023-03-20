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
	~User();
	User(const User& cpy);
	User& operator=(const User& cpy);

	void buyMovie(Movie& movie);
	void watchMovie();
	void addBalance(double money);
	void buySubscription(Subscription& plan);
	void buySubscription(Subscription& plan, const char* discount);
	friend std::ostream& operator<<(std::ostream &os, User& user);

	void setBoughtMovie(Movie *boughtMovie);
	void setName(char *name);
	void setMail(char *mail);
	void setPhone(char *phone);
	void setUserPlan(Subscription *userPlan);
	void setBalance(double balance);
	void setBoughtMoviesCounter(int boughtMoviesCounter);

};


#endif //NETFLIP_USER_H
