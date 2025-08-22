#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MAX = 25;

signed main(){
    darvem;

    int n, c;
    cin >> n >> c;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];        
    }

    vector<vector<int>> prox(MAX, vector<int>(n));
    for (int l = 0, r = 0, tot = 0; l < n; l++)
    {
        while(r - l < n && tot < c){
            tot += v[r % n];
            r++;
        }
        prox[0][l] = r % n;
        if(prox[0][l] == l) prox[0][l] = -1;
        tot -= v[l];
    }
    
    for (int i = 1; i < MAX; i++)
    {
        //cout << "i: " << i << endl;
        for (int j = 0; j < n; j++)
        {
            int p1 = prox[i-1][j], p2 = -1;
            if(p1 != -1){
                p2 = prox[i-1][p1];

                if(p2 != -1 && ((p1 > j && p2 < p1 && p2 >= j) || (p1 < j && (p2 >= j || p2 <= p1)))) p2 = -1;
            }        
            //cout << "j: " << j <<  " p1: " << p1 << " p2: " << p2 << endl;    
            prox[i][j] = p2;
        }
        //cout << endl;
        
    }
    
    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        int curr = i;
        for (int j = MAX-1; j >= 0; j--)
        {
            if(prox[j][curr] == -1) continue;
            int p = prox[j][curr];
            if((curr > i && p < curr && p >= i) or (curr < i && (p >= i or p <= curr)) ) continue;
            ans += (1 << j);
            curr = prox[j][curr];
        }
        cout << ans << " ";       
    }
    cout << endl;
    
}