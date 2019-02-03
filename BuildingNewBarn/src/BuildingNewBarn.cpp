#include <bits/stdc++.h>

using namespace std;
set<pair<int, int>> locations;
set<pair<int, int>> work;

int Median(vector<int> coordinates){
	sort(coordinates.begin(), coordinates.end());

	if((int) coordinates.size() % 2 == 0){
		return coordinates[coordinates.size() / 2];
	}
	else{
		return (coordinates[(coordinates.size() / 2) + 1] + coordinates[(coordinates.size() / 2)] )/ 2;
	}
}

int distance(int barnX, int barnY, vector<int> X, vector<int> Y){
	int cost = 0;

	for(int i = 0; i < (int) X.size(); i++){
		cost += abs(X[i] - barnX) + abs(Y[i] - barnY);
	}

	return cost;
}

int main(){
	int N;
	cin >> N;
	vector<int> X (N, 0);
	vector<int> Y = X;

	for(int i = 0; i < N; i++){
		cin >> X[i] >> Y[i];
		locations.insert(make_pair(X[i], Y[i]));
	}

	int medianX = Median(X);
	int medianY = Median(Y);

//	cout << medianX << " " << medianY << endl;

	int dx[] = {0, 0, -1, 1, 0, 0, 0, 2, -2};
	int dy[] = {1, -1, 0, 0, 0, 2, -2, 0, 0};

	map<int, int> answers;

	for(int k = 0; k < 9; k++){
		for(int l = 0; l < 9; l++){
			if(locations.find(make_pair(medianX + dx[k], medianY + dy[l])) != locations.end() ||
					work.find(make_pair(medianX + dx[k], medianY + dy[l])) != work.end()){
				continue;
			}

			int dist = distance(medianX + dx[k], medianY + dy[k], X, Y);
			answers[dist]++;
			work.insert(make_pair(medianX + dx[k], medianY + dy[l]));
		}
	}

	cout << answers.begin()->first << " " << answers.begin()->second << endl;

	return 0;
}
