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
	~SuperUser() override;
	void whoAmI() const override;
	void buyMovie(const Movie* movie) const;
	void watchMovie(Movie* movie) const;
	void checkBoughtMovies() const override;

};


#endif //NETFLIP_SUPERUSER_H
