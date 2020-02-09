#include "simple_graph.h"


template <typename T>
std::vector<T*> SimpleGraph<T>::get_connections(int32_t node_idx)
{
    return this->connections[node_idx].second;
}

