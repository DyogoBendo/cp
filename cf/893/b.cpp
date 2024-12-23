#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> sellers(m);
    vector<int> eat_points;
    eat_points.push_back(1);

    for (auto &s: sellers)
    {
        int x;
        cin >> x;
        s = x;
        eat_points.push_back(x);
    }
    
    eat_points.push_back(n);    

    int total_cookies = 0;
    for (int i = 1; i <= m + 1; i++)
    {        
        if(eat_points[i] == 1) total_cookies --;
        total_cookies ++;
        int previous_dist = eat_points[i - 1];        
        if(eat_points[i] - previous_dist > d){
            total_cookies += (eat_points[i] - previous_dist) / d;
        }

        if(eat_points[i] - previous_dist == d && i == m + 1){
            total_cookies ++;
        }
    }

    vector<int> ans;
    int ans_qttd = 0;
    int current_ans = total_cookies + total_cookies; 

    cout <<  "total de cookies! " << total_cookies << endl;

    for (int i = 1; i < m + 1; i++)
    {
        int previous_dist = eat_points[i] -  eat_points[i - 1];
        int next_dist = eat_points[i + 1] - eat_points[i];        

        int current_subtotal = ((previous_dist - 1) / d) + ((next_dist - 1) / d) + 1;
        int end_factor = eat_points[i] == n ? 0 : -1;
        int start_factor = eat_points[i] == 1 ? 1 : 0;
        int remove_subtotal = ((previous_dist + next_dist + end_factor) / d) + start_factor;
        int current_cookies = total_cookies - (current_subtotal - remove_subtotal);
        cout << "current subtotal: " << current_subtotal <<  " remove subtotal: " << remove_subtotal << endl;
        cout << "elemento atual: " << i << endl;
        cout << "valor de cookies atual: " << current_cookies << endl;
        cout << endl;

        if(current_cookies < current_ans){
            ans_qttd = 1;
            current_ans = current_cookies;
        } else if(current_cookies == current_ans){
            ans_qttd ++;
        }
    }
    
    cout << current_ans << " " << ans_qttd;
    
    cout << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}