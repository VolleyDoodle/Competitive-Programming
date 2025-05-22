#include <bits/stdc++.h>
#define ll long long
#define s second
#define f first
using namespace std;

void setIO(string prob) {
    freopen((prob + ".in").c_str(), "r", stdin);
    freopen((prob + ".out").c_str(), "w", stdout);
}
class DisjointSets {
    private:
      vector<int> parents;
      vector<int> sizes;
  
    public:
        DisjointSets(int size) : parents(size), sizes(size, 1) {
            for (int i = 0; i < size; i++) { parents[i] = i; }
        }
    
        /** @return the "representative" node in x's component */
        //keeps on going up to root and then path compression with parents[x] = find..
        int find(int x) { return parents[x] == x ? x : (parents[x] = find(parents[x])); }
    
        /** @return whether the merge changed connectivity */
        bool unite(int x, int y) {
            int x_root = find(x);
            int y_root = find(y);
            if (x_root == y_root) { return false; }
    
            if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
            sizes[x_root] += sizes[y_root];
            parents[y_root] = x_root;
            return true;
        }
    
        /** @return whether x and y are in the same connected component */
        bool connected(int x, int y) { return find(x) == find(y); }
        //left const return type for vector <int> (can't modify returned vector as im passing by referce)
        //right const is labeling it as a const method so can be called on const dsu asw
        const vector<int>& getParents() const { return parents; }
        const vector<int>& getSizes() const { return sizes; }
    };
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    setIO("txt");
    int n, q;
    cin >> n >> q;
    DisjointSets dsu(n + 1);
    while (q--){
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0){
            dsu.unite(u, v);
        } else{
            cout << dsu.connected(u, v) << "\n";
        }
    }
}