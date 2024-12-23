#include <bits/stdc++.h>

using namespace std;


int cards[4];
int used[4];

int ans;
int k;

int perm[4];

int calculate(int op, int a, int b){
    switch (op)
    {
    case 0:
        return a + b;
        break;
    case 1:
        return a - b;
        break;
    case 2:
        return a * b;
        break;
    case 3:
        if(b != 0 && a % b == 0){            
            return a / b;
        }
    default:
        return INT32_MIN;
        break;
    }
}

void solve(int current){    
    if(current == 4){
        
        for (int op1 = 0; op1 < 4; op1++)
        {
            for(int op2 = 0; op2 < 4; op2++){
                for (int op3 = 0; op3 < 4; op3++)
                {
                    int first = calculate(op1, perm[0], perm[1]);

                    if(first == INT32_MIN) continue;

                    int second = calculate(op2, first, perm[2]);   
                    if(second == INT32_MIN) continue;

                    int third = calculate(op3, second, perm[3]);   
                    if(third == INT32_MIN) continue;

                    if(third > ans && third <= 24){
                        ans = third;
                    }
                }
                
            }
        }

        for (int op1 = 0; op1 < 4; op1++)
        {
            for(int op2 = 0; op2 < 4; op2++){
                for (int op3 = 0; op3 < 4; op3++)
                {
                    int first = calculate(op1, perm[0], perm[1]);

                    if(first == INT32_MIN) continue;

                    int second = calculate(op2, perm[2], perm[3]);   
                    if(second == INT32_MIN) continue;
                    
                    int third = calculate(op3, first, second);   
                    if(third == INT32_MIN) continue;

                    if(third > ans && third <= 24){
                        ans = third;
                    }
                }
                
            }
        }
        return;
    }
    
    for (int i = 0; i < 4; i++)
    {
        if(!used[i]){
            used[i] = 1;
            perm[current] = cards[i];
            solve(current + 1);
            used[i] = 0;
        }
    }
    
}


int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        ans = 0;
        k = 0;
        for (int j = 0; j < 4; j++)
        {
            cin >> cards[j];
        }
                
        solve(0);
        cout << ans << endl;
    }
    
}