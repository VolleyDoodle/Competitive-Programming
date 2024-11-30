#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);
    int n;
    cin >> n;
    vector <pair <int, int>> particles(n);
    for (int i = 0; i < n; i++){
        cin >> particles[i].first >> particles[i].second;
    }
    sort(particles.begin(), particles.end(), []
        (auto& a, auto& b){
            if (a.first == b.first){
                return a.second < b.second;
            }
            return a.first < b.first;
        }
    );

    //use upper_bound b/c y-vals can be equal
    vector <int> yCords;
    yCords.push_back(particles[0].second);
    for (int i = 1; i < n; i++){
        //as we go through the list
        //it is GUARENTEED that this current particle X cord is greater 
        //so just store all the y cords and see where this current can fit 
        //then delete all the y cords that fit in this current one execpt the least y
        //can delete all others because the least y encompasses all the others
        auto pos = upper_bound(yCords.begin(), yCords.end(), particles[i].second);
        //if pos == .end() then nothing was found and this y-pos is greatest
        //so everything is one big connected componenet (so far)
        if (pos == yCords.begin()){
            yCords.insert(yCords.begin(), particles[i].second);
        } else{
            while (pos != yCords.begin() + 1){
                pos--;
                yCords.erase(pos);
                
                //make sure to not delete the begin() (which is why pos-- is after) (or can do just +1)
            }
        }

    }
    cout << yCords.size();
}