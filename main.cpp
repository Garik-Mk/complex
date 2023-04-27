#include <iostream>
#include "complex.h"


int main()
{
    complex a(2.3, 1.4);
    complex b(4, -1.7);
    complex c;
    c = a / b;
    print(c);
}

