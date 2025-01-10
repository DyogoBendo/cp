//https://codeforces.com/problemset/problem/632/C
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<string> sl;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        sl.push_back(s);
    }

    sort(sl.begin(), sl.end(), [](const string &s1, const string &s2){
        /*
        int i = 0;
        for (; i < min(s1.size(), s2.size()); i++)
        {
            if(s1[i] < s2[i]) return true;
            if(s1[i] > s2[i]) return false;
        }
        
        i --;
        return s1[i]
        */        
       string x = s1 + s2;
       string y = s2 + s1;
       return x < y;
    });
    
    for (auto &s : sl)
    {
        cout << s;
    }
    cout << endl;
    
}