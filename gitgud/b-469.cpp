#include <bits/stdc++.h>

using namespace std;

string s;
vector<string>v[26];
int aparece[26];
int main(){
    cin >> s;

    int n = s.length();


    for (int i = 0; i < n; i++)
    {
        int comeco = s[i] - 'a';

        string tmp = "";

        for (int j = 0; j < n; j++)
        {
            tmp += s[(i + j) %n];
        }
        
        v[comeco].push_back(tmp);
    }
    
    long double favor = 0;

    for (int i = 0; i < 26; i++)
    {        
        vector<string> current_words = v[i];        

        long double cases = current_words.size();
        if(cases == 0) continue;
        
        long double mx = 0;
        for (int j = 0; j < n; j++)
        {        
            for (int k = 0; k < 26; k++)
            {
                aparece[k] = 0;
            }
            
            for (int k = 0; k < cases; k++)
            {
                aparece[current_words[k][j] - 'a'] ++;
            }

            long double curr = 0;
            for (int j = 0; j < 26; j++)
            {
                if(aparece[j] == 1) curr ++;
            }

                        
            mx = max(mx, curr);
        }
                
        favor += (mx);
    }

    long double ans = favor / n;

    printf("%.12Lf\n",ans);
    
}