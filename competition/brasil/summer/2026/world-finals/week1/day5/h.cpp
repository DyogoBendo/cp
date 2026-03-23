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

int calc(int x){
    int curr = 1;

    if(x % 5 == 0){
        curr++;
    }
    if(x % 4 == 0){
        curr ++;
    }
    return curr;
}

void solve(){
    string s;
    cin >> s;

    int n = sz(s);

    vector<int> cnt(10);
    for(int i = 0; i < n; i++) cnt[s[i] - '0']++;

    int sum = 0;
    for(int i = 0; i < 10; i++) sum += cnt[i] * i;

    if(sum % 3){ // não é divísivel por 3
        cout << "0 0" << endl;
        return;
    }

    vector<pair<int, int>> candidates;
    int lst_digit = s.back() - '0';
    int penultimo_digit = n > 1 ? s[n-2] - '0' : -1; 
    int x = lst_digit;
    if(n > 1) x += penultimo_digit * 10;

    candidates.push_back({calc(x), 0});

    // fazendo uma motificação, podemos ou trocar os dois dígitos, ou pegar qualquer um dos outros dígitos e colocar na primeira ou segunda posição
    if(n > 2 or (n== 2 and s.back() != '0')){
        int y = (lst_digit * 10) + penultimo_digit;
        candidates.push_back({calc(y), -1});
    }
    
    // com mais de 2 dígitos, podemos fazer duas modificações e definir os últimos dois dígitos como quisermos
    if(n > 2){        
        for(int i = 0; i < 10; i++){
            int qtd = cnt[i] - (lst_digit == i) - (penultimo_digit == i);
            if(!qtd) continue;
            candidates.push_back({calc(lst_digit + (i*10)), -1});
            candidates.push_back({calc(penultimo_digit*10 + i), -1});
        }
        
        for(int i = 0; i < 10; i++){
            if(!cnt[i]) continue;
            cnt[i]--;
            for(int j = 0; j < 10; j++){
                if(cnt[j]){
                    candidates.push_back({calc(i*10 + j), -2});
                }
            }
            cnt[i]++;
        }
    }

    sort(candidates.rbegin(), candidates.rend());

    cout << candidates[0].first << " " << -candidates[0].second << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}