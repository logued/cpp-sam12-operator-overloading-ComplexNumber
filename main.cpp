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
    ComplexNumber c1(3,4);  // construct object C1 (on the stack)

    ComplexNumber c2(2, 3);

    cout << "Created complexNumber c1=" << c1 << " and c2 : " << c2 << endl;

    cout << "Executing statement c3 = c1 + c2; - will invoke the operator+" << endl;

    ComplexNumber c3 = c1 + c2;	// invoke "operator+" to add C1 and C2

    cout << "c3 = ";
    cout << c3;     // uses the stream insertion operator<< to output the object
                    // the operator<< must be implemented by us otherwise the system
                    // would not know how to output the c3 object

    cout << "Enter a complex number. Format (Number for real, space, number for imaginary): " << endl;

    ComplexNumber c4;   // crete a new ComplexNumber object (on the stack), initialized with default values

    cin >> c4;	// invokes the global overloaded stream extraction operator "operator>>"
                // as defined in the ComplexNumber class.
                // The extraction operator>> extracts data from the console input stream (cin)
                // and sends the data into the ComplexNumber object c4.
                // (The compiler searches for an implementation of "operator>>" function in the
                // ComplexNumber class, and the stream is passed as an argument into the function.

    cout << "The complex number c4 = ";
    cout << c4;	// invokes the overloaded insertion operator<<

    cout << "Outputting c2 and c3 using the print() member function" << endl;
    c1.print();
    c3.print();

    cout << "Executing statement \"if( c1 > c3 )\", which invokes \"operator>\"" << endl;

    if (c2 > c3)			// invoke the greater-than operator - "operator>", which returns true or false
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;

    //TODO Exercises (see ComplexNumber.cpp)
}