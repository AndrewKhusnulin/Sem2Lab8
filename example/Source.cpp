#include "testclass.hpp"

typedef unsigned int ring; 

int main()
{
	try{
	complex a, b;
	double c;
	std::cin >> a >> b >> c;
	std::cout << a+b << a-b << a*b << a/b;
	std::cout << a+c << a-c << a*c << a/c;
	std::cout << c+a << a-c << c*a << c/a;
	if (a!=b) std::cout << "OK";
	}
	catch (DevideError) { std::cout <<"Devide by zero!";}
	return 0;
}
