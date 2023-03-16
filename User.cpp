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
	if (boughtMovie == nullptr) {
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


