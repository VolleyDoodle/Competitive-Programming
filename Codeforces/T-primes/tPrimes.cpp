#include <bits/stdc++.h>
using namespace std;
const int limit = pow(10, 6) + 1;

bool nums[limit];
unordered_set <double> primes;
void sieveOfEratosthenes(){
    for (int i = 2; i * i < limit; i++){
        if (nums[i] == false){
            for (int x = i * i; x < limit; x+=i){
                nums[x] = true;
            }
        }
    }
    for (int i = 2; i < limit; i++){
        if (!nums[i]){
            primes.insert(i);
        }
    }
}
int main(){
    //notice that for number "n" to have three factors 
    //(counting 1 and n)
    //it must be a square of a prime
    //so basically use sieve of eratosthenes to generate primes
    //then check if numbers is prime num squared
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;  cin >> n;
    sieveOfEratosthenes();
    for (int i = 0; i < n; i++){
        long long temp; cin >> temp;
        //cout << "sqrt: " << sqrt(temp) << "\n";
        //cout << typeid(sqrt(temp)).name() << "\n";
        if (primes.count(sqrt(temp))){
            cout << "YES";
        } else{
            cout << "NO";
        }
        cout << "\n";
    }
    //cout << primes.size();

}