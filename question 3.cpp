#include <iostream>
#include <cstring>
using namespace std;

void printList(char **list, int size) {
    for (int i = 0; i < size; i++) {
        cout << list[i] << endl;
    }
}

int main() {
    int size = 5;
    char **list = new char*[size];

    const char *words[] = {"alpha", "bravo", "charlie", "delta", "echo"};

    // allocate + copy words
    for (int i = 0; i < size; i++) {
        list[i] = new char[strlen(words[i]) + 1];
        strcpy(list[i], words[i]);
    }

    cout << "Initial list:\n";
    printList(list, size);

    // search "delta"
    cout << "\nSearching for 'delta':\n";
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i], "delta") == 0) {
            cout << "Found at index " << i << endl;
        }
    }

    // modify index 1 ? blueberry
    delete[] list[1];
    list[1] = new char[strlen("blueberry") + 1];
    strcpy(list[1], "blueberry");

    cout << "\nAfter modification:\n";
    printList(list, size);

    // delete "charlie"
    int deleteIndex = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(list[i], "charlie") == 0) {
            deleteIndex = i;
            break;
        }
    }

    if (deleteIndex != -1) {
        delete[] list[deleteIndex];

        for (int i = deleteIndex; i < size - 1; i++) {
            list[i] = list[i + 1]; // shift left
        }
        size--;
    }

    cout << "\nAfter deletion:\n";
    printList(list, size);

    // free memory
    for (int i = 0; i < size; i++) {
        delete[] list[i];
    }
    delete[] list;

    return 0;
}