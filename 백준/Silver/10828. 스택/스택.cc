#include <iostream>
#include <stack>
#include <string>
using namespace std;

int N;

void solve(void) {

	stack<int> stk;

	for (int i = 0; i < N; ++i) {

		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int X;
			cin >> X;
			stk.push(X);
		}
		else if (cmd == "pop") {
			if (stk.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << stk.top() << "\n";
				stk.pop();
			}
		}
		else if (cmd == "size") {
			cout << stk.size() << "\n";
		}
		else if (cmd == "empty") {
			cout << stk.empty() << "\n";
		}
		else if (cmd == "top") {
			if (stk.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << stk.top() << "\n";
			}
		}
	}

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	solve();

	return 0;
}