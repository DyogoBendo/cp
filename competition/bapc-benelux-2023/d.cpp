#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> oc(m, vector<int>(26));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++)
        {
            oc[j][s[j]-'a']++;
        }
        
    }

    for (int i = 0; i < m; i++)
    {
        char ans;
        int curr = 0;
        for (int j = 0; j < 26; j++)
        {
            if(oc[i][j] > curr){
                curr = oc[i][j];
                ans = 'a' + j;
            }
        }
        cout << ans;
    }
    cout << endl;
}