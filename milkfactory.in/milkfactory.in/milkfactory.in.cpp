
#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
ifstream fin("factory.in");
ofstream fout("factory.out");
set <int> a[101];
set <int> b;
set <int> ans;
int n;
void dfs(int root, int i) {
	//i is root
	//a[i] are nodes connected to i
	if (ans.size() >= n - 1){
		//fout << "rad";
		b.insert(root);
	}
	if (a[i].size() == 0){ //doesnt connect to anything
		return;
	}
	for (auto element : a[i]) {
		//element is new "mini root"
		ans.insert(element);
		/*for (auto e : ans) {
			fout << e << " ";
		}*/
		//fout << endl;
		dfs(root, element);
	}
	
}
int main()
{

	int  from, to;

	//for (int i = 0; i < 101; i++) { a[i] = 1; }
	//for (int i = 0; i < 5; i++) {fout << a[i];}
	fin >> n;
	//take inputs
	for (int i = 0; i < n - 1; i++) {
		fin >> from >> to;
		a[to].insert(from);
	}
	/*for (int i = 0; i < n; i++) {
		fout << i << ": ";
		for (auto e : a[i]) {
			fout << e << " ";
		}
		fout << endl;
	}*/
	//run some sort of dfs to find possible answers

	int index;
	set <int> p;
	for (int i = n; i >= 1; i--) {
		dfs( i,i);
		if (b.size() > 0) { fout << i; exit(0); break; }
		//use dfs
	}
	if (b.size() == 0) { fout << -1; }

}

