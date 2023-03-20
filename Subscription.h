//
// Created by flawreen on 3/16/23.
//

#ifndef NETFLIP_SUBSCRIPTION_H
#define NETFLIP_SUBSCRIPTION_H


#include "String.h"
#include <iostream>

class Subscription {
	double subscriptionPrice, discountedValue;
	String* discountCode, *subscriptionPlan, *streamingQuality;
public:
	Subscription();
	Subscription(const char* plan, const char* discountCode, const char* streamingQuality, double subscriptionPrice);
	~Subscription();
	Subscription(const Subscription& cpy);
	Subscription& operator=(const Subscription& cpy);
	friend std::ostream& operator<<(std::ostream& os, Subscription& sub);

	void applyDiscount(const char* code);
	void setSubscriptionPrice(double subscriptionPrice);
	void setDiscountCode(char *discountCode);
	void setSubscriptionPlan(char *subscriptionPlan);
	void setStreamingQuality(char *streamingQuality);
	void revertPriceAfterBuy();
	double getSubscriptionPrice() const;
	String *getDiscountCode() const;
	String *getSubscriptionPlan() const;
	String *getStreamingQuality() const;

};


#endif //NETFLIP_SUBSCRIPTION_H
