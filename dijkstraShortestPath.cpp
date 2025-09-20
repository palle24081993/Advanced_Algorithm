#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <set>
#include <algorithm>

using namespace std;

unordered_map<char, unordered_map<char, int>> graph = {
    {'A', {{'B', 10}, {'E', 3}}},
    {'B', {{'C', 2}, {'E', 4}}},
    {'C', {{'D', 9}}},
    {'D', {{'C', 7}}},
    {'E', {{'B', 1}, {'C', 8}}}
};

char findClosestUnvisitedNode(const unordered_map<char, int>& distanceMap, const set<char>& visitedNodes) {
    int minDistance = numeric_limits<int>::max();
    char bestNode = '\0';
    for (const auto& entry : distanceMap) {
        char node = entry.first;
        int distance = entry.second;
        if (visitedNodes.find(node) == visitedNodes.end() && distance < minDistance) {
            minDistance = distance;
            bestNode = node;
        }
    }
    return bestNode;
}

pair<int, vector<char>> dijkstraShortestPath(char startNode, char targetNode) {
    unordered_map<char, int> distanceMap;
    unordered_map<char, char> parentNode;
    set<char> visitedNodes;
    for (const auto& entry : graph) {
        distanceMap[entry.first] = numeric_limits<int>::max();
    }
    distanceMap[startNode] = 0;
    while (visitedNodes.size() < graph.size()) {
        char currentNode = findClosestUnvisitedNode(distanceMap, visitedNodes);
        if (currentNode == '\0') break;  
        visitedNodes.insert(currentNode);
        for (const auto& neighbor : graph[currentNode]) {
            char neighborNode = neighbor.first;
            int edgeWeight = neighbor.second;
            if (visitedNodes.find(neighborNode) == visitedNodes.end()) {
                int newDistance = distanceMap[currentNode] + edgeWeight;
                if (newDistance < distanceMap[neighborNode]) {
                    distanceMap[neighborNode] = newDistance;
                    parentNode[neighborNode] = currentNode;
                }
            }
        }
        if (currentNode == targetNode) break;
    }
    vector<char> shortestPath;
    int totalCost = distanceMap[targetNode];
    if (totalCost == numeric_limits<int>::max()) {
        return {totalCost, {}};  
    }
    for (char at = targetNode; at != startNode; at = parentNode[at]) {
        if (parentNode.find(at) == parentNode.end()) return {numeric_limits<int>::max(), {}};
        shortestPath.push_back(at);
    }
    shortestPath.push_back(startNode);
    reverse(shortestPath.begin(), shortestPath.end());
    return {totalCost, shortestPath};
}

int main() {
    char startNode, targetNode;
    cout << "Enter start node (A-E): ";
    cin >> startNode;
    cout << "Enter target node (A-E): ";
    cin >> targetNode;
    startNode = toupper(startNode);
    targetNode = toupper(targetNode);
    if (graph.find(startNode) == graph.end() || graph.find(targetNode) == graph.end()) {
        cout << "Error: Invalid node entered.\n";
        return 1;
    }
    auto result = dijkstraShortestPath(startNode, targetNode);
    if (!result.second.empty()) {
        cout << "Shortest path: ";
        for (char node : result.second) cout << node << " ";
        cout << "\nTotal cost: " << result.first << endl;
    } else {
        cout << "No path exists between " << startNode << " and " << targetNode << ".\n";
    }
    return 0;
}
