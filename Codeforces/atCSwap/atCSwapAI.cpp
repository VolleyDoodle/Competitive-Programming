#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    long long K;
    cin >> S >> K;
    int n = S.size();

    // collect original positions
    vector<int> posK, posE, posY;
    for(int i = 0; i < n; i++){
        if(S[i] == 'K')      posK.push_back(i);
        else if(S[i] == 'E') posE.push_back(i);
        else                  posY.push_back(i);
    }
    int nK = posK.size(),
        nE = posE.size(),
        nY = posY.size();

    int maxInv = n*(n-1)/2;
    if(K >= maxInv){
        // safe multinomial: first choose K-positions, then E-positions among the rest
        auto choose = [&](int N, int R){
            if(R < 0 || R > N) return 0ULL;
            if(R > N - R) R = N - R;
            __int128 r = 1;
            for(int i = 1; i <= R; i++){
                r = r * (N - R + i) / i;
            }
            return (ull)r;
        };
        ull ans = choose(n, nK) * choose(n - nK, nE);
        cout << ans << "\n";
        return 0;
    }
    int KK = (int)K;

    static ull dp[31][31][31][436];
    dp[0][0][0][0] = 1;

    for(int a = 0; a <= nK; a++){
      for(int b = 0; b <= nE; b++){
        for(int c = 0; c <= nY; c++){
          for(int s = 0; s <= KK; s++){
            ull ways = dp[a][b][c][s];
            if(!ways) continue;
            int used = a + b + c;

            // place K
            if(a < nK){
              int p = posK[a];
              int ubE = upper_bound(posE.begin(), posE.begin()+b, p) - posE.begin();
              int ubY = upper_bound(posY.begin(), posY.begin()+c, p) - posY.begin();
              int delta = used - (a + ubE + ubY);
              if(s + delta <= KK)
                dp[a+1][b][c][s+delta] += ways;
            }
            // place E
            if(b < nE){
              int p = posE[b];
              int ubK = upper_bound(posK.begin(), posK.begin()+a, p) - posK.begin();
              int ubY = upper_bound(posY.begin(), posY.begin()+c, p) - posY.begin();
              int delta = used - (b + ubK + ubY);
              if(s + delta <= KK)
                dp[a][b+1][c][s+delta] += ways;
            }
            // place Y
            if(c < nY){
              int p = posY[c];
              int ubK = upper_bound(posK.begin(), posK.begin()+a, p) - posK.begin();
              int ubE = upper_bound(posE.begin(), posE.begin()+b, p) - posE.begin();
              int delta = used - (c + ubK + ubE);
              if(s + delta <= KK)
                dp[a][b][c+1][s+delta] += ways;
            }
          }
        }
      }
    }

    ull answer = 0;
    for(int s = 0; s <= KK; s++)
        answer += dp[nK][nE][nY][s];
    cout << answer << "\n";
    return 0;
}
