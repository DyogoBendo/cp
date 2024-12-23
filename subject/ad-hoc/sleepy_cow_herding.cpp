#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("herding");

    int v[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> v[i];        
    }

    sort(v, v + 3);
    

    int d1 = v[1] - v[0];
    int d2 = v[2] - v[1];


    int mn = min(min(d1, d2) - 1, 2);
    if(min(d1, d2) - 1 == 0 && max(d1, d2) - 1 != 0){
        mn = min(max(d1, d2) - 1, 2);
    }

    cout << mn << endl;
    cout << max(d1, d2) - 1 << endl;
}
