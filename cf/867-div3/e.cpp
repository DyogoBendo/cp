#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){                  
        string s;
        int n;
        cin >> n >> s;


        if(n % 2){
            cout << - 1 << endl;
        } else{
            vector<int> count(26, 0);        

            for (int i = 0; i < n; i++)
            {
                count[s[i] - 'a'] ++;
            }
            
            int p = 1;
            for(int i = 0; i < 26; i ++){
                if(count[i] > n/2){
                    cout << -1 << endl;
                    p = 0;
                    break;
                }
            }
            if(!p) continue;
        
            vector<int> pair_count(26, 0);
            int pair_total = 0;
            for (int i = 0; i < n/2; i++)
            {
                if(s[i] == s[n - i - 1]){
                    pair_total ++;
                    pair_count[s[i] - 'a'] ++;
                }
            }

            int a = 0;
            for (int i = 0; i < 26; i++)
            {
                if(2 * pair_count[i] > pair_total){
                    a = pair_count[i];
                }
            }
            
            if(!a) a = (pair_total + 1) / 2;

            cout << a << endl;
            
        }        
        
    }
}