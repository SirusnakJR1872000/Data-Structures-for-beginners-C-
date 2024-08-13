# include <vector>
# include <queue>
# include <unordered_map>
# include <unordered_set>

using std :: vector;
using std :: queue;
using std :: string;
using std :: unordered_map;
using std :: unordered_set;

// lets define a graph node for adjacency list

class GraphNode {
    public:
        string& val_;
        vector<string> neighbors_;

        GraphNode(string& val) : val_(val) {}
};

// lets define a unordered map to traverse
unordered_map<string, vector<string>> buildAdjList() {
    vector<vector<string>> edges = 
        {{"A", "B"}, {"B", "C"}, {"B", "E"}, {"C", "E"}, {"E", "D"}};
    unordered_map<string, vector<string>> adjList;

    // now we will iterate through each element in the edge collection
    for (vector<string> edge:  edges) {
        // now we will extract the source and destination from the edge
        string src = edge[0], dst = edge[1];
        adjList[src].push_back(dst);
    }
    return adjList;
}

// now lets count the path using the depth first serach approach
int dfs(string& node, string& target, unordered_map<string, vector<string>>& adjList, unordered_set<string>& visit) {
    if (visit.count(node)) {
        // if the node is in the visited section we just return 0
        return 0;
    }
    if (node == target) {
        // it might be possible that the node is the target so we return true value
        return 1;
    }

    int count = 0;
    // set the initial count to 0
    // we will add the node to the visited section
    visit.insert(node);
    for (string neighbor: adjList[node]) {
        // now we recursively call the dfs function
        count += dfs(neighbor, target, adjList, visit);
    }
    // now we will remove the node from visited to see if any other paths exist to destination
    visit.erase(node);
    return count;
}

// now lets count the shortest path from node to target
int bfs(string& node, string& target, unordered_map<string, vector<string>>& adjList) {
    int length = 0;
    unordered_set<string> visit;
    queue<string> queue;
    visit.insert(node);
    queue.push(node);

    // now we run the loop till there are elements in the queue
    while (queue.size()) {
        int queueLength = queue.size();
        for (int i = 0; i < queueLength; i ++) {
            // now we set the curr pointer to front of the queue
            string curr = queue.front();
            // now we remove the node
            queue.pop();
            // if the curr node is the target then we return length
            if (curr == target) {
                return length;
            }

            // now we go through the nodes in the neighbors
            for (string neighbor: adjList[curr]) {
                // if the neighbor is not visited then we add it to visited and then push it into the queue
                if (visit.count(neighbor) == 0) {
                    visit.insert(neighbor);
                    queue.push(neighbor);
                }
            }
        }
        length ++;
    }
    return length;
}