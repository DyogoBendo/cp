#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

//#define DEBUG

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

int n, curr_n, cnt;
int query(int i, int j, int x, int y){
    int ans;
    cnt++;
    assert(cnt <= 13);
    cout << "? " << i << " " << j << " " << x << " " << y << endl;
    cin >> ans;
    return ans;
}

bool is_palindrome(){
    int ans = query(1, 2, 1, 1);

    return (ans >= curr_n);
}

bool is_half_equal(){
    int m = curr_n/2;

    int ans = query(1, 1, 1, 1+m);

    return (ans >= m);
}

void answer(int x){
    cout << "! " << x << endl;
}

void solve(){
    cin >> n;
    cnt = 0;

    curr_n = n;
    if(is_palindrome()){
        answer(1);
        return;
    }

    int curr = 0;    

    while(curr_n % 2 == 0 and curr_n > 2 and is_half_equal()){
        curr ^= 1, curr_n>>=1;
    }         
    
    answer(curr);
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int cases = 1;
    cin >> cases;
    for (int i=0; i<cases; i++) solve();
}