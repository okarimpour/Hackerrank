#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    //int quotient = n / s.size();
    //int reminder = n % s.size();
    int numbers_of_a = 0;
    int rest_of_a = 0;
    int element;
    
    for (element = 0; element < s.size(); ++element) {
        if (s[element] == 'a') {
            numbers_of_a += 1;
        }
        if (n % s.size() == element + 1) {
            rest_of_a = numbers_of_a;
        }
    }

    auto total_numbers_of_a = numbers_of_a * (n / s.size()) + rest_of_a;
    return total_numbers_of_a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}

