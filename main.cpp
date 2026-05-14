// COMSC-210 | Lab 37 | Barsbek
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <map>

using namespace std;

const int BUCKET_RANGE{500};

int get_hash_index(const string& text);

int main() {
    ifstream fileInput{"lab-37-data-3.txt"};
    if (!fileInput) {
        cerr << "File not found\n";
        return 1;
    }

    map<int, list<string>> hashTable;
    string inputText;

    while (fileInput >> inputText) {
        int hashIndex{get_hash_index(inputText)}; // generate hash index
        hashTable[hashIndex].push_back(inputText);
    }


    fileInput.close();

    return 0;
}

int get_hash_index(const string& text) {
    int total{};

    for (char each : text)
        total += (int)each;

    int hashIndex{total % BUCKET_RANGE};

    return hashIndex;
}