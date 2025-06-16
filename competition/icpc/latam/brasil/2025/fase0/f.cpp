#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int N = 1e3 + 10;
const int MAX = 4e3;
const int MAXA = 1e3;

ll dp1[2*MAX + 10];
ll dp2[2*MAX + 10];
ll dp3[2*MAX + 10];
ll dp4[2*MAX + 10];
int n;
int v[N];

void init(){
    for (int i = 1; i <= n; i++) // possibilidades usando os i primeiros elementos
    {
        int x = v[i-1];

        for (int j = 0; j < 2*MAX; j++)
        {
            if(j + x < 2*MAX) dp4[j+x] += dp3[j];
        }

        for (int j = 0; j < 2* MAX; j++)
        {
            if(j + x < 2* MAX) dp3[j+x] += dp2[j];
        }

        for (int j = 0; j < 2* MAX; j++)
        {
            if(j + x < 2* MAX) dp2[j+x] += dp1[j];
        }
        dp1[x]++;
    }
    
}

signed main(){
    darvem;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];    
        v[i] += MAXA;
    }

    init();

    int q;
    cin >> q;

    while(q--){
        int x;
        cin >> x;
        cout << dp4[x+MAX] << endl;
    }

}