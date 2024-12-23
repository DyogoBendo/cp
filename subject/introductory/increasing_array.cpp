#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> values(n);

    for(auto &v: values) cin >> v;

    long long total = 0;
    for (int i = 1; i < n; i++)
    {
        int c = max(values[i - 1] - values[i], 0);
        total += c;
        values[i] += c;
    }

    cout << total << endl;
    
    
}