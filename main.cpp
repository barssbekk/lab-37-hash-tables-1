// COMSC-210 | Lab 37 | Barsbek
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <map>

using namespace std;

const int BUCKET_RANGE{500};    // total bucket count
const int NUM_FIRST_ENTRIES{100};

int get_hash_index(const string& text);
void print_first_entries(const map<int, list<string>>& hashTable);

int main() {
    // open dataset file
    ifstream fileInput{"lab-37-data-3.txt"};

    // make sure file opened
    if (!fileInput) {
        cerr << "File not found\n";
        return 1;
    }

    // key = bucket num
    // value = list of txt codes
    map<int, list<string>> hashTable;
    string inputText;

    while (fileInput >> inputText) {
        int hashIndex{get_hash_index(inputText)}; // generate hash index
        hashTable[hashIndex].push_back(inputText);
    }

    // print hash first 100 table
    print_first_entries(hashTable);

    fileInput.close();

    return 0;
}

int get_hash_index(const string& text) {
    int total{};

    for (char each : text)
        total += (int)each;              // add ascii values

    int hashIndex{total % BUCKET_RANGE}; // generate bucket num

    return hashIndex;
}

void print_first_entries(const map<int, list<string>>& hashTable) {
    int counter{};

    for (const auto& pair : hashTable) {
        cout << pair.first << ": ";
        for (const auto& each : pair.second)
            cout << each << ' ';

        cout << '\n';
        ++counter;
        if (counter >= NUM_FIRST_ENTRIES)
            break;
    }
}