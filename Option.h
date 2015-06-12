#ifndef OPTION_H
#define OPTION_H

//The Option type. This is an alternative to the throw/catch system.
//In many languages, Option is considered a better alternative, but
//here it is chosen out of concerns for how poor throw performance is
//in C++, and the need to write code with an eye towards performance
//due to the deeply embedded microcontroller environment.
struct Option
{
	int errorcode;
	union {
		unsigned int intval;
		unsigned short shortval;
		unsigned char charval;
		struct {
			unsigned short* data;
			unsigned char length;
		} arrayval;
	} val;
};

#endif