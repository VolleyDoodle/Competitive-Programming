#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);
	int n, m, r; cin >> n >> m >> r;
	vector <int> milkRate(n); vector <pair <int, int>> storeRate(m); vector <int> rentRate(r);
	int t, tt;
	for (int i = 0; i < n; i++) {
		cin >> milkRate[i];
	}
	for (int i = 0; i < m; i++) { cin >> storeRate[i].second >> storeRate[i].first;
	}
	for (int i = 0; i < r; i++) {cin >> rentRate[i];}
	sort(milkRate.begin(), milkRate.end());
	sort(storeRate.begin(), storeRate.end(), greater<pair<int, int>>());
	sort(rentRate.begin(), rentRate.end(), greater <int>());
	//each cow has choice to either get rented or milked
	//first sort cows (since we want low-milk producing cows to get first priority)
	int curStore = 0, curRent = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int curCowRate = milkRate[i];
		
		long long curCowMilk = 0;
		int startCurStore = curStore;
		//decide weather to milk or rent (if milk get from first element of milkRate to maximize)
		//find money made w/ curCow's milk
		while (curCowRate > 0) {
			if (curCowRate > storeRate[curStore].second) {
				curCowRate -= storeRate[curStore].second;
				curCowMilk += storeRate[curStore].second * storeRate[curStore].first;
				//storeRate[i].first = 0; 
				if (curStore == m - 1) { break; }
				curStore++;
			}
			else {
				//curCowRate is left over???
				curCowMilk += curCowRate * storeRate[curStore].first;
				break;
			}
		}
		//curCowMilk is equal to money earned from milking cow[i] (curCow)
		if (curRent != r) {
			if (rentRate[curRent] > curCowMilk) {
				//rent
				ans += rentRate[curRent];
				
				curRent++;

				
				
				curStore = startCurStore;
			}
			else {
				//milk selling is greater than renting
				i--;
				ans += curCowMilk;
				storeRate[curStore].second -= curCowRate;
			}
		}
		else {
			//milk selling is greater than renting
			i--;
			ans += curCowMilk;
			storeRate[curStore].second -= curCowRate;
		}

	}
	cout << ans;

}


