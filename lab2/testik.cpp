#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


long long f(){
    int g = 6;
    return (long long)&g;
}

void f2(long long p)
{
    int a =777;
    cout<<*(int*)p;
}

int main() {
    f2(f());
}