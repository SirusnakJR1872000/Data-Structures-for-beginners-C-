# include <vector>
# include <queue>
# include <algorithm>
# include <utility>

using std :: vector;
using std :: queue;
using std :: pair;
using std :: min;

// lets define a method for bfs to find the shortest path from top left to bottom right
int bfs(vector<vector<int>>& grid) {
    int Rows = grid.size(), Cols = grid[0].size();
    // here we will use a 2D array instead of a hashset of the dimension 4 x 4 to keep a track of the cell visited
    vector<vector<int>> visit(4, vector<int>(4));
    // we will use pair of queues to store the co ordinates of cells explored
    queue<pair<int, int>> queue;
    // the starting cell is (0,0)
    queue.push(pair<int, int>(0,0));
    // we will mark that visited by assigning 1 to it
    visit[0][0] = 1;

    // we will use another variable to keep track of the length of the path and we will initially set it to 0
    int length = 0;
    // now we will run the loop as long as there are elements in the queue
    while (queue.size()) {
        int queueLength = queue.size();
        // we will go till the length of the queue
        for (int i = 0; i < queueLength; i ++) {
            // we will retrieve the first element from the front of the queue and pop it
            pair<int, int> curPair = queue.front();
            queue.pop();
            // now we will extract the row and column indices of the current cell
            int r = curPair.first, c = curPair.second;
            // if we reach the bottom most and right most cell it means we have reached the destination
            if (r == Rows - 1 && c == Cols - 1) {
                return length;
            }

            // now we will define neighbors that is to right, left, upwards or downwards
            int neighbors[4][2] = {{r, c + 1}, {r, c - 1}, {r + 1, c}, {r - 1, c}};
            for (int j = 0; j < 4; j ++) {
                // we will have another loop to iterate through the possible neighbors
                int newR = neighbors[j][0], newC = neighbors[j][1];
                // now we will check for the conditions:
                // if it is out of bounds
                // already visisted
                // blocked value
                if (min(newR, newC) < 0 || newR == Rows || newC == Cols || visit[newR][newC] || grid[newR][newC]) {
                    continue;
                }
                // if the cell is valid then we add it to the queue and mark it as visited
                queue.push(pair<int, int>(newR, newC));
                visit[newR][newC] = 1;
            }
        }
        // increment the length
        length ++;
    }
}