//
// Created by flawreen on 3/15/23.
//

#ifndef NETFLIP_DIRECTOR_H
#define NETFLIP_DIRECTOR_H


#include <string>
using namespace std;
#include <vector>
#include "Movie.h"
#include "Person.h"

class Director : public virtual Person {
protected:
	vector<Movie> filmography;
	static int movieCount;
	string university;

public:
	Director();
	Director(string name, string mail, string phone, string university);
	Director(const Director& cpy);
	virtual ~Director();
	Director& operator=(const Director& cpy);

	void whoAmI() override;
	void addMovie(Movie &movie);
	static void increaseMovieCount();
	static int getMovieCount();

	// setters and getters
	string getName() const;
};


#endif //NETFLIP_DIRECTOR_H
