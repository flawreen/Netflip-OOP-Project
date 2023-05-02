//
// Created by flawreen on 3/14/23.
//

#ifndef NETFLIP_MOVIE_H
#define NETFLIP_MOVIE_H

#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include "Content.h"

using namespace std;


class Movie : public Content {
	string title;
	vector<string> movieAwards;
	int rating, viewCount;
	double moviePrice;
public:
	Movie();  // Default constructor
	Movie(string title, double price);
	Movie(string title, double price, string award);
	Movie(const Movie &cpy);
	~Movie();
	Movie& operator=(const Movie& cpy);

	void addAward(string &award);
	void contentDescription() override;
	void increaseViewCount() override;
	friend std::ostream& operator<<(std::ostream& os, Movie& mov);
	string getTitle() const;
	double getMoviePrice() const;
	void setTitle(string title);
	void setMoviePrice(double moviePrice);

};


#endif //NETFLIP_MOVIE_H
