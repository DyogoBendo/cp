#include <bits/stdc++.h>

using namespace std;

void solve(int t){
    int n;
    string s;
    cin >> n >> s;

    string m = "map";
    string p = "pie";


    char current = 'z';
    int current_lenght = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {        
        if(current_lenght == 0){
            if(s[i] == 'm' || s[i] == 'p'){
                current = s[i];
                current_lenght = 1;
            }
        } else if(current_lenght == 1){
            if(current == 'm'){
                if(s[i] == 'a'){                    
                    current_lenght = 2;
                } else{
                    if(s[i] == 'm' || s[i] == 'p'){
                        current = s[i];
                        current_lenght = 1;
                    } else{                        
                        current_lenght = 0;
                    }
                    
                }
            } else{
                if(s[i] == 'i'){                    
                    current_lenght = 2;
                } else{
                    if(s[i] == 'm' || s[i] == 'p'){
                        current = s[i];
                        current_lenght = 1;
                    } else{                        
                        current_lenght = 0;
                    }
                }
            }
        } else{
            if(current == 'm'){
                if(s[i] == 'p'){
                    // verificar se o proximo é pie                    
                    count ++;
                    if(i + 3 < n){
                        string pie = s.substr(i, 3);
                        if(pie == "pie"){
                            i += 2;                            
                        } 
                    }                     
                    current_lenght = 0;
                } else{
                    if(s[i] == 'm'){
                        current = s[i];
                        current_lenght = 1;
                    } else{                        
                        current_lenght = 0;
                    }
                } 
            } else{
                if(s[i] == 'e'){                    
                    count ++;                    
                    current_lenght = 0;
                } else{
                    if(s[i] == 'm' || s[i] == 'p'){
                        current = s[i];
                        current_lenght = 1;
                    } else{                        
                        current_lenght = 0;
                    }
                }
            }
        }
    }
        
    cout << count << endl;

}

int main(){
    int t;
    int i = 0;
    cin >> t;

    while(t--){
        i++;
        solve(i);
    }
}