#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

map<string, int> names = {
    {"Shadow", 6},
    {"Gale", 5},
    {"Ranger", 4},
    {"Anvil", 7},
    {"Vexia", 3},
    {"Guardian", 8},
    {"Thunderheart", 6},
    {"Frostwhisper", 2},
    {"Voidclaw", 3},
    {"Ironwood", 3},
    {"Zenith", 4},
    {"Seraphina", 1},
};

signed main(){
    darvem;

    vector<vector<int>> ponctuation(3, vector<int>(2));
    for (int i = 0; i < 3; i++)
    {        
        for (int j = 0; j < 2; j++)
        {
            int k;
            cin >> k;

            int total = 0, cnt = 0;
            for (int a = 0; a < k; a++)
            {
                string s;
                cin >> s;
                total += names[s];

                if(s == "Thunderheart" && k == 4) total += names[s];
                if(s == "Zenith" && i == 1) total += 5;
                if(s == "Seraphina") cnt++;
            }
            total += (cnt * (k - 1));
            ponctuation[i][j] = total;
        }        
    }

    int p1_wins = 0, p2_wins = 0, p1_total = 0, p2_total = 0;

    for (int i = 0; i < 3; i++)
    {
        int p1 = ponctuation[i][0], p2 = ponctuation[i][1];
        if(p1 > p2) p1_wins ++;
        else if( p1 < p2) p2_wins ++;
        p1_total += p1; p2_total += p2;        
    }

    if(p1_wins == p2_wins && p1_total == p2_total){
        cout << "Tie" << endl;
        return 0;
    }

    cout << "Player " << (p1_wins > p2_wins or (p1_wins == p2_wins && p1_total > p2_total) ? 1 : 2) << endl;
    
}