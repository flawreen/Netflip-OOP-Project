//
// Created by flawreen on 3/16/23.
//

#include "Subscription.h"
#include <iostream>
using namespace std;

Subscription::Subscription() : subscriptionPrice(0.0), discountedValue(0.0),
								discountCode(""),
								subscriptionPlan("Free"),
								streamingQuality("Full HD") {}

Subscription::Subscription(string plan, string discountCode, string streamingQuality,
						   double subscriptionPrice) : subscriptionPrice(subscriptionPrice),
						   discountedValue(0.0),
						   discountCode(discountCode),
						   subscriptionPlan(plan),
						   streamingQuality(streamingQuality) {}

Subscription::Subscription(const Subscription &cpy) {
	subscriptionPrice = cpy.subscriptionPrice;
	discountedValue = cpy.discountedValue;
	subscriptionPlan = cpy.subscriptionPlan;
	discountCode = cpy.discountCode;
	streamingQuality = cpy.streamingQuality;
}

Subscription &Subscription::operator=(const Subscription &cpy) {
	subscriptionPrice = cpy.subscriptionPrice;
	discountedValue = cpy.discountedValue;
	subscriptionPrice = cpy.subscriptionPrice;
	discountedValue = cpy.discountedValue;
	subscriptionPlan = cpy.subscriptionPlan;
	discountCode = cpy.discountCode;
	streamingQuality = cpy.streamingQuality;
	return *this;
}

void Subscription::applyDiscount(string code) {
	if (subscriptionPrice <= 0.0) {
		cout << "You can't apply a discount code for this subscription!\n";
	} else if (code == discountCode) {
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

string Subscription::getDiscountCode() const {
	return discountCode;
}

string Subscription::getSubscriptionPlan() const {
	return subscriptionPlan;
}

string Subscription::getStreamingQuality() const {
	return streamingQuality;
}

Subscription::~Subscription() {
}

std::ostream &operator<<(ostream &os, Subscription &sub) {
	if (sub.subscriptionPlan.empty()) {
		os << "No subscription found.\n";
		return os;
	}
	os << "Your plan, " << sub.getSubscriptionPlan();
	os << ", can stream in " << sub.getStreamingQuality();
	os << " and can be bought for $" << sub.getSubscriptionPrice() << ".";
	return os;
}

void Subscription::setSubscriptionPrice(double subscriptionPrice) {
	Subscription::subscriptionPrice = subscriptionPrice;
}

void Subscription::setDiscountCode(string discountCode) {
	Subscription::discountCode = discountCode;
}

void Subscription::setSubscriptionPlan(string subscriptionPlan) {
	Subscription::subscriptionPlan = subscriptionPlan;
}

void Subscription::setStreamingQuality(string streamingQuality) {
	Subscription::streamingQuality = streamingQuality;
}




