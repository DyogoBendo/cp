#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> deck(n);

    for (int i = 0; i < n; i++)
    {
        cin >> deck[i];
    }

    sort(deck.begin(), deck.end());

    vector<int> count;
    vector<int> values;
    
    int curr = -1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(deck[i] != curr){
            if(curr != -1){
                count.push_back(cnt);
                values.push_back(curr);
            } 
            curr = deck[i];
            cnt= 1;
        } else{
            cnt ++;
        }
    }
    count.push_back(cnt);
    values.push_back(curr);

    int ans = 0;
    int tmp_ans = 0;
    int qtd_diff = count.size();
    int i = 0, j = 0;
    cnt = 0;
    
    while(j < qtd_diff){        
        if(cnt < k){            
            if(j > 0 && values[j] == values[j - 1] + 1){
                tmp_ans += count[j];         
            } else{
                i = j;
                tmp_ans = count[j];
                cnt = 0;
            }
            cnt ++;   
            j ++;
        } else{
            tmp_ans -= count[i];
            i ++;
            cnt --;
        }
        //cout << "i: " << i << " j: " << j << " cnt: " << cnt << " tmp ans: " << tmp_ans << endl;
        ans = max(ans, tmp_ans);
    }

    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}