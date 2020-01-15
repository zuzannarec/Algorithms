#include "trees_and_graphs.h"

using namespace graph;

Node::Node(int idx)
{
    this->idx = idx;
}

void Node::add_child(int child_idx)
{
    this->children.push_back(child_idx);
}

void Node::visit()
{
    this->visited = true;
}

Graph::Graph(std::unordered_map<int, std::shared_ptr<Node>> nodes)
{
    this->nodes = nodes;
}

void Graph::reset()
{
    for (auto& node : this->nodes)
    {
        node.second->visited = false;
    }
}

std::pair<bool, std::vector<int>> bfs(graph::Graph graph, int start_node_idx, int end_node_idx)
{
    std::vector<int> visited_nodes;
    visited_nodes.reserve(graph.nodes.size());
    Node* start_node = graph.nodes[start_node_idx].get();
    start_node->visit();
    std::vector<int> nodes_to_search;
    nodes_to_search.reserve(graph.nodes.size());
    nodes_to_search.push_back(start_node_idx);
    auto it_start = nodes_to_search.begin();

    while (!nodes_to_search.empty() &&
           it_start != nodes_to_search.end())
    {
        visited_nodes.push_back(*it_start);
        if (*it_start == end_node_idx)
        {
            return std::make_pair(true, visited_nodes);
        }
        for (auto& child_idx : graph.nodes[*it_start]->children)
        {
            if (!graph.nodes[child_idx]->visited)
            {
                graph.nodes[child_idx]->visit();
                nodes_to_search.push_back(child_idx);
            }
        }
        it_start++;
    }
    return std::make_pair(false, visited_nodes);
}

