// sleeping_in_class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    int t, n;
    int sum = 0, temp, curr = 0, ans = 100001, temp_ans = 0;
    bool good = true;
    cin >> t;
    for (int c = 0; c < t; c++) {
        cin >> n; 
        vector<int> v(n);
        for (int k = 0; k < n; k++) {
            cin >> temp; v.at(k) = temp; sum += temp;
            //fout << v[k] << " ";
        }
        //fout << endl;
        //fout << "SUM: " << sum << endl;
        //logic
        for (int i = 1; i <= sum; i++) {
            //fout << "i: " << i << endl;
            if (sum % i == 0) {
                for (int x = 0; x < n; x++) {
                    curr += v[x];
                    //fout << "v[x]: " << v[x] << endl;
                    //fout << "Bcurr: " << curr << " x: " << x << endl;
                    if (curr == i) {
                        curr = 0;
                    }
                    else if (curr > i) {
                        good = false;
                        //fout << "breaked LOL " << endl;
                        break;
                    }
                    else if (curr < i) {
                        temp_ans++; 
                    }
                    //fout << "Bcurr: " << curr << " x: " << x << endl;
                    //fout << "temp_ans: " << temp_ans << endl;
                    
                }
                if (good && temp_ans < ans) {
                    ans = temp_ans;
                }
                //works
            }
            //reset
            good = true; temp_ans = 0; curr = 0;
        }
        sum = 0;
        if (ans != 100001) { cout  << ans << endl; }
        else { cout << 0 << endl; }
        ans = 100001;
    }
}
