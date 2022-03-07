#ifndef SAM12_OPERATOR_OVERLOADING_COMPLEXNUMBER_COMPLEXNUMBER_H
#define SAM12_OPERATOR_OVERLOADING_COMPLEXNUMBER_COMPLEXNUMBER_H


/*  ComplexNumber
	A class that represents a Complex Number with Real and Imaginary number parts.
	This class declares overloaded insertion << and extraction >> operators as 'friends'
	and overloaded "+" and ">" operators.
*/

#include <iostream>
using namespace std;

class ComplexNumber
{

private:
    int real;	// member data/fields
    int imaginary;

public:
    ComplexNumber(int real = 0, int imaginary = 0)		// constructor with default initializers
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    void print() {
        cout << "print() : Real: " << real << ", Imaginary: " << imaginary << endl;
    }

    // This is automatically called when the '+' symbol is used
    // between two ComplexNumber objects.
    // complexNumberResult = complexNumber1 + complexNumber2;

    ComplexNumber operator+ (ComplexNumber const& obj);

    bool operator > (ComplexNumber const& obj);

    // Declaring overloaded global extraction >> and insertion << operators
    // These are NOT member functions (as they don't have the "ComplexNumber::" scope resolution
    // operator in front of their definition in the ComplexNumber.cpp file).
    // However, they are declared as FRIEND functions in the header file, which gives the functions
    // direct access to the fields (member data).

    friend ostream& operator << (ostream& out, const ComplexNumber& c);
    friend istream& operator >> (istream& in, ComplexNumber& c);


    /* We don't want the global overloaded operators to be member functions of the ComplexNumber class,
      as we will not be invoking them on ComplexNumber objects. (like "c1.<<" )
      (i.e. the object on the left hand side of the "<<" is not a ComplexNumber type; it
      is an output stream.)

      "friend" functions:
      However, as these operators work on ComplexNumber objects, we want them to have direct access
      to the member variables of those objects.  To achieve this we make them 'friend' functions,
      which gives them direct access to the member fields of the ComplexNumber class.
     */
};

#endif //SAM12_OPERATOR_OVERLOADING_COMPLEXNUMBER_COMPLEXNUMBER_H
