

#include <iostream>
#include <cmath>
using namespace std;
int algo(int room_height[], int first_table[], int second_table[], int i) {
    int first = 100000001, second = 100000001;
    if (first_table[i + 2] - first_table[i] + second_table[i] <= room_height[i]) {
        if (room_height[i] - first_table[i + 2] >= second_table[i]) { first = 0;}
        else { first = second_table[i] - (room_height[i] - first_table[i + 2]); }
        //cout << "first: " << first << endl;
        if (first_table[i] >= second_table[i]) { second = 0; }
        else { second = second_table[i] - first_table[i]; }
        //cout << "second: " << second << endl;
        return min(second, first);
    }
    return first;
}

int main()
{
    int t, temp;
    int room_height[2], first_table[4], second_table[2];
    //only allowed to move first_table
    cin >> t;
    for (int g = 0; g < t; g++) {
        for (int i = 0; i < 2; i++) { cin >> room_height[i]; }
        for (int i = 0; i < 4; i++) { cin >> first_table[i]; }
        for (int i = 0; i < 2; i++) { cin >> second_table[i]; }
        //4 cases
        temp = min(algo(room_height, first_table, second_table, 0), algo(room_height, first_table, second_table, 1));
        if ( temp == 100000001) {
            cout << "-1" << endl;
        }
        else {
            cout << temp << endl;
        }

    }
}

