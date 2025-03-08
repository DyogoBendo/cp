#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

int n;
int check(int i, vector<int> &idx_a, vector<int> &idx_b){
    auto pos_prox_b = lower_bound(idx_b.begin(), idx_b.end(), i);
    if(pos_prox_b == idx_b.end()) return 0;
    int prox_b = *pos_prox_b;                                        

    auto pos_prox_a = lower_bound(idx_a.begin(), idx_a.end(), prox_b);
    int qtd_b =  (pos_prox_a == idx_a.end() ? n : *pos_prox_a) - prox_b; 
    
    int begin_a_qtd = prox_b - i;                             
    if(qtd_b < begin_a_qtd) return 0;

    if(qtd_b == begin_a_qtd)return begin_a_qtd;
    else if(pos_prox_a != idx_a.end()){
        int prox_a = *pos_prox_a;
        auto lst_b_pos = lower_bound(idx_b.begin(), idx_b.end(), prox_a);
        int av = (lst_b_pos == idx_b.end() ? n : *lst_b_pos) - prox_a;        
        if(qtd_b <= av + begin_a_qtd) return qtd_b;
        else return begin_a_qtd;
    }         
}

void solve(){
    cin >> n;
    string s;
    cin >> s;

    vector<int> widx;
    vector<int> bidx;

    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'a') widx.push_back(i);
        else bidx.push_back(i);
    }    

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'b')ans = max(check(i, bidx, widx), ans);
        else ans = max(check(i, widx, bidx), ans);        
    }    
    cout << ans * 2 << endl;    
}

signed main(){
    flash;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}