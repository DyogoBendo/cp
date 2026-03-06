#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())



ll f5 = 2*3*4*5;
ll f7 = f5*6*7;
ll f10 = f7*8*9*10;

vector<string> perm[3];

int get_order(string s){
    int i = 0;

    if (s.size() == 10) i = 0;
    else if (s.size() == 7) i = 1;
    else if (s.size() == 5) i = 2;
    else{
        assert(1 == 0);
    }

    return lower_bound(all(perm[i]), s) - perm[i].begin();
}

vector<vector<int>> perm2;

void init(){
    string s10 = "ABCDEFGHIJ";
    string s7 = "ABCDEFG";
    string s5 = "ABCDE";

    vector<string> strs = {s10, s7, s5};

    int i=0;
    for (auto s: strs){
        do{
            perm[i].push_back(s);
        }
        while(next_permutation(all(s)));
        i++;
    }

    vector<int> nbrs = {1, 5, 7};
    do{
        perm2.push_back(nbrs);
    }
    while(next_permutation(all(nbrs)));
}


void team(){
    string a, b, c;
    cin >> a >> b >> c;
    vector<int> ord = {sz(a), sz(b), sz(c)};
    int mult = lower_bound(all(perm2), ord) - perm2.begin();

    int ans = mult*f5*f7;
    
    string s;
    if (sz(a) == 5) s = a;
    else if (sz(b) == 5) s = b;
    else s = c;

    ans += get_order(s) * f7;

    if (sz(a) == 7) s = a;
    else if (sz(b) == 7) s = b;
    else s = c;

    ans += get_order(s);

    cout << perm[0][ans] << '\n';
}

void coach(){
    string s;
    cin >> s;

    int ord = get_order(s);

    string s7 = perm[1][ord%f7];
    ord /= f7;
    string s5 = perm[2][ord%f5];
    ord /= f5;

    string A = "A";
    vector<pair<int, string>> ans;
    ans.push_back({1, A});
    ans.push_back({5, s5});
    ans.push_back({7, s7});
    for (int i=0; i<ord; i++){
        next_permutation(all(ans));
    }
    
    for (auto a: ans) cout << a.second << ' ';
    cout << '\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);

    init();

    string s;
    cin >> s;
    int cases = 1;
    cin >> cases;
    for (int i=0; i<cases; i++){
        if (s[0] == 'c') coach();
        else team();
    }
}