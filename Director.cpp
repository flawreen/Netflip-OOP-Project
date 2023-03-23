//
// Created by flawreen on 3/15/23.
//

#include <iostream>
#include "Director.h"
using namespace std;

Director::Director() : bestMovie(nullptr), name(""), lastAward(""), university(""),
					movieCount(0), movieViews(0), revenuePerMovie(0.0), earnings(0.0) {}

Director::Director(string name, string university) : name(name), university(university),
					bestMovie(nullptr), lastAward(""), movieCount(0), movieViews(0), revenuePerMovie(0.0), earnings(0.0) {}

Director::Director(string name, string university, string award)
					: name(name), university(university),
					lastAward(award),
					bestMovie(nullptr), movieCount(0), movieViews(0), revenuePerMovie(0), earnings(0.0) {}

Director::Director(string name, string university, string movieName, const double price)
					: name(name), university(university),
					bestMovie(new Movie(movieName, price)),
					lastAward(""), movieCount(1), movieViews(0), revenuePerMovie(1 * constant), earnings(0.0) {}

Director::Director(string name, string university, string movieName, const double price, string award)
				   : name(name), university(university),
				   lastAward(award),
				   bestMovie(new Movie(movieName, price)),
				   movieCount(1), movieViews(0), revenuePerMovie(1 * constant), earnings(0.0) {}

Director::Director(const Director &cpy) {
	if (cpy.bestMovie == nullptr) { bestMovie = nullptr; }
	else {
		if (cpy.bestMovie->getBestAward().empty()) {
			bestMovie = new Movie(cpy.bestMovie->getTitle(), cpy.bestMovie->getMoviePrice(), cpy.bestMovie->getBestAward());
		}
		else bestMovie = new Movie(cpy.bestMovie->getTitle(), cpy.bestMovie->getMoviePrice());
	}

	name = cpy.name;
	lastAward = cpy.lastAward;
	university = cpy.university;
	movieCount = cpy.movieCount;
	movieViews = cpy.movieViews;
	revenuePerMovie = cpy.revenuePerMovie;
	earnings = cpy.earnings;
}

Director& Director::operator=(const Director &cpy) {
	if (cpy.bestMovie == nullptr) { bestMovie = nullptr; }
	else {
		if (cpy.bestMovie->getBestAward().empty()) {
			bestMovie = new Movie(cpy.bestMovie->getTitle(), cpy.bestMovie->getMoviePrice(), cpy.bestMovie->getBestAward());
		}
		else bestMovie = new Movie(cpy.bestMovie->getTitle(), cpy.bestMovie->getMoviePrice());
	}

	name = cpy.name;
	lastAward = cpy.lastAward;
	university = cpy.university;
	movieCount = cpy.movieCount;
	movieViews = cpy.movieViews;
	revenuePerMovie = cpy.revenuePerMovie;
	earnings = cpy.earnings;
	return *this;
}

Director::~Director() {
	delete bestMovie;
}

void Director::setMovie(string movieName, const double price) {
	if (bestMovie != nullptr) {
		cout << this->name << "'s best movie is already added: ";
		cout << bestMovie->getTitle() << endl;
		return;
	}
	bestMovie = new Movie(movieName, price);
	movieCount += 1;
}

void Director::setMovie(string movieName, const double price, string award) {
	if (bestMovie != nullptr) {
		cout << this->name << "'s best movie is already added: ";
		cout << bestMovie->getTitle() << endl;
		return;
	}
	bestMovie = new Movie(movieName, price, award);
	movieCount += 1;
}

void Director::updateRevenue() {
	revenuePerMovie = movieCount * constant;
}

void Director::calculateEarnings() {
	 earnings = revenuePerMovie * movieViews;
}

void Director::showInfo() const {
	cout << this->name << "'s most liked movie is '" << bestMovie->getTitle() << "'.\nHe studied at " << university << ".\n";
	cout << "Having directed " << movieCount << " movies, he gained over " << movieViews << " views worldwide.\n";
	cout << "Last award: " << lastAward << endl;
}

string Director::getName() const {
	return name;
}

int Director::getMovieCount() const {
	return movieCount;
}

int Director::getMovieViews() const {
	return movieViews;
}

double Director::getEarnings() const {
	return earnings;
}

void Director::setMovieCount(int movieCount) {
	Director::movieCount = movieCount;
}

void Director::setMovieViews(int movieViews) {
	Director::movieViews = movieViews;
}

void Director::setRevenuePerMovie(double revenuePerMovie) {
	Director::revenuePerMovie = revenuePerMovie;
}

void Director::setEarnings(double earnings) {
	Director::earnings = earnings;
}

