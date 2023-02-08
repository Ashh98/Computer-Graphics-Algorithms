#include<iostream>
#include<vector>;
using namespace std;

void bresenhamLine(int& x1, int& x2, int& y1, int& y2, vector<vector<int>>& plt) {
	int dx = x2 - x1, dy = y2 - y1;
	int x = x1, y = y1;
	int p = 2* dx - dy;
	plt.resize(10, vector<int>(10, 0));

	plt[x2][y2] = 1;
	while (x < x2) {
		plt[x][y] = 1;
		if (p < 0) {
			p = p + 2 * dy;
		}
		else {
			p = p + 2 * dy - 2 * dx;
			y++;
		}
		x++;
	}
}

void drawGraph(vector<vector<int>>& plt) {
	for (int i = 0; i < plt.size(); i++) {
		for (int j = 0; j < plt[0].size(); j++) {
			cout << plt[i][j];
		}
		cout << endl;
	}
}


int main() {
	int x1, x2, y1, y2;
	vector<vector<int>> plt;
	cout << "Please enter x1: ";
	cin >> x1;
	cout << "Please enter y1: ";
	cin >> y1;
	cout << "Please enter x2: ";
	cin >> x2;
	cout << "Please enter y2: ";
	cin >> y2;
	bresenhamLine(x1, x2, y1, y2, plt);
	drawGraph(plt);

	return 0;
}