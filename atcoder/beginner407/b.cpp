#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int x, y;
    cin >> x >> y;

    double favor = 0;
    double total = 36;

    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if(i + j >= x or abs(j-i) >= y) favor++;
        }
        
    }
    
    printf("%.15lf\n", favor/total);    
}