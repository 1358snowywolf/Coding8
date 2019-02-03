#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, P, Q, R;
	cin >> N >> P >> Q >> R;

	vector<long long> A (N, 0);
	vector<long long> multiply = {P, Q, R};
	vector<vector<long long>> DP (3, vector<long long> (N, 0));

	for(int i = 0; i < N; i++){
		cin >> A[i];
	}

	for(int i = 0; i < 3; i++){
		DP[i][0] = (i == 0) ? A[0] * multiply[i] :
				DP[i - 1][0] + (A[0] * multiply[i]);

		for(int j = 1; j < N; j++){
			long long current = max(DP[i][j - 1], (i == 0) ? A[j] * multiply[i] :
											DP[i - 1][j] + (A[j] * multiply[i]));

			DP[i][j] = current;
		}
	}

	cout << DP[2][N - 1];

	return 0;
}
