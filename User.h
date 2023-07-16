//
// Created by flawreen on 3/16/23.
//

#ifndef NETFLIP_USER_H
#define NETFLIP_USER_H


#include <string>
#include <vector>
#include "Subscription.h"
#include "Movie.h"
#include <chrono>

using namespace std;

#include "Person.h"

class User : public virtual Person {
protected:
	vector<Movie> boughtMovies;
	Subscription *userPlan;
	const time_t time_created;
	string user_id;
	double balance;
	int boughtMoviesCounter;

public:
	User();

	User(const string& name, string mail, string phone);

	virtual ~User();

	User(const User &cpy);

	User &operator=(const User &cpy);

	void whoAmI() const override;

	virtual void buyMovie(const Movie *movie);

	virtual void watchMovie(Movie *movie) const;

	virtual void checkBoughtMovies() const;

	void addBalance(double money);

	void buySubscription(Subscription &plan);

	void buySubscription(Subscription &plan, string discount);

	friend std::ostream &operator<<(std::ostream &os, User &user);

	void setName(string name);

	void setMail(string mail);

	void setPhone(const string& phone);

	void setUserPlan(Subscription *userPlan);

	void setBalance(double balance);

	void setBoughtMoviesCounter(int boughtMoviesCounter);

	double getBalance() const;

	string getName() const;

};


#endif //NETFLIP_USER_H
