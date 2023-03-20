//
// Created by flawreen on 3/14/23.
//

#include <iostream>
#include "Movie.h"

using namespace std;

Movie::Movie() : title(nullptr), bestAward(nullptr), rating(0), viewCount(0), moviePrice(0) {}

Movie::Movie(const char *title, double price) : title(new String(title)), bestAward(nullptr),
												rating(0), viewCount(0), moviePrice(price) {}

Movie::Movie(const char *title, double price, const char *award) : Movie(title, price) {
	bestAward = new String(award);
}

Movie::Movie(const Movie &cpy) {
	if (title != nullptr) { delete title; }
	if (bestAward != nullptr) { delete bestAward; }

	if (cpy.title == nullptr) { title = nullptr; }
	else title = new String(cpy.title->getStr());

	if (cpy.bestAward == nullptr) { bestAward = nullptr; }
	else bestAward = new String(cpy.bestAward->getStr());

	rating = cpy.rating;
	viewCount = cpy.viewCount;
	moviePrice = cpy.moviePrice;
}

Movie &Movie::operator=(const Movie &cpy) {
	if (title != nullptr) { delete title; }
	if (bestAward != nullptr) { delete bestAward; }

	if (cpy.title == nullptr) { title = nullptr; }
	else title = new String(cpy.title->getStr());

	if (cpy.bestAward == nullptr) { bestAward = nullptr; }
	else bestAward = new String(cpy.bestAward->getStr());

	rating = cpy.rating;
	viewCount = cpy.viewCount;
	moviePrice = cpy.moviePrice;
	return *this;
}

Movie::~Movie() {
	if(title) delete title;
	if(bestAward) delete bestAward;
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
	os << " has reached " << mov.viewCount << " views";
	if (mov.bestAward) {
		os << " and has been awarded the " << *mov.bestAward << " award.\n";
	} else os << ".";
	os << "Rating: " << mov.rating << "/5 stars.";
	return os;
}

char *Movie::getTitle() const {
	return title->getStr();
}

double Movie::getMoviePrice() const {
	return moviePrice;
}

String *Movie::getBestAward() const {
	return bestAward;
}

void Movie::setTitle(char *title) {
	Movie::title = new String(title);
}

void Movie::setBestAward(char *bestAward) {
	Movie::bestAward = new String(bestAward);
}

void Movie::setMoviePrice(double moviePrice) {
	Movie::moviePrice = moviePrice;
}












