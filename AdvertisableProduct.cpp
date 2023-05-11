//
// Created by flawreen on 4/24/23.
//

#include "AdvertisableProduct.h"
#include <iostream>

AdvertisableProduct::AdvertisableProduct(string name, double price) : productName(name), productPrice(price) {}

void AdvertisableProduct::advertiseProduct() {
	cout << "============================================================\n";
	cout << "You can now buy " << productName << " for only $" << productPrice << "!\n";
	cout << "============================================================\n";
}

AdvertisableProduct::~AdvertisableProduct() = default;

