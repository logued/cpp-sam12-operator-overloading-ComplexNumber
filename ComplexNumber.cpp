//
// C++  Feb 2022
//

#include "ComplexNumber.h"

/* Implementation of Class ComplexNumber:		Mar 2021

   Demonstrates Operator Overloading.
   Operator Overloading allows us to define the behaviour of operators (e.g. +.-,*, <, etc.)
   for a class type.

   - operator overloading of "+" and "-" operators: (operator+) and (operator-)
   - operator overloading of global friend operators << and >>
*/

#include <iostream>
#include "ComplexNumber.h"

using namespace std;

/* The stream insertion << and stream extraction >> operators are
   defined *outside* the class definition,
   and therefore have global scope.
   They are GLOBAL operators that are overridden for a ComplexNumber.
*/

/* the "<<" operator is invoked by the following pattern :
   "   outputStream << complexNumber   "
*/

ostream& operator << (ostream& out, const ComplexNumber& c)
{
    // As this is defined as a 'friend' of ComplexNumber in the header file,
    // it has direct access to the private member data of the ComplexNumber object.

    out << c.real;
    out << " + " << c.imaginary << "i" << endl;
    return out;
}

/* The extraction operator ">>"  is invoked by the following pattern
   "  inputStream >> complexNumber     "
*/

istream& operator >> (istream& in, ComplexNumber& c)
{
    cout << "Enter Real Part ";
    in >> c.real;
    cout << "Enter Imaginary Part ";
    in >> c.imaginary;
    return in;
}


// The + and > operators below are implemented as member functions,
// as they are invoked on ComplexNumber objects.
// i.e.  complexNumResult = complexNum1 + complexNum2

/* Implementation of the operator "+",
   enabling the addition of two ComplexNumber objects.
   Usage: complexNumberResult = complexNumber1 + complexNumber2;

*/
ComplexNumber ComplexNumber::operator + (ComplexNumber const& obj) {
    ComplexNumber temp;
    temp.real = real + obj.real;
    temp.imaginary = imaginary + obj.imaginary;
    return temp; // return an object (by value)
}

// 2DO Implement a 'minus' operator: "operator-"



/* Implementation of the greater than operator: "operator>"
   Assume that we need only compare the real parts of two complex numbers
   (and ignore the imaginary parts)
*/
bool ComplexNumber::operator > (ComplexNumber const& obj) {
    if (real > obj.real)
        return true;
    else
        return false;
}

// 2DO Implement a "less than" operator (using real part only)


