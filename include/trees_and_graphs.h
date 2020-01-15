#pragma once
#include <stdint.h>
#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>

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

std::vector<int> find_route_between_nodes(Node first, Node second);
}

std::pair<bool, std::vector<int>> bfs(graph::Graph graph, int start_node_idx, int end_node_idx);



