// NAME: Dylan Le
// FILE: main.cpp
// DESCRIPTION: Tests IntSet class

#include <iostream>
using namespace std;

#include "IntSet.h" // Corrected file inclusion

int main()
{



    IntSet a(100);
    IntSet b(100);
    IntSet C(100);


    // Adding elements to set 'a' (numbers evenly divisible by 6, less than or equal to 100
    for (int i = 1; i <= 100; ++i) {
        if (i % 6 == 0) {
            a.addElement(i);
        }
    }

    // Adding elements to set b that are greater than or equal to 40 but less than or equal to 50
    for (int i = 40; i <= 50; ++i) {
        b.addElement(i);
    }
    // Adding factors of 96 to set 'b'
    for (int i = 1; i <= 96; ++i) {
        if (96 % i == 0) {
            C.addElement(i);
        }
    }

    IntSet c = unions(a, b);
    c.display();
    cout << endl;

    IntSet D = complement(a);
    IntSet E = unions(b, a);
    IntSet F = unions(a, D);
    IntSet G = intersect(a, b);
    IntSet H = intersect(b, c);
    IntSet I = difference(c, a);
    IntSet J = difference(b, D);
    IntSet K = difference(b, E);

    // Display the resulting sets
    cout << "Set A: ";a.display();
    cout << "Number of elements: "<<a.numElements()<<"\n\n";

    cout << "Set B: ";b.display();
    cout << "Number of elements: "<<b.numElements()<<"\n\n";

    cout << "Set C: ";C.display();
    cout << "Number of elements: "<<C.numElements()<<"\n\n";

    cout << "Set D: ";D.display();
    cout << "Number of elements: "<<D.numElements()<<"\n\n";

    cout << "Set E: ";E.display();
    cout << "Number of elements: "<<E.numElements()<<"\n\n";

    cout << "Set F: ";F.display();
    cout << "Number of elements: "<<F.numElements()<<"\n\n";

    cout << "Set G: ";G.display();
    cout << "Number of elements: "<<G.numElements()<<"\n\n";

    cout << "Set H: ";H.display();
    cout << "Number of elements: "<<H.numElements()<<"\n\n";

    cout << "Set I: ";I.display();
    cout << "Number of elements: "<<I.numElements()<<"\n\n";

    cout << "Set J: ";J.display();
    cout << "Number of elements: "<<J.numElements()<<"\n\n";

    cout << "Set K: ";K.display();
    cout << "Number of elements: "<<K.numElements()<<"\n\n";

    // Print whether 42 ∈ A?
    cout << "42 ∈ A? ";
    if (a.isElement(42)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

// Print whether 42 ∈ C?
    cout << "42 ∈ C? ";
    if (C.isElement(42)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

// Print whether C = I?
    cout << "C = I? ";
    if (isEqual(C, I)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

// Print whether G = J?
    cout << "G = J? ";
    if (isEqual(G, J)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }


    return 0;
}