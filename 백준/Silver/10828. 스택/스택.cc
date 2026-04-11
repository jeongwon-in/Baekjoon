#include <iostream>
#include <stack>
#include <string>
using namespace std;

int N;
string command[5] = { "push", "pop", "size", "empty", "top" };

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	stack<int> stack;

	for (int i = 0; i < N; ++i) {

		string cmd;
		cin >> cmd;

		if (!cmd.compare(command[0])) {
			int X;
			cin >> X;
			stack.push(X);
		}
		else if (!cmd.compare(command[1])) {
			if (stack.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << stack.top() << "\n";
				stack.pop();
			}
		}
		else if (!cmd.compare(command[2])) {
			cout << stack.size() << "\n";
		}
		else if (!cmd.compare(command[3])) {
			cout << stack.empty() << "\n";
		}
		else if (!cmd.compare(command[4])) {
			if (stack.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << stack.top() << "\n";
			}
		}

	}

	return 0;
}