#include "gtest/gtest.h"
#include "trees_and_graphs.h"
#include <unordered_map>


TEST(trees_and_graphs_tests, find_route_between_nodes)
{
    std::vector<std::vector<int>> children = {{1, 2, 6}, {0, 2, 4, 6}, {1, 3},
                                              {3}, {1, 3, 5, 6, 9}, {4, 6, 9},
                                              {7}, {5, 8}, {5, 9, 7}, {4, 9}};
    std::unordered_map<int, std::shared_ptr<graph::Node>> nodes;
    auto it = children.begin();
    for (int i = 0; i < 10; i++)
    {
        nodes.insert({i, std::shared_ptr<graph::Node>(new graph::Node(i))});
        for (auto& item : *it)
        {
            nodes[i]->add_child(item);
        }
        it++;
    }
    graph::Graph graph = graph::Graph(nodes);
    auto result = graph::bfs(graph, 3, 4);
    ASSERT_FALSE(result.first);
    graph.reset();
    result = graph::bfs(graph, 0, 9);
    ASSERT_TRUE(result.first);
    std::vector<int> ref = {0, 1, 2, 6, 4, 3, 7, 5, 9};
    ASSERT_EQ(result.second, ref);
}

TEST(trees_and_graphs_tests, create_minimal_binary_search_tree)
{
    std::vector<int> elements = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto root = tree::create_minimal_binary_search_tree(elements);
    std::vector<int> nodes;
    nodes.push_back(root->value);
    auto current_node = &root;
    while ((*current_node) != nullptr)
    {
        if ((*current_node)->right != nullptr)
        {
            nodes.push_back((*current_node)->left->value);
            nodes.push_back((*current_node)->right->value);
        }
        current_node = &((*current_node)->right);
    }
    std::vector<int> ref_tree = {2, 1, 4, 3, 6, 5, 8, 7, 9};
    ASSERT_EQ(nodes, ref_tree);
}