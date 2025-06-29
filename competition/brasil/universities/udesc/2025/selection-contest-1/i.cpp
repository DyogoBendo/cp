#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<vector<int>> out(26, vector<int>(26, 0)), in(26, vector<int>(26, 0));

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;        
        
        
        char lst = 'Z';
        for (auto c : s)
        {            
            if(lst != c && lst != 'Z'){
                out[c - 'a'][lst - 'a'] = 1;
                in[lst - 'a'][c - 'a'] = 1;

                for (int i = 0; i < 26; i++)
                {                    
                    out[c-'a'][i] = out[c-'a'][i] | out[lst - 'a'][i];
                    in[i][c - 'a'] = in[i][c-'a'] | in[i][lst - 'a'];
                }                                
            }
            
            lst = c;
        }        
    }

    vector<char> ans;

    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        int cntIn = 0, cntOut = 0;
        for (int j = 0; j < 26; j++)
        {
            cntIn += in[i][j];
            cntOut += out[i][j];            
        }

        if(cntOut == 0){            
            q.push(i);            
        }
        
    }

    while(!q.empty()){
        int curr = q.front(); q.pop();
        ans.push_back('a' + curr);        

        for (int i = 0; i < 26; i++)
        {            
            if(in[curr][i]){
                out[i][curr] = 0;
                int cnt = 0;
                for (int j = 0; j < 26; j++)
                {
                    cnt += out[i][j];
                }                

                if(cnt == 0) q.push(i);
            }            
        }
    }
    
    if(ans.size() == 26){
        cout << "SIM" << endl;
        for (auto c : ans)
        {
            cout << c;
        }
        cout << endl;
        
    } else{
        cout << "NAO" << endl;
    }
    
    

}