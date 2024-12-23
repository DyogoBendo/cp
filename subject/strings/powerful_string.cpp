#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<int>> pos(26);

    for (int i = 0; i < n; i++)
    {
        pos[s[i] - 'a'].push_back(i);
    }
    

    int q;
    cin >> q;

    while(q--){
        int l, r;
        cin >> l >> r;
        l --; r--;

        vector<int> ocr(26), frst(26, -1), last(26, -1);

        for (int c = 0; c < 26; c++)
        {
            auto ub = upper_bound(pos[c].begin(), pos[c].end(), r) - pos[c].begin();
            auto lb = lower_bound(pos[c].begin(), pos[c].end(), l) - pos[c].begin();

            ocr[c] = ub - lb;

            if(ocr[c]){
                frst[c] = pos[c][lb];
                last[c] = pos[c][ub - 1];
            }
        }

        bool found = false;

        for (int c1 = 0; c1 < 26; c1++){
            if(ocr[c1]){
                for (int c2 = 0; c2 < 26; c2++)
                {
                    if(ocr[c2] > ocr[c1]){
                        if(frst[c2] < last[c1]) found = true;
                    }
                }
                
            }
        }        
        
        cout << (found? "YES": "NO") << endl;
        
    }
}