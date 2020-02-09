#include <stdint.h>
#include <vector>
#include <unordered_map>

template <typename T>
class SimpleNode
{
public:
    SimpleNode(T value) : value(value), visited(false)
    {}
    T value;
    bool visited;
};

template <typename T>
class SimpleGraph
{
public:
    SimpleGraph(std::unordered_map<int32_t, std::pair<T*, std::vector<T*>>> connections) : connections(connections)
    {}
    std::unordered_map<int32_t, std::pair<T*, std::vector<T*>>> connections;
    std::vector<T*> get_connections(int32_t node_idx);
};

