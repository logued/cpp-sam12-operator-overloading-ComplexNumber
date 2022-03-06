/* Implementation of Class ComplexNumber:		March 2022

   Demonstrates Operator Overloading.
   Operator Overloading allows us to define the behaviour of operators (e.g. +.-,*, <, etc.)
   for a class type.

   - operator overloading of "+" and "-" operators: (operator+) and (operator-)
   - operator overloading of global friend operators << and >>
*/
#include "ComplexNumber.h"
#include <iostream>
using namespace std;

/* The stream insertion operator<< and stream extraction operator>>  are
   defined *outside* the class definition,
   and therefore have global scope.
   They are GLOBAL operators that we override for our ComplexNumber class.
*/

/* the insertion "operator<<" is invoked by the following pattern :
   "   outputStream << complexNumber   "
*/

ostream& operator<< (ostream& out, const ComplexNumber& c)
{
    // As this is defined as a 'friend' of ComplexNumber in the header file,
    // code here has direct access to the private member data of the ComplexNumber object.
    // (So, we don't need to call getters and setters)

    // code to implement the operator<< functionality
    out << c.real;
    out << " + " << c.imaginary << "i" << endl;
    return out;
}

/* The extraction "operator>>"  is invoked by the following pattern
   "  inputStream >> complexNumber     "
*/

istream& operator>> (istream& in, ComplexNumber& c)
{
    cout << "Enter Real Part ";
    in >> c.real;
    cout << "Enter Imaginary Part ";
    in >> c.imaginary;
    return in;
}

// The operator+ and operator> below are implemented as member functions,
// as they are invoked on ComplexNumber objects.
// i.e.  complexNumResult = complexNum1 + complexNum2

/* Implementation of the "operator+"
   enabling the addition of two ComplexNumber objects.
   Usage: complexNumberResult = complexNumber1 + complexNumber2;

*/
ComplexNumber ComplexNumber::operator+ (ComplexNumber const& obj) {
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
bool ComplexNumber::operator> (ComplexNumber const& obj) {
    if (real > obj.real)
        return true;
    else
        return false;
}

//TODO Implement a "less than" operator< (using real part only for comparisons)


