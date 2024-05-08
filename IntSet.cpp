// NAME: Dylan Le
// FILE: IntSet.cpp
// DESCRIPTION: Implementation of the IntSet class.

#include <iostream>

#include <cstring>
using namespace std;

#include "IntSet.h"

const int ELEM_BITS = 32;

// Constructor: the argument represents the largest possible integer the set
// can have in its domain.  If the argument is 5, then the domain of the set
// is the integers 1-5.  The set that is being constructed however is empty.
IntSet::IntSet(int sizeArg)
{
    // Initialize the domain with sizeArg
    domain = sizeArg;

    // Allocate memory for the bit_array
    bit_array = new int[domain + 1];

    // Initialize all elements of bit_array to 0
    std::memset(bit_array, 0, sizeof(int) * (domain + 1));
}

// Copy constructor
IntSet::IntSet(const IntSet& src)
{
    // Copy the domain value
    domain = src.domain;

    // Allocate memory for the bit_array
    bit_array = new int[domain + 1];

    // Copy the elements of src bit_array to the new bit_array
    std::copy(src.bit_array, src.bit_array + domain + 1, bit_array);
}

// Destructor
IntSet::~IntSet()
{
    // Deallocate the dynamically allocated memory for bit_array
    delete[] bit_array;
}

// Adds the specified integer to the set if not already an element.
void IntSet::addElement(int num)
{
    // Check if the specified integer is within the domain
    if (num >= 1 && num <= domain) {
        // If the element is not already in the set, set its corresponding bit to 1
        if (bit_array[num] != 1) {
            bit_array[num] = 1;
        }
    }
    // If the specified integer is not within the domain, it cannot be added to the set
    // Do nothing in this case
}

// Removes the specified integer if it is in the set.  Note that nothing happens
// if the element is in the domain but not in the set.
void IntSet::removeElement(int num)
{
    // Check if the specified integer is within the domain
    if (num >= 1 && num <= domain) {
        // If the element is present in the set, set its corresponding bit to 0
        bit_array[num] = 0;
    }
    // If the specified integer is not within the domain, it is not in the set, so do nothing
}

// Returns true if the specified integer is in the set.  Returns false otherwise.
bool IntSet::isElement(int num) const
{
    // Check if the specified integer is within the domain
    if (num >= 1 && num <= domain) {
        // Return true if the element is present in the set, false otherwise
        return (bit_array[num] == 1);
    }
    // If the specified integer is not within the domain, it cannot be in the set
    return false;
}

// Returns the number of elements in the set.
int IntSet::numElements() const
{
    int count = 0;

    // Iterate through all elements in the domain
    for (int i = 1; i <= domain; i++) {
        // If an element is present in the set, increment the count
        if (bit_array[i] == 1) {
            count++;
        }
    }

    return count;
}

// Returns a set that is the union of sets a and b.
IntSet unions(const IntSet& a, const IntSet& b)
{
    // Determine the maximum domain of the two sets
    int maxDomain = std::max(a.domain, b.domain);

    IntSet unionSet(maxDomain);

    // Iterate through all elements in the domain
    for (int i = 1; i <= maxDomain; i++) {
        // If an element is in either set 'a' or set 'b', it belongs to the union set
        if (a.isElement(i) || b.isElement(i)) {
            unionSet.addElement(i);
        }
    }

    return unionSet;
}

// Returns a set that is the intersection of sets a and b.
IntSet intersect(const IntSet& a, const IntSet& b)
{
    // Determine the maximum domain of the two sets
    int maxDomain = std::min(a.domain, b.domain);

    IntSet intersectionSet(maxDomain);

    // Iterate through all elements in the domain
    for (int i = 1; i <= maxDomain; i++) {
        // If an element is in both set 'a' and set 'b', it belongs to the intersection set
        if (a.isElement(i) && b.isElement(i)) {
            intersectionSet.addElement(i);
        }
    }

    return intersectionSet;
}

// Returns a set that is the difference a - b.
IntSet difference(const IntSet& a, const IntSet& b)
{
    IntSet differenceSet(a.domain);

    // Iterate through all elements in the domain
    for (int i = 1; i <= a.domain; i++) {
        // If an element is in set 'a' but not in set 'b', it belongs to the difference set
        if (a.isElement(i) && !b.isElement(i)) {
            differenceSet.addElement(i);
        }
    }

    return differenceSet;
}

// Returns the complement of the set a
IntSet complement(const IntSet& a)
{
    IntSet complementSet(a.domain);

    // Iterate through all elements in the domain
    for (int i = 1; i <= a.domain; i++) {
        // If an element is not in set 'a', it belongs to the complement set
        if (!a.isElement(i)) {
            complementSet.addElement(i);
        }
    }

    return complementSet;
}



