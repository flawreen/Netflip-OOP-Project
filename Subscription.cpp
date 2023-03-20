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

Subscription::Subscription(const Subscription &cpy) {
	subscriptionPrice = cpy.subscriptionPrice;
	discountedValue = cpy.discountedValue;
	if (subscriptionPlan) delete subscriptionPlan;
	if (discountCode) delete discountCode;
	if (streamingQuality) delete streamingQuality;

	if (cpy.subscriptionPlan == nullptr) subscriptionPlan = nullptr;
	else subscriptionPlan = new String(cpy.subscriptionPlan->getStr());

	if (cpy.discountCode == nullptr) discountCode = nullptr;
	else discountCode = new String(cpy.discountCode->getStr());

	if (cpy.streamingQuality == nullptr) streamingQuality = nullptr;
	else streamingQuality = new String(cpy.streamingQuality->getStr());
}

Subscription &Subscription::operator=(const Subscription &cpy) {
	subscriptionPrice = cpy.subscriptionPrice;
	discountedValue = cpy.discountedValue;
	if (subscriptionPlan) delete subscriptionPlan;
	if (discountCode) delete discountCode;
	if (streamingQuality) delete streamingQuality;

	if (cpy.subscriptionPlan == nullptr) subscriptionPlan = nullptr;
	else subscriptionPlan = new String(cpy.subscriptionPlan->getStr());

	if (cpy.discountCode == nullptr) discountCode = nullptr;
	else discountCode = new String(cpy.discountCode->getStr());

	if (cpy.streamingQuality == nullptr) streamingQuality = nullptr;
	else streamingQuality = new String(cpy.streamingQuality->getStr());
	return *this;
}

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

Subscription::~Subscription() {
	if (discountCode != nullptr) delete discountCode;
	if (subscriptionPlan != nullptr) delete subscriptionPlan;
	if (streamingQuality != nullptr) delete streamingQuality;
}

std::ostream &operator<<(ostream &os, Subscription &sub) {
	if (sub.subscriptionPlan == nullptr) {
		os << "No subscription found.\n";
		return os;
	}
	os << "Your plan, " << sub.getSubscriptionPlan()->getStr();
	os << ", can stream in " << sub.getStreamingQuality()->getStr();
	os << " and can be bought for $" << sub.getSubscriptionPrice() << ".";
	return os;
}

void Subscription::setSubscriptionPrice(double subscriptionPrice) {
	Subscription::subscriptionPrice = subscriptionPrice;
}

void Subscription::setDiscountCode(char *discountCode) {
	Subscription::discountCode = new String(discountCode);
}

void Subscription::setSubscriptionPlan(char *subscriptionPlan) {
	Subscription::subscriptionPlan = new String(subscriptionPlan);
}

void Subscription::setStreamingQuality(char *streamingQuality) {
	Subscription::streamingQuality = new String(streamingQuality);
}




