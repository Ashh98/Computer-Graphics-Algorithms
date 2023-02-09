#include<iostream>
#include<vector>;
using namespace std;

void midPointCircle(int& xi, int& yi, int& r, vector<vector<int>>& plt) {
	int x = xi, y = yi + r;
	int p;
	while (x <= y) {
		if (x == xi) {
			p = 1 - r;
			if (p >= 0) y--;
			x++;
			plt[x][y] = 1;
		}
		else {
			if (p < 0) {
				p = p + 1 + 2 * (x + 1);
				if (p >= 0) y--;
			}
			else {
				p = p + 1 + 2 * (x + 1) - 2 * y + 1;
				if (p >= 0) y--;
			}
			x++;
			plt[x][y] = 1;
		}
		cout << x << " " << y << endl;
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
	int x, y, r;
	vector<vector<int>> plt;
	plt.resize(12, vector<int>(12, 0));
	cout << "Please enter x: ";
	cin >> x;
	cout << "Please enter y: ";
	cin >> y;
	cout << "Please enter r: ";
	cin >> r;
	midPointCircle(x, y, r, plt);
	drawGraph(plt);

	return 0;
}