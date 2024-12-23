#include <bits/stdc++.h>
using namespace std;


void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    setIO("stacking");
    int n, k;

    cin >> n >> k;

    vector<int> updates(n + 1, 0);

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        updates[--a] += 1;
        updates[b] -= 1;
    }
    

    vector<int> values(n);

    int current = 0;
    for (int i = 0; i < n; i++)
    {
        current += updates[i];
        values[i] = current;
    }

    sort(values.begin(), values.end());

    cout << values[n / 2] << endl;
    
    
}