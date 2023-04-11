#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int *a ;
    int arr[5] = {31,17,33,22,16};
    a = arr;
    for(int i = 0; i < 5; i++){
        *(a + i) += 10;
        cout << *(a+i) << ' ';
    }
    cout << "\n";

    int max = -1e5, min = 1e5;
    for(int i = 0; i < 5; i++){
        if(*(a+i) < min) min = *(a+i);
        if(*(a+i) > max) max = *(a+i);
    }
    cout << "max: " << max << "\nmin: " << min << "\n";
}