#include <bits/stdc++.h>
using namespace std;
vector <long long> months;
long long ans = 0, mostVal;
set <long long> alreadyDid;
void addorNot(long long L);
void solve(long long dif){
    //first find all divisors
    for (long long i = sqrt(dif); i >= 1; i--){
        set <long long> mods; //stores the unique mods
        bool works = true;
        if (dif%i != 0) continue;

        if (alreadyDid.count(i) == 0 && i <= mostVal){
            alreadyDid.insert(i);
            addorNot(i);
        }
        if (alreadyDid.count(dif/i) == 0 && dif/i <= mostVal){
            alreadyDid.insert(dif/i);
            addorNot(dif/i);
        }
        
    }
}
void addorNot(long long L){
    //looping through months
    //and seeing if atmost 3 unique
    set <long long> mods;
    for (int x = 0; x < months.size(); x++){
        mods.insert(months[x]%L);
        if (mods.size() > 3){
            return;
        }
    }
    ans+=L;
}
int main(){
    //freopen("txt.in", "r", stdin);
    //freopen("txt.out", "w", stdout);
    long long n;
    cin >> n;
    set <long long> disMonths;
    
    for (long long i = 0; i < n; i++){
        long long t1;
        cin >> t1;
        if (disMonths.count(t1) == 0){
            disMonths.insert(t1);
            months.push_back(t1);
        }

    }
    sort(months.begin(), months.end());
    mostVal = months[0]/4;
    if (months.size() <= 3){
        cout << (long long)(mostVal * (mostVal + 1))/2;
        return 0;
    }

    for (int i = 0; i < 3; i++){
        for (int x = 1; x <= 3; x++){
            solve(months[x] - months[i]);
        }
    }

    cout << ans;



}