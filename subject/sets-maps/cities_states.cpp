#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("citystate");
    int n;
    cin >> n;

    map<string, int> sc;

    for (int i = 0; i < n; i++)
    {
        string name, s;
        cin >> name >> s;
        string na = name.substr(0,2);
        if(na == s) continue;
        sc[na+s] ++;        
    }

    int ans = 0;
    for (auto kv : sc)
    {
        string name = kv.first;
        string s1 = name.substr(0, 2);
        string s2 = name.substr(2, 2);        
        auto f = sc.find(s2 + s1);
        if(f != sc.end()) ans += (sc[(s2 + s1)] * sc[(s1 +s2)]);
    }    

    cout << ans / 2 << endl;
    
    
}