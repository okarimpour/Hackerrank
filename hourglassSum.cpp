#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int ROW = arr.size();
    int COL = arr[0].size();
    int row, col;
    int maxHourglassSum= -63;
    if (ROW < 3 || COL < 3) {
        throw "The input matrix is smaller than 3X3";
    }

    for (row = 1; row < ROW - 1; ++row) {
        for (col = 1; col < COL - 1; ++col) {
            maxHourglassSum = std::max(maxHourglassSum, arr[row][col] + arr[row-1][col-1] + arr[row-1][col] + arr[row-1][col+1] + arr[row+1][col-1] + arr[row+1][col] + arr[row+1][col+1]);
        }
    }
    return maxHourglassSum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

