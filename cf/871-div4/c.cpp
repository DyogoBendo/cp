#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>> books;
        vector<int> current_v;
        vector<int> current_m;

        for (int i = 0; i < n; i++)
        {
            int m, v;
            cin >> m >> v;

            books.push_back({m, v});
        }        

        int best_a = 0;
        int best_b = 0;

        int visited_1 = 0, visited_2 = 0, visited_3 = 0;

        sort(books.begin(), books.end());

        for (int i = 0; i < n; i++)
        {
            if(books[i].second == 1 && !visited_1){
                visited_1 = 1;
                best_a += books[i].first;
            }
            if(books[i].second == 10 && !visited_2){
                visited_2 = 1;
                best_a += books[i].first;
            }
            if(books[i].second == 11 && !visited_3){
                visited_3 = 1;
                best_b += books[i].first;
            }         
            
        }        
        
        if(!visited_3) best_b = best_a + 1;
        if(!(visited_1 && visited_2)) best_a = best_b + 1;
        int r = (visited_1 && visited_2) || visited_3 ? min(best_a, best_b) : -1;
        
        cout << r << endl;
        
    }
}