#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("breedflip");

    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    int ans =0;
    for (int i = 0; i < n;)
    {   
        int j = i;
        while(s1[j] != s2[j] && j < n){
            j ++;
        }    
        if(j != i){
            ans ++;
            i = j;
        } else{
            i ++;
        }   
    }

    cout << ans << endl;
    
}