#include <bits/stdc++.h>

using namespace std;

int main(){
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

    int left = 0;
    int right = n - 1;
    int a1, a2;
    while(!possible && values[left] != values[right]){
        int current = values[left].first + values[right].first;
        if( current == x){
            possible = 1;
            a1 = values[left].second;
            a2 = values[right].second;
        } else if(current > x){
            right--;
        } else{
            left++;
        }
    }
    
    if(possible){
        cout << a1 << " " << a2 << endl;
    } else{
        cout << "IMPOSSIBLE" << endl;
    }
}