#include <bits/stdc++.h>

using namespace std;

int* compute_pi(const string &t) {

    int m = t.size();
    int *pi = new int[m + 1];
    if (0 <= m) pi[0] = 0;
    if (1 <= m) pi[1] = 0;
    for (int i = 2; i <= m; i++) {
        for (int j = pi[i - 1]; ; j = pi[j]) {
            if (t[j] == t[i - 1]) {
                pi[i] = j + 1;
                break;
            }
            if (j == 0) {
                pi[i] = 0;
                break;
            }
        }
    }

    return pi;
}

int main(){
    string s;
    string t;
    cin >> s >> t;

    int * pi = compute_pi(t);
    int ans = 0;
    int p = 0;    
    int t_to_s[26];

    int t_defined[26];

    for (int i = 0; i < 26; i++)
    {
        t_to_s[i] = -1;
        t_defined[i] = t.length() + 1;
    }
    

    for (int i = 0, j = 0; i < s.size(); )
    {       

        cout << "i, j: " << i << " " << j << endl; 
        int sp = s[i] - 'a';
        int tp = t[j] - 'a';
        if(t_to_s[tp] == -1){            
            t_to_s[tp] = sp;
            t_defined[tp] = j; 
            i ++;
            j++;
        } else if(sp == t_to_s[tp]){
            i ++;
            j ++;
        } else{
            j = pi[j];
            for (int i = 0; i < 26; i++)
            {
                if(t_defined[i] >= j){
                    t_defined[i] = -1;
                    t_to_s[i] = -1;
                }
            }            
        }                

        if(j == t.size()){
           j = pi[j];
           ans ++;
           p = i; 
        }   
    }
    
    
    if(ans != 1) cout << ans << endl;
    else{
        for (int i = p - t.size(); i < p; i++)
        {
            cout << s[i];
        }
        cout << endl;
    }
}