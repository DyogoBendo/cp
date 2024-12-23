#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int contagem = 0;
    for (int k = 0; k < n; k++)
    {
        cout << k << endl;
        string entrada;
        getline(cin, entrada);

        string current_word = "";
        int lastNumber = -1;
        int activeNumber = 0;
        int count = 0;
        char last = ' ';
        for (int j = 0; j < entrada.length(); j++)
        {            
            if(entrada[j] - '0' >= '0' && entrada[j] - '9' <= '0'){
                activeNumber = 1;
                if(last == ' ' || last == ',' || last == '.' || (last - '0' >= '0' && last - '9' <= '0') && activeNumber){
                    current_word += entrada[j];
                }
            } else{
                if(entrada[j] == ' ' ||  entrada[j] == ',' || entrada[j] == '.'){
                    if (!(last - '0' >= '0' && last - '9' <= '0')){
                        if(activeNumber){
                            if(lastNumber == -1){
                                lastNumber = stoi(current_word);
                                count = 1;
                            } else{
                                if(stoi(current_word) == lastNumber + 1){
                                    count ++;
                                    lastNumber = stoi(current_word);
                                }
                            }
                        }
                        current_word = "";
                        activeNumber = 0;
                    }
                }
            }

            last = entrada[j];
        }

        if(count >= 3){
            contagem = 1;
        }
        
    }

    if(contagem){
        cout << "123" << endl;
    } else{
        cout << ":)" << endl;
    }

       
}