//
// Created by flawreen on 3/16/23.
//

#ifndef NETFLIP_SUBSCRIPTION_H
#define NETFLIP_SUBSCRIPTION_H


#include <string>
#include <vector>
#include <iostream>
#include "AdvertisableProduct.h"

using namespace std;

class Subscription : public AdvertisableProduct {
	double discountedValue;
	string discountCode, streamingQuality;
public:
	Subscription();
	Subscription(string plan, string discountCode, string streamingQuality, double productPrice);
	~Subscription();
	Subscription(const Subscription& cpy);
	Subscription& operator=(const Subscription& cpy);
	friend std::ostream& operator<<(std::ostream& os, Subscription& sub);

	void applyDiscount(string code);
	void revertPriceAfterBuy();
	void advertiseProduct() override;

	void setProductPrice(double productPrice);
	void setDiscountCode(string discountCode);
	void setProductName(string productName);
	void setStreamingQuality(string streamingQuality);

	double getProductPrice() const;
	string getDiscountCode() const;
	string getProductName() const;
	string getStreamingQuality() const;

};


#endif //NETFLIP_SUBSCRIPTION_H
