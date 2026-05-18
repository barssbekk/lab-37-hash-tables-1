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

bool search_key(const map<int, list<string>>& hashTable,
                const string& target);

void add_key(map<int, list<string>>& hashTable,
             const string& newKey);

bool remove_key(map<int, list<string>>& hashTable,
                const string& target);

bool modify_key(map<int, list<string>>& hashTable,
                const string& oldKey,
                const string& newKey);

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

    fileInput.close();
    int choice{};
    do {

        cout << "\n---MENU---\n";
        cout << "1. Print first 100 entries\n";
        cout << "2. Search key\n";
        cout << "3. Add key\n";
        cout << "4. Remove key\n";
        cout << "5. Modify key\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            // print
            case 1: {
                print_first_entries(hashTable);
                break;
            }

            // search
            case 2: {
                string target;
                cout << "\nEnter key to search: ";
                cin >> target;
                if (search_key(hashTable, target))
                    cout << "Found\n";
                else
                    cout << "Not found\n";
                break;
            }

            // add
            case 3: {
                string newKey;
                cout << "\nEnter key to add: ";
                cin >> newKey;

                add_key(hashTable, newKey);
                cout << "Key added\n";
                break;
            }

            // remove
            case 4: {
                string removeTarget;

                cout << "\nEnter key to remove: ";
                cin >> removeTarget;

                if (remove_key(hashTable, removeTarget))
                    cout << "Key removed\n";
                else
                    cout << "Key not found\n";

                break;
            }

            // modify
            case 5: {
                string oldKey;
                string updatedKey;

                cout << "\nEnter key to modify: ";
                cin >> oldKey;

                cout << "Enter new key: ";
                cin >> updatedKey;

                if (modify_key(hashTable, oldKey, updatedKey))
                    cout << "Key modified\n";
                else
                    cout << "Original key not found\n";
                break;
            }

            // exit
            case 6: {
                cout << "Exit\n";
                break;
            }

        }

    } while (choice != 6);

    return 0;
}

    // print hash first 100 table
    // print_first_entries(hashTable);
    //
    // // find target
    // string target;
    // cout << "\nEnter key to search: ";
    // cin >> target;
    //
    // if (search_key(hashTable, target))
    //     cout << "Found\n";
    // else
    //     cout << "Not found\n";
    //
    // // Add key
    // string newKey;
    //
    // cout << "\nEnter key to add: ";
    // cin >> newKey;
    // add_key(hashTable, newKey);
    // cout << "Key added\n";
    //
    // // remove key
    // string removeTarget;
    //
    // cout << "\nEnter key to remove: ";
    // cin >> removeTarget;
    //
    // if (remove_key(hashTable, removeTarget))
    //     cout << "Key removed\n";
    // else
    //     cout << "Key not found\n";
    //
    // // modify key
    // string oldKey;
    // string updatedKey;
    //
    // cout << "\nEnter key to modify: ";
    // cin >> oldKey;
    //
    // cout << "Enter new key: ";
    // cin >> updatedKey;
    //
    // if (modify_key(hashTable, oldKey, updatedKey))
    //     cout << "Key modified\n";
    // else
    //     cout << "Original key not found\n";


//
//     return 0;
// }

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

bool search_key(const map<int, list<string>>& hashTable,
                const string& target) {
    int hashIndex{get_hash_index(target)};

    if (hashTable.count(hashIndex) == 0)
        return false;

    for (const auto& each : hashTable.at(hashIndex)) {
        if (each == target)
            return true;
    }
    return false;
}

void add_key(map<int, list<string>>& hashTable,
             const string& newKey) {

    int hashIndex{get_hash_index(newKey)};

    hashTable[hashIndex].push_back(newKey);
}

bool remove_key(map<int, list<string>>& hashTable,
                const string& target) {

    int hashIndex{get_hash_index(target)};

    // bucket doesnt exist
    if (hashTable.count(hashIndex) == 0)
        return false;

    if (!search_key(hashTable, target))
        return false;

    // remove target from list
    hashTable[hashIndex].remove(target);

    return true;
}

bool modify_key(map<int, list<string>>& hashTable,
                const string& oldKey,
                const string& newKey) {

    if (!search_key(hashTable, oldKey))
        return false;

    remove_key(hashTable, oldKey);
    add_key(hashTable, newKey);

    return true;
}