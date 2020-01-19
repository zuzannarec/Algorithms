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
            nodes[i]->add_neighbour(item);
        }
        it++;
    }
    graph::Graph graph = graph::Graph(nodes);
    auto result = graph::bfs(graph, 3, 4);
    ASSERT_FALSE(result.first);
    graph.reset();
    result = graph::bfs(graph, 0, 9);
    ASSERT_TRUE(result.first);
    graph.reset();
    std::vector<int> ref = {0, 1, 2, 6, 4, 3, 7, 5, 9};
    ASSERT_EQ(result.second, ref);

    auto result2 = graph::dfs(graph, 3, 4);
    ASSERT_FALSE(result2);
    graph.reset();
    result2 = graph::dfs(graph, 0, 9);
    ASSERT_TRUE(result2);
    graph.reset();
}

TEST(trees_and_graphs_tests, create_minimal_binary_search_tree)
{
    std::vector<int> elements = {1, 2, 3, 4, 5, 6, 7};
    auto root = tree::create_minimal_binary_search_tree(elements);
    std::vector<int> in_order;
    tree::inOrder(root.get(), in_order);
    ASSERT_EQ(in_order, elements);

    std::vector<int> pre_order;
    tree::preOrder(root.get(), pre_order);
    std::vector<int> pre_order_tree_ref = {4, 2, 1, 3, 6, 5, 7};
    ASSERT_EQ(pre_order, pre_order_tree_ref);

    std::vector<int> post_order;
    tree::postOrder(root.get(), post_order);
    std::vector<int> post_order_tree_ref = {1, 3, 2, 5, 7, 6, 4};
    ASSERT_EQ(post_order, post_order_tree_ref);
}

TEST(trees_and_graphs_tests, create_maximal_binary_search_tree)
{
    std::vector<int> elements = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto root = tree::create_maximal_binary_search_tree(elements);
    std::vector<int> in_order;
    tree::inOrder(root.get(), in_order);
    ASSERT_EQ(in_order, elements);

    std::vector<int> pre_order;
    tree::preOrder(root.get(), pre_order);
    std::vector<int> pre_order_tree_ref = {2, 1, 4, 3, 6, 5, 8, 7, 9};
    ASSERT_EQ(pre_order, pre_order_tree_ref);

    std::vector<int> post_order;
    tree::postOrder(root.get(), post_order);
    std::vector<int> post_order_tree_ref = { 1, 3, 5, 7, 9, 8, 6, 4, 2};
    ASSERT_EQ(post_order, post_order_tree_ref);
}

TEST(trees_and_graphs_tests, buildOrder)
{
    std::vector<char> projects = {'a', 'b', 'c', 'd', 'e', 'f'};
    std::vector<std::pair<char, char>> dependencies = {{'a', 'd'}, {'f', 'b'}, {'b', 'd'}, {'f', 'a'}, {'d', 'c'}};
    auto output = tree::buildOrder(projects, dependencies);
    std::vector<char> output_ref = {'e', 'f', 'a', 'b', 'd', 'c'};
    ASSERT_EQ(output, output_ref);
}