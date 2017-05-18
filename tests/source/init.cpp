#include <testclass.hpp>
#include <catch.hpp>

SCENARIO ("constructor")
{
	complex a (5,2);
	REQUIRE(a.get_re() == 5); 
	REQUIRE(a.get_im()==2);
}
SCENARIO("copy constructor")
{
	complex a (5,2);
	complex b (a);
	REQUIRE(b.get_re() == 5); 
	REQUIRE(b.get_im() == 2);
}
SCENARIO("opertor =")
{
	complex a (5,2);
	complex b = a;
	REQUIRE(b.get_re() == 5); 
	REQUIRE(b.get_im() == 2);
}
SCENARIO("opertor +=")
{
	complex a (5,2);
	complex b (6,4);
	double c = 100;
	a+=b;
	b+=c;
	REQUIRE(a.get_re() == 11); 
	REQUIRE(a.get_im() == 8);
	REQUIRE(b.get_re() == 106); 
	REQUIRE(b.get_im() == 4);
}
SCENARIO("opertor -=")
{
	complex a (5,2);
	complex b (6,4);
	double c = 1;
	a-=b;
	b-=c;
	REQUIRE(a.get_re() == -1); 
	REQUIRE(a.get_im() == -2);
	REQUIRE(b.get_re() == 5); 
	REQUIRE(b.get_im() == 3);
}
SCENARIO("opertor *=")
{
	complex a (1,2);
	complex b (3,4);
	double c = 10;
	a*=b;
	b*=c;
	REQUIRE(a.get_re() == -5); 
	REQUIRE(a.get_im() == -10);
	REQUIRE(b.get_re() == 30); 
	REQUIRE(b.get_im() == 40);
}
SCENARIO("opertor /=")
{
	complex a (16,8);
	complex b (4,2);
	double c = 10;
	a/=b;
	b/=c;
	REQUIRE(a.get_re() == 4); 
	REQUIRE(a.get_im() == 0);
	REQUIRE(b.get_re() == 0.4); 
	REQUIRE(b.get_im() == 0.2);
}

