#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m, w;
    cin >> n >> m >> w;
    set<pair<int, int>> plants;

    for (size_t i = 0; i < n; i++)
    {
        int plant;
        cin >> plant;
        plants.insert(make_pair(plant, i));        
    }
        
    int smaller = plants.begin()->first;
    set<int> indexes;     

    auto it  = plants.begin();

    while(it != plants.end()){
        auto plant = *it;        
        if(plant.first == smaller){
            indexes.insert(plant.second); 
            ++it;
            plants.erase(plant);           
        } else{
            break;
        }
    }    
    
    auto currentPosition = indexes.begin();    
    set<int> breakPoints;

    while (m > 0)
    {
        m --;        

        int currentIndex = *currentPosition;        
        int maximumIndex = currentIndex + w - 1;
        breakPoints.insert(currentIndex);

        auto nextIndex = indexes.upper_bound(maximumIndex);         
        if(nextIndex == indexes.end()){
            smaller ++; 

            auto it = plants.begin();            
            while (it != plants.end())
            {                                
                auto plant = *it;
                int value = plant.first;

                cout << "plant: " << plant.first << " " << plant.second << endl;

                auto lowerBound = breakPoints.lower_bound(plant.second);
                    if(lowerBound != breakPoints.begin()){
                        lowerBound --;   
                        if(plant.second < *lowerBound + w){                                                    
                            auto newPair = make_pair(plant.first + 1, plant.second);                            
                            ++it;
                            plants.erase(plant);
                            plants.insert(newPair);
                            continue;
                        }
                    } 
                
                if( value <= smaller){                    
                    auto lowerBound = breakPoints.lower_bound(plant.second);
                    if(lowerBound != breakPoints.begin()){
                        lowerBound --;   
                        if(plant.second >= *lowerBound + w){                            
                            indexes.insert(plant.second);
                            ++it;
                            plants.erase(plant);
                            continue;
                        }
                    } else{                                                                          
                        indexes.insert(plant.second);
                        ++it;
                        plants.erase(plant);
                        continue;                        
                    }                    
                } else{
                    break;
                }
                ++it;
            }            
                                                         
            currentPosition = indexes.begin();
            breakPoints.clear();
        } else{
            currentPosition = nextIndex;
        }
    }
    
    cout << smaller << endl;

}