#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;

    int biggest= n, smallest = 1;    

    for (int i = 1; i <= n; i++)
    {
        if(i % 2){            
            cout << biggest << " ";
            biggest --;
        } else{            
            cout << smallest << " ";
            smallest ++;
        }
    }
    
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}