#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    // setIO("promote");

    vector<int> v(7);
    for (auto &value : v)
    {
        cin >> value;
    }

    sort(v.begin(), v.end());

    int a = v[0];
    int b = v[1];
    int c = v[6] - a - b;

    cout << a << " " << b << " " << c << endl;
    
}