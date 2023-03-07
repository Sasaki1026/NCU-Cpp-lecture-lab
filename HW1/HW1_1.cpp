#include<bits/stdc++.h>
using namespace std;

signed main()
{
    cin.tie(0);
    int n;

    while (1)
    {
        cin >> n;
        if (n % 2 == 1) break;
        cout << "Invalid input\n";
    }

    int ans = 0;

    for (int i = 1; i <= n; i+=2){
        ans += i;
    }

    cout << ans << "\n";
    
}