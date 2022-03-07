#include <iostream>

/*  ComplexNumber sample			Feb 2022

   Demonstrates Operator Overloading.
   Operator Overloading allows us to define the behaviour of operators (e.g. +.-,*,...)
   for a class type.

   Below, we implement:
   - operator overloading of "+" and "-" operators: (operator+) and (operator-)
   - operator overloading of global friend operators << and >>
*/

#include <iostream>
#include "ComplexNumber.h"
using namespace std;

int main()
{
    ComplexNumber c1(3,4);  // creates an object on the stack

    ComplexNumber c2(2, 3);

    cout << "Created complex numbers c1=" << c1 << " and c2 : " << c2 << endl;	// invokes "operator<<"

    cout << "Executing c3 = c1 + c2 - will invoke the operator+" << endl;
    ComplexNumber c3 = c1 + c2;	// invoke "operator+"

    cout << "C3 = " << c3;     // uses the stream insertion operator <<

    cout << "Enter a complex number. Format (Number for real, space, number for imaginary): " << endl;

    ComplexNumber c4;
    cin >> c4;	// invokes the global overloaded extraction operator ">>" defined in the ComplexNumber class
    // The extraction is into a ComplexNumber object, so the compiler searches for
    // an implementation of operator>>, that has been defined for a ComplexNumber.
    // The ">>" operator is overloaded, as there are many versions of it for different
    // class types.

    cout << "The complex number C4 = " << c4;		// invokes the overloaded insertion operator that has been defined
    // to format an output data to the output stream.

    cout << "Outputting c2 and c3 using the print() member function" << endl;
    c1.print();
    c3.print();

    cout << "Executing statement \"if( c1 > c3 )\", which invokes \"operator>\"" << endl;

    if (c2 > c3)			// invoke operator >, which returns true or false
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;

    // Exercises (see ComplexNumber.cpp)
}