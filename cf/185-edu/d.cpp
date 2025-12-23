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

int calc(char c){
    if(c == '?') return 0;
    if(c == 'X') return 10;
    if(c == 'V') return 5;
    return 1;
}

int ans (int tot, int ci, int cv, int cx, int tot_av, int negative_spot, int av_to_change, int one_extra){
    dbg(tot_av, av_to_change, negative_spot, one_extra, tot);
    int cost = tot;
    dbg(tot, ci, cv, cx);
    if(ci >= tot_av){
        cost += (tot_av - negative_spot) - negative_spot + av_to_change;
        return cost;
    }

    int need_non_one = tot_av - ci;
    int need_x = max(need_non_one - cv, 0);

    dbg(need_non_one, need_x, cost);

    int used_negative_spots = min({negative_spot, ci, tot_av});
    ci -= used_negative_spots;
    tot_av -= used_negative_spots;
    cost -= used_negative_spots;
    negative_spot -= used_negative_spots;

    dbg(used_negative_spots, cost);

    int used_v_after_one_fixed = min({av_to_change, cv, tot_av, need_non_one});
    cv -= used_v_after_one_fixed;
    av_to_change -= used_v_after_one_fixed;
    tot_av -= used_v_after_one_fixed;
    need_non_one -= used_v_after_one_fixed;
    cost += (4*used_v_after_one_fixed);

    dbg(used_v_after_one_fixed, cost);

    if(need_non_one == 0){
        cost += av_to_change + tot_av;
        return cost;
    }

    int used_v_after_one_open = min({one_extra, tot_av/2, cv, ci, need_non_one});
    cv -= used_v_after_one_open;
    ci -= used_v_after_one_open;
    one_extra -= used_v_after_one_open;
    tot_av -= 2*used_v_after_one_open;
    need_non_one -= used_v_after_one_open;
    cost += (4*used_v_after_one_open);

    dbg(used_v_after_one_open, cost);

    if(need_non_one == 0){
        cost += av_to_change + tot_av;
        return cost;
    }
    
    if(need_x == 0){
        cost += av_to_change + ci + 5*need_non_one;
        return cost;
    }

    int used_x_after_one_fixed = min({av_to_change, cx, tot_av, need_non_one});
    cx -= used_x_after_one_fixed;
    av_to_change -= used_x_after_one_fixed;
    tot_av -= used_x_after_one_fixed;
    need_non_one -= used_x_after_one_fixed;
    cost += (9*used_x_after_one_fixed);

    dbg(used_x_after_one_fixed, cost);

    if(need_non_one == 0){
        cost += av_to_change + tot_av;
        return cost;
    }

    int used_x_after_one_open = min({one_extra, tot_av/2, cx, ci, need_non_one});
    cx -= used_x_after_one_open;
    ci -= used_x_after_one_open;
    one_extra -= used_x_after_one_open;
    tot_av -= 2*used_x_after_one_open;
    need_non_one -= used_x_after_one_open;
    cost += (9*used_x_after_one_open);

    dbg(used_x_after_one_open, cost);

    int left_one = min(ci, tot_av);
    cost += left_one + av_to_change;
    tot_av -= left_one;

    dbg(left_one, cost);

    int left_v = min(cv, tot_av);
    cost += left_v*5;
    tot_av -= left_v;

    int left_x = min(tot_av, cx);
    cost += 10*left_x;

    dbg(left_x, cost);
    return cost;
}

void solve(){
    int n, q, cx, cv, ci;
    string s;
    cin >> n >> q >> s;

    int tot = 0;
    int av_to_change = 0;
    int tot_av = 0;
    vector<int> fixed(n);
    for(int i = 0; i < n; i++){
        if(s[i] == '?') tot_av++;
        else fixed[i] = 1;
    } 
    
    for(int i = 0; i < n-1; i++){
        if(s[i] != 'I'){
            tot += calc(s[i]);
        } else{
            if(s[i+1] == 'V' or s[i+1] == 'X') tot --;
            else if(s[i+1] == 'I') tot++;
            else{
                fixed[i+1]=1;
                av_to_change++;
            } 
        }
    }

    tot += calc(s[n-1]);
    int negative_spot = 0;
    for(int i = n-1; i>0; i--){
        if((s[i] == 'X' or s[i] == 'V') and s[i-1] == '?'){
            fixed[i-1] = 1;
            negative_spot ++;
        } 
    }

    int one_extra = 0;
    int curr_sz = 0;
    for(int i = 0; i < n; i++){
        dbg(i, fixed[i]);
        if(!fixed[i]) curr_sz++;
        else{
            one_extra += curr_sz / 2;
            curr_sz = 0;
        }
    }

    one_extra += curr_sz / 2;

    while(q--){
        cin >> cx >> cv >> ci;
        cout << ans(tot, ci, cv, cx, tot_av, negative_spot, av_to_change, one_extra) << endl;
    }
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}