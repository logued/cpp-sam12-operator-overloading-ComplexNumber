/* Implementation of Class ComplexNumber:		February 2023

   Demonstrates implementation of Operator Overloading functions.
   Operator Overloading allows us to define the behaviour of operators,
   such as operators:  +,-,*, <, << etc., for a class type.

    Implemented below:
   - operator overloading of "operator+" and "operator-" operators
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
 * We have overloaded the "<<" and ">>" operators to operate on ComplexNumber objects.
 * However, we define them in the ComplexNumber class, because they operate on a
 * ComplexNumber object, and, when we use the keyword "friend", which means that
 * the code in the friend function can directly access the Data Members (fields) of
 * the ComplexNumber class.
*/

/* The stream insertion "operator<<" is invoked by the following pattern :
   "outputStream << complexNumber"  e.g. "cout << c1";
   Note that this is similar (in functionality) to implementing the .toString() method in Java.
   It allows us to output an object's contents to the output stream in a format decided upon by
   the programmer.
*/

// Parameters:   out = "output stream", and
//               ref_ComplexNumber = "reference to a constant ComplexNumber object"
// Returns:      a reference to the output stream
//
ostream& operator<< (ostream& out, const ComplexNumber& ref_ComplexNumber)
{
    // As this is defined as a 'friend' function in the ComplexNumber header file,
    // the code here has direct access to the private member data of the ComplexNumber object.
    // (So, we don't need to call getters and setters)

    // code to implement the "operator<<" functionality
    out << "[ Real:" << ref_ComplexNumber.real << ", ";
    out <<  "Imaginary:" << ref_ComplexNumber.imaginary << " ]" << endl;

    return out;
}

/* The extraction "operator>>"  is invoked by the following pattern
   "  inputStream >> complexNumber;    e.g. cin >> c1; "
   In this case we must prompt the user to enter a real and imaginary part,
   and then stream the inputted values into the target ComplexNumber object
   using the reference to that ComplexNumber.
*/

istream& operator>> (istream& in, ComplexNumber& ref_complexNumber)
{
    cout << "Enter Real Part ";
    in >> ref_complexNumber.real;

    cout << "Enter Imaginary Part ";
    in >> ref_complexNumber.imaginary;

    return in;
}

// Implementation of overloaded "plus" and "greater than" operators.
// The operator+ and operator> below are implemented as MEMBER functions,
// as they are invoked on ComplexNumber objects.
// i.e.  complexNumResult = complexNum1 + complexNum2
// Above, the + operator is "invoked on the complexNum1 object" and is
// passed a reference to the complexNumber2 object.

/* Implementation of the "operator+"
   enabling the addition of two ComplexNumber objects.
   Usage: complexNumberResult = complexNumber1 + complexNumber2;
*/

ComplexNumber ComplexNumber::operator+ (const ComplexNumber& otherComplexNumber)  {

    ComplexNumber temp; // create a ComplexNumber object to store the result

    temp.real = this->real + otherComplexNumber.real;   // add both real parts together
    temp.imaginary = this->imaginary + otherComplexNumber.imaginary; // add both imaginary parts together

    return temp; // return contents of temp object (by value)
}

//TODO Implement a 'minus' operator function: "operator-"


/* Implementation of the greater-than operator: "operator>"
   Assume that we need only compare the real parts of two complex numbers
   (and ignore the imaginary parts)
   e.g. if ( c1 > c2 ) { do something...... }
*/
bool ComplexNumber::operator> (const ComplexNumber& other) {
    if (this->real > other.real)
        return true;
    else
        return false;
}

//TODO Implement a "less than" operator< (using real part only for comparisons)
// Test it in main()


