#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("shuffle");

    int n;
    cin >> n;

    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(--x);
    }
    vector<string> id;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        id.push_back(s);
    }


    vector<string> ans = id;
    for (int i = 0; i < 3; i++)
    {
        vector<string> tmp = ans;
        for (int j = 0; j < n; j++)
        {
            tmp[j] = ans[a[j]];
        }
        ans = tmp;
        
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
    
    
    
    
    
}