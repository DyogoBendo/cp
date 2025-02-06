// https://codeforces.com/contest/633/problem/B

#include <bits/stdc++.h>
using namespace std;

int log5(int k){
    int ans = 0;    
    int x = 5;
    while(k){
        if(k % x != 0) return ans;
        x *= 5;
        ans ++;        
    }
    cout << endl;
    return ans;
}

int main(){    
    int m;
    cin >> m;

    // para ter 0, o número precisa ser multiplicado por 10! Para ele ser multiplicado por 10 ele precisa ter fator 2 e 5, como todos os pares tem fator 2, o problema gira em torno da ocorrencia de 5!
    /*
        5 -> 1 (1 zero)        
        10 -> 1 (2 zeros)
        15 -> 1 (3 zeros)
        20 -> 1 (4 zero)
        25 -> 2 (6 zeros)
        30 -> 1 (7 zeros)
        ...
        50 -> 2
        ...
        75 -> 2
        ...
        100 -> 2
        ...
        125 -> 3 (25 * 5 = 5 * 5 * 5)
    */

   int possible = 1;
   int found = 0;
   int i = 0;
   int qtd_0 = 0;
   while(!found && possible){
        //cout << "i: " << i << " qtd_0: " << qtd_0 << endl;
        if(qtd_0 == m){
            found = true;
        } else if(qtd_0 > m){
            possible = false;
        } else{
            i+=5;
            qtd_0 += log5(i);
        }
   }
   
   if(possible){
    cout << 5<< endl;
        for (int k = i; k < i + 5 ; k++)
        {
            cout << k << " ";
        }
        cout << endl;        
   } else{
    cout << 0 << endl;
   }
}