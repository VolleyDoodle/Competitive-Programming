#include <iostream>

using namespace std;

int main() {
	char* data;
	
	cout << &data << "\n";
	cout << *data << "\n";
	
	data = new char[100];

	strcpy_s(data, 10, "Aaroosh");
	cout << &data << "\n";
	cout << data << "\n";
	cout << *data << "\n";
	return 0;
}