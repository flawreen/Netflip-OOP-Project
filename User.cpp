//
// Created by flawreen on 3/16/23.
//

#include <iostream>

using namespace std;

#include "User.h"

User::User() : Person(), userPlan(nullptr), balance(0.0), boughtMoviesCounter(0) {}

User::User(string name, string mail, string phone) : Person(name, mail, phone), balance(0.0),
													 boughtMoviesCounter(0) { userPlan = new Subscription(); }

User::~User() {
	boughtMovies.clear();
	if (userPlan) userPlan = nullptr; // la fel ca la boughtMovie
}

void User::whoAmI() {
	cout << "My name is " << name << "! You can contact me at any time by phone at " << phone;
	cout << " or you can send me a mail at " << mail << "!\n";
}

void User::buyMovie(Movie &movie) {
	if (!name.empty()) {
		if (balance < movie.getMoviePrice()) {
			cout << "Not enough balance.\n";
			return;
		} else {
			if (userPlan->getSubscriptionPlan() == "FREE") {
				balance -= movie.getMoviePrice();
				boughtMovies.push_back(movie);
			} else {
				// Daca nu are abonamentul gratis atunci nu mai plateste pentru filme
				boughtMovies.push_back(movie);
			}
			++boughtMoviesCounter;
		}
	} else cout << "Create an account first!\n";
}

void User::watchMovie(Movie &movie) {
	if (name.empty()) {
		cout << "Create an account first!\n";
		return;
	} else {
		int foundMovie = 0;
		for (const auto &mov: boughtMovies) {
			if (mov.getTitle() == movie.getTitle()) {
				movie.increaseViewCount();
				cout << "You are now watching " << movie.getTitle() << " in ";
				cout << userPlan->getStreamingQuality() << " resolution.\n";
				foundMovie = 1;
				break;
			}
		}
		if (!foundMovie) {
			cout << "You don't own that movie.\n";
		}
	}
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

User::User(const User &cpy) {
	balance = cpy.balance;
	boughtMoviesCounter = cpy.boughtMoviesCounter;
	name = cpy.name;
	mail = cpy.mail;
	phone = cpy.phone;
	boughtMovies = cpy.boughtMovies;

	if (cpy.userPlan == nullptr) userPlan = nullptr;
	else *userPlan = *cpy.userPlan;
}

User &User::operator=(const User &cpy) {
	balance = cpy.balance;
	boughtMoviesCounter = cpy.boughtMoviesCounter;
	name = cpy.name;
	mail = cpy.mail;
	phone = cpy.phone;
	boughtMovies = cpy.boughtMovies;

	if (cpy.userPlan == nullptr) userPlan = nullptr;
	else *userPlan = *cpy.userPlan;
	return *this;
}

std::ostream &operator<<(ostream &os, User &user) {
	if (user.name.empty()) {
		os << "No account created.\n";
		return os;
	}
	os << "You have bought over " << user.boughtMoviesCounter << " movie(s)";
	os << ".\nBalance: $" << user.balance << ".";
	return os;
}

void User::setName(string name) {
	User::name = name;
}

void User::setMail(string mail) {
	User::mail = mail;
}

void User::setPhone(string phone) {
	for (auto x: phone) {
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

void User::checkBoughtMovies() {
	for (const auto m : boughtMovies) {
		cout << m.getTitle() << " ";
	}
	cout << endl;
}


