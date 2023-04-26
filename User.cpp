//
// Created by flawreen on 3/16/23.
//

#include <iostream>
#include "InvalidPhoneNumber.cpp"
#include "InexistentAccount.cpp"
#include "NegativeBalance.cpp"
#include "ExistingObject.cpp"

using namespace std;

#include "User.h"

User::User() : Person(), userPlan(nullptr), balance(0.0), boughtMoviesCounter(0) {}

User::User(string name, string mail, string phone) : Person(name, mail, phone), balance(0.0),
													 boughtMoviesCounter(0) { userPlan = new Subscription(); }

User::~User() {
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
			if (userPlan->getProductName() == "FREE") {
				balance -= movie.getMoviePrice();
				boughtMovies.push_back(movie);
			} else {
				// Daca nu are abonamentul gratis atunci nu mai plateste pentru filme
				boughtMovies.push_back(movie);
			}
			++boughtMoviesCounter;
			cout << "Movie bought: " << endl;
			movie.contentDescription();
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
	try {
		if (name.empty() || mail.empty() || phone.empty()) {
			throw ("Create an account first");
		}
		try {
			if (money <= 0) {
				throw ("You are trying to add a number <= 0");
			}
		} catch (NegativeBalance &err_bal) {
			cerr << "Negative balance error: " << err_bal.what() << endl;
		}
		User::balance += money;
	} catch (InexistentAccount &err_account) {
		cerr << "Inexistent account error: " << err_account.what() << endl;
	}
}

void User::buySubscription(Subscription &plan) {
	try {
		if (name.empty() || mail.empty() || phone.empty()) {
			throw ("Create an account first");
		}

		try {
			if (balance < plan.getProductPrice()) {
				throw ("Insufficient balance");
			}

			try {
				if (userPlan->getProductName() == plan.getProductName()) {
					throw ("You already have this subscription");
				}

				balance -= plan.getProductPrice();
				delete userPlan;
				userPlan = &plan;
			} catch (ExistingObject &err_eobj) {
				cerr << "Existing object error: " << err_eobj.what() << endl;
			}
		}
		catch (NegativeBalance &err_bal) {
			cerr << "Negative Balance Error: " << err_bal.what() << endl;
		}
	} catch (InexistentAccount &err_account) {
		cerr << "Inexistent account error: " << err_account.what() << endl;
	}
}

void User::buySubscription(Subscription &plan, string discount) {
	if (name.empty()) {
		cout << "Create an account first!\n";
		return;
	}

	if (balance < plan.getProductPrice()) {
		cout << "Not enough balance.\n";
		return;
	} else {
		if (userPlan->getProductName() == plan.getProductName()) {
			cout << "You already have this subscription.\n";
			return;
		} else {
			plan.applyDiscount(discount);
			balance -= plan.getProductPrice();
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
	try {
		if (phone.size() > 10) {
			throw invalid_argument("Argument \'phone\' too long");
		}
	} catch (invalid_argument &err_ia) {
		cerr << "Invalid argument exception: " << err_ia.what() << endl;
		for (auto x: phone) {
			if (!isdigit(x)) {
				throw InvalidPhoneNumber("Found char in phone number");
			}
		}
	} catch (InvalidPhoneNumber &e) {
		cerr << "Error: " << e.what() << endl;
	}

	try {
		for (auto x: phone) {
			if (!isdigit(x)) {
				throw InvalidPhoneNumber("Found char in phone number");
			}
		}
		User::phone = phone;
	} catch (InvalidPhoneNumber &e) {
		cerr << "Error: " << e.what() << endl;
	}
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
	for (const auto m: boughtMovies) {
		cout << m.getTitle() << " ";
	}
	cout << endl;
}


