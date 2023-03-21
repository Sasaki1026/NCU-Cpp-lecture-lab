#include <bits/stdc++.h>
#define db double
using namespace std;
db pow(db d, int n)
{
    db ret = 1.0;
    for (int i = 0; i < n; i++){
        ret *= d;
    }
    return ret;
}

int f(int n)
{
    int ret = 1;
    for (int i = 1; i <= n; i++){
        ret *= i;
    }
    return ret;
}

db my_fun(db x, int n)
{
    db t = 0;
    db tmp;
    for (int i = 1; i <= n; i++){
        tmp = pow(x,i) / f(i);
        t += tmp;
    }
    return t;
}
signed main()
{
    cout << my_fun(0.1,5) <<"\n";
    cout << my_fun(0.1,8) <<"\n";
    cout << my_fun(0.2,8) <<"\n";

    int i = 1;
    while (1){
        i++;
        db check = my_fun(0.1,i) - my_fun(0.1, i - 1);
        if (check < 0.00001) break;
    }

    cout << i << "\n";
}