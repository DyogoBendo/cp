#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, test = 1;
    cin >> n;
    while(n){
        string word;
        cin >> word;
        vector<vector<int>> palindrome (n, vector<int>(n, 0));        

        for (int i = 0; i < n; i++)
        {            
            palindrome[i][i] = 1;            
        }

        for (int i = 1; i < n; i++)
        {
            palindrome[i - 1][i] = word[i - 1] == word[i];
        }
        for (int i = n - 3; i >=0; i--)      
        {
            for (int j = i + 2; j < n; j++)
            {
                palindrome[i][j] = word[i] == word[j] & palindrome[i + 1][j - 1];
            }            
        }

        // vamos calcular em quantas partes precisamos dividir a palavra até o index i
        vector<int> parts (n, 0);
        for (int i = 0; i < n; i++)
        {
            // se tivermos um palindromo na palavra até i, significa que precisamos dividir em apenas uma parte
            if(palindrome[0][i]) {
                parts[i] = 1;
            } else{
                int min = n + 1; // iniciamos minimo com o valor maior que o maior valor possível, que seria dividir em n partes                
                for (int j = 1; j <= i; j++)
                {                    
                    if(palindrome[j][i] && parts[j - 1] < min){ // se formamos um palindromo de j até i, o que torna possível essa divisão, então verificamos em quantas partes partes precisamos dividir a plavra até j - 1                        
                        min = parts[j - 1]; // iremos sempre pegar a menor divisão que encontrarmos
                    
                    }
                }

                parts[i] = min + 1; // somamos um, pois pegamos todas as divisões que fazemos até j - 1, e somamos 1 que é o palindromo de j até i.
                

            }
        }
        
        cout << "Teste " << test <<endl;
        cout << parts[n - 1] << endl << endl;
        
        test ++;
        cin >> n;
    }
    

}