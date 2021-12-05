#include <iostream>
//
// Created by reenie on 04.12.2021.
//

class String {
private:
	char* _raw_string;
	size_t length;
public:
	String ();

	String (const char* str);

	String (const String& str);

	~String ();

	size_t get_length () {
		return this->length;
	}

	char& operator[] (size_t index);
	String& operator= (const String& str);

	int32_t compare (String& str);

	friend std::ostream& operator<< (std::ostream& out, String& str);
};

#ifndef ALGORITHMS_2021_STRING_H
#define ALGORITHMS_2021_STRING_H

#endif //ALGORITHMS_2021_STRING_H

#include "string.cpp"