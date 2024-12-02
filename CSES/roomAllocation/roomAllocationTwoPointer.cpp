#include <bits/stdc++.h>
using namespace std;
//two
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
    
    int left = 0, right = 0;
    queue <int> roomsEmpty;
    int maxGap = 0;
    while (right < n){
        
       
        while (cust[right][0] > cust[left][1]){
            roomsEmpty.push(roomOcc[cust[left][2]]);
            left++;
        }
        maxGap = max(maxGap, right - left + 1);
        if (roomsEmpty.empty()){
            roomOcc[cust[right][2]] = maxGap;
        } else{
            int newRoom = roomsEmpty.front();
            roomsEmpty.pop();
            roomOcc[cust[right][2]] = newRoom;
        }
        right++;

    }
    cout << maxGap << "\n";
    for (int& i : roomOcc){
        cout << i << " ";
    }

}