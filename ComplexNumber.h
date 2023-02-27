#ifndef SAM12_OPERATOR_OVERLOADING_COMPLEXNUMBER_COMPLEXNUMBER_H
#define SAM12_OPERATOR_OVERLOADING_COMPLEXNUMBER_COMPLEXNUMBER_H

//
/*  ComplexNumber
	A class that represents a Complex Number with Real and Imaginary parts.
	This class declares:
        an overloaded insertion operator  "operator<<" and
        an overloaded extraction operator "operator>>"
        both as "friend" functions.
        A "friend" function is one that can access the private member data of the ComplexNumber class
        without actually being member functions of the class.  They are global functions.

	This class als defines:
      an overloaded add operator "operator+" and
      an overloaded greater than operator "operator>".
      Both of these are member functions of the class.
*/
#include <iostream>

class ComplexNumber
{
private:
    int real;	    // member data (fields)
    int imaginary;

public:
    ComplexNumber(int real = 0, int imaginary = 0)		// constructor with default initializers
    {
        this->real = real;
        this->imaginary = imaginary;
    }

    void print() {
        std::cout << "print() : Real: " << real << ", Imaginary: " << imaginary << std::endl;
    }

    // Definition of Overloaded plus (+) operator
    // This is automatically called when the '+' symbol is used
    // between two ComplexNumber objects.
    // complexNumberResult = complexNumber1 + complexNumber2;

    ComplexNumber operator+ (const ComplexNumber & otherComplexNumber);

    // Overloaded greater-than (>) operator, is used to compare two ComplexNumber objects
    bool operator > (ComplexNumber const& obj);

    // Global FRIEND functions.
    // Declaring overloaded global extraction operator>> and insertion operator<< operators.

    friend std::ostream& operator << (std::ostream& out, const ComplexNumber& c);
    friend std::istream& operator >> (std::istream& in, ComplexNumber& c);

    /* Global Friend functions.
     * We don't want the global overloaded operators to be member functions of the ComplexNumber class,
      as we will not be invoking them on ComplexNumber objects. (like "c1.<<" )
      (i.e. the object on the left-hand side of the "<<" is not a ComplexNumber type; it
      is an output stream. i.e. "cout << c1") Therefore, our operator takes a stream to its left, and
      a ComplexNumber to its right. So, the above function definitions are used to satisfy this requirement.

      "friend" functions:
      However, as these operators work on ComplexNumber objects, we want them to have direct access
      to the member variables of those objects.  To achieve this we make them 'friend' functions,
      which gives them direct access to the member data fields of the ComplexNumber class.
     */
};

#endif //SAM12_OPERATOR_OVERLOADING_COMPLEXNUMBER_COMPLEXNUMBER_H
