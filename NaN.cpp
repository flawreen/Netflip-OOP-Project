//
// Created by flawreen on 5/2/23.
//
#include <exception>
#include <string>
#include <utility>
using namespace std;

class NaN : public exception {
	string mesaj;
public:
	NaN(string  message) : mesaj(std::move(message)) {}
	const char* what() const noexcept override {
		return mesaj.c_str();
	}
};