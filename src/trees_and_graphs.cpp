#include "trees_and_graphs.h"

namespace graph {

Node::Node(int idx)
{
    this->idx = idx;
}

void Node::add_neighbour(int child_idx)
{
    this->adjacency_list.push_back(child_idx);
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
        for (auto& child_idx : graph.nodes[nodes_to_search.front()]->adjacency_list)
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

bool dfs(Graph graph, int start_node_idx, int end_node_idx)
{
    bool is_route = false;
    graph.nodes[start_node_idx]->visit();
    if (start_node_idx == end_node_idx)
    {
        return true;
    }
    for (auto& each : graph.nodes[start_node_idx]->adjacency_list)
    {          
        if (!graph.nodes[each]->visited)
        {
            start_node_idx = each;
            is_route = dfs(graph, start_node_idx, end_node_idx);
        }
    }
    return is_route;
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

void inOrder(Node* node, std::vector<int>& output)
{
    if (node != nullptr)
    {
        inOrder(node->left.get(), output);
        output.push_back(node->value);
        inOrder(node->right.get(), output);
    }
}

void preOrder(Node* node, std::vector<int>& output)
{
    if (node != nullptr)
    {
        output.push_back(node->value);
        preOrder(node->left.get(), output);
        preOrder(node->right.get(), output);
    }
}

void postOrder(Node* node, std::vector<int>& output)
{
    if (node != nullptr)
    {
        postOrder(node->left.get(), output);
        postOrder(node->right.get(), output);
        output.push_back(node->value);
    }
}

std::unique_ptr<Node> create_minimal_binary_search_tree(std::vector<int> elements)
{
    if (elements.size() == 0)
    {
        return nullptr;
    }
    return create_minimal_binary_search_tree_(elements, 0, elements.size() - 1);
}

std::unique_ptr<Node> create_minimal_binary_search_tree_(std::vector<int> elements, int low_idx, int high_idx)
{
    if (low_idx > high_idx)
    {
        return nullptr;
    }
    int mid_idx = (low_idx + high_idx) / 2;
    std::unique_ptr<Node> root = std::unique_ptr<Node>(new Node(elements[mid_idx]));
    root->left = create_minimal_binary_search_tree_(elements, low_idx, mid_idx - 1);
    root->right = create_minimal_binary_search_tree_(elements, mid_idx + 1, high_idx);
    return std::move(root);
}

std::unique_ptr<Node> create_maximal_binary_search_tree(std::vector<int> elements)
{
    auto it = elements.begin();
    auto root = std::unique_ptr<Node>(new Node(*it));
    std::unique_ptr<Node>* parent_node;
    std::unique_ptr<Node>* current_node;
    while (it != elements.end() - 1)
    {
        it++;
        if (root->left == nullptr)
        {
            auto leftmost_node = std::move(root);
            root = std::unique_ptr<Node>(new Node(*it));
            root->left = std::move(leftmost_node);
        }
        else if (root->right == nullptr)
        {
            root->right = std::unique_ptr<Node>(new Node(*it));
            parent_node = &root;
            current_node = &(root->right);
        }
        else
        {
            if ((*current_node)->right == nullptr)
            {
                auto rightmost_child = std::unique_ptr<Node>(new Node(*it));
                if ((*current_node)->left == nullptr)
                {
                    (*parent_node)->right.swap(rightmost_child);
                    (*parent_node)->right->left = std::move(rightmost_child);
                    current_node = &((*parent_node)->right);
                }
                else
                {
                    (*current_node)->right = std::move(rightmost_child);
                    parent_node = &((*parent_node)->right);
                    current_node = &((*current_node)->right);        
                }
            }
        }
    }
    return std::move(root);
}

bool elementFound(std::vector<char> elements, char element)
{
    for (auto& e : elements)
    {
        if (e == element)
        {
            return true;
        }
    }
    return false;
}

std::vector<char> buildOrder(std::vector<char> projects,std::vector<std::pair<char, char>> dependencies)
{
    std::vector<char> output;
    std::vector<char> done;
    output.reserve(projects.size());
    done.reserve(projects.size());
    bool skip = false;
    while (output.size() != projects.size())
    {
        for (auto& project : projects)
        {   
            skip = false;
            if (!elementFound(done, project))
            {
                output.push_back(project);
            }
            for (auto& pair : dependencies)
            {
                if (project == pair.second &&
                    !elementFound(done, pair.first))
                {
                    output.pop_back();
                    skip = true;
                    break;
                }
            }
            if (!skip &&
                !elementFound(done, project))
            {
                done.push_back(project);
            }
        }
    }
    return output;
}

} // namespace tree