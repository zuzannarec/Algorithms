#pragma once
#include <stdint.h>
#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>
#include <list>

namespace graph
{

class Node
{
public:
    Node(int idx);
    void add_neighbour(int child_idx);
    void visit();
    std::vector<int> adjacency_list;
    int idx;
    bool visited = false;
};

class Graph
{
public:
    Graph(std::unordered_map<int, std::shared_ptr<Node>> nodes);
    std::unordered_map<int, std::shared_ptr<Node>> nodes;
    void reset();
};

bool dfs(Graph graph, int start_node_idx, int end_node_idx);

std::pair<bool, std::vector<int>> bfs(Graph graph, int start_node_idx, int end_node_idx);

} // namespace graph

namespace tree
{

class Node
{
public:
    Node(int value);
    void visit();
    int value;
    std::unique_ptr<Node> left = nullptr;
    std::unique_ptr<Node> right = nullptr;
    bool visited;
};

void inOrder(Node* node, std::vector<int>& output);

void preOrder(Node* node, std::vector<int>& output);

void postOrder(Node* node, std::vector<int>& output);

std::unique_ptr<Node> create_minimal_binary_search_tree(std::vector<int> elements);
std::unique_ptr<Node> create_minimal_binary_search_tree_(std::vector<int> elements, int low_idx, int high_idx);

std::unique_ptr<Node> create_maximal_binary_search_tree(std::vector<int> elements);

bool elementFound(std::vector<char> elements, char element);
std::vector<char> buildOrder(std::vector<char> projects,std::vector<std::pair<char, char>> dependencies);

} // namespace tree


