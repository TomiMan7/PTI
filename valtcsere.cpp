#include <iostream>

using namespace std;

int main()
{

int a = 4, b = 7;

cout<<"a: "<<a<<" b: "<<b<<endl;

a ^= b;
b ^= a;
a ^= b;

cout<<"a: "<<a<<" b: "<<b<<endl;

}
