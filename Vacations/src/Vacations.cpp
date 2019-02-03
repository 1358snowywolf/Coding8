#include <bits/stdc++.h>

using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> A (N, 0);

	for(int i = 0; i < N; i++){
		cin >> A[i];
	}

	vector<vector<int>> DP (N, vector<int> (3, 200000000));
	DP[0][0] = 1;

	if(A[0] == 1 || A[0] == 3){
		DP[0][1] = 0;
	}
	if(A[0] == 2 || A[0] == 3){
		DP[0][2] = 0;
	}

	for(int i = 1; i < N; i++){
		DP[i][0] = min(DP[i - 1][0], min(DP[i - 1][1], DP[i - 1][2])) + 1;

		if(A[i] == 1 || A[i] == 3){
			DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]);
		}
		if(A[i] == 2 || A[i] == 3){
			DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]);
		}
	}

	cout << min(DP[N - 1][0], min(DP[N - 1][1], DP[N - 1][2]));

	return 0;
}
