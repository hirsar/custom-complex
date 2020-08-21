#include "complex.hpp"

int main()
{
    Complex<double> var1 = 3.2_j+7.4;
    cout << "Complex variable declared: " << var1 << endl;
    Complex<double> var2 = 8.9_j+21.2;
	cout << "Complex variable declared: " << var2 << endl;
	Complex<int> var3 = 5_j+2;
	cout << "Complex variable declared: " << var3 << endl;
	Complex<int> var4 = -2_j+3;
	cout << "Complex variabled declared: " << var4 << endl;
    cout << "(" << var1 << ")" << " x " << "(" << var2 << ")" << " = " << var1*var2 << endl;
    cout << "(" << var1 << ")" << " / " << "(" << var2 << ")" << " = " << var1/var2 << endl;
	cout << "(" << var3 << ")" << " x " << "(" << var4 << ")" << " = " << var3*var4 << endl;
	cout << "(" << var3 << ")" << " / " << "(" << var4 << ")" << " = " << var3/var4 << endl;
}
