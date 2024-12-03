#include <bits/stdc++.h>
using namespace std;
//two pointers will NOT work
//why?
//because of nested while()
//see example, (1, 4), (2, 2) -> should go to 2, but stops at 4
//cant sort by ending cuz then screws up everything else
int main(){
    
    int n;
    cin >> n;
    vector <vector <int>> cust(n, vector <int>(3));
    vector <int> roomOcc(n, 0);
    for (int i = 0; i < n; i++){
        cin >> cust[i][0] >> cust[i][1];
        cust[i][2] = i;
    }
    sort(cust.begin(), cust.end());
    
    int  right = 0;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <>> endTimes;
    queue <int> roomsEmpty;
    int maxGap = 0;
    //definitly could use for loop
    //just used two-pointer code slightly modified and kept while loop
    while (right < n){
        endTimes.push({cust[right][1], cust[right][2]});
        //handle right++ first
        while (cust[right][0] > endTimes.top().first){
            roomsEmpty.push(roomOcc[endTimes.top().second]);
            endTimes.pop();
        }
        maxGap = max(maxGap, (int)endTimes.size());
        if (roomsEmpty.empty()){
            roomOcc[cust[right][2]] = maxGap;
        } else{
            roomOcc[cust[right][2]] = roomsEmpty.front();
            roomsEmpty.pop();
        }
        
        right++;
       
    }
    cout << maxGap << "\n";
    for (int& i : roomOcc){
        cout << i << " ";
    }

}