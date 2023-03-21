//
// Created by flawreen on 3/18/23.
//

#include <iostream>
#include "Subscription.h"
#include "User.h"
#include "Movie.h"
using namespace std;

void createUser(User& u) {
	char nume[20], mail[40], phone[11];
	cout << "Full name: ";
	cin.getline(nume, 20, '\n');
	cout << "Mail address: ";
	cin.getline(mail, 40, '\n');
	cout << "Phone number: ";
	cin.getline(phone, 10, '\n');
	u.setName(nume);
	u.setMail(mail);
	u.setPhone(phone);
}

void createSubscription(Subscription& sub) {
	char ans;
	cout << "Create free subscription? [y/N]: ";
	cin >> ans;
	cin.get();
	if (ans == 'y') {
		return; // constructorul default initializeaza abonamentul gratis
	}

	char name[20], code[20], quality[10], price[10];
	cout << "Subscription name: ";
	cin.getline(name, 20, '\n');
	cout << "Discount code (15%): ";
	cin.getline(code, 20, '\n');
	cout << "Streaming quality: ";
	cin.getline(quality, 10, '\n');
	cout << "Subscription price: ";
	cin.getline(price, 10, '\n');

	sub.setSubscriptionPlan(name);
	sub.setDiscountCode(code);
	sub.setStreamingQuality(quality);
	sub.setSubscriptionPrice(stod(price));
}

void createMovie(Movie& mov) {
	char title[30], price[10], award[30];

	cout << "Movie title: ";
	cin.getline(title, 30, '\n');
	cout << "Movie price: ";
	cin.getline(price, 10, '\n');
	cout << "Movie award [press enter to skip]: ";
	cin.getline(award, 30, '\n');

	mov.setTitle(title);
	mov.setMoviePrice(stod(price));
	if (award[0]) mov.setBestAward(award);
}


int main() {
	char option;
	User user;
	Subscription sub;
	Movie mov;
	cout << "1) Create user;\n2) Create subscription plan;\n3) Create movie;\n4) Add balance;\nx) Exit.\n";
	cout << "Choose option[1/2/3/4/x]: ";
	cin >> option;
	cin.get();

	while (option != 'x') {
		switch (option) {
			case '1':
				createUser(user);
				cout << user << endl;
				break;
			case '2':
				createSubscription(sub);
				cout << sub << endl;
				break;
			case '3':
				createMovie(mov);
				cout << mov << endl;
				break;
			case '4':
				double amount;
				cout << "Current balance: " << user.getBalance();
				cout << "\nEnter amount: ";
				cin >> amount;
				user.addBalance(amount);
				break;
			default:
				cout << "Choose a valid option!";
				return 0;
		}
		cout << "Choose option[1/2/3/4/x]: ";
		cin >> option;
		cin.get();
	}

	return 0;
}

