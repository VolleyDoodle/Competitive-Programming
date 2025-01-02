#include <bits/stdc++.h>
#include <utility>
using namespace std;
#define f first
#define s second
//vector <vector <pair <long long, long long>>> firstSums;
/*struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.f);
        auto hash2 = hash<T2>{}(p.s);
        return hash1 * 107 + hash2; // Combine the two hashes
    }
};*/
map <pair <long long, long long>, vector <int>> secondSums, firstSums;
//key represents location
//vector represents how many moves it takes to get there ;)
void generateSubsets(vector <pair <int, int>>& nums, int half){
    int n = nums.size();
    for (int i = 0; i < (1LL << n); i++){
        vector <long long> id = {0, 0, 0};
        for (int x = 0; x < n; x++){
            if (i & (1 << x)){
                id[0]+=nums[x].f;
                id[1]+=nums[x].s;
                id[2]++;
            }
        }
        if (half == 1) firstSums[{id[0], id[1]}].push_back(id[2]);
        else secondSums[{id[0], id[1]}].push_back(id[2]);
    }
}
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    /*ios::sync_with_stdio(false);
    cin.tie(nullptr);*/
    //commented line of code does not change tle
    int n;
    cin >> n;
    pair <int, int> target;
    cin >> target.f >> target.s;
    vector <pair <int, int>> firstHalf(n/2), secondHalf(n - n/2);
    for (int i = 0; i < n/2; i++){
        cin >> firstHalf[i].f >> firstHalf[i].s;
    }
    for (int i = n/2; i < n; i++){
        cin >> secondHalf[i - n/2].f >> secondHalf[i - n/2].s;
    }
    generateSubsets(firstHalf, 1);
    generateSubsets(secondHalf, 2);
    vector <long long> ans(n + 1, 0);
    for (auto& element : firstSums){
        if (secondSums.count({target.f - element.f.f, target.s - element.f.s})){
            for (int& moveNum : element.s){
                for (int& scMoveNum : secondSums[{target.f - element.f.f, target.s - element.f.s}]){
                    ans[moveNum + scMoveNum]++;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }

}