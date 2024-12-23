#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("measurement");

   int n;
   cin >> n;

    int value[3] = {7, 7, 7};
    int leading = 1 + 3 + 9;

    pair<int, int> days[101]; 
    for (int i = 0; i <= 100; i++)
    {
        days[i] = {0, 0};
    }
       

   for (int i = 0; i < n; i++)
   {
        int day, change, code;
        string cow;

        cin >> day >> cow >> change;
        if(cow == "Mildred") code = 0;
        else if(cow == "Elsie") code = 1;
        else code = 2;

        days[day] = {code, change}; 
   }
       
    int ans = 0;
    for (int i = 1; i <= 100; i++)
    {
        int cow, change;
        cow = days[i].first;
        change = days[i].second;

        value[cow] += change;

        int m = max({value[0], value[1], value[2]});

        int count = 0;
        for (int i = 0; i < 3; i++)
        {
            if(value[i] == m){
                count += pow(3, i);
            }
        }
        
        if(count != leading){
            leading = count;
            ans ++;
        }
    }

    cout << ans << endl;
    
    
    
}