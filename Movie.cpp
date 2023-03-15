//
// Created by flawreen on 3/14/23.
//

#include <iostream>
#include "Movie.h"

using namespace std;

Movie::Movie() : title(nullptr), bestAward(nullptr), rating(0), viewCount(0), price(0) {}

Movie::Movie(const char *title, double price) : title(new String(title)), bestAward(nullptr),
												rating(0), viewCount(0), price(price) {}

Movie::Movie(const char *title, double price, const char *award) : Movie(title, price) {
	bestAward = new String(award);
}

Movie::Movie(const Movie &cpy) {
	if (title != nullptr) { delete title; }
	if (bestAward != nullptr) { delete bestAward; }

	if (cpy.title == nullptr) { title = nullptr; }
	else title = new String(*cpy.title);

	if (cpy.bestAward == nullptr) { bestAward = nullptr; }
	else bestAward = new String(*cpy.bestAward);

	rating = cpy.rating;
	viewCount = cpy.viewCount;
	price = cpy.price;
}

Movie &Movie::operator=(const Movie &cpy) {
	if (title != nullptr) { delete title; }
	if (bestAward != nullptr) { delete bestAward; }

	if (cpy.title == nullptr) { title = nullptr; }
	else title = new String(*cpy.title);

	if (cpy.bestAward == nullptr) { bestAward = nullptr; }
	else bestAward = new String(*cpy.bestAward);

	rating = cpy.rating;
	viewCount = cpy.viewCount;
	price = cpy.price;
	return *this;
}

Movie::~Movie() {
	delete title;
	delete bestAward;
}

void Movie::addAward(const char *award) {
	if (bestAward == nullptr) {
		bestAward = new String(award);
	} else {
		cout << "This movie already has an award.\n";
	}
}

void Movie::increaseViewCount() {
	++this->viewCount;
}

std::ostream &operator<<(ostream &os, Movie &mov) {
	cout << *mov.title;
	os << " has reached " << mov.viewCount << " views ";
	os << "and has been awarded the " << *mov.bestAward << " award.\n";
	os << "Rating: " << mov.rating << "/5 stars.";
}

char *Movie::getTitle() const {
	return title->getStr();
}

//int main() {
//	Movie Matrix("Matrix", 120.33, "Golden Globe");
//	Matrix.addAward("Emmy");
//	cout << Matrix;
//
//	return 0;
//}













