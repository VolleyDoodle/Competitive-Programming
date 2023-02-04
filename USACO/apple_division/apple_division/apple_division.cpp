

#include <iostream>
using namespace std;
long long solve(int i, long long oSet, long long sSet, int n, int nums[]) {
    if (i == n) {
        //done
        return abs(oSet - sSet);
    }
    return min(solve(i + 1, oSet + nums[i], sSet, n, nums),
    solve(i + 1, oSet, sSet + nums[i], n, nums));


}
int main()
{
    int n;
    int nums[21];
    cin >> n;
    for (int y = 0; y < n; y++) {
        cin >> nums[y];
    }
    cout << solve(0, 0, 0, n, nums);
}
