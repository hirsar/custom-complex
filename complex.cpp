#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

class Complex
{
private:
	double rl, im;
	string complexInString;

public:
    Complex(){rl=0;im=0;complexInString="0 + 0j";}	
	Complex(double RL, double IM): rl(RL), im(IM) {complexInString = to_string(rl)+" + "+to_string(im)+"j";}
	~Complex() {}
	double real() const {return rl;}
	double imag() const {return im;}

	operator const char*()
	{
    	    ostringstream formattedComplex;
      	    formattedComplex << rl << " + " << im << "j";
	    complexInString = formattedComplex.str();
    	    return complexInString.data();
	}

	double mag()
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

	Complex operator - (double subD)
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

	Complex operator * (double mulD)
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
	    double rltmp = (rl*divC.real()+im*divC.imag())/(divC.real()*divC.real()+divC.imag()*divC.imag());
	    double imagtmp = (-rl*divC.imag()+im*divC.real())/(divC.real()*divC.real()+divC.imag()*divC.imag());
	    return Complex(rltmp, imagtmp); 
	}

	Complex operator / (double divD)
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

Complex operator "" _j(long double im)
{
    return Complex(0,im);
}

int main()
{
    Complex var1 = 3.2_j+7.4;
    cout << "Complex variable declared: " << var1 << endl;
    Complex var2 = 8.9_j+21.2;
    cout << "Complex variable declared: " << var2 << endl;
    cout << "(" << var1 << ")" << " x " << "(" << var2 << ")" << " = " << var1*var2 << endl;
    Complex div = var1/var2;
    cout << "(" << var1 << ")" << " / " << "(" << var2 << ")" << " = " << var1/var2 << endl;
}
