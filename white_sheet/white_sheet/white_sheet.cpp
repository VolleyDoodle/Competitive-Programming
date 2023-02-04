

#include <iostream>
#include <vector>
using namespace std;
vector <int> intersection(vector <int> white_sheet, vector<int> black_sheet) {
	int xb, xt, yb, yt;
	xb = max(white_sheet[0], black_sheet[0]);
	xt = min(white_sheet[2], black_sheet[2]);
	yb = max(white_sheet[1], black_sheet[1]);
	yt = min(white_sheet[3], black_sheet[3]);
	if (black_sheet[0] >= white_sheet[2] || black_sheet[1] >= white_sheet[3] 
		|| black_sheet[2] <= white_sheet[0] || black_sheet[3] <= white_sheet[1]) {
		return { 0, 0,0,0 };
	}
	else {
		return {xb, yb, xt, yt};
	}
}
long long area(vector<int> a) {
	long long w = a[2] - a[0];
	long long h = a[3] - a[1];
	return w * h;
}
int main()
{
	vector<int>white_sheet(4), black_sheet_1(4), black_sheet_2(4);
	for (int i = 0; i < 4; i++) {cin >> white_sheet[i]; }
	for (int i = 0; i < 4; i++) { cin >> black_sheet_1[i]; }
	for (int i = 0; i < 4; i++) { cin >> black_sheet_2[i]; }
	/*cout << area(white_sheet) << endl;
	cout << area(intersection(white_sheet, black_sheet_1)) << endl;
	cout << area(intersection(white_sheet, black_sheet_2)) << endl;
	cout << area(intersection(black_sheet_1, black_sheet_2)) << endl;
	cout << area(intersection(white_sheet, intersection(black_sheet_1, black_sheet_2))) << endl;*/
	if (area(white_sheet) == area(intersection(white_sheet, black_sheet_1)) + area(intersection(white_sheet, black_sheet_2))
		- area(intersection(white_sheet,intersection(black_sheet_1, black_sheet_2)))) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}

}

