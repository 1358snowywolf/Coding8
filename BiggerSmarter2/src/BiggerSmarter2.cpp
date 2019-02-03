#include <bits/stdc++.h>

using namespace std;
map<int, int> past;
map<int, int> indexes; // current previous

int main(){
	vector<pair<int, int>> input;
	int N;
	cin >> N;
	int a, b;
	vector<int> parents;

	for(int i = 0; i < N; i++){
		cin >> a >> b;

		input.push_back(make_pair(a, b));
		parents.push_back(i);
		past.insert(make_pair(b, i));
	}

	sort(input.begin(), input.end());
	vector<int> DP (input.size(), 0);

	DP[0] = 1;
	indexes[0] = past[input[0].second];

	for(int i = 1; i < N; i++){
		int bestIndex = i;
//		indexes[past[input[i].second]] = i;
		indexes[i] = past[input[i].second];

		for(int j = i - 1; j >= 0; j--){
			if(DP[bestIndex] < DP[j] && input[i].second < input[j].second){
				bestIndex = j;
			}
		}

		parents[i] = bestIndex;
		DP[i] = DP[bestIndex] + 1;
	}

	int best = 0;

	for(int i = 1; i < N; i++){
		if(DP[best] < DP[i]){
			best = i;
		}
	}

//	for(int i = 0; i < N; i++){
//		cout << parents[i] << " ";
//	}
//	cout << endl;


	cout << DP[best] << endl;
	int pre = -1;
	int u = parents[best];

	while(pre == -1 || pre != parents[u]){
//		cout << indexes[u] + 1 << endl;
		cout << indexes[u] + 1 << endl;
		pre = u;
		u = parents[u];
	}

	cout << indexes[u];

	return 0;
}
