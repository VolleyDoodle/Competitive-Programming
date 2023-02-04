
#include <iostream>
#include <unordered_set>
#include <fstream>
#include <vector>
using namespace std;
unordered_set <int> answer;
ifstream fin("backforth.in");
ofstream fout("backforth.out");
void solve( vector <int> a, vector <int> b, int firstbarn, int secondbarn, int c) {
    int temp;
    if (c == 4) { answer.insert(firstbarn); return; }
    else {
        if (c % 2 == 0) {
            for (int i = 0; i < a.size(); i++) {
                temp = a[i];
                a.erase(a.begin() + i);
                b.insert(b.begin(), temp);
                solve(a, b, firstbarn - temp, secondbarn + temp, c + 1);
                b.erase(b.begin());
                a.insert(a.begin(), temp);
            }
        }
        else if (c % 2 == 1) {
            for (int i = 0; i < b.size(); i++) {
                temp = b[i];
                b.erase(b.begin() + i);
                a.insert(a.begin(), temp);
                solve(a, b, firstbarn + temp, secondbarn - temp, c + 1);
                a.erase(a.begin());
                b.insert(b.begin(), temp);
            }
        }
    }
    

}
int main()
{

    int firstbarn = 0, secondbarn = 0;
    int input;
    vector <int> milkfirstbarn, milksecondbarn;
    for (int i = 0; i < 10; i++) { fin >> input; milkfirstbarn.push_back(input); }
    for (int i = 0; i < 10; i++) { fin >> input; milksecondbarn.push_back(input); }
    solve(milkfirstbarn, milksecondbarn, firstbarn, secondbarn, 0);
    fout << answer.size() << endl;

}
