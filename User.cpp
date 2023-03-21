//
// Created by flawreen on 3/16/23.
//

#include <iostream>
#include <cstring>
using namespace std;
#include "User.h"

User::User() : name(nullptr), mail(nullptr), phone(nullptr), userPlan(nullptr),
				balance(0.0), boughtMoviesCounter(0), boughtMovie(nullptr) {}

User::User(const char *name, const char *mail, const char *phone) :
				name(new String(name)), mail(new String(mail)), boughtMovie(nullptr),
				phone(new String(phone)), balance(0.0), boughtMoviesCounter(0)
	{userPlan = new Subscription();}

void User::buyMovie(Movie& movie) {
	if (boughtMovie != nullptr) {
		cout << "You can't buy another movie!\n";
	} else if (name != nullptr) {
		if (balance < movie.getMoviePrice()) {
			cout << "Not enough balance.\n";
			return;
		} else {
			if (strcmp(userPlan->getSubscriptionPlan()->getStr(), "FREE") == 0) {
				balance -= movie.getMoviePrice();
			}
			++boughtMoviesCounter;
			boughtMovie = &movie;
		}
	} else cout << "Create an account first!\n";
}

void User::watchMovie() {
	if (name == nullptr) {
		cout << "Create an account first!\n";
		return;
	} else if (boughtMovie == nullptr) {
		cout << "You haven't bought any movie.\n";
		return;
	}
	boughtMovie->increaseViewCount();
	cout << "You are now watching " << boughtMovie->getTitle() << " in ";
	cout << userPlan->getStreamingQuality()->getStr() << " resolution.\n";
}

void User::addBalance(const double money) {
	if (name != nullptr) {
		balance += money;
		cout << "New balance: " << balance << endl;
	} else cout << "Create an account first!\n";
}

void User::buySubscription(Subscription &plan) {
	if (name == nullptr) {
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

void User::buySubscription(Subscription &plan, const char *discount) {
	if (name == nullptr) {
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
	if (name) delete name;
	if (boughtMovie) boughtMovie = nullptr; // nu sterg obiectul de tip Movie, sterg doar asocierea lui cu User
	if (mail) delete mail;
	if (phone) delete phone;
	if (userPlan) userPlan = nullptr; // la fel ca la boughtMovie
}

User::User(const User &cpy) {
	balance = cpy.balance;
	boughtMoviesCounter = cpy.boughtMoviesCounter;
	if (name) delete name;
	if (mail) delete mail;
	if (phone) delete phone;
	if (boughtMovie) boughtMovie = nullptr;
	if (userPlan) userPlan = nullptr;

	if (cpy.name == nullptr) name = nullptr;
	else name = new String(cpy.name->getStr());

	if (cpy.mail == nullptr) mail = nullptr;
	else mail = new String(cpy.mail->getStr());

	if (cpy.phone == nullptr) phone = nullptr;
	else phone = new String(cpy.phone->getStr());

	if (cpy.boughtMovie == nullptr) boughtMovie = nullptr;
	else *boughtMovie = *cpy.boughtMovie;

	if (cpy.userPlan == nullptr) userPlan = nullptr;
	else *userPlan = *cpy.userPlan;
}

User &User::operator=(const User &cpy) {
	balance = cpy.balance;
	boughtMoviesCounter = cpy.boughtMoviesCounter;
	if (name) delete name;
	if (mail) delete mail;
	if (phone) delete phone;
	if (boughtMovie) boughtMovie = nullptr;
	if (userPlan) userPlan = nullptr;

	if (cpy.name == nullptr) name = nullptr;
	else name = new String(cpy.name->getStr());

	if (cpy.mail == nullptr) mail = nullptr;
	else mail = new String(cpy.mail->getStr());

	if (cpy.phone == nullptr) phone = nullptr;
	else phone = new String(cpy.phone->getStr());

	if (cpy.boughtMovie == nullptr) boughtMovie = nullptr;
	else *boughtMovie = *cpy.boughtMovie;

	if (cpy.userPlan == nullptr) userPlan = nullptr;
	else *userPlan = *cpy.userPlan;
	return *this;
}

std::ostream &operator<<(ostream &os, User &user) {
	if (user.name == nullptr) {
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

void User::setName(char *name) {
	User::name = new String(name);
}

void User::setMail(char *mail) {
	User::mail = new String(mail);
}

void User::setPhone(char *phone) {
	User::phone = new String(phone);
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

String *User::getName() const {
	return name;
}


