#include <vector>
#include <iostream>
using namespace std;
int main()
{
	int r, c;
	cin >> r >> c;
	vector <string> field; 
	field.push_back(string(c + 2, 'Y'));
	string temp; int ans = 0;
	for (int x = 0; x < r; x++){
		cin >> temp; temp.insert(0, "Y"); temp.insert(c + 1, "Y");
		field.push_back(temp);
		
		for (int i = 1; i <= c; i++) {
			if (temp[i] == '#') { ans++; }
		}
	}
	
	field.push_back(string(c + 2, 'Y'));
	//find adjacent #'s now(subtract for every time found)

	//cout << ans << endl; 
	int subtract = 0;
	for (int x = 1; x <= r; x++) {
		for (int i = 1; i <= c; i++) {
			if (field[x][i] == '#') {
				if (field[x][i + 1] == field[x][i] || field[x][i - 1] == field[x][i] || field[x + 1][i] == field[x][i] || field[x - 1][i] == field[x][i]) {
					subtract++;
				}
			}
			
		}
	}
	//cout << subtract;
	cout << ans - (subtract / 2);


}

