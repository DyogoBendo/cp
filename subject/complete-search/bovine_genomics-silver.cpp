#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("cownomics");

   int n, m;
   cin >> n >> m;

   vector<vector<char>> spotty(n, vector<char>(m));
   vector<vector<char>> plain(n, vector<char>(m));   

   for (int i = 0; i < n; i++)
   {
    for (int j = 0; j < m; j++)
    {
        cin >> spotty[i][j];
    }
    
   }
   
   for (int i = 0; i < n; i++)
   {
    for (int j = 0; j < m; j++)
    {
        cin >> plain[i][j];
    }
    
   }

   int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            for (int k = j + 1; k < m; k++)
            {
                set<string> sp;
                set<string> pp;
                for (int l = 0; l < n; l++)
                {                    
                    sp.insert(string()+ spotty[l][i] + spotty[l][j] + spotty[l][k]);
                    pp.insert(string()+ plain[l][i] + plain[l][j] + plain[l][k]);
                }                                
                int intersect = 1;
                for (string word : sp)
                {                    
                    if(pp.count(word)){
                        intersect = 0;
                        break;
                    }
                }                
                count += intersect;
            }
            
        }
        
    }
    
    cout << count << endl;
}