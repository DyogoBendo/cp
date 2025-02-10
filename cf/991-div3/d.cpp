#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin >> s;

    int n = s.size();

    vector<int> s2(n);

    for(int i = 0;i<n;i++) s2[i] = s[i] - '0';

    for (int i = 0; i < n; i++)
    {        
        for (int j = i - 1; j >= 0; j--)
        {            
            if(s2[j] + 1 < s2[j + 1]){
                swap(s2[j], s2[j + 1]);
                s2[j] --;
            } else{
                break;
            }
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        cout << s2[i];
    }

    cout << endl;
    
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}