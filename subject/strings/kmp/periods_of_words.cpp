#include <bits/stdc++.h>

using namespace std;

#define int long long

int * calculate_pi(string &s){
    int n = s.size();
    int *pi = new int[n + 1];

    pi[0] = 0;
    pi[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        for(int j = pi[i - 1];;j = pi[j]){            
            if(s[j] == s[i - 1]){                
                pi[i] = j + 1;
                break;
            }

            if(j == 0){
                pi[i] = 0;
                break;
            }
        }
    }

    return pi;
    
}


signed main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int*pi = calculate_pi(s);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int k = i + 1;
        if(pi[k] == 0) continue;
        if(pi[pi[k]] != 0) pi[k] = pi[pi[k]];        
        ans += (i - pi[k]) + 1;
        
    }
    cout << ans << endl;
}