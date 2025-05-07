#include "Base.hpp"
#include <ctime> 

Base *generate(void)
{
	int random = rand() % 3;
	if (random == 0)
	{
		std::cout << "A generated" << std::endl;
		return new A;
	}
	else if (random == 1)
	{
		std::cout << "B generated" << std::endl;
		return new B;
	}
	else
	{
		std::cout << "C generated" << std::endl;
		return new C;
	}
}

void identify(Base *p)
{
	if (!p)
	{
		std::cout << "NULL" << std::endl;
		return;
	}
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{
	}
}

int main()
{
	srand(time(NULL));
	Base *randbase1 = generate();
	Base *randbase2 = generate();
	Base *randbase3 = generate();
	Base *randbase4 = generate();

	std::cout << std::endl;

	std::cout << "Identify from pointer:" << std::endl;
	identify(randbase1);
	identify(randbase2);
	identify(randbase3);
	identify(randbase4);

	std::cout << "Identify from reference:" << std::endl;
	
	Base &ref1 = *randbase1;
	Base &ref2 = *randbase2;
	Base &ref3 = *randbase3;
	Base &ref4 = *randbase4;

	identify(ref1);
	identify(ref2);
	identify(ref3);
	identify(ref4);

	delete randbase1;
	delete randbase2;
	delete randbase3;
	delete randbase4;
	return 0;
}
