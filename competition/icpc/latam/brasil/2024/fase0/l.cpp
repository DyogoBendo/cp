#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ll long long

struct P{
    ll x, y;
};

void dbg_out() { cerr << endl; }
template <typename H, typename... T>
void dbg_out(H h, T... t) { cerr << ' ' << h; dbg_out(t...); }
#define dbg(...) { cerr << #__VA_ARGS__ << ':'; dbg_out(__VA_ARGS__); }

signed main(){
    fastio;
    int n;
    cin >> n;
    queue<string> k, a;
    string temp;
    for (int i=0; i<n; i++){
        cin >> temp;
        k.push(temp);
    }
    for (int i=0; i<n; i++){
        cin >> temp;
        a.push(temp);
    }
    
    map<string, bool> remove;
    for (int i=0; i<n; i++){
        while (!a.empty() && remove[a.front()]){
            a.pop();
        }
        cout << a.front();
        if (i != n-1) cout << ' ';
        remove[k.front()] = 1;
        k.pop();
    }
    cout << '\n';
}