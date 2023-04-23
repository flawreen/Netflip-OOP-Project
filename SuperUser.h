//
// Created by flawreen on 4/23/23.
//

#ifndef NETFLIP_SUPERUSER_H
#define NETFLIP_SUPERUSER_H


#include "User.h"
#include "Director.h"

class SuperUser : public User, public Director {
	static Subscription god;
public:
	SuperUser()=default;
	SuperUser(string name, string mail, string phone, string university);
	~SuperUser();
	void whoAmI() override;
	void buyMovie(Movie &movie);
	void watchMovie(Movie &movie);
	void checkBoughtMovies();

};


#endif //NETFLIP_SUPERUSER_H
