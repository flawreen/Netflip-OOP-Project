#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;

String::String() {
    str = nullptr;
	size = 0;
}

String::String(const char *s) {
    size = strlen(s);
    str = new char[size+1];
    strncpy(str, s, size+1);
}

String::String(const String& cpy) {
    if (str != nullptr) {
		delete[] str;
	}
	size = cpy.size;
	if (cpy.str == nullptr) {
		str = nullptr;
	} else {
		str = new char[size+1];
		strcpy(str, cpy.str);
	}
}

String &String::operator=(const String &cpy) {
	if (str != nullptr) {
		delete[] str;
	}
	size = cpy.size;
	if (cpy.str == nullptr) {
		str = nullptr;
	} else {
		str = new char[size];
		strcpy(str, cpy.str);
	}
	return *this;
}

String::~String() {
	if(str) delete[] str;
	str = nullptr;

}

String String::operator+ (const String& a) {
    String concat;
    const int size_new = a.size + size;
    char* str2;
    str2 = new char[size_new+1];
    strncpy(str2, str, size);
    strncpy(str2+size, a.str, a.size);
    str2[size_new] = '\0';
    concat.str = str2;
    concat.size = size_new;
    return concat;
}

ostream &operator<<(ostream &os, String &str) {
    os << str.str;
    return os;
}

String &String::operator+=(const char s) {
    char *str2;
    str2 = new char[size+2];
    strncpy(str2, str, size);
    str2[size] = s;
    str2[size+1] = '\0';
    delete[] str;
    str = str2;
    size+= 1;
    return *this;
}

void String::operator[](const char *substr) {
    char* rezultat = strstr(this->str, substr);
    if (rezultat == nullptr) {
        cout << "Sirul nu a fost gasit.";
    } else {
        cout << rezultat;
    }
}

char* String::getStr() const {
	return this->str;
}
