#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> ap(26, 0);

    for (int i = 0; i < n; i++)
    {
        ap[s[i] - 'a']++;
    }

    int smallest = n + 1;
    int sm_idx = -1;
    int biggest = 0;
    int big_idx = -1;

    for (int i = 0; i < 26; i++)
    {
        if(ap[i] > biggest){
            biggest = ap[i];
            big_idx = i;
        }
        if(ap[i] && ap[i] <= smallest){
            smallest = ap[i]; 
            sm_idx = i;
        }
    }

    // cout << "big idx: " << big_idx << " small idx: " << sm_idx << endl;
    
    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'a' + sm_idx){
            s[i] = 'a' + big_idx;
            break;
        }        
    }    
    cout << s <<endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}