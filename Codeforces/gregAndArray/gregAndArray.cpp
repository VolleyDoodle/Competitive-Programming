#include <bits/stdc++.h>
using namespace std;
class lrd{
public:
    long long l, r, d;
};

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector <long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector <lrd> operations(m);
    vector <long long> finalArr(n + 1);
    for (int i = 0; i < m; i++){
        lrd temp;
        cin >> temp.l >> temp.r >> temp.d;
        operations[i] = temp;
    }
    vector <long long> operationCount(m + 1);
    
    for (int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        operationCount[x - 1]++; operationCount[y]--;
    }
    long long cntOp = 0;
    for (long long i = 0; i < m; i++){
        cntOp += operationCount[i];
        finalArr[operations[i].l - 1] += operations[i].d * cntOp;
        finalArr[operations[i]. r] -= operations[i].d * cntOp;
    }
    long long amt = 0;
    for (long long i = 0; i < n; i++){
        amt += finalArr[i];
        cout << a[i] + amt << " ";
    }
}