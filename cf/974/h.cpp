#include <bits/stdc++.h>

using namespace std;

#define ll long long

void solve(){
    int n, q;
    cin >> n >> q;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];   
    }

    vector<int> pse(n + 1, 0);
    vector<int> pso(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        pse[i + 1] = pse[i - 1];
        pso[i + 1] = pso[i - 1];

        if(i % 2 == 0){
            pse[i + 1] += v[i];
        } else{
            pso[i + 1] += v[i];
        }
    }
    

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;

        int e = pse[r] - pse[l];
        int o = pso[r] - pso[l];

        int x = e - o;

        if(l % 2){
            if(x >= 0){
                cout << "YES" << endl;
            } else{
                cout << "NO" << endl;
            }
        } else{
            if(x <= 0){
                cout << "YES" << endl;
            } else{
                cout << "NO" << endl;
            }
        }
    }
    
    
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}