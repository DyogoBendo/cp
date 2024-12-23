#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> grid;

    for (int i = 0; i < n; i++)
    {
        vector<int> line;
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {            
            line.push_back(s[j] == '1');
        }

        grid.push_back(line);        
    }
    

    int is_square = 0;
    int previous_1 = 0;
    for (int i = 0; i < n; i++)
    {
        int number_1 = 0;
        for (int j = 0; j < n; j++)
        {            
            if(grid[i][j] == 1) number_1 ++;
        }        
        
        if(number_1 == previous_1 && number_1 != 0) is_square = 1;
        previous_1 = number_1;
    }
    

    if(is_square) cout << "SQUARE" << endl;
    else cout << "TRIANGLE" << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
}