#include <bits/stdc++.h>

using namespace std;
map<int, int> past;
map<int, int> indexes; // current previous

int main() {
	vector<pair<int, int>> input;
	int N;
	cin >> N;
	int a, b;

	for(int i = 0; i < N; i++){
		cin >> a >> b;

		input.push_back(make_pair(a, b));
		past.insert(make_pair(b, i));
	}

//	int cur = 0;
//	while(cin >> a){
//		cin >> b;
//
//		input.push_back(make_pair(a, b));
//		past.insert(make_pair(b, cur));
//
//		cur++;
//	}

	sort(input.begin(), input.end());
	vector<pair<int, vector<int>>> DP (input.size(), make_pair(0, vector<int> ()));

	for(int i = 0; i < (int) input.size(); i++){
		int indexBest = i;
		indexes[i] = past[input[i].second];

		for(int j = i - 1; j >= 0; j--){
			if(input[i].second < input[j].second){
				if(DP[indexBest].first < DP[j].first){
					indexBest = j;
				}
			}
		}

		DP[i].first = DP[indexBest].first + 1;
		DP[i].second = DP[indexBest].second;
		DP[i].second.push_back(i);
	}

	int best = 0;

	for(int i = 1; i < (int) DP.size(); i++){
		if(DP[best].first < DP[i].first){
			best = i;
		}
	}

	cout << DP[best].first << endl;

	for(int i : DP[best].second){
		cout << indexes[i] + 1 << endl;
	}

	return 0;
}
