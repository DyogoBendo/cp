#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("pails");
    int x, y, m;
    cin >> x >> y >> m;
    stack<int> s;
    s.push(0);
    int ans = 0;
    vector<int> checked(m + 1);
    while(!s.empty()){
        int t = s.top();
        s.pop();
        if(checked[t]) continue;
        checked[t] = 1;

        int v1, v2;
        v1 = x + t;
        v2 = y + t;
        int possible = t;
        if(v1 <= m){
            possible = v1;
            s.push(v1);
        }
        if(v2 <= m){
            possible = v2;
            s.push(v2);
        }
        ans = max({ans, possible});
    }

    cout << ans << endl;


}