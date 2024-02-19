/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

void sum(int *a)
{
    // Youre passing pointer ar argument not int. Hence have to dereference and work accordingly.
    *a = 4;
}
void sum2(int &a)
{
    // Youre passing reference to the int hence it will take automatically.
    a = 4;
}

void sum2(int a)
{
    // in main if you send reeference and the function is not expecting then error.
    a = 4;
}
int main()
{
    int a = 3;
    cout << "a before: " << a << endl;
    sum(&a);
    cout << "a after: " << a << endl;

    a = 3;
    cout << "a before (sum2): " << a << endl;
    sum(&a);
    cout << "a after (sum2): " << a << endl;
    return 0;
}
