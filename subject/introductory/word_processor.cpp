/*
USACO 2020 January Contest, Bronze
Problem 1. Word Processor
*/

#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("word");

    int n, k;
    cin >> n >> k;

    vector<string> words;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;        
        words.push_back(s);
    }




    int current_value = 0;
    int i = 0;
    while(i < n)
    {
        string ans = "";

        while(i < n && current_value + words[i].length() <= k){            
            ans += words[i] + " ";
            current_value += words[i].length();
            i++;
        }
        cout << ans.substr(0, ans.length() - 1) << endl;
        current_value = 0;
    }
    
    
    
}