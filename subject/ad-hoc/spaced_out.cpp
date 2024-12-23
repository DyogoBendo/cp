#include <bits/stdc++.h>

using namespace std;
const int N = 1e3;

int m[N][N];
int n;

int check(int a){    
    // a: se 0, indica que vamos alternar colunas, se 1 indica que vamos alternar linhas
    int ans = 0;

    if(a == 0){
        for (int j = 0; j < n; j++)
        {
            int tmp = 0;
            for (int k = 0; k < 2; k++)
            {                
                int curr = 0;
                for (int i = 0; i < n; i++)
                {
                    if(i % 2 == k) curr += m[i][j];
                }
                tmp = max(curr, tmp);
            }            
            ans += tmp;
        }        
    } else{
        for (int i = 0; i < n; i++)
        {
            int tmp = 0;
            for (int k = 0; k < 2; k++)
            {                
                int curr = 0;
                for (int j = 0; j < n; j++)
                {
                    if(j % 2 == k) curr += m[i][j];
                }
                tmp = max(curr, tmp);
            }            
            ans += tmp;
        }        
    }
    
    return ans;
}

int main(){
    cin >> n;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }        
    }

    // podemos começar na primeira posição pegando ou não pegando ele. E para cada opção, escolher alternar linhas ou colunas
    
    for (int i = 0; i < 2; i++)
    {
        ans = max(ans, check(i));   
    }


    cout << ans << endl;
    
}