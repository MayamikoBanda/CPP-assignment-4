#include <iostream>
#include <cstring>
using namespace std;

void print_seat(int **seat, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%02d ", seat[i][j]); // print 2 digits
        }
        cout << endl;
    }
}

int main() {
    int row = 10, col = 10;

    // allocate 2D array
    int **seat = new int*[row];
    for (int i = 0; i < row; i++) {
        seat[i] = new int[col];
        memset(seat[i], 0, col * sizeof(int)); // initialize
    }

    // assign values
    seat[0][0]=11; seat[0][3]=24;
    seat[1][1]=35;
    seat[2][5]=47;
    seat[3][3]=58;
    seat[4][9]=69;
    seat[5][0]=70; seat[5][5]=81; seat[5][9]=92;
    seat[6][4]=13;
    seat[7][7]=26;
    seat[8][2]=39;
    seat[9][9]=44;

    cout << "Original:\n";
    print_seat(seat, row, col);

    // backup array
    int **backup = new int*[row];
    for (int i = 0; i < row; i++) {
        backup[i] = new int[col];
        memcpy(backup[i], seat[i], col * sizeof(int)); // copy row
    }

    cout << "\nBackup:\n";
    print_seat(backup, row, col);

    // clear row 5
    memset(seat[5], 0, col * sizeof(int));

    cout << "\nAfter clearing row 5 (original):\n";
    print_seat(seat, row, col);

    cout << "\nBackup remains:\n";
    print_seat(backup, row, col);

    // find row with most non-zero
    int maxRow = 0, maxCount = 0;

    for (int i = 0; i < row; i++) {
        int count = 0;
        for (int j = 0; j < col; j++) {
            if (backup[i][j] != 0) count++;
        }
        if (count > maxCount) {
            maxCount = count;
            maxRow = i;
        }
    }

    cout << "\nRow with most assigned seats: " << maxRow << endl;

    // free memory
    for (int i = 0; i < row; i++) {
        delete[] seat[i];
        delete[] backup[i];
    }
    delete[] seat;
    delete[] backup;

    return 0;
}