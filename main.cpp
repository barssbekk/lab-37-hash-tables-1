// COMSC-210 | Lab 37 | Barsbek
#include <iostream>
#include <string>
using namespace std;

int sum_ascii(const string& input);

int main() {
    cout << sum_ascii("ABC");
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