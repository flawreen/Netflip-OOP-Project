//
// Created by flawreen on 3/14/23.
//

#include <iostream>
#include "Movie.h"

using namespace std;

Movie::Movie() : title(""), bestAward(""), rating(0), viewCount(0), moviePrice(0) {}

Movie::Movie(string title, double price) : title(title), bestAward(""),
												rating(0), viewCount(0), moviePrice(price) {}

Movie::Movie(string title, double price, string award) : Movie(title, price) {
	bestAward = award;
}

Movie::Movie(const Movie &cpy) {
	title = cpy.title;
	bestAward = cpy.bestAward;
	rating = cpy.rating;
	viewCount = cpy.viewCount;
	moviePrice = cpy.moviePrice;
}

Movie &Movie::operator=(const Movie &cpy) {
	title = cpy.title;
	bestAward = cpy.bestAward;
	rating = cpy.rating;
	viewCount = cpy.viewCount;
	moviePrice = cpy.moviePrice;
	return *this;
}

Movie::~Movie() {

}

void Movie::addAward(string award) {
	if (bestAward.empty()) {
		bestAward = award;
	} else {
		cout << "This movie already has an award.\n";
	}
}

void Movie::increaseViewCount() {
	++this->viewCount;
}

std::ostream &operator<<(ostream &os, Movie &mov) {
	os << mov.title;
	os << " has reached " << mov.viewCount << " views";
	if (!mov.bestAward.empty()) {
		os << " and has been awarded the " << mov.bestAward << " award.\n";
	} else os << ". ";
	os << "Rating: " << mov.rating << "/5 stars.";
	return os;
}

string Movie::getTitle() const {
	return title;
}

double Movie::getMoviePrice() const {
	return moviePrice;
}

string Movie::getBestAward() const {
	return bestAward;
}

void Movie::setTitle(string title) {
	Movie::title = title;
}

void Movie::setBestAward(string bestAward) {
	Movie::bestAward = bestAward;
}

void Movie::setMoviePrice(double moviePrice) {
	Movie::moviePrice = moviePrice;
}












