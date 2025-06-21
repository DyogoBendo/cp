#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n - 1; i++)
    {
        cin >> v[i];
    }    

    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int j = i + 1; j < n; j++)
        {
            curr += v[j - 1];
            cout << curr << " ";
        }
        cout << endl;
    }
    
    
}