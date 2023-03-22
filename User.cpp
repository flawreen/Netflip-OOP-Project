//
// Created by flawreen on 3/16/23.
//

#include <iostream>
#include <cstring>
using namespace std;
#include "User.h"

User::User() : name(""), mail(""), phone(""), userPlan(nullptr),
				balance(0.0), boughtMoviesCounter(0), boughtMovie(nullptr) {}

User::User(string name, string mail, string phone) :
				name(name), mail(mail), boughtMovie(nullptr),
				phone(phone), balance(0.0), boughtMoviesCounter(0)
	{userPlan = new Subscription();}

void User::buyMovie(Movie& movie) {
	if (boughtMovie != nullptr) {
		cout << "You can't buy another movie!\n";
	} else if (!name.empty()) {
		if (balance < movie.getMoviePrice()) {
			cout << "Not enough balance.\n";
			return;
		} else {
			if (userPlan->getSubscriptionPlan() == "FREE") {
				balance -= movie.getMoviePrice();
			}
			++boughtMoviesCounter;
			boughtMovie = &movie;
		}
	} else cout << "Create an account first!\n";
}

void User::watchMovie() {
	if (name.empty()) {
		cout << "Create an account first!\n";
		return;
	} else if (boughtMovie == nullptr) {
		cout << "You haven't bought any movie.\n";
		return;
	}
	boughtMovie->increaseViewCount();
	cout << "You are now watching " << boughtMovie->getTitle() << " in ";
	cout << userPlan->getStreamingQuality() << " resolution.\n";
}

void User::addBalance(const double money) {
	if (!name.empty()) {
		balance += money;
		cout << "New balance: " << balance << endl;
	} else cout << "Create an account first!\n";
}

void User::buySubscription(Subscription &plan) {
	if (name.empty()) {
		cout << "Create an account first!\n";
		return;
	}
	if (balance < plan.getSubscriptionPrice()) {
		cout << "Not enough balance.\n";
		return;
	} else {
		if (userPlan->getSubscriptionPlan() == plan.getSubscriptionPlan()) {
			cout << "You already have this subscription.\n";
			return;
		} else {
			balance -= plan.getSubscriptionPrice();
			delete userPlan;
			userPlan = &plan;
		}
	}
}

void User::buySubscription(Subscription &plan, string discount) {
	if (name.empty()) {
		cout << "Create an account first!\n";
		return;
	}

	if (balance < plan.getSubscriptionPrice()) {
		cout << "Not enough balance.\n";
		return;
	} else {
		if (userPlan->getSubscriptionPlan() == plan.getSubscriptionPlan()) {
			cout << "You already have this subscription.\n";
			return;
		} else {
			plan.applyDiscount(discount);
			balance -= plan.getSubscriptionPrice();
			plan.revertPriceAfterBuy();
			delete userPlan;
			userPlan = &plan;
		}
	}
}

User::~User() {
	if (boughtMovie) boughtMovie = nullptr; // nu sterg obiectul de tip Movie, sterg doar asocierea lui cu User
	if (userPlan) userPlan = nullptr; // la fel ca la boughtMovie
}

User::User(const User &cpy) {
	balance = cpy.balance;
	boughtMoviesCounter = cpy.boughtMoviesCounter;
	name = cpy.name;
	mail = cpy.mail;
	phone = cpy.phone;

	if (cpy.boughtMovie == nullptr) boughtMovie = nullptr;
	else *boughtMovie = *cpy.boughtMovie;

	if (cpy.userPlan == nullptr) userPlan = nullptr;
	else *userPlan = *cpy.userPlan;
}

User &User::operator=(const User &cpy) {
	balance = cpy.balance;
	boughtMoviesCounter = cpy.boughtMoviesCounter;
	name = cpy.name;
	mail = cpy.mail;
	phone = cpy.phone;

	if (cpy.boughtMovie == nullptr) boughtMovie = nullptr;
	else *boughtMovie = *cpy.boughtMovie;

	if (cpy.userPlan == nullptr) userPlan = nullptr;
	else *userPlan = *cpy.userPlan;
	return *this;
}

std::ostream &operator<<(ostream &os, User &user) {
	if (user.name.empty()) {
		os << "No account created.\n";
		return os;
	}
	os << "You have bought " << user.boughtMoviesCounter << " movie(s): ";
	if (user.boughtMovie) os << user.boughtMovie->getTitle();
	else os << "-";
	os << ".\nBalance: $" << user.balance << ".";
	return os;
}

void User::setBoughtMovie(Movie *boughtMovie) {
	User::boughtMovie = boughtMovie;
}

void User::setName(string name) {
	User::name = name;
}

void User::setMail(string mail) {
	User::mail = mail;
}

void User::setPhone(string phone) {
	for (auto x : phone) {
		if (!isdigit(x)) {
			cout << "Invalid phone number.\n";
			return;
		}
	}
	User::phone = phone;
}

void User::setUserPlan(Subscription *userPlan) {
	User::userPlan = userPlan;
}

void User::setBalance(double balance) {
	User::balance = balance;
}

void User::setBoughtMoviesCounter(int boughtMoviesCounter) {
	User::boughtMoviesCounter = boughtMoviesCounter;
}

double User::getBalance() const {
	return balance;
}

string User::getName() const {
	return name;
}


