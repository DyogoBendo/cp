#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("lineup");
    int n;
    cin >> n;
    
    vector<pair<string, string>> besides;
    for (int i = 0; i < n; i++)
    {
        string a, b1, b2, b3, b4, c;
        cin >> a >> b1 >> b2 >> b3 >> b4 >> c;

        besides.push_back({a, c});
    }
    
    string cows[] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

    sort(cows, cows + 8);

    int possible = 0;

    while (1)
    {
        int possible_case = 1;
        for (int j = 0; j < 8; j++)
        {
            string left="none", right = "none", current;
            if(j > 0) left = cows[j - 1];
            if(j < 7) right = cows[j + 1];
            current = cows[j];
            for (int i = 0; i < n; i++)
            {
                string first = besides[i].first, second = besides[i].second;

                if(first == current){
                    if(second != left && second != right) possible_case = 0;
                } else if (second == current)
                {
                    if(first != left && first != right) possible_case = 0;
                }                
            }
        }
        
        if(possible_case) break;

        next_permutation(cows, cows + 8);
    }
    
    for (string cow : cows)
    {
        cout << cow << endl;
    }
    

    
}