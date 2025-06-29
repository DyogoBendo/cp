#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, a, b;

    cin >> n >> a >> b;

    vector<int> dst(n);
    int curr = 0;    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        curr += x;

        dst[i] = curr;
    }

    int k;
    cin >> k;
    k--;

    int marcel = dst[k] + b;

    for (int i = 0; i < n; i++)
    {
        if(i != k && a + dst[i] >= marcel){
            cout << "SIM" << endl;
            cout << i+1 << endl;
            return 0;
        }
    }
    

    cout << "NAO" << endl;
    
}