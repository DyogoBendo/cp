#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;

    cin >> t;
    while(t){
        t --;
        int n, s;        
        cin >> n >> s;
        vector<int> values(n);
        for(int i = 0; i < n; i++) cin >> values[i];
        
        int max = 0;
        for (int possibilities = 0; possibilities < (1 << n) ; possibilities++)
        {
            int total = 0;
            int qtd = 0;
            for (int i = 0; i < n; i++)
            {
                if(possibilities & 1 << i){
                    total += values[i];
                    qtd ++;
                }
            }
            if(total < s) continue;

            int possible = 1;
            for (int i = 0; i < n; i++)
            {
                if(possibilities & 1 << i){
                    if(total - values[i] >= s){
                        possible = 0;
                    }
                }
            }
            if(possible){
                if(qtd > max){
                    max = qtd;
                }
            }
                        
        }
        cout << max << endl;
        
    }
}