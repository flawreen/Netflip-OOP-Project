//
// Created by flawreen on 3/15/23.
//

#include <iostream>
#include "Director.h"
using namespace std;

Director::Director() : bestMovie(nullptr), name(nullptr), lastAward(nullptr), university(nullptr),
					movieCount(0), movieViews(0), revenuePerMovie(0.0), earnings(0.0) {}

Director::Director(const char *name, const char *university) : name(new String(name)), university(new String(university)),
					bestMovie(nullptr), lastAward(nullptr), movieCount(0), movieViews(0), revenuePerMovie(0.0), earnings(0.0) {}

Director::Director(const char *name, const char *university, const char *award)
					: name(new String(name)), university(new String(university)),
					lastAward(new String(award)),
					bestMovie(nullptr), movieCount(0), movieViews(0), revenuePerMovie(0), earnings(0.0) {}

Director::Director(const char *name, const char *university, const char *movieName, const double price)
					: name(new String(name)), university(new String(university)),
					bestMovie(new Movie(movieName, price)),
					lastAward(nullptr), movieCount(1), movieViews(0), revenuePerMovie(1 * constant), earnings(0.0) {}

Director::Director(const char *name, const char *university, const char *movieName, const double price, const char *award)
				   : name(new String(name)), university(new String(university)),
				   lastAward(new String(award)),
				   bestMovie(new Movie(movieName, price)),
				   movieCount(1), movieViews(0), revenuePerMovie(1 * constant), earnings(0.0) {}

Director::Director(const Director &cpy) {
	if (bestMovie != nullptr) { delete bestMovie; }
	if (name != nullptr) { delete name; }
	if (lastAward != nullptr) { delete lastAward; }
	if (university != nullptr) { delete university; }

	if (cpy.bestMovie == nullptr) { bestMovie = nullptr; }
	else bestMovie = new Movie(*cpy.bestMovie);

	if (cpy.name == nullptr) { name = nullptr; }
	else name = new String(*cpy.name);

	if (cpy.lastAward == nullptr) { lastAward = nullptr; }
	else lastAward = new String(*cpy.lastAward);

	if (cpy.university == nullptr) { university = nullptr; }
	else university = new String(*cpy.university);

	movieCount = cpy.movieCount;
	movieViews = cpy.movieViews;
	revenuePerMovie = cpy.revenuePerMovie;
	earnings = cpy.earnings;
}

Director& Director::operator=(const Director &cpy) {
	if (bestMovie != nullptr) { delete bestMovie; }
	if (name != nullptr) { delete name; }
	if (lastAward != nullptr) { delete lastAward; }
	if (university != nullptr) { delete university; }

	if (cpy.bestMovie == nullptr) { bestMovie = nullptr; }
	else bestMovie = new Movie(*cpy.bestMovie);

	if (cpy.name == nullptr) { name = nullptr; }
	else name = new String(*cpy.name);

	if (cpy.lastAward == nullptr) { lastAward = nullptr; }
	else lastAward = new String(*cpy.lastAward);

	if (cpy.university == nullptr) { university = nullptr; }
	else university = new String(*cpy.university);

	movieCount = cpy.movieCount;
	movieViews = cpy.movieViews;
	revenuePerMovie = cpy.revenuePerMovie;
	earnings = cpy.earnings;
	return *this;
}

Director::~Director() {
	delete bestMovie;
	delete name;
	delete lastAward;
	delete university;
}

void Director::setMovie(const char *movieName, const double price) {
	if (bestMovie != nullptr) {
		cout << *this->name << "'s best movie is already added: ";
		cout << bestMovie->getTitle() << endl;
		return;
	}
	bestMovie = new Movie(movieName, price);
	movieCount += 1;
}

void Director::setMovie(const char *movieName, const double price, const char *award) {
	if (bestMovie != nullptr) {
		cout << *this->name << "'s best movie is already added: ";
		cout << bestMovie->getTitle() << endl;
		return;
	}
	bestMovie = new Movie(movieName, price, award);
	movieCount += 1;
}

void Director::updateRevenue() {
	revenuePerMovie = movieCount * constant;
	cout << revenuePerMovie << endl;
}

void Director::calculateEarnings() {
	 earnings = revenuePerMovie * movieViews;
	 cout << earnings;
}

void Director::showInfo() const {
	cout << *this->name << "'s most liked movie is '" << bestMovie->getTitle() << "'.\nHe studied at " << *university << ".\n";
	cout << "Having directed " << movieCount << " movies, he gained over " << movieViews << " views worldwide.\n";
}

String *Director::getName() const {
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

//int main() {
//	Director d1("Mihai Bercea", "La leagane");
//	Director d2("Eugen Cotitu", "Pe afara", "best burger 2021");
//	Director d3("Bromaniac", "Berceni", "Teambuilding", 10.00);
//	Director d4("Quentin Bambino", "La furat", "A fost odata ca niciodata in Balotexas", 14.55, "Club99 - aproape micutzu");
//
//	d4.setMovie("Minecraft SMP", 19.33);
//	d4.showInfo();
//	d4.updateRevenue();
//	d4.calculateEarnings();
//
//	return 0;
//}

