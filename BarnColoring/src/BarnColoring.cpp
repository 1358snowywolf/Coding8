#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> graph;
map<int, int> determined;
vector<bool> visited;
int MOD = 1000000007;

long long helper(int i, vector<vector<long long>> tmp){
	long long product = 1;

	for(auto j : tmp){
		int tmp = j[0] + j[1] + j[2];
		tmp -= j[i];

		product *= tmp;
		product %= MOD;
	}

	return product;
}

vector<long long> DFS(int u){
	vector<long long> answer (3, 0);
	visited[u] = true;

	if(determined.find(u) != determined.end()){
		answer[determined[u] - 1] = 1;
	}
	else{
		answer = {1, 1, 1};
	}

	vector<vector<long long>> tmp;

	for(int v : graph[u]){
		if(visited[v]) continue;
		tmp.push_back(DFS(v));
	}

	for(int i = 0; i < 3; i++){
		answer[i] *= helper(i, tmp);
		answer[i] %= MOD;
	}

	return answer;
}

int main(){
	freopen("barnpainting.in", "r", stdin);
	freopen("barnpainting.out", "w", stdout);

	int N, K;
	cin >> N >> K;

	for(int i = 0; i < N - 1; i++){
		int u, v;
		cin >> u >> v;

		graph[u - 1].push_back(v - 1);
		graph[v - 1].push_back(u - 1);
	}

	for(int i = 0; i < K; i++){
		int barn, color;
		cin >> barn >> color;

		determined[barn - 1] = color;
	}

//	for(auto i : determined){
//		cout << i.first << " " << i.second << endl;
//	}

//	for(auto i : graph){
//		cout << i.first << ": ";
//
//		for(auto j : i.second){
//			cout << j << ", ";
//		}
//		cout << endl;
//	}

	visited.assign(N, false);
	vector<long long> vec;

	for(int i = 0; i < N; i++){
		if(determined.find(i) == determined.end()){
			vec = DFS(i);
			break;
		}
	}

	int sum = 0;

	for(int i : vec){
//		cout << i << " ";
		sum += i;
		sum %= MOD;
	}

//	cout << endl;
	cout << sum;

	return 0;
}
