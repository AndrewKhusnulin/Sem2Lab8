#include <iostream>

class complex
{
	double re_;
	double im_;
	public:
		complex(double re=0, double im=0): re_(re), im_(im) {} ;
		complex (const complex &);
		
		complex & operator=(const complex &);
		
		friend complex operator+ (const complex &, const complex &);
		complex & operator += (const complex &);
		
		friend complex operator* (const complex &, const complex &);
		complex & operator *= (const complex &);
		
		friend complex operator/ (const complex &, const complex &);
		complex & operator /= (const complex &);
		
		friend complex operator- (const complex &, const complex &);
		complex & operator -= (const complex &);
		
		friend std::ostream& operator << (std::ostream &, const complex &);
		friend std::istream& operator >> (std::istream &, complex &);
		
		friend bool operator ==(const complex &, const complex &);
		friend bool operator !=(const complex &, const complex &);
		
		double get_im() const;
		double get_re() const;
		
};
class DevideError
{
	public:
		DevideError(){};
};
complex::complex (const complex & rhs)
{
	re_=rhs.re_;
	im_=rhs.im_;
}
complex & complex::operator=(const complex & rhs)
{
	if (this!= &rhs)
	{
		re_=rhs.re_;
		im_=rhs.im_;
	}
}
		
complex operator+ (const complex & lhs, const complex & rhs)
{
	complex ts;
	ts = lhs;
	ts +=rhs;
	return ts;
}
complex & complex::operator += (const complex & rhs)
{
	re_+=rhs.re_;
	im_+=rhs.im_;
}
		
complex operator* (const complex & lhs, const complex & rhs)
{
	complex ts;
	ts = lhs;
	ts *=rhs;
	return ts;
}
complex & complex::operator *= (const complex & rhs)
{
	double re_n=re_*rhs.re_-im_*rhs.im_;
	double im_n=re_*rhs.im_+rhs.re_*im_;
	re_=re_n;
	im_=im_n;
}
		
complex operator/ (const complex & lhs, const complex & rhs)
{
	if (rhs.re_*rhs.re_+rhs.im_*rhs.im_==0) throw DevideError();
	else 
	{
	complex ts;
	ts = lhs;
	ts /=rhs;
	return ts;
	}
}
complex & complex::operator /= (const complex & rhs)
{
	if (rhs.re_*rhs.re_+rhs.im_*rhs.im_== 0) throw DevideError();
	else {
		double re_n=(re_*rhs.re_+im_*rhs.im_)/(rhs.re_*rhs.re_+rhs.im_*rhs.im_);
		double im_n=(im_*rhs.re_-re_*rhs.im_)/(rhs.re_*rhs.re_+rhs.im_*rhs.im_);
		re_=re_n;
		im_=im_n;
	}
}
		
complex operator- (const complex & lhs, const complex & rhs)
{
	complex ts;
	ts = lhs;
	ts -=rhs;
	return ts;
}
complex & complex::operator -= (const complex & rhs)
{
	re_-=rhs.re_;
	im_-=rhs.im_;
}
		
std::ostream& operator << (std::ostream & os, const complex & obj)
{
	os << "(" << obj.re_ << "," << obj.im_ << ")\n";
	return os;
}
std::istream& operator >> (std::istream & is, complex & obj)
{
	is >> obj.re_ >> obj.im_ ;
	return is;
}
bool operator ==(const complex & rhs , const complex & lhs)
{
	return rhs.re_==lhs.re_ && rhs.im_==lhs.im_;
}
bool operator !=(const complex & lhs, const complex & rhs)
{
	return !(lhs==rhs);
}
double complex::get_im() const
{
	return this->im_; 
}
double complex::get_re() const
{
	return this->re_;
}

