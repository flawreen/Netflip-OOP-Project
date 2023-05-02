//
// Created by flawreen on 4/24/23.
//
#include <exception>
#include <string>
#include <utility>
using namespace std;

class InvalidPhoneNumber : public exception {
	string mesaj;
public:
	InvalidPhoneNumber(string  message) : mesaj(std::move(message)) {}
	const char* what() const noexcept override {
		return mesaj.c_str();
	}
};