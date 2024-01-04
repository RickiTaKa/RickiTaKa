#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;


bool newNode(vector<vector<int>> g, int start, int finish, int num) {

    int cost;
    vector<bool> visit(num, false);
    vector<int> q;

    q.push_back(start);

    while (!q.empty()) {

        cost = q.back();
        q.pop_back();

        if (!visit.at(cost)) {

            visit.at(cost) = true;

            for (auto temp : g.at(cost)) {
                q.push_back(temp);
            }

        }
    }

    return visit.at(finish);
}

int search(vector<tuple<int, char, char>> m, vector<vector<int>> g, int num) {

    int result = 0;
    bool check;

    for (auto n : m) {

        check = newNode(g, get<1>(n) - 'A', get<2>(n) - 'A', num);

        if (!check) {

            result += get<0>(n);
            g.at(get<1>(n) - 'A').push_back(get<2>(n) - 'A');
            g.at(get<2>(n) - 'A').push_back(get<1>(n) - 'A');

        }
    }

    return result;
}

int main()
{
    int num, result;
    vector<tuple<int, char, char>> map;
    vector<vector<int>> graph;

    cin >> num;

    while (num != 0) {
        
        graph.resize(num);

        for (int x = 0; x < num - 1; x++) {

            char st, end;
            int paths, con;

            cin >> st;
            cin >> paths;

            for (int y = 0; y < paths; y++) {

                cin >> end;
                cin >> con;
                map.push_back({ con, st, end });

            }

        }
        sort(map.begin(), map.end());

        result = search(map, graph, num);

        cout << result << endl;

        map.clear();
        graph.clear();

        cin >> num;
    }
}