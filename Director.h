//
// Created by flawreen on 3/15/23.
//

#ifndef NETFLIP_DIRECTOR_H
#define NETFLIP_DIRECTOR_H


#include "Movie.h"

class Director {
	//	Movie* filmography = new Movie[10];
	Movie *bestMovie;
	String *name, *lastAward, *university;
	int movieCount, movieViews;
	double revenuePerMovie, earnings;
	constexpr static double constant = 0.00133129;

public:
	Director();
	Director(const char* name, const char* university);
	Director(const char* name, const char* university, const char *award);
	Director(const char* name, const char* university, const char* movieName, double price);
	Director(const char* name, const char* university, const char* movieName, double price, const char* award);
	Director(const Director& cpy);
	~Director();

	Director& operator=(const Director& cpy);

	void setMovie(const char* movieName, double price);
	void setMovie(const char* movieName, double price, const char* award);
	void updateRevenue();
	void calculateEarnings();
	void showInfo() const;

	// setters and getters
	int getMovieCount() const;
	int getMovieViews() const;
	double getEarnings() const;
	String *getName() const;

	void setMovieCount(int movieCount);
	void setMovieViews(int movieViews);
	void setRevenuePerMovie(double revenuePerMovie);
	void setEarnings(double earnings);
};


#endif //NETFLIP_DIRECTOR_H
