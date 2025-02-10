#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        vector<bool> used(26, false);

        int m = 0;
        int n = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            if(used[s[i] - 'a'] == false) used[s[i] - 'a'] = true;
            else{
                m += 2;
                for (int j = 0; j < 26; j++)
                {
                    used[j] = false;
                }
                
            }
        }
        cout << n - m << endl;
        
    }
}