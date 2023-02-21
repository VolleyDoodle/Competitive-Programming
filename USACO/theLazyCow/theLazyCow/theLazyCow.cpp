#include <bits/stdc++.h>
#define for_n(i,a,n) for (int i=a;i<n;i++)
#define maxim(a,b) a=max(a,b)
using namespace std;
//below is not my code (just wanted to see if code worked)
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("maxcross.in","r",stdin);
	ifstream fin("lazy.in");
	ofstream fout("lazy.out");
	int n,k;
	fin>>n>>k;
	vector<vector<int>> Grass(n+1,vector<int>(n+1));
	for_n(i,1,n+1){
		for_n(j,1,n+1){
			int grass;
			fin>>grass;
			Grass[i][j]+=grass;
			Grass[i][j]+=Grass[i][j-1];
		}
	}
	int ans=0;
	for_n(i,1,n+1){
		for_n(j,1,n+1){
			int sum=0;
			for_n(m,max(0,i-k),min(n+1,i+k+1)){
				sum+=Grass[m][min(n,j+(k-abs(i-m)))]-Grass[m][max(0,j-(k-abs(i-m))-1)];
			}
			maxim(ans,sum);
		}
	}
	fout<<ans<<'\n';

	 
}