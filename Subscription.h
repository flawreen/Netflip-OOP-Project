//
// Created by flawreen on 3/16/23.
//

#ifndef NETFLIP_SUBSCRIPTION_H
#define NETFLIP_SUBSCRIPTION_H


#include "String.h"

class Subscription {
	double subscriptionPrice, discountedValue;
	String* discountCode, *subscriptionPlan, *streamingQuality;
public:
	Subscription();
	Subscription(const char* plan, const char* discountCode, const char* streamingQuality, double subscriptionPrice);

	void applyDiscount(const char* code);
	void revertPriceAfterBuy();

	double getSubscriptionPrice() const;
	String *getDiscountCode() const;
	String *getSubscriptionPlan() const;
	String *getStreamingQuality() const;

};


#endif //NETFLIP_SUBSCRIPTION_H
