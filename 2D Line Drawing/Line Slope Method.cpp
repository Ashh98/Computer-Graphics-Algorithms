#include<iostream>
#include<vector>;
using namespace std;

void LineSlope(int& x1, int& x2, int& y1, int& y2, vector<vector<int>>& plt) {
	int dx, dy, m, c, x, y, xend;
	
	plt.resize(5, vector<int>(10, 0));
	dy = y2 - y1;
	dx = x2 - x1;
	m = dy / dx;
	c = y1 - (m * x1);

	if (dx < 0) {
		xend = x1;
		x = x2;
		y = y2;
	}
	else {
		xend = x2;
		x = x1;
		y = y1;
	}
	while (x <= xend) {
		cout << x << " " << y << endl;
		plt[x][y] = 1;
		x++;
		y = (m * x) + c;
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
	LineSlope(x1, x2, y1, y2, plt);
	drawGraph(plt);

	return 0;
}