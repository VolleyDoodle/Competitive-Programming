// year_of_the_cow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
using namespace std;


int main()
{
	int n;
	map<string, int> m;
	cin >> n;
	string trash;
	string cowa, cowb, relation, animal;
	string animals[12] = { "Ox", "Tiger", "Rabbit", "Dragon", "Snake",
"Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat" };
	m["Bessie"] = 0;
	for (int i = 0; i < n; i++) {
		cin >> cowa >> trash >> trash >> relation >> animal >> trash >> trash >> cowb;
		if (relation == "next") {
			//do stuff

		}
		if (relation == "previous") {
			//do other stuff 
		}
	}

	
}

