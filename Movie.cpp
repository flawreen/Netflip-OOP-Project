//
// Created by flawreen on 3/14/23.
//

#include <iostream>
#include "Movie.h"
#include "Content.h"
#include "InvalidAward.cpp"
using namespace std;


Movie::Movie() : title(""), rating(0), viewCount(0), moviePrice(0.0) {}

Movie::Movie(string title, double price) : title(title),
										   rating(0), viewCount(0), moviePrice(price) {}

Movie::Movie(string title, double price, string award) : title(title), moviePrice(price), rating(0),
														 viewCount(0) {
	movieAwards.push_back(award);
}

Movie::Movie(const Movie &cpy) : title(cpy.title), rating(cpy.rating), viewCount(cpy.viewCount),
								 moviePrice(cpy.moviePrice), movieAwards(cpy.movieAwards) {}

Movie &Movie::operator=(const Movie &cpy) {
	title = cpy.title;
	rating = cpy.rating;
	viewCount = cpy.viewCount;
	moviePrice = cpy.moviePrice;
	movieAwards = cpy.movieAwards;
	return *this;
}

Movie::~Movie() = default;

void Movie::addAward(string &award) {
	try {
		if (award.size() <= 3) {
			throw InvalidAward("\'award\' must be more than 3 characters long");
		}
		movieAwards.push_back((award));
	} catch (InvalidAward& e) {
		cerr << "Invalid Award Error: " << e.what() << endl;
	}
}

void Movie::increaseViewCount() {
	++this->viewCount;
}

std::ostream &operator<<(ostream &os, Movie &mov) {
	os << mov.title;
	os << " has reached " << mov.viewCount << " views";
	if (!mov.movieAwards.empty()) {
		os << " and has been awarded the " << mov.movieAwards[0] << " award.\n";
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

void Movie::setTitle(string title) {
	Movie::title = title;
}


void Movie::setMoviePrice(double moviePrice) {
	Movie::moviePrice = moviePrice;
}

void Movie::contentDescription() {
	cout << "Movie title: " << title << endl;
	cout << "Number of awards: " << movieAwards.size() << endl;
	cout << "Number of views: " << viewCount << endl;
	cout << "Price: " << moviePrice << endl;
}












