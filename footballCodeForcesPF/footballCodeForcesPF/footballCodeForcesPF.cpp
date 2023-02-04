using namespace std;
#include <iostream>
#include <vector>

int main()
{
    //for constructive algos try it out on piece of paper for some test inputs to find solution
    int n = 0, x, y;
    vector <vector <int>> games;
    
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        games.push_back({ 0, 0 });
    }
    int a = max(x, y), b = min(x, y); int end = n - 1;
    if (n == 1 && x == y) {cout << 1 << endl << x << ":" << y;}
    else if (x + y <= n) {
        cout << n - (x + y) << endl;
        for (int i = 0; i < x; i++) { cout << "1:0" << endl; }
        for (int i = 0; i < y; i++) { cout << "0:1" << endl; }
        for (int i = 0; i < n - (x + y); i++) { cout << "0:0" << endl; }
    }
    
    else { 
        cout << 0 << endl;
        if (b == 0) {
            //means a > n (because of previous if statement)
            if (b == x) {
                cout << "0:" << (a - (n - 1)) << endl;
                for (int i = 0; i < n - 1; i++) {
                    cout << "0:1" << endl;
                }
                
            }
            else {
                cout << (a - (n - 1)) << ":0" << endl;
                for (int i = 0; i < n - 1; i++) {
                    cout << "1:0" << endl;
                }
            }
            
        }
        else {
            if (a >= n) {
                if (a == x){ 
                    cout << (a - (n - 2)) << ":0" << endl; 
                    for (int i = 0; i < n - 2; i++) { cout << "1:0" << endl; }
                    cout << "0:" << b << endl;
                }
                else { 
                    cout  << "0:" << (a - (n - 2)) << endl; 
                    for (int i = 0; i < n - 2; i++) { cout << "0:1" << endl; }
                    cout << b << ":0" << endl;
                }
                
            }
            else {
                if (a == x) {
                    for (int i = 0; i < a; i++) {
                        cout << "1:0" << endl;
                    }
                    cout << "0:" << (b - (n - a - 1)) << endl;
                    for (int i = 0; i < n - (a + 1); i++) {
                        cout << "0:1" << endl;
                    }
                }
                else {
                    for (int i = 0; i < a; i++) {
                        cout << "0:1" << endl;
                    }
                    cout << (b - (n - a - 1)) << ":0"  << endl;
                    for (int i = 0; i < n - (a + 1); i++) {
                        cout << "1:0" << endl;
                    }
                }
                
            }

        }
        
    }
    
    
}

