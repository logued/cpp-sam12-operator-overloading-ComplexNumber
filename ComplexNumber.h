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

    // Overloaded plus operator
    // his is automatically called when the '+' symbol is used
    // between two ComplexNumber objects.
    // complexNumberResult = complexNumber1 + complexNumber2;

    ComplexNumber operator+ (ComplexNumber const& otherComplexNumber);

    // Overloaded greater-than operator
    bool operator > (ComplexNumber const& obj);

    // Global FRIEND functions.
    // Declaring overloaded global extraction >> and insertion << operators

    friend ostream& operator << (ostream& out, const ComplexNumber& c);
    friend istream& operator >> (istream& in, ComplexNumber& c);


    /* Global Friend functions.
     * We don't want the global overloaded operators to be member functions of the ComplexNumber class,
      as we will not be invoking them on ComplexNumber objects. (like "c1.<<" )
      (i.e. the object on the left-hand side of the "<<" is not a ComplexNumber type; it
      is an output stream. i.e. cout << c1;)

      "friend" functions:
      However, as these operators work on ComplexNumber objects, we want them to have direct access
      to the member variables of those objects.  To achieve this we make them 'friend' functions,
      which gives them direct access to the member fields of the ComplexNumber class.
     */
};

#endif //SAM12_OPERATOR_OVERLOADING_COMPLEXNUMBER_COMPLEXNUMBER_H
