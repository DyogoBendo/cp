#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int l = 0;
    for (int i = 0; i < k; i++)
    {
        vector<int> move(n, 0);
        bool possible = true;        
        for (int j = 0; j < n - 1; j++)
        {
            if(s[j] == '#'){
                if(j + 1 == n - 1) possible = false;
                move[j] = 1;
                if(s[j + 1] == 'o') move[j+1] = 1;
            } 
            if(s[j] == 'o' && move[j] && j + 1 == n-1) possible = false;
            if(s[j] == 'o' && move[j] && s[j+1] == 'o') move[j+1] = 1;            
        }

        if(possible){            
            for (int j = n - 2; j > 0; j--)
            {            
                if(move[j - 1]){                    
                    s[j] = s[j - 1];
                } 
    
            }   
            s[i] = '.';        
        }        
    }

    cout << s << endl;
    
}