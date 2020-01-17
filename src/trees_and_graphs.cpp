#include "trees_and_graphs.h"

namespace graph {

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

std::pair<bool, std::vector<int>> bfs(Graph graph, int start_node_idx, int end_node_idx)
{
    std::vector<int> visited_nodes;
    visited_nodes.reserve(graph.nodes.size());
    Node* start_node = graph.nodes[start_node_idx].get();
    start_node->visit();
    std::list<int> nodes_to_search;
    nodes_to_search.push_back(start_node_idx);

    while (!nodes_to_search.empty())
    {
        visited_nodes.push_back(nodes_to_search.front());
        if (nodes_to_search.front() == end_node_idx)
        {
            return std::make_pair(true, visited_nodes);
        }
        for (auto& child_idx : graph.nodes[nodes_to_search.front()]->children)
        {
            if (!graph.nodes[child_idx]->visited)
            {
                graph.nodes[child_idx]->visit();
                nodes_to_search.push_back(child_idx);
            }
        }
        nodes_to_search.pop_front();
    }
    return std::make_pair(false, visited_nodes);
}

} // namespace graph

namespace tree
{

Node::Node(int value)
{
    this->value = value;
}

void Node::visit()
{
    this->visited = true;
}

std::shared_ptr<Node> create_minimal_binary_search_tree(std::vector<int> elements)
{
    auto it = elements.begin();
    auto root = std::shared_ptr<Node>(new Node(*it));
    std::shared_ptr<Node> parent_node;
    std::shared_ptr<Node> current_node;
    while (it != elements.end() - 1)
    {
        it++;
        if (root->left == nullptr)
        {
            auto leftmost_node = std::move(root);
            root = std::shared_ptr<Node>(new Node(*it));
            root->left = std::move(leftmost_node);
        }
        else if (root->right == nullptr)
        {
            root->right = std::shared_ptr<Node>(new Node(*it));
            parent_node = root;
            current_node = root->right;
        }
        else
        {
            if (current_node->right == nullptr)
            {
                auto rightmost_child = std::shared_ptr<Node>(new Node(*it));
                if (current_node->left == nullptr)
                {
                    auto tmp = current_node;
                    parent_node->right = rightmost_child;
                    parent_node->right->left = tmp;
                    current_node = rightmost_child;
                }
                else
                {
                    current_node->right = rightmost_child;
                    parent_node = parent_node->right;
                    current_node = current_node->right;        
                }
            }
        }
    }
    return std::move(root);
}

} // namespace tree