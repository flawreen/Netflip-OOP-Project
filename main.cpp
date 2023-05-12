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

template<class T>
void freeVector(vector<T *> &vect) {
	for (auto x: vect) {
		delete x;
	}
	vect.clear();
}

template<typename T>
class ClassHolder {
	vector<T*> holder;
public:
	ClassHolder() = default;

	~ClassHolder() {
		freeVector<T>(holder);
	}

	void addItem(T* item) {
		holder.push_back(item);
	}

	void printAllItems() {
		for (const auto item: holder) {
			cout << *item << endl;
		}
	}

};

template<>
class ClassHolder<Director> {
	vector<Director*> holder;
public:
	ClassHolder() = default;

	~ClassHolder() {
		freeVector<Director>(holder);
	}

	void addItem(Director* item) {
		holder.push_back(item);
	}

	void printAllItems() {
		for (const auto item: holder) {
			item->whoAmI();
			cout << endl;
		}
	}
};

int main() {
	vector<Person *> vperson;
	vector<AdvertisableProduct *> vprod;
	vector<Content *> vcontent;

	// Fac vectorul cu upcasting de Person
	Person *user1 = new User("Mircea", "mircea.boss@hotmail.com", "0712233456");
	Person *user2 = new User("nume1", "mail1", "0700000000");
	Person *director = new Director("Promania", "costin.boss@hotmail.uk", "07maiincearca", "Scoala vietii");
	vperson.push_back(user1);
	vperson.push_back(user2);
	vperson.push_back(director);
	int userCounter = 0, directorCounter = 0;
	for (const auto p: vperson) {
		p->whoAmI();
		cout << endl;
		if (dynamic_cast<User *>(p) != nullptr) {
			++userCounter;
		} else if (dynamic_cast<Director *>(p) != nullptr) {
			++directorCounter;
		}
	}

	cout << "On our platform there are " << vperson.size() << " people of which:\n";
	cout << userCounter << " are users;\n";
	cout << directorCounter << " are directors;\n";

	// Fac vectorul cu upcasting de AdvertisableProduct
	AdvertisableProduct *subscription1 = new Subscription("Premium", "nflip112", "4K", 199.89);
	AdvertisableProduct *subscription2 = new Subscription("Plus", "-", "1080p", 20.99);
	vprod.push_back(subscription1);
	vprod.push_back(subscription2);

	for (const auto sub: vprod) {
		sub->advertiseProduct();
		cout << endl;
	}

	// Fac vectorul cu upcasting de Content
	Content *mov1 = new Movie("film1", 123.0);
	Content *mov2 = new Movie("film2", 1234.55);
	vcontent.push_back(mov1);
	vcontent.push_back(mov2);

	User *superuser = new SuperUser("Lenghel", "imiplacesamananc@hotmail.uk", "07maiincearca", "Dristor Oradea");
	for (const auto mov: vcontent) {
		mov->contentDescription();
		cout << endl;
		superuser->watchMovie(dynamic_cast<Movie *>(mov));
		cout << endl;
	}

	auto *normalMovie = dynamic_cast<Movie *>(mov1);
	auto *normalUser = dynamic_cast<User *>(user1);
	normalUser->setBalance(99999.9);
	normalUser->buyMovie(normalMovie);
	normalUser->watchMovie(normalMovie);

	ClassHolder<User> userHolder;
	userHolder.addItem(new User("Mihai", "mihai", "0712345678"));
	userHolder.addItem(new User("Mihai2", "mihai2", "0712345678"));
	userHolder.addItem(new User("Mihai3", "mihai3", "0712345678"));
	userHolder.printAllItems();

	ClassHolder<Director> directorHolder;
	directorHolder.addItem(new Director("Mihai3", "mihai3", "0712345678", "test1"));
	directorHolder.addItem(new Director("Mihai33", "mihai33", "0712345678", "test13"));
	directorHolder.addItem(new Director("Mihai34", "mihai34", "0712345678", "test14"));
	directorHolder.printAllItems();



	freeVector<Person>(vperson);
	freeVector<AdvertisableProduct>(vprod);
	freeVector<Content>(vcontent);
	normalUser = nullptr;
	normalMovie = nullptr;
	delete superuser;

	return 0;
}




