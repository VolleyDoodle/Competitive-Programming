#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
class DisjointSet {
    private:
        vector <int> parents;
        vector <int> sizes;
    public:
        DisjointSet(int size) : parents(size), sizes(size, 1){
            for (int i = 0; i < size; i++) parents[i] = i;
        }
        int find(int x){
            if (parents[x] != x){
                parents[x] = find(parents[x]);
            }
            return parents[x];
        }
        bool unite(int x, int y){
            int xRoot = find(x);
            int yRoot = find(y);
            if (xRoot == yRoot) return false;
            if (sizes[xRoot] <  sizes[yRoot]) swap(xRoot, yRoot);
            //now xRoot is root with larger size, yRoot with smaller size
            //why add smaller to bigger or bigger to smaller
            //prolly adding small to big
            sizes[xRoot]+=sizes[yRoot];
            parents[yRoot] = xRoot;
            return true; 
            //now xAmt is larger
        }
        bool connected(int x, int y){
            return find(x) == find(y);
        }
        int szOf(int x){
            return sizes[find(x)];
        }

};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //setIO("txt");
    int n , m;
    cin >> n >> m;
    DisjointSet dsu(n + 1);
    int curSz = n;
    multiset <int> ms;
    for (int i = 0; i < n; i++) ms.insert(1);
    while (m--){
        int a, b;
        cin >> a >> b;
        if (!dsu.connected(a, b)){
            ms.erase(ms.find(dsu.szOf(a)));
            ms.erase(ms.find(dsu.szOf(b)));
            dsu.unite(a, b);
            ms.insert(dsu.szOf(a));
            curSz--;
        }
        cout << curSz << " " << *prev(ms.end()) << "\n";
    }
}