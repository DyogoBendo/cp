#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("evolution");

    int n;
    cin >> n;

    vector<vector<string>> features(n, vector<string>());

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++)
        {
            string s;
            cin >> s;
            features[i].push_back(s);
        }
        
    }

    vector<vector<int>> commons(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool share = false;
            for (auto a : features[i])
            {
                for (auto b: features[j])
                {
                    if(a == b) share = true;
                }
                
            }
            if(share){
                commons[i].push_back(j);
                commons[j].push_back(i);
            }            
        }        
    }

    bool possible = 1;

    for (int i = 0; i < n; i++)
    {
        for (auto c : commons[i])
        {            
            for (auto a : commons[c])
            {
                if(a == i) continue;
                bool found = false;
                for(auto b : commons[i]){
                    if(a == b) found = true;
                }
                if(!found) possible = false;
            }
            
        }        
        
    }

    possible ? cout << "yes" : cout << "no";
    cout << endl;
    
}