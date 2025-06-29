#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MAXW = 1e4;

signed main(){
    darvem;

    int n, W, K;
    cin >> n >> W;
    K = n/2 - 1;

    int w=0, q = 0;    
    

    vector<int> vw(n);    
    vector<int> vq(n);

    for (int i = 0; i < n ; i++)
    {
        vw[i] = i;
        vq[i] = i <= K ? K - i : i;
    }

    reverse(vw.begin(), vw.end());

    for (int i = 0; i < n; i++)
    {        
        cout << ( W + vw[i] <= MAXW ? W + vw[i] : W - vw[i]) << " " << vq[i] << endl;
    }
    
}