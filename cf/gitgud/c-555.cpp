#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int curr = 0;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int i = 0;
    int j = n - 1;

    int t = 0;
    string ans;

    while(t < n && i <= j){
        if(v[i] > curr){
            if(v[i] <= v[j] || v[j] < curr){
                ans += 'L';
                curr = v[i];
                i ++;
                t++;
            } else{
                ans += 'R';
                curr = v[j];
                j --;
                t++;
            }
        } else if(v[j] > curr){
            ans += 'R';
            curr = v[j];
            j --;
            t++;
        } else{
            break;
        }
    }
    cout << t << endl << ans << endl;
}