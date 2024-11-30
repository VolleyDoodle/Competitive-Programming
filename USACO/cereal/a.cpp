#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define MAXN 100001

int N,M;
int f[MAXN], s[MAXN];
int occ[MAXN];
int ans[MAXN];

int main()
{
	ifstream fin("cereal.in");
	fin >> N >> M;
	for(int i=1;i<=N;i++)
		fin >> f[i] >> s[i];
	int cnt = 0;
	for(int i=N;i>=1;i--)
	{
		int j = i;
		int pos = f[i];
		while(1)
		{
			if(occ[pos] == 0)
			{
				occ[pos] = j;
				cnt++;
				break;
			}
			else if(occ[pos] < j)
				break;
			else
			{
				int k = occ[pos];
				occ[pos] = j;
				if(pos == s[k])
					break;
				j = k;
				pos = s[k];
			}
		}
		ans[i] = cnt;
	}
	ofstream fout ("cereal.out");
	for(int i=1;i<=N;i++)
		fout << ans[i] << '\n';
}