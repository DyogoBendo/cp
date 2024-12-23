#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("teleport");

    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int tmp = x;
    x = min(x, y);
    y = max(tmp, y);

    tmp = a;
    a = min(a, b);
    b = max(tmp, b);

    int best = min(b - a, abs(x - a) + abs(y - b));

    cout << best << endl;
}