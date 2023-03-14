#include<bits/stdc++.h>
using namespace std;

double my_fun(int n)
{
    double ans = 0;
    for(int i = 1; i <= n; i++){
        ans += 1 / pow(2,i);
    }

    return ans;
}
signed main()
{
    int n = 1;
    while(1){
        if(my_fun(n) > 0.99999){
            cout << n << "\n";
            break;
        }
        n++;
    }
}