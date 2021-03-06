#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	cin >> str;

	int N = (int) str.size();
	str = '0' + str;
	vector<vector<int>> palindromes (str.size() + 1, vector<int> (str.size() + 1, 0));

	for(int i = 1; i <= N; i++){
		palindromes[i][i] = 1;
	}

	for(int i = 1; i < N; i++){
		if(str[i] == str[i + 1]){
			palindromes[i][i + 1] = 1;
		}
	}


	for(int length = 0; length < N - 2; length++){
		for(int L = 1; L < N - length; L++){
			if(palindromes[L][length + L] == 1 && str[L - 1] == str[L + length + 1]){
				palindromes[L - 1][length + L + 1] = 1;
			}
		}

	}

	vector<vector<int>> DP (str.size() + 1, vector<int> (str.size() + 1, 0));

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			DP[i][j] = palindromes[i][j] + DP[i - 1][j] + DP[i][j - 1] - DP[i - 1][j - 1];
		}
	}

	int querries;
	cin >> querries;

	for(int i = 0; i < querries; i++){
		int L, R;
		cin >> L >> R;

		cout << DP[R][R] - DP[L - 1][R] - DP[R][L - 1] + DP[L - 1][L - 1] << endl;
	}

	return 0;
}
