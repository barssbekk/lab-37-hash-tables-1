// COMSC-210 | Lab 37 | Barsbek
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int sum_ascii(const string& text);

int main() {
    ifstream fileInput{"lab-37-data-3.txt"};
    if (!fileInput) {
        cerr << "File not found\n";
        return 1;
    }

    string inputCode{};
    long long bigTotal{};
    while (fileInput >> inputCode)
        bigTotal += sum_ascii(inputCode);
    cout << bigTotal;

    fileInput.close();

    return 0;
}

int sum_ascii(const string& text) {
    int total{};

    for (char each : text)
        total += (int)each;

    return total;
}
/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/