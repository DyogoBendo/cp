#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("diamond");
    int n, k;
    cin >> n >> k;
    vector<int> diamonds(n);
    for (int &x: diamonds)
    {
        cin >> x;
    }
    
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int current = diamonds[i];
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            int next = diamonds[j];
            if(next >= current && next <= current + k){                
                count ++;
            }
        }        
        ans = max(ans, count);
    }
    
    cout << ans << endl;    
}