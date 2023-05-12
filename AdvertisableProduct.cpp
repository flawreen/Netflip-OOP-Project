//
// Created by flawreen on 4/24/23.
//

#include "AdvertisableProduct.h"
#include <iostream>
#include <utility>

AdvertisableProduct::AdvertisableProduct(string name, double price) : productName(std::move(name)), productPrice(price) {}

void AdvertisableProduct::advertiseProduct() const {
	cout << "============================================================\n";
	cout << "You can now buy " << productName << " for only $" << productPrice << "!\n";
	cout << "============================================================\n";
}

AdvertisableProduct::~AdvertisableProduct() = default;

