//
// Created by flawreen on 3/14/23.
//

#ifndef NETFLIP_MOVIE_H
#define NETFLIP_MOVIE_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Movie {
	string title, bestAward;
	int rating, viewCount;
	double moviePrice;
public:
	Movie();  // Default constructor
	Movie(string title, double price);
	Movie(string title, double price, string award);
	Movie(const Movie &cpy);
	~Movie();
	Movie& operator=(const Movie& cpy);

	string getTitle() const;
	void addAward(string award);
	void increaseViewCount();
	void calculateRating();
	friend std::ostream& operator<<(std::ostream& os, Movie& mov);
	double getMoviePrice() const;
	string getBestAward() const;
	void setTitle(string title);
	void setBestAward(string bestAward);
	void setMoviePrice(double moviePrice);

};


#endif //NETFLIP_MOVIE_H
