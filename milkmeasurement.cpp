#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void bubbleSwitch(int* list, int c) {
    int box = list[c];
    list[c] = list[c + 1];
    list[c + 1] = box;
}
int main() {
    ifstream fin;
    ofstream fout;
    int count;
    char data[100];
    string cowName;
    bool Mildred = false, Bessie = false, Elsie = false;

    fin.open("C:\\Users\\Aaroosh Rustagi\\source\\repos\\milkmeasurement\\Debug\\apple.txt");
    if (fin.fail())
    {
        cerr << "Could not open input.\n";
        cerr << "Error code: " << strerror_s(data, errno);
        exit(1); // 1 indicates an error occurred
    }

    fout.open("C:\\Users\\Aaroosh Rustagi\\source\\repos\\milkmeasurement\\Debug\\measurement.out");
    if (fout.fail()) {
        cerr << "Could not open input.\n";
        exit(1); // 1 indicates an error occurred
    }
    fin >> count;
    fout << count;

    int *cowOrder, *milkAmount, *cowNameNum;

    cowOrder = new int[count];
    milkAmount = new int[count];
    cowNameNum = new int[count];

    for (int i = 0; i < count; i++) {
        fin >> cowOrder[i] >> cowName >> milkAmount[i];
        if (cowName == "Mildred") { 
            cowNameNum[i] = 1; 
        } else if (cowName == "Elsie") { 
            cowNameNum[i] = 2; 
        } else (cowName == "Bessie") { 
            cowNameNum[i] = 3; 
        }
        fout << cowOrder[i] << cowNameNum[i] << milkAmount[i];
    }
    //bubble sort
    for (int i = 0; i < count; i++) {
        for (int c = 0; c < count - i - 1; c++) {
            if (cowOrder[c] > cowOrder[c + 1]) { 
                bubbleSwitch(cowOrder, c);
                bubbleSwitch(milkAmount, c);
                bubbleSwitch(cowNameNum, c);
            }
        }
    }
    //switch fn
}