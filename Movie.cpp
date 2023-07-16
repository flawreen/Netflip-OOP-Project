//
// Created by flawreen on 3/14/23.
//

#include <iostream>
#include <utility>
#include "Movie.h"
#include "Content.h"
#include "InvalidAward.cpp"
#include "NaN.cpp"

using namespace std;


Movie::Movie() : title(""), rating(0), viewCount(0), moviePrice(0.0) {}

Movie::Movie(string title, const double price) : title(std::move(title)),
										   rating(0), viewCount(0), moviePrice(price) {}

Movie::Movie(string title, const double price, const string& award) : title(std::move(title)), moviePrice(price), rating(0),
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
	while (true) {
		try {
			if (award.size() <= 3) {
				throw InvalidAward("\'award\' must be more than 3 characters long");
			}
			movieAwards.push_back(award);
			break;
		} catch (InvalidAward &e) {
			cerr << "Invalid Award Error: " << e.what() << ". Add a year to the award title: " << endl;
			string year;
			cin >> year;
			try {
				for (auto s: year) {
					if (!isdigit(s)) throw NaN("Not a number.");
				}
			} catch (const NaN& err) {
				cerr << "NaN error: " << err.what() << endl;
				continue;
			}
			award.push_back(' ');
			award.append(year);
		}
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
	Movie::title = std::move(title);
}


void Movie::setMoviePrice(const double moviePrice) {
	Movie::moviePrice = moviePrice;
}

void Movie::contentDescription() const {
	cout << "Movie title: " << title << endl;
	cout << "Number of awards: " << movieAwards.size() << endl;
	cout << "Number of views: " << viewCount << endl;
	cout << "Price: " << moviePrice << endl;
}












