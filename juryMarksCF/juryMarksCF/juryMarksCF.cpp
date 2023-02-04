
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector <int> juryMarks;
    juryMarks.push_back(0);
    vector <int> known;
    int temp;
    for (int i = 0; i < n; i++) {
        
        cin >> temp;
        juryMarks.push_back(temp + juryMarks[i]);
    }
    for (int i = 0; i < k; i++) {
        cin >> temp;
        known.push_back(temp);
    }
    for (int i = 0; i < n + 1; i++) {
        cout << juryMarks[i] << " ";
    }
}

