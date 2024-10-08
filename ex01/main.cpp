#include "Serializer.hpp"

int main()
{
	std::cout << "-------Test 1-------" << std::endl;
	Data data;
	data.s1 = "Hello";
	data.n = 42;
	data.s2 = "World";

	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);

	std::cout << "Raw data: " << raw << std::endl;
	std::cout << std::endl;

	std::cout << "Raw s1: " << raw << std::endl;
	std::cout << "s1: " << ptr->s1 << std::endl;
	std::cout << "Raw n: " << raw + sizeof(std::string) << std::endl;
	std::cout << "n: " << ptr->n << std::endl;
	std::cout << "Raw s2: " << raw + sizeof(std::string) + sizeof(int) << std::endl;
	std::cout << "s2: " << ptr->s2 << std::endl;

	std::cout << "-------Test 2-------" << std::endl;
	Data data2;
	data2.s1 = "Bonjour";
	data2.n = 21;
	data2.s2 = "Monde";

	uintptr_t raw2 = Serializer::serialize(&data2);
	Data *ptr2 = Serializer::deserialize(raw2);

	std::cout << "Raw data: " << raw2 << std::endl;
	std::cout << std::endl;

	std::cout << "Raw s1: " << raw2 << std::endl;
	std::cout << "s1: " << ptr2->s1 << std::endl;
	std::cout << "Raw n: " << raw2 + sizeof(std::string) << std::endl;
	std::cout << "n: " << ptr2->n << std::endl;
	std::cout << "Raw s2: " << raw2 + sizeof(std::string) + sizeof(int) << std::endl;
	std::cout << "s2: " << ptr2->s2 << std::endl;

	std::cout << "-------Test 3-------" << std::endl;
	Data* data3 = new Data();
	data3->s1 = "Hola";
	data3->n = 84;
	data3->s2 = "Mundo";

	uintptr_t raw3 = Serializer::serialize(data3);
	Data *ptr3 = Serializer::deserialize(raw3);

	std::cout << "Raw data: " << raw3 << std::endl;
	std::cout << std::endl;

	std::cout << "Raw s1: " << raw3 << std::endl;
	std::cout << "s1: " << ptr3->s1 << std::endl;
	std::cout << "Raw n: " << raw3 + sizeof(std::string) << std::endl;
	std::cout << "n: " << ptr3->n << std::endl;
	std::cout << "Raw s2: " << raw3 + sizeof(std::string) + sizeof(int) << std::endl;
	std::cout << "s2: " << ptr3->s2 << std::endl;

	delete data3;

	return 0;
}