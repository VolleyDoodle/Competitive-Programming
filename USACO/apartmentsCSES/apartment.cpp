#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, k; 
    cin >> n >> m >> k;
    vector <int> applicant(n), apartments(m);
    for (int i = 0; i < n; i++){cin >> applicant[i];}
    for (int i = 0; i < m; i++){ cin >> apartments[i];}
    sort(applicant.begin(), applicant.end());
    sort(apartments.begin(), apartments.end());
    int curMent = 0, ans = 0;
    for (int i = 0; i < n; i++){
        if (curMent == m){break;}
        if (applicant[i] <=  apartments[curMent] + k && applicant[i] >= apartments[curMent] - k){
            curMent++; ans++;
        } else if (applicant[i] > apartments[curMent] + k){
            i--;
            curMent++;
        }

    }
    cout << ans;
}
