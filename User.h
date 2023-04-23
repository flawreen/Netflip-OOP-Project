//
// Created by flawreen on 3/16/23.
//

#ifndef NETFLIP_USER_H
#define NETFLIP_USER_H


#include <string>
#include <vector>
#include "Subscription.h"
#include "Movie.h"
using namespace std;
#include "Person.h"

class User : public virtual Person {
protected:
	vector<Movie> boughtMovies;
	Subscription* userPlan;
	double balance;
	int boughtMoviesCounter;

public:
	User();
	User(string name, string mail, string phone);
	virtual ~User() override;
	User(const User& cpy);
	User& operator=(const User& cpy);
	void whoAmI() override;

	void buyMovie(Movie& movie);
	void watchMovie(Movie& movie);
	void checkBoughtMovies();
	void addBalance(double money);
	void buySubscription(Subscription& plan);
	void buySubscription(Subscription& plan, string discount);
	friend std::ostream& operator<<(std::ostream &os, User& user);

	void setName(string name);
	void setMail(string mail);
	void setPhone(string phone);
	void setUserPlan(Subscription *userPlan);
	void setBalance(double balance);
	void setBoughtMoviesCounter(int boughtMoviesCounter);
	double getBalance() const;
	string getName() const;

};


#endif //NETFLIP_USER_H
