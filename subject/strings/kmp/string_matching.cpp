#include <bits/stdc++.h>

using namespace std;

vector<int> compute_pi(string &p){
    int n = p.size();
    vector<int> pi (n + 1, 0);
    pi[0] = 0;
    pi[1] = 0;

    for (int i = 1; i < n; i++)
    {
        for(int j = pi[i];; j = pi[j]){            
            if(p[j] == p[i]){                
                pi[i + 1] = j + 1;
                break;
            } else{
                if(j == 0){
                    break;
                }
            }
        }
    }

    return pi;
    
}

int main(){
    string s;
    string p;
    cin >> s >> p;

    int n = s.length();
    int m = p.length();

    vector<int> pi = compute_pi(p);

    int ans = 0;

    for (int i = 0, j = 0; i < n; )
    {               
        if(s[i] != p[j] && j == 0){
            i ++;
        }
        else if(s[i] == p[j]){               
            i ++;
            j ++;
        } else{            
            j = pi[j];                                                      
        }

        if(j == m){
            j = pi[j];
            ans ++;
        }
    }

    cout << ans << endl;
    
}