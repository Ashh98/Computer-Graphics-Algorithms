#include<iostream>
#include<vector>;
using namespace std;

void DDA(int& x1, int& x2, int& y1, int& y2, vector<vector<int>>& plt) {
	double x, y, dx, dy, steps;
	plt.resize(15, vector<int>(15, 0));
	x = x1; y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	if (abs(dy) > abs(dx)) steps = abs(dy);
	else steps = abs(dx);

	dy = dy / steps;
	dx = dx / steps;

	for (int i = 0; i <= steps; i++) {
		plt[(int) round(x)][(int) round(y)] = 1;
		x += dx;
		y += dy;
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
	DDA(x1, x2, y1, y2, plt);
	drawGraph(plt);

	return 0;
}