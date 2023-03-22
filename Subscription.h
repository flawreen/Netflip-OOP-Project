//
// Created by flawreen on 3/16/23.
//

#ifndef NETFLIP_SUBSCRIPTION_H
#define NETFLIP_SUBSCRIPTION_H


#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Subscription {
	double subscriptionPrice, discountedValue;
	string discountCode, subscriptionPlan, streamingQuality;
public:
	Subscription();
	Subscription(string plan, string discountCode, string streamingQuality, double subscriptionPrice);
	~Subscription();
	Subscription(const Subscription& cpy);
	Subscription& operator=(const Subscription& cpy);
	friend std::ostream& operator<<(std::ostream& os, Subscription& sub);

	void applyDiscount(string code);
	void setSubscriptionPrice(double subscriptionPrice);
	void setDiscountCode(string discountCode);
	void setSubscriptionPlan(string subscriptionPlan);
	void setStreamingQuality(string streamingQuality);
	void revertPriceAfterBuy();
	double getSubscriptionPrice() const;
	string getDiscountCode() const;
	string getSubscriptionPlan() const;
	string getStreamingQuality() const;

};


#endif //NETFLIP_SUBSCRIPTION_H
