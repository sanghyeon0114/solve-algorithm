#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <unordered_map>
#include <time.h>

using namespace std;

void preorder(vector<vector<char>> &graph, char current) {
    cout << current;
    if(graph[current-65][0] != 0) 
        preorder(graph, graph[current-65][0]);
    
    if(graph[current-65][1] != 0)
        preorder(graph, graph[current-65][1]);
}

void inorder(vector<vector<char>> &graph, char current) {
    if(graph[current-65][0] != 0)
        inorder(graph, graph[current-65][0]);
    cout << current;
    if(graph[current-65][1] != 0) 
        inorder(graph, graph[current-65][1]);
}

void postorder(vector<vector<char>> &graph, char current) {
    if(graph[current-65][0] != 0)
        postorder(graph, graph[current-65][0]);
    if(graph[current-65][1] != 0) 
        postorder(graph, graph[current-65][1]);
    cout << current;
}

int main() {

    int N;
    cin >> N;

    vector<vector<char>> graph;

    for(char a = 0; a < 26; a++) {
        graph.push_back({0, 0});
    }

    for(int i = 0; i < N; i++) {
        char root, left, right;
        cin >> root >> left >> right;
        if(left != 46) {
            graph[root-65][0] = left;
        }
        if(right != 46) {
            graph[root-65][1] = right;
        }
    }

    preorder(graph, 'A');
    cout << "\n";
    inorder(graph, 'A');
    cout << "\n";
    postorder(graph, 'A');
    cout << "\n";

    return 0;
}