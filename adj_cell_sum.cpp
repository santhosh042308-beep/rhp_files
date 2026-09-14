#include <iostream>
#include <vector>

using namespace std;

void solve(){
  int R, C; cin >> R >> C;

    vector<vector<int>> grid(R, vector<int>(C));
    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            cin >> grid[row][col];
        }
    }

    int row, col;
    cin >> row >> col;

    const int diff[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

    long long sum = 0; 
    for (int i = 0; i < 8; i++) {
        int adjRow = row + diff[i][0];
        int adjCol = col + diff[i][1];

        if (adjRow >= 0 && adjRow < R && adjCol >= 0 && adjCol < C) {
            sum += grid[adjRow][adjCol];
        }
    }

    cout << sum << "\n";

    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    while(tc--) solve();
    return 0;
}
