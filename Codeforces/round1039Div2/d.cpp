#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void setIO(string pre){
    freopen((pre + ".in").c_str(), "r", stdin);
    freopen((pre + ".out").c_str(), "w", stdout);
}
/*
should've approached this problem with -> what does max(pi, pi + 1) > p(i + 2) imply
given list of [a, b, c, d, e, f]
    max(a, b) > c (is always true)
    if b > a all elements to the right are less than b
    if a > b all elements to the right are less than a
    fuck this is so stupid
    the main observation is literally just each has to contribute like say u have
    if a > b, then that creates one little thign so all L, R should have that as a +1?
    
    oh if a > b then all elements to the right are less than a, meaning that it
    can create a decreasing sequence with all of em
    Observation: if u have [a, b, c] and b > a then all elements to the right of b are less than it
    if a > b then same thing? 
    How can we use this to count?
    lets say a > b. Now b can be less or greater than c we dont know.
    Look at b, c, d. 
    say c > b (so sequence was like 7, 3, 4)
    hmm i have an idea.

    [4, 3, 1, 2] | ans = 17
    +4
    so 4 + 3 + 3 + 2 + 3 = 9 + 6 = 15 BRUH
    [4] yes a > b (decreasing) so all elements to the right of 4 are less than it
    this means that it can be paired with any of those for length of 2
        l = 0 : r = 1, r = 2, r = 3
        [4, 3] [4, 3, 1] [4, 3, 1, 2] -> + 3
    [3] yes a > b (decreasing)
        l = 0: r = 1, r = 2, r = 3
        [4, 3] [4, 3, 1] [4, 3, 1, 2] -> + 3
        l = 1: r = 2, r = 3
        [3, 1] [3, 2] -> + 2
    [1]
        only count left
        [4, 1] [3, 1] + 2 -> 
    [2]
    r = 3: l = 0, 1, 2
    [4, 3, 1, 2] [3, 1, 2] [1, 2] -> + 3
    oh so the [1, 2] should only be counted once... but idk where TBH? prolly bigger one

    so how does this work? do u always oh this is easy as shit
    so if its a big one u know that all the ones to the right it can always be "matched" and increment one
    but if its a small one like1 then u know the only things is that it can be matched with the left ones and not right
    n = 6
    5 (i = 2)
    [6, 1, 5, 2, 4, 3]

*/
void solve(){
    ll n;
    cin >> n;
    vector <ll> nums(n);
    for (ll i = 0; i < n; i++){
        cin >> nums[i];
    }
    ll ans = 0;
    nums.push_back(5e5 + 10);
    for (ll i = 0; i < n; i++){
        if (nums[i] > nums[i + 1]){
            //keep this
            ans += (i + 1) * (n - i);
        } else{
            //don't keep this
            ans += (i + 1);
        }
    }
    cout << ans << "\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    ll t;
    cin >> t;
    while (t--){
        solve();
    }
}