#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int n, k;
    cin >> n >> k;    

    int biggest_safe = 1;
    int smallest_broken = k;
    for (int i = 0; i < n; i++)
    {
        int f;
        string action;
        cin >> f >> action;

        if(action == "SAFE"){
            biggest_safe = max(biggest_safe, f);
        } else{
            smallest_broken = min(smallest_broken, f);
        }
    }

    cout << biggest_safe + 1 << " " << smallest_broken -1 << endl;
    
}