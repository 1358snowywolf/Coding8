#include <bits/stdc++.h>

using namespace std;
vector<vector<vector<int>>> DP (100, vector<vector<int>> (101, vector<int> (100, 2000000000)));

int findMin(int i, int j, int N){
	int minimum = INT_MAX;

	for(int k = 0; k < N; k++){
		minimum = min(minimum, DP[i - 1][j - 1][k]);
	}

	return minimum;
}

int main() {
	int N;
	cin >> N;

	vector<int> log (N, 0);

	for(int i = 0; i < N; i++){
		cin >> log[i];
	}

	if(log[0] == 0){
		DP[0][1][0] = 0;
	}
	else{
		DP[0][1][0] = 1;
	}

	for(int i = 1; i < N; i++){
		for(int j = 1; j < N; j++){
			for(int k = 0; k < N; k++){
				if(k == 0){
					DP[i][j][k] = findMin(i, j, N);

					if(log[i] != k){
						DP[i][j][k]++;
					}
				}
				else{
					DP[i][j][k] = DP[i - 1][j][k - 1];
				}
			}
		}
	}

	for(int j = 1; j < N + 1; j++){
		int answer = INT_MAX;

		for(int k = 0; k < N; k++){
			answer = min(answer, DP[N - 1][j][k]);
		}

		cout << answer << endl;
	}

	return 0;
}