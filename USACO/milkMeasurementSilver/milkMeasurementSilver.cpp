#include <bits/stdc++.h>
 
using namespace std;
 
struct measurement {
  int day;
  int cow;
  int delta;
};
 
int main() {
  ios_base::sync_with_stdio(false);
  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);
 
  int N;
  int G;
  cin >> N >> G;
 
  vector<measurement> A(N);
  for (auto& m : A) {
    cin >> m.day >> m.cow >> m.delta;
  }
  sort(A.begin(), A.end(), [](const measurement& a, const measurement& b) {
    return a.day < b.day;
  });
  map <int, int> valuesCount;
  map <int, int> idVal;
  valuesCount[0] = N + 1;
  int prevLeader = N + 1, curLeader, ans = 0;
  for (auto &m : A){
    bool wasTop = ((--valuesCount.end())->first == idVal[m.cow]);
    valuesCount[idVal[m.cow]]--;
    if (valuesCount[idVal[m.cow]] == 0) valuesCount.erase(idVal[m.cow]);
    idVal[m.cow]+=m.delta;
    valuesCount[idVal[m.cow]]++;
    auto it = --valuesCount.end();
    curLeader = it->second;
    bool isTop = (it->first == idVal[m.cow]);
    if (curLeader != prevLeader || wasTop != isTop){
      ans++;
    }
    prevLeader = curLeader;
  }
  cout << ans;

  
}