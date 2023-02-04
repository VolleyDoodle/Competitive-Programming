

#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int t;
    int top = 100000001, bottom = 100000001, left = 100000001, right = 100000001;
    int room_height[2], first_table[4], second_table[2];
    //only allowed to move first_table
    cin >> t;
    for (int g = 0; g < t; g++) {
        for (int i = 0; i < 2; i++) { cin >> room_height[i]; }
        for (int i = 0; i < 4; i++) { cin >> first_table[i]; }
        for (int i = 0; i < 2; i++) { cin >> second_table[i]; }
        //4 cases
        if (first_table[2] - first_table[0] + second_table[0] >= room_height[0]) {
            right = second_table[0] - (room_height[0] - first_table[2]);
            left = second_table[0] - first_table[0];
            cout << "right: " << right << endl;
            cout << "left: " << left << endl;
        }
        if (first_table[3] - first_table[1] + second_table[1] >= room_height[1]) {
            top = second_table[1] - (room_height[1] - first_table[3]);
            bottom = second_table[1] - first_table[1];
            cout << "top: " << top << endl;
            cout << "bottom: " << top << endl;
        }
        if (min({ top, bottom, left, right }) == 100000001) {
            cout << "-1" << endl;
        }
        else {
            cout << min({ top, bottom, left, right }) << endl;
        }

    }
}

