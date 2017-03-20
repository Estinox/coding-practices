#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> &A) {

	// store the odds and evens
	map<int, int> count;
	for (auto v : A) {
		if (count.count(v) == 0)
			count[v] = 1;
		else
			count[v] += 1;
	}

	for (auto kvp : count)
		cout << kvp.first << " " << kvp.second << "\n";

	// roll counts up, 4 of even before rolls up
	for (auto& kvp : count) {
		int rollable = kvp.second / 4;
		if (rollable > 0 ) {
			kvp.second -= rollable * 4;
			if (count.count(kvp.first + 2) == 0) {
				count[kvp.first + 2] = rollable;
			} else {
				count[kvp.first + 2] += rollable;
			}
		}
	}

	// reduce
	cout << "-----\n";
	auto before = count.rbegin();
	for (auto it = count.rbegin(); it != count.rend(); ++it) {
		if (before == it)
			continue;
		cout << it->first << " " << it->second << " before= " << before->first << " " << before->second << '\n'; // << it+1 << '\n';

		if (before->first - it->first == 1) {
			int reduceable = it->second / 2;
			if (before->second > reduceable)
				before->second -= reduceable;
			else {
				before->second = 0;
				reduceable -= before->second;
				it->second -= reduceable * 2;
			}
		}

		before = it;
	}

	// base 10
	cout << "\n-----\n";
	int sum = 0;
	for (auto kvp : count) {
		cout << kvp.first << " " << kvp.second << "=" << pow(-2, kvp.first) * kvp.second << "\n";
		sum += pow(-2, kvp.first) * kvp.second;
	}

	return sum;
}

int main() {
	//vector<int> v {0,0,0,0,0};
	vector<int> v {5,4,7};
	cout << solution(v);

}
