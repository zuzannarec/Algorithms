#include "gtest/gtest.h"
#include "trees_and_graphs.h"
#include <unordered_map>

using namespace graph;

TEST(trees_and_graphs_tests, find_route_between_nodes)
{
    std::vector<std::vector<int>> children = {{1, 2, 6}, {0, 2, 4, 6}, {1, 3},
                                              {3}, {1, 3, 5, 6, 9}, {4, 6, 9},
                                              {7}, {5, 8}, {5, 9, 7}, {4, 9}};
    std::unordered_map<int, std::shared_ptr<Node>> nodes;
    auto it = children.begin();
    for (int i = 0; i < 10; i++)
    {
        nodes.insert({i, std::shared_ptr<Node>(new Node(i))});
        for (auto& item : *it)
        {
            nodes[i]->add_child(item);
        }
        it++;
    }
    Graph graph = Graph(nodes);
    auto result = bfs(graph, 3, 4);
    ASSERT_FALSE(result.first);
    graph.reset();
    result = bfs(graph, 0, 9);
    ASSERT_TRUE(result.first);
    std::vector<int> ref = {0, 1, 2, 6, 4, 3, 7, 5, 9};
    ASSERT_EQ(result.second, ref);
}