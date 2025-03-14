#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'


void solve(){
    string s;
    cin >> s;

    int n = s.size();    

    for (int i = 0; i < n - 1; i)
    {
        int curr = 0;
        int j = i + 1;
        while(j < n && s[i] == s[j]){
            if((i % 2) ^ (j % 2)){                
                for (int k = 0; k < 26; k++)
                {
                    char c = 'a' + k;                                        
                    if(s[i] == c || (j < n - 1 && s[j + 1] == c)) continue;                    
                    s[j] = c;
                    break;
                }
            }
            j++;
        }      
        i = j;   
    }
    
    cout << s << endl;
}

signed main(){
    darvem;
    int t = 1;    

    while(t--) solve();
}