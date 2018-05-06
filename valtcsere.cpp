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

a = 4, b = 7;
cout<<endl;

cout<<"a: "<<a<<" b: "<<b<<endl;
a = a - b;
b = a + b;
a = b - a;
cout<<"a: "<<a<<" b: "<<b<<endl;

a = 4, b = 7;
cout<<endl;

cout<<"a: "<<a<<" b: "<<b<<endl;
a = a * b;
b = a / b;
a = a / b;
cout<<"a: "<<a<<" b: "<<b<<endl;


}
