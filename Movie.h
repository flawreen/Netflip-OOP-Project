//
// Created by flawreen on 3/14/23.
//

#ifndef NETFLIP_MOVIE_H
#define NETFLIP_MOVIE_H
#include "String.h"

class Movie {
	String *title, *bestAward;
	int rating, viewCount;
	double price;
public:
	Movie();  // Default constructor
	Movie(const char* title, double price);
	Movie(const char* title, double price, const char* awards);
	Movie(const Movie &cpy);
	~Movie();
	Movie& operator=(const Movie& cpy);

	char* getTitle() const;

	void addAward(const char* award);
	void increaseViewCount();
	void calculateRating();
	friend std::ostream& operator<<(std::ostream& os, Movie& mov);

	double getPrice() const;

	String *getBestAward() const;
};


#endif //NETFLIP_MOVIE_H
