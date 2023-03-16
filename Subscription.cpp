//
// Created by flawreen on 3/16/23.
//

#include "Subscription.h"
#include <iostream>
using namespace std;

Subscription::Subscription() : subscriptionPrice(0.0), discountedValue(0.0),
								discountCode(nullptr),
								subscriptionPlan(new String("Free")),
								streamingQuality(new String("Full HD")) {}

Subscription::Subscription(const char *plan, const char *discountCode, const char *streamingQuality,
						   double subscriptionPrice) : subscriptionPrice(subscriptionPrice),
						   discountedValue(0.0),
						   discountCode(new String(discountCode)),
						   subscriptionPlan(new String(plan)),
						   streamingQuality(new String(streamingQuality)) {}

void Subscription::applyDiscount(const char* code) {
	if (subscriptionPrice <= 0.0) {
		cout << "You can't apply a discount code for this subscription!\n";
	} else if (code == discountCode->getStr()) {
		discountedValue = subscriptionPrice * 0.15;
		subscriptionPrice -= discountedValue;
	} else {
		cout << "Discount code not available.\n";
	}
}

void Subscription::revertPriceAfterBuy() {
	subscriptionPrice += discountedValue;
	discountedValue = 0.0;
}

double Subscription::getSubscriptionPrice() const {
	return subscriptionPrice;
}

String *Subscription::getDiscountCode() const {
	return discountCode;
}

String *Subscription::getSubscriptionPlan() const {
	return subscriptionPlan;
}

String *Subscription::getStreamingQuality() const {
	return streamingQuality;
}


