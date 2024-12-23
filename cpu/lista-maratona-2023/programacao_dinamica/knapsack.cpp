#include <bits/stdc++.h>

using namespace std;

int main(){
    int s, n;

    vector<vector<int>> table;
    vector<pair<int, int>> size_value;
    cin >> s >> n;

    for(int i = 0; i < n + 1; i++) table.push_back(vector<int>(s + 1));    
    size_value.push_back(make_pair(0, 0));
    for (size_t i = 0; i < n; i++)
    {
        int size, value;

        cin >> size >> value;
        size_value.push_back(make_pair(size, value));
    }
    
    for (size_t i = 1; i <= n; i++)
    {
        auto current = size_value[i];
        int current_size = current.first;
        int current_value = current.second;
        for (size_t j = 1; j <= s; j++)
        {   
            if( current_size <= j){
                table[i][j] = max(table[i - 1][j], table[i - 1][j - current_size] + current_value);
            } else{
                table[i][j] = table[i - 1][j];
            }
        }        
    }
    cout << table[n][s] << endl;
    
}