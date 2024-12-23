#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main(){
    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> values(n);
    for (int i = 0; i < n; i++)
    { 
        values[i].second = i + 1;
        cin >> values[i].first;
    }

    sort(values.begin(), values.end());

    int possible = 0;


    for (int i = 0; i < n; i++)
    {        
        int target = x - values[i].first;
        int left = 0;
        int right = n - 1;              

        while(i != left && i != right && left < right){            
            int current = values[left].first + values[right].first;            
            if(current == target){
                cout << values[left].second << " " << values[i].second << " " << values[right].second << endl;
                return 0;
            }
            if(current > target){
                right--;
            } else{
                left++;
            }
        }
    }
    

    
    cout << "IMPOSSIBLE" << endl;
    
}