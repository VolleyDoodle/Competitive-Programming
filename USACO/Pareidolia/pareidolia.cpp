#include <bits/stdc++.h>
using namespace std;
#define f first 
#define s second
int main(){
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    string s;
    vector <char> bessie = {'b', 'e', 's', 's', 'i', 'e'};
    vector <pair <int, int>> rlE, lrB;
    //lr.push_back({-1, 0});
    cin >> s;
    int right = 0, left = 0, curChIdx = 0;
    //the first pass finds the earliest ending
    while (left <= right && right < s.size()){
        /*if (s[right] == 'b' && curChIdx <= 1){
            //readjusting the start of substr "bessie"
            left = right;
        }*/
        if (s[right] == bessie[curChIdx]){
            curChIdx++;
            
            if (curChIdx == 6){
                rlE.push_back({right, left});
                left = ++right;
                curChIdx = 0;
            }
            continue;
        }
        right++;
    }
    //second pass finds earliest starting
    sort(rLE.begin(), rLE.end());
    left = s.size() - 1, right = s.size() - 1; curChIdx = 5;
    while (left <= right && left >= 0){
        /*if (s[right] == 'b' && curChIdx <= 1){
            //readjusting the start of substr "bessie"
            left = right;
        }*/
        if (s[left] == bessie[curChIdx]){
            curChIdx--;
            
            if (curChIdx == -1){
                lr.push_back({left, right});
                right = --left;
                curChIdx = 5;
            }
            continue;
        }
        left--;
    }
    //cout << "h";
    //i dont know what i am doing fucking holy shit
    //alright just count the subsring with 1 bessie sepereately por favor
    pair <int, int> lr;
    for (auto& p : lrB){
        
    }
    //assume that the below stuff is correct?? for some reason
    long long ans = 0;
    //lr.push_back({s.size(), s.size()});
    for (int i = 1; i < lr.size() - 1; i++){
        //counting the substr with bessie
        ans += (lr[i].f - lr[i - 1].f) * (lr[i + 1].s - lr[i].s);
    }
    lr[0].f = 0;
    vector <long long> pfsF(lr.size() - 1, 0), subPfs(lr.size(), 0);
    long long factor = lr.size() - 2;
    pfsF[0] = (lr[1].first + 1) * factor;
    subPfs[1] = lr[1].first + 1;
    factor--;
    for (int i = 1; i < lr.size() - 1; i++){
        pfsF[i]+= (pfsF[i - 1] + (lr[i + 1].second - lr[i].second)) * max(1LL, factor);
        subPfs[i + 1] += (pfsF[i - 1] + (lr[i + 1].second - lr[i].second));
        factor--;
    }

    for (int i = pfsF.size() - 1; i >= 2; i--){
        ans += (pfsF[i] - pfsF[i - 1]) * (pfsF[i - 2] - (subPfs[i - 1] * (pfsF.size() - i - 1)));
        factor/=i;
    }
    cout << ans;
}