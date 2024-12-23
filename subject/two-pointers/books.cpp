#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, t;
    cin >> n >> t;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int current = numbers[0];
    int i = 0;
    int j = 0;

    int ans = 0;
    while(j < n){                
        if(current < t){
            ans = max(ans, j - i + 1);
            j++;
            if(j < n){
                current += numbers[j];
            }
        } else if (current == t){
            current -= numbers[i];
            i ++;
            j ++;
            if(j < n){
                current += numbers[j];
            }
        } else{
            current -= numbers[i];
            i ++;
            if(i > j){
                j = i;
                if(j < n) current += numbers[j];
            }
        }
    }
    
    cout << ans << endl;
}