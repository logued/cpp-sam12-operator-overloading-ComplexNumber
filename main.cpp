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
    ComplexNumber c1;
    cout << "Enter a complex number. Format (Number for real, space, number for imaginary): " << endl;

    cin >> c1;	// invokes the global overloaded extraction operator ">>" defined in the ComplexNumber class
    // The extraction is into a ComplexNumber object, so the compiler searches for
    // an implementation of operator>>, that has been defined for a ComplexNumber.
    // The ">>" operator is overloaded, as there are many versions of it for different
    // class types.


    cout << "The complex number is ";

    cout << c1;		// invokes the overloaded insertion operator that has been defined
    // to format an output data to the output stream.


    ComplexNumber c2(2, 3);	// creates an object on the stack

    cout << "Created complex number c2 : " << c2 << endl;	// invokes "operator<<"

    cout << "Executing c3 = c1 + c2" << endl;
    ComplexNumber c3 = c1 + c2;	// invoke "operator+"

    cout << "c3: " << c3 << endl;

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