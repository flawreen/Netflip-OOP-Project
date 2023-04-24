//
// Created by flawreen on 4/24/23.
//

#ifndef NETFLIP_ADVERTISABLEPRODUCT_H
#define NETFLIP_ADVERTISABLEPRODUCT_H

#include <string>
using namespace std;

class AdvertisableProduct {
protected:
	string productName;
	double productPrice;
public:
	AdvertisableProduct()=default;
	AdvertisableProduct(string name, double price);
	virtual ~AdvertisableProduct();
	virtual void advertiseProduct();
};


#endif //NETFLIP_ADVERTISABLEPRODUCT_H
