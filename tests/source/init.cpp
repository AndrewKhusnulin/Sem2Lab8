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
	REQUIRE(a.get_im() == 6);
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
	REQUIRE(b.get_im() == 4);
}
SCENARIO("opertor *=")
{
	complex a (1,2);
	complex b (3,4);
	double c = 10;
	a*=b;
	b*=c;
	REQUIRE(a.get_re() == -5); 
	REQUIRE(a.get_im() == 10);
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
SCENARIO("opertor +")
{
	complex a (1,2);
	complex b (3,4);
	double c = 100;
	a/=b;
	b/=c;
	REQUIRE((a+b).get_re() == 4); 
	REQUIRE((a+b).get_im() == 6);
	REQUIRE((a+c).get_re() == 101); 
	REQUIRE((a+c).get_im() == 2);
	REQUIRE((c+a).get_re() == 101); 
	REQUIRE((c+a).get_im() == 2);
}
SCENARIO("opertor -")
{
	complex a (10,20);
	complex b (3,4);
	double c = 1;
	REQUIRE((a-b).get_re() == 7); 
	REQUIRE((a-b).get_im() == 16);
	REQUIRE((a-c).get_re() == 9); 
	REQUIRE((a-c).get_im() == 20);
	REQUIRE((c-a).get_re() == -9); 
	REQUIRE((c-a).get_im() == 20);
}
SCENARIO("opertor *")
{
	complex a (1,2);
	complex b (3,4);
	double c = 10;
	REQUIRE((a*b).get_re() == -5); 
	REQUIRE((a*b).get_im() == 10);
	REQUIRE((a*c).get_re() == 10); 
	REQUIRE((a*c).get_im() == 20);
	REQUIRE((c*a).get_re() == 10); 
	REQUIRE((c*a).get_im() == 20);
}
SCENARIO("opertor /")
{
	complex a (1,2);
	complex b (3,4);
	double c = 10;
	REQUIRE((a/b).get_re() == 0.44); 
	REQUIRE((a/b).get_im() == 0.08);
	REQUIRE((a/c).get_re() == 0.1); 
	REQUIRE((a/c).get_im() == 0.2);
	REQUIRE((c/a).get_re() == 2); 
	REQUIRE((c/a).get_im() == -4);
}
SCENARIO("operator ==")
{
	complex a (5,2);
	complex b (5,2);
	REQUIRE((a==b)==1);
}
SCENARIO("operator !=")
{
	complex a (5,2);
	complex b (6.2);
	REQUIRE((a!=b)==1);
}
