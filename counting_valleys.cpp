#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int level = 0;
    int number_of_valleys = 0;
    int string_element;
    for (string_element = 0; string_element < n; ++string_element) {
        if (s[string_element] == 'D' && level == 0) {
            number_of_valleys += 1;
            level -= 1;
        } else if (s[string_element] == 'D' && level != 0) {
            level -= 1;
        } else if (s[string_element] == 'U') {
            level +=1;
        }
    }

    return number_of_valleys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
