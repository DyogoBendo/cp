#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long a, b, n;

    vector<long long> tools;
    cin >> a >> b >> n;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        tools.push_back(x);
    }

    long long result = b;

    sort(tools.begin(), tools.end());

    for (int i = 0; i < n; i++)
    {
        result += min(a - 1, tools[i]);
    }

    cout << result << endl;
    
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}