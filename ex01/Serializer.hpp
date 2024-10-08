#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>

typedef unsigned long uintptr_t;

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &obj);
		Serializer &operator=(const Serializer &obj);
	public:
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif