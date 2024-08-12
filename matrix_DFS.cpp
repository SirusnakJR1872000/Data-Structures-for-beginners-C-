// lets implement a matrix DFS 
// import all the required libraries
# include <vector>
# include <algorithm>

using std :: vector;
using std :: min;

// lets define a DFS function 

int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& visit) {
    // the rows would be of the outer size of the grid
    // whereas the columns would be of the inner size of the grid
    int Rows = grid.size(),  Cols = grid[0].size();
    // now we will check for the conditions:
    // where the node is out of bounds
    // it is already visited
    // or it is a blocked node
    if (min(r,c) < 0 || r == Rows || c == Cols || visit[r][c] || grid[r][c]) {
        return 0;
    }
    // if we reach the right and bottom most node then we know we have reached the destination
    if (r == Rows - 1 && c == Cols -1) {
        return 1;
    }
    // we will add it to the visited node
    visit[r][c] = 1;

    // now we will initialize a counter variable which we will first set to 0
    // then we will keep on adding as per the 4 movements
    int count = 0;
    count += dfs(grid, r + 1, c, visit);
    count += dfs(grid, r - 1, c, visit);
    count += dfs(grid, r, c + 1, visit);
    count += dfs(grid, r, c - 1, visit);

    // if we remove the node from the visited list if there are any other probable paths
    visit[r][c] = 0;
    return count;
}