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
    void add_child(int child_idx);
    void visit();
    std::vector<int> children;
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

std::unique_ptr<Node> create_minimal_binary_search_tree(std::vector<int> elements);

} // namespace tree


