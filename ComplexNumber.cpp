/* Implementation of Class ComplexNumber:		March 2022

   Demonstrates implementation of Operator Overloading functions.
   Operator Overloading allows us to define the behaviour of operators,
   such as +,-,*, <, << etc., for a class type.

    Implemented below:
   - operator overloading of "+" and "-" operators: (operator+) and (operator-)
   - operator overloading of global friend operators << and >>
*/
#include "ComplexNumber.h"
#include <iostream>
using namespace std;

/* Observe carefully that the stream insertion operator<< and
 * stream extraction operator>>  do NOT have the qualifier "ComplexNumber::"
 * in front of the function.  That means that they are not members of the
 * ComplexNumber class.  They are actually global functions (with global scope).
 * They can be called from anywhere (that has included ComplexNumber.h).
 * We have overloaded the "<<" and ">>" operators for the ComplexNumber class.

*/

/* the insertion "operator<<" is invoked by the following pattern :
   "outputStream << complexNumber"  e.g. cout << c1;
*/

// Parameters:   << ("output stream", "reference to a constant ComplexNumber object")
// Returns:      reference to the output stream (usually 'cout')
//
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

// Implementation of overloaded "plus" and "greater than" operators.
// The operator+ and operator> below are implemented as MEMBER functions,
// as they are invoked on ComplexNumber objects.
// i.e.  complexNumResult = complexNum1 + complexNum2
// The + operator is "invoked on the complexNum1 object"

/* Implementation of the "operator+"
   enabling the addition of two ComplexNumber objects.
   Usage: complexNumberResult = complexNumber1 + complexNumber2;
*/

ComplexNumber ComplexNumber::operator+ (ComplexNumber const& other) {
    ComplexNumber temp;
    temp.real = this->real + obj.real;
    temp.imaginary = this->imaginary + obj.imaginary;
    return temp; // return an object (by value)
}

//TODO Implement a 'minus' operator function: "operator-"


/* Implementation of the greater than operator: "operator>"
   Assume that we need only compare the real parts of two complex numbers
   (and ignore the imaginary parts)
*/
bool ComplexNumber::operator> (ComplexNumber const& other) {
    if (this->real > other.real)
        return true;
    else
        return false;
}

//TODO Implement a "less than" operator< (using real part only for comparisons)
// Test it from main()


