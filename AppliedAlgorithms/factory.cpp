#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

void findPath(int N, int M, map<string, int> num, vector<string> names, vector<vector<int>> adj) {

    vector<vector<long long int>> d(N, vector<long long int>(N));

    for (int c = 0; c < N; c++) {

        for (int x = 0; x < N; x++) {

            if (c == x) {
                d[c][x] = 0;
            }
            else if (adj[c][x]) {
                d[c][x] = adj[c][x];
            }
            else {
                d[c][x] = UINT_MAX;
            }
        }
    }

    for (int i = 0; i < N; i++) {

        for (int x = 0; x < N; x++) {

            for (int y = 0; y < N; y++) {

                d[x][y] = min(d[x][y], d[x][i] + d[i][y]);

            }
        }
    }
    
    int best = 0;
    long long int total = LLONG_MAX;

    for (int c = 0; c < N; c++) {

        long long int sum = 0;

        int count = 0;

        while (count < N && d[c][count] != UINT_MAX) {
            sum += d[c][count];
            count++;
        }

        if (count != N) continue;

        if (sum < total) {
            total = sum;
            best = c;
        }
    }
    
    if (total != LLONG_MAX) {
        cout << names[best] << endl;
    }
    else {
        cout << "No suitable location" << endl;
    }

}

int main() {
    int M, N;

    cin >> N;

    while (N != 0) {

        cin >> M;

        map<string, int> num;
        vector<string> names(N);
        vector<vector<int>> adj(N, vector<int>(N));

        int x = 0;

        for (int i = 0; i < M; i++) {

            string from, to;
            int weight;

            cin >> from;
            cin >> to;
            cin >> weight;

            if (!num.count(from)) {
                names[x] = from;
                num[from] = x;
                x++;
            }
            if (!num.count(to)) {
                names[x] = to;
                num[to] = x;
                x++;
            }

            adj[num[from]][num[to]] = weight;

        }

        findPath(N, M, num, names, adj);

        cin >> N;

    }

}