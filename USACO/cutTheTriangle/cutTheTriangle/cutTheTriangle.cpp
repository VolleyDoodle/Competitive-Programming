#include <vector>
#include <algorithm>
using namespace std;
#include <iostream>
class v {
public:
	int x, y;

};
bool sortColX(const v& a, const v& b) {
	return a.x < b.x;
}
bool sortColY(const v& a, const v& b) {
	return a.y < b.y;
}
int main()
{
	int t;
	cin >> t;
	for (int r = 0; r < t; r++) {
		vector <v> points;
		for (int i = 0; i < 3; i++) {
			v temp;
			cin >> temp.x >> temp.y; points.push_back(temp);
			//cout << triV[i][0] << triV[i][1];
		}
		//two scenarioes
		//vertical line check
		//first sort by x location
		
		for (int i = 0; i < 1; i++) {
			sort(points.begin(), points.end(), sortColX);
			if (points[1].x > points[0].x && points[2].x > points[1].x) {
				cout << "YES" << endl; break;
			}
			sort(points.begin(), points.end(), sortColY);
			if (points[1].y > points[0].y && points[2].y > points[1].y) {
				cout << "YES" << endl; break;
			}
			cout << "NO" << endl;
		}
		//horizontal line check
	}
}


