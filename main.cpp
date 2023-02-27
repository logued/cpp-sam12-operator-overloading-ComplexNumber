#include <iostream>

/*  ComplexNumber sample			Feb 2023

   Demonstrates Operator Overloading in a sample ComplexNumber class.
   Complex Numbers have two parts; a Real part and an Imaginary part.
   Operator Overloading allows us to define the behaviour of whichever
   operators we choose to implement (e.g. +.-,*,...) for a class type.

   Below, we implement:
   - operator overloading of "+" and "-" operators: (operator+) and (operator-)
   - operator overloading of global friend operators << and >>
*/

#include <iostream>
#include "ComplexNumber.h"
using namespace std;

int main()
{
    ComplexNumber c1(3,4);  // construct an object C1 (on the stack), real part =3, imaginary part =4

    ComplexNumber c2(2, 3);

    cout << "Created complexNumber c1 = " << c1 << " and c2 = " << c2 << endl;  // how is c1 formatted? Ans: by operator<<

    cout << "Executing statement c3 = c1 + c2; - will invoke the overloaded operator+" << endl;

    ComplexNumber c3 = c1 + c2;	// invoke overloaded "operator+" to add C1 and C2

    cout << "Result : c3 = ";
    cout << c3;     // Uses the stream insertion operator "operator<<" to output the object.
                    // The operator<< must be implemented in the program otherwise the system
                    // would not know how to output the c3 object contents.

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

    //TODO Exercises (see tasks in ComplexNumber.cpp)
}