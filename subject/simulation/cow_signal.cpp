#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("cowsignal");

    int n, m, k;
    cin >> n >> m >> k;

    vector<string> v;

    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v.push_back(s);
    }

    for (int i = 0; i < n; i++)
    {
        string ans = "";
        for (int j = 0; j < m; j++)
        {
            for (int l = 0; l < k; l++)
            {
                ans += v[i][j];
            }
                                    
        }
        for (int l = 0; l < k; l++)
        {            
            cout << ans << endl;
        }
        
    }
    
    
}