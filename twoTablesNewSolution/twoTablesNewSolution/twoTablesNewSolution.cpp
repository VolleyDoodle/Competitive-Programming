using namespace std;
#include <iostream>

int main()
{
    int t;
    cin >> t;
    for (int r = 0; r < t; r++) {
        int wRoom, hRoom, h2, w2;
        int x1, x2, y1, y2;
        cin >> wRoom >> hRoom;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> w2 >> h2;
        int ans = INT_MAX;
        if ((x2 - x1) + w2 <= wRoom) {
            ans = max(0, w2 - x1);
        }
        if ((y2 - y1) + h2 <= hRoom) {
            if (h2 < y1) {
                ans = 0;
            }
            else {
                ans = min(ans, h2 - y1);
            }
        }
        //cout << "ans: ";
        if (ans == INT_MAX) {
            cout << -1 << endl;
        }
        else {
            cout << ans << endl;
        }
    }
}

