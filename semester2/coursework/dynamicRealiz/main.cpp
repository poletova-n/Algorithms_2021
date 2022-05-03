#include <iostream>
#include "Graph.h"

int main()
{
    Graph graph;
    std::string name = "sus";
    graph.addPoint(name);

    std::cout << graph.pointExists(name);

    return 0;
}