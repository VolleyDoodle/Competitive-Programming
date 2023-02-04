// do_you_know_ABC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int n = 7;
    int a, b, c;
    int nums[7];
    bool done = false;
    bool a_b = false, a_c = false, b_c = false, a_b_c = false;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            for (int z = 0; z < n; z++) {
                a = nums[x]; b = nums[y]; c = nums[z];
                for (int i = 0; i < n; i++) {
                    if (nums[i] == a + b) {a_b = true;}
                    if (nums[i] == a + c) { a_c = true;}
                    if (nums[i] == c + b) { b_c = true; }
                    if (nums[i] == a + b + c) { a_b_c = true; }
                }
                if (a_b && a_c && b_c && a_b_c) {
                    if (a <= b && b <= c && !done) {
                        done = true;
                        cout << a << " " << b << " " << c;
                    }
                    
                    
                }
                a_b = false, a_c = false, b_c = false, a_b_c = false;
            }
        }

    }

}

