#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("guess");
    int n;
    cin >> n;
    vector<vector<string>> ch (n);

    for (int i = 0; i < n; i++)
    {
        string s;
        int k;
        cin >> s >> k;
        for (int j = 0; j < k; j++)
        {
            string desc;
            cin >> desc;
            ch[i].push_back(desc);
        }
        
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int tmp = 0;
            for (int l = 0; l < ch[i].size(); l++)
            {
                int match = 0;
                for (int m = 0; m < ch[j].size(); m++)
                {
                    if(ch[j][m] == ch[i][l]){
                        match = 1;
                        break;
                    }
                }

                tmp += match;
            }
            ans = max(ans, tmp);
            
        }   
    }
    
    cout << ans + 1 << endl;

    
}