#include <bits/stdc++.h>
using namespace std;

void address(float* p)
{
    cout << *p << "\n";
    return;
}

signed main()
{
    float pi = 3.14f;
    float* ptr = &pi;

    address(&pi);
    address(ptr);
}