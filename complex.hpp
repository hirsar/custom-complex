#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

template<typename T>
class Complex
{
private:
	T rl, im;
	string complexInString;

public:
    	Complex(){rl=0;im=0;complexInString="0 + 0j";}	
	Complex(T RL, T IM): rl(RL), im(IM) {complexInString = to_string(rl)+" + "+to_string(im)+"j";}
	~Complex() {}
	T real() const {return rl;}
	T imag() const {return im;}

	operator const char*()
	{
    	    ostringstream formattedComplex;
      	    formattedComplex << rl << " + " << im << "j";
	    	complexInString = formattedComplex.str();
    	    return complexInString.data();
	}

	T mag()
	{
	    return rl*rl+im*im;
	}

	Complex operator + (const Complex& addC)
	{
	    return Complex(rl+addC.real(), im+addC.imag());
	}

	Complex operator + (double addD)
	{
	    return Complex(rl+addD, im);
	}
	
	void operator += (const Complex& addC)
	{
	    rl += addC.real();
	    im += addC.imag();
	}

	Complex operator - (const Complex& subC)
	{
	    return Complex(rl-subC.real(), im-subC.imag());
	}

	Complex operator-() 
	{
		return Complex(-rl, -im);
	}
	Complex operator - (T subD)
	{
	    return Complex(rl-subD, im);
	}

	void operator -= (const Complex& subC)
	{
	    rl -= subC.real();
	    im -= subC.imag();
	}

	Complex operator * (const Complex& mulC)
	{
	    return Complex(rl*mulC.real()-im*mulC.imag(), rl*mulC.imag()+im*mulC.real());
	}

	Complex operator * (T mulD)
	{
	    return Complex(rl*mulD, im*mulD);
	}

	void operator *= (const Complex& mulC)
	{
	    rl = rl*mulC.real()-im*mulC.imag();
	    im = rl*mulC.imag()+im*mulC.real();
	}

	Complex operator / (const Complex& divC)
	{
	    T rltmp = (rl*divC.real()+im*divC.imag())/(divC.real()*divC.real()+divC.imag()*divC.imag());
	    T imagtmp = (-rl*divC.imag()+im*divC.real())/(divC.real()*divC.real()+divC.imag()*divC.imag());
	    return Complex(rltmp, imagtmp); 
	}

	Complex operator / (T divD)
	{
	    return Complex(rl/divD, im/divD);
	}

	void operator /= (const Complex& divC)
	{
	    rl = (rl*divC.real()+im*divC.imag())/(divC.real()-divC.imag());
	    im = (rl*divC.imag()+im*divC.real())/(divC.real()-divC.imag());
	}

	bool operator== (const Complex& compareTo)
	{
	    return((rl==compareTo.real())&&(im==compareTo.imag()));
	}

	bool operator!= (const Complex& compareTo)
	{
	    return((rl!=compareTo.real())&&(im==compareTo.imag()));
	}

	Complex& operator= (const Complex& copySource)
	{
	    if(this != &copySource)
	    {
		rl = copySource.real();
		im = copySource.imag();
	    }
	    return *this;
	}
};

Complex<int> operator "" _j(unsigned long long im) 
{
	return Complex<int>(0,im);
}

Complex<double> operator "" _j(long double im)
{
    	return Complex<double>(0,im);
}
