#include <algorithm>
#include <string> 
#include<iostream>
using namespace std;
int main()
{
string data = "Abc"; 
transform(data.begin(), data.end(), data.begin(), ::tolower);
cout<<data;
}
