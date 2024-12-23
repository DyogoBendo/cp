#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;

    cin >> n >> k;
    vector<int> colors;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        x --;
        colors.push_back(x);
    }

    int start_color = colors[0];
    int count = 0;
    int end_index = 0;
    for (int i = 0; i < n; i++)
    {
        if(count == k) break;
        if(colors[i] == start_color){
            count ++;
            end_index = i;
        }
    }
    
    if(count != k){
        cout << "NO" << endl;
        return;
    }

    if(colors[n - 1] == start_color){
        cout << "YES" << endl;
        return;
    }
    
    int count_last = 0;
    int last_color = colors[n - 1];
    for (int i = n - 1; i > end_index; i--)
    {        
        if(count_last == k) break;
        if(colors[i] == last_color){
            count_last ++;
        }
    }
    if(count_last == k){
        cout << "YES" << endl;
    }  else{
        cout << "NO" << endl;
    }
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}