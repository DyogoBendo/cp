#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

signed main(){
    darvem;

    int c, n;
    cin >> c >> n;
    
    vector<int> pizza(c);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        pizza[x] ++;
    }

    bool found = false;

    int g = c/n;
    vector<int> groups(n);
    bool possible = true;    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < g; j++){            
            groups[i] += pizza[j + i*g];
        }        
        if(groups[i] != 1) possible= false;
    }
    if(possible) found = true;

    for(int i = 1; i < g; i++){           
        possible =true; 
        for(int j = 0; j < n; j++){
            int st = j*g + i;
            int en = ((j+1)*(g) + i - 1) % c;            
            groups[j] -= pizza[st-1];
            groups[j] += pizza[en];
            if(groups[j] != 1) possible = false;            
        }
        if(possible) found = true;
    }

    cout << (found? "S" : "N") << endl;
}