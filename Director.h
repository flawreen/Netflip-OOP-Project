//
// Created by flawreen on 3/15/23.
//

#ifndef NETFLIP_DIRECTOR_H
#define NETFLIP_DIRECTOR_H


#include "Movie.h"

class Director {
	//	Movie* filmography = new Movie[10];
	Movie *bestMovie;
	string name, lastAward, university;
	int movieCount, movieViews;
	double revenuePerMovie, earnings;
	constexpr static double constant = 0.00133129;

public:
	Director();
	Director(string name, string university);
	Director(string ame, string university, string award);
	Director(string name, string university, string movieName, double price);
	Director(string name, string university, string movieName, double price, string award);
	Director(const Director& cpy);
	~Director();

	Director& operator=(const Director& cpy);

	void setMovie(string movieName, double price);
	void setMovie(string movieName, double price, string award);
	void updateRevenue();
	void calculateEarnings();
	void showInfo() const;

	// setters and getters
	int getMovieCount() const;
	int getMovieViews() const;
	double getEarnings() const;
	string getName() const;

	void setMovieCount(int movieCount);
	void setMovieViews(int movieViews);
	void setRevenuePerMovie(double revenuePerMovie);
	void setEarnings(double earnings);
};


#endif //NETFLIP_DIRECTOR_H
