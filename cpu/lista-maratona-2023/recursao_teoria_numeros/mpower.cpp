    #include <bits/stdc++.h>

    using namespace std;

    #define MOD 1000000007LL
    void calculaMatriz(long long int matrizFinal [50][50], long long int matrizOriginal [50][50], int m){
        long long int matrizTemp[50][50];

        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < m; j++)
            {           
                long long int temp = 0; 
                for (size_t k = 0; k < m; k++)
                {
                    temp += ((matrizFinal[i][k] % MOD)  * (matrizOriginal[k][j] % MOD)) % MOD;
                    
                }   
                matrizTemp[i][j] = temp % MOD;          
            }        
        }
        

        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < m; j++)
            {
                matrizFinal[i][j] = matrizTemp[i][j];
            }
            
        }
        
    }

    int main(){
        int t;

        cin >> t;    
        for (size_t i = 0; i < t; i++)
        {
            int n, m;
            cin >> m >> n;

            long long int matrix [50][50];

            for (size_t j = 0; j < m; j++)
            {
                for (size_t k = 0; k < m; k++)
                {                                        
                    scanf("%dll", &matrix[j][k]);
                }            
            }

            long long int initialMatrix [50][50] = {0};
            
            for (size_t i = 0; i < m; i++)
            {
                initialMatrix[i][i] = 1;
            }
            
            while (n)
            {            
                if( n & 1){                
                    calculaMatriz(initialMatrix, matrix, m);
                    n --;
                } else{
                    calculaMatriz(matrix, matrix, m);
                    n >>= 1;
                }
            }
            

            for (size_t j = 0; j < m; j++)
            {
                for (size_t k = 0; k < m; k++)
                {                
                    cout << initialMatrix[j][k] << " ";
                    
                }            
                cout << endl;
            }
            
        }
        
    }