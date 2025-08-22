#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> cards_prev(m + 1);
    vector<int> cards_ans(m + 1);    

    while(k--){
        int p, c;
        cin >> p >> c;

        if(cards_prev[c]){
            cards_ans[c] += cards_prev[c] == p ? 100 : abs(cards_prev[c] - p);
            cards_prev[c] = 0;
        } else{
            cards_prev[c] = p;            
        }
        
    }

    for (int i = 1; i <= m; i++)
    {
        if(cards_prev[i]) cards_ans[i] += 100;

        cout << cards_ans[i] << " ";
    }
    cout << endl;
    
}