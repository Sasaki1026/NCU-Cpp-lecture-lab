#include <bits/stdc++.h>
#define ROW 2
#define COL 4
#define db double
using namespace std;

db average(int arr[ROW][COL])
{
    db ret = 0;
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            ret += arr[i][j];
        }
    }
    ret /= ROW*COL;
    return ret;
}

signed main()
{
    int arr[ROW][COL] = {{2,3,4,5},{6,7,8,9}};
    cout << average(arr) << endl;
}