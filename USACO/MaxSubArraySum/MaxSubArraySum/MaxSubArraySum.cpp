#include <vector>
#include <iostream>
#include <fstream>
#include <climits>
using namespace std;
int main()
{
    //ifstream cin("input.in");
    //ofstream cout("output.out");
    int n;
    cin >> n;
    vector <int> v;
    vector <long long> vPrefixSums;
    vPrefixSums.push_back(0);
    for (int i = 0; i < n; i++) {
        int nums;cin >> nums;
        v.push_back(nums);
        vPrefixSums.push_back(v[i] + vPrefixSums[i]);
        //cout << vPrefixSums[i + 1] << " ";
    }
    //cind min and max
    long long prefixMin = 0, ans = INT_MIN;
    //cout << prefixMin;
    //cant cind max and min in whole array then subtract
    //min cant be ahead of max additionally, need to cind max 
    for (int i = 1; i <= n; i++) {
        if (vPrefixSums[i] - prefixMin > ans) { ans = vPrefixSums[i] - prefixMin; }
        if (vPrefixSums[i] < prefixMin) { prefixMin = vPrefixSums[i]; }
    }
    cout << ans;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu

