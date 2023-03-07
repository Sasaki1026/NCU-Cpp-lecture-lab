#include<bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    int n = 3000, d = 0;

    while (n >= 5)
    {
        d++;
        n /= 2;
    }

    cout << d << "\n";
    
}