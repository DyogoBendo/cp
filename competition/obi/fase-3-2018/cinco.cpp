#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> d(n);
    int first_zero = -1;
    int first_five = -1;
    int last_five = -1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x == 0 && first_zero == -1) first_zero = i;
        if(x == 5 && first_five == -1) first_five = i;
        if(x == 5 && first_five != -1) last_five = i;
        d[i] = x;
    }

    int lst = d[n - 1];
    if(first_zero == - 1 && first_five == -1){
        cout << -1 << endl;
        return 0;
    } 
    if(lst > 5){        
        int p = min(first_zero, first_five);
        swap(d[p], d[n - 1]);
    } else{
        if(first_zero != -1) swap(d[first_zero], d[n - 1]);
        else swap(d[last_five], d[n - 1]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << d[i];
        if(i < n - 1) cout << " ";
    }
    cout << endl;
       
}