#include <bits/stdc++.h>

using namespace std;

void print(vector<int> path, int end, vector<pair<pair<int, int>, int>> input) {
    if(end > -1) {
        print(path, path[end], input);
        cout << input[end].second + 1 << endl;
    }
}

int main() {
	vector<pair<pair<int, int>, int>> input;
	int index = 0;
	int weight, IQ;

    while(cin >> weight >> IQ){
        input.push_back(make_pair(make_pair(weight, IQ), index));  // weight smartness index
        index++;
    }

    sort(input.begin(), input.end());

    vector<int> DP (input.size(), 0);
    vector<int> path (input.size(), 0);
    int maximum = 1;
    int position = 0;

    DP[0] = 1;
    path[0] = -1;

    for(int i = 1; i < input.size(); i++) {
        int parent = -1;
        DP[i] = 1;

        for(int j = 0; j < i; j++) {
            if(input[j].first.first < input[i].first.first && input[j].first.second > input[i].first.second && DP[i] < DP[j] + 1) {
                DP[i] = DP[j] + 1;
                parent = j;
            }
        }

        path[i] = parent;

        if(maximum < DP[i]) {
            maximum = DP[i];
            position = i;
        }
    }

    cout << maximum << endl;
    print(path, position, input);
}
