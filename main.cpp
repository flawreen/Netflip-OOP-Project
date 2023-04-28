//
// Created by flawreen on 3/18/23.
//

#include <iostream>
#include <string>
#include "Subscription.h"
#include "User.h"
#include "Director.h"
#include "Movie.h"
#include "SuperUser.h"

using namespace std;

void createUser(User &u) {
	string nume, mail, phone;
	cout << "Full name: ";
	getline(cin, nume, '\n');
	cout << "Mail address: ";
	getline(cin, mail, '\n');
	cout << "Phone number: ";
	getline(cin, phone, '\n');
	u.setName(nume);
	u.setMail(mail);
	u.setPhone(phone);
}

void createSubscription(Subscription &sub) {
	char ans;
	cout << "Create free subscription? [y/N]: ";
	cin >> ans;
	cin.get();
	if (ans == 'y') {
		return; // constructorul default initializeaza abonamentul gratis
	}

	string name, code, quality, price;
	cout << "Subscription name: ";
	getline(cin, name, '\n');
	cout << "Discount code (15%): ";
	getline(cin, code, '\n');
	cout << "Streaming quality: ";
	getline(cin, quality, '\n');
	cout << "Subscription price: ";
	getline(cin, price, '\n');

	sub.setProductName(name);
	sub.setDiscountCode(code);
	sub.setStreamingQuality(quality);
	sub.setProductPrice(stod(price));
}

void createMovie(Movie &mov) {
	string title, price, award;

	cout << "Movie title: ";
	getline(cin, title, '\n');
	cout << "Movie price: ";
	getline(cin, price, '\n');
	cout << "Movie award [press enter to skip]: ";
	getline(cin, award, '\n');

	mov.setTitle(title);
	mov.setMoviePrice(stod(price));
	mov.addAward(award);
}

int main() {
//	Subscription free;
//	Subscription premium("Premium", "nflip112", "4K", 199.89);
//	User u1;
//	User u2("Mircea", "mircea.boss@hotmail.com", "0712233456");
//	Movie m1("Matrix", 199.99);
//	Director d1("Promania", "costin.boss@hotmail.uk", "07maiincearca", "Scoala vietii");
//	d1.addMovie(m1);
//	u2.addBalance(99999.99);
//	u2.buySubscription(premium);
//	u2.buyMovie(m1);
//	u2.checkBoughtMovies();

	vector<Person*> vperson;
	vector<User*> vuser;
	vector<Director*> vdirector;
	vector<SuperUser*> vsuperuser;
	Person* user = new User("Mircea", "mircea.boss@hotmail.com", "0712233456");
	Person* director = new Director("Promania", "costin.boss@hotmail.uk", "07maiincearca", "Scoala vietii");
	vperson.push_back(user);
	vperson.push_back(director);
	User* superuser = new SuperUser("Lenghel", "imiplacesamananc@hotmail.uk", "07maiincearca", "Dristor Oradea");
	vperson.push_back(superuser);
	AdvertisableProduct* subscription = new Subscription("Premium", "nflip112", "4K", 199.89);
	user->whoAmI();
	cout << endl;
	director->whoAmI();
	cout << endl;
	superuser->checkBoughtMovies();
	cout << endl;
	subscription->advertiseProduct();
	cout << endl;

	AdvertisableProduct* abonament = new Subscription();
	Subscription* free = dynamic_cast<Subscription*>(abonament); // am realizat downcastingul
	free->advertiseProduct();

	for (auto p : vperson) {
		if (dynamic_cast<User*>(p) != nullptr) {
			vuser.push_back(dynamic_cast<User*>(p));
		} else if (dynamic_cast<Director*>(p)) {
			vdirector.push_back(dynamic_cast<Director*>(p));
		}
		if (dynamic_cast<SuperUser*>(p)) {
			vsuperuser.push_back(dynamic_cast<SuperUser*>(p));
		}
	}

	cout << "On our platform there are " << vperson.size() << " people of which:\n";
	cout << vuser.size() << " are users.\n";
	cout << vdirector.size() << " are directors.\n";

	delete user;
	delete director;
	delete superuser;
	delete subscription;

//	char option;
//	User user;
//	Subscription sub;
//	Movie mov;
//	cout << "1) Create user;\n2) Create subscription plan;\n3) Create movie;\n4) Add balance;\nx) Exit.\n";
//	cout << "Choose option[1/2/3/4/x]: ";
//	cin >> option;
//	cin.get();
//
//	while (option != 'x') {
//		switch (option) {
//			case '1':
//				createUser(user);
//				cout << user << endl;
//				break;
//			case '2':
//				createSubscription(sub);
//				cout << sub << endl;
//				break;
//			case '3':
//				createMovie(mov);
//				cout << mov << endl;
//				break;
//			case '4':
//				double amount;
//				cout << "Current balance: " << user.getBalance();
//				cout << "\nEnter amount: ";
//				cin >> amount;
//				user.addBalance(amount);
//				break;
//			default:
//				cout << "Choose a valid option!";
//				return 0;
//		}
//		cout << "Choose option[1/2/3/4/x]: ";
//		cin >> option;
//		cin.get();
//	}

	return 0;
}




