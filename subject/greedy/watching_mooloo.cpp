#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }    

    int cost = k + 1;
    
    for (int i = 1; i < n; i++)
    {
        int d = v[i] - v[i - 1];
        if(d <= k){
            cost += d;            
        } else{
            cost += k + 1;            
        }
    }    

    cout << cost << endl;

}