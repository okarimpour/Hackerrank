#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <sstream> 
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>

using namespace std;

vector<string> split_string(string);

// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int> > edges, int s) {
    std::vector<int> pathCost (n + 1, -1);
    std::vector<bool> visited (n + 1, false);
    std::queue<int> q;
    visited[s] = true;
    pathCost[s] = 0;
    q.push(s);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int i = 0; i < edges.size(); i++) {
            if (edges[i][0] == v) {
                if (visited[edges [i][1]] == false) {
                    visited[edges [i][1]] = true;
                    q.push(edges [i][1]);
                    pathCost[edges [i][1]] = pathCost[v] + edges [i][2];
                }
                else if (visited[edges [i][1]] == true && pathCost[v] + edges [i][2] < pathCost[edges [i][1]]) {
                    pathCost[edges [i][1]] = pathCost[v] + edges [i][2];
                }
            }
            else if (edges[i][1] == v) {
                if (visited[edges [i][0]] == false) {
                    visited[edges [i][0]] = true;
                    q.push(edges [i][0]);
                    pathCost[edges [i][0]] = pathCost[v] + edges [i][2];
                }
                else if (visited[edges [i][0]] == true && pathCost[v] + edges [i][2] < pathCost[edges [i][0]]) {
                    pathCost[edges [i][0]] = pathCost[v] + edges [i][2];
                }
            }
        }
    }
    pathCost.erase (pathCost.begin());
    pathCost.erase (pathCost.begin() + s - 1);
    return pathCost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int> > edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(3);

            for (int j = 0; j < 3; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = shortestReach(n, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
