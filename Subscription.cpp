//
// Created by flawreen on 3/16/23.
//

#include "Subscription.h"
#include <iostream>
#include <utility>

using namespace std;

Subscription::Subscription() : AdvertisableProduct("Free Netflip Subscription", 0.0),
							   discountedValue(0.0),
							   discountCode(""),
							   streamingQuality("Full HD") {}

Subscription::Subscription(string plan, string discountCode, string streamingQuality, const double productPrice) :
		AdvertisableProduct(std::move(plan), productPrice),
		discountedValue(0.0),
		discountCode(std::move(discountCode)),
		streamingQuality(std::move(streamingQuality)) {}

Subscription::Subscription(const Subscription &cpy) {
	productPrice = cpy.productPrice;
	discountedValue = cpy.discountedValue;
	productName = cpy.productName;
	discountCode = cpy.discountCode;
	streamingQuality = cpy.streamingQuality;
}

Subscription &Subscription::operator=(const Subscription &cpy) {
	discountedValue = cpy.discountedValue;
	productPrice = cpy.productPrice;
	productName = cpy.productName;
	discountCode = cpy.discountCode;
	streamingQuality = cpy.streamingQuality;
	return *this;
}

void Subscription::applyDiscount(const string &code) {
	if (productPrice <= 0.0) {
		cout << "You can't apply a discount code for this subscription!\n";
	} else if (code == discountCode) {
		discountedValue = productPrice * 0.15;
		productPrice -= discountedValue;
	} else {
		cout << "Discount code not available.\n";
	}
}

void Subscription::revertPriceAfterBuy() {
	productPrice += discountedValue;
	discountedValue = 0.0;
}

double Subscription::getProductPrice() const {
	return productPrice;
}

string Subscription::getDiscountCode() const {
	return discountCode;
}

string Subscription::getProductName() const {
	return productName;
}

string Subscription::getStreamingQuality() const {
	return streamingQuality;
}

Subscription::~Subscription() {
}

std::ostream &operator<<(ostream &os, Subscription &sub) {
	if (sub.productName.empty()) {
		os << "No subscription found.\n";
		return os;
	}
	os << "Your plan, " << sub.getProductName();
	os << ", can stream in " << sub.getStreamingQuality();
	os << " and can be bought for $" << sub.getProductPrice() << ".";
	return os;
}

void Subscription::setProductPrice(const double productPrice) {
	Subscription::productPrice = productPrice;
}

void Subscription::setDiscountCode(string discountCode) {
	Subscription::discountCode = std::move(discountCode);
}

void Subscription::setProductName(string productName) {
	Subscription::productName = std::move(productName);
}

void Subscription::setStreamingQuality(string streamingQuality) {
	Subscription::streamingQuality = std::move(streamingQuality);
}

void Subscription::advertiseProduct() const {
	cout << "============================================================\n";
	cout << "You can now buy our new Netflip subscription, " << productName << "!\n";
	cout << "For only " << productPrice << " you can stream our movies in " << streamingQuality << "!\n";
	cout << "Discount code: " << discountCode << endl;
	cout << "============================================================\n";
}




