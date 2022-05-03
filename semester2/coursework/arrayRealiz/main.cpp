#include <iostream>
#include "Graph.h"
#include "SmartArray.h"
#include "SmartMatrix.h"

void testAll(std::string&& departmentPoint, std::string&& destinationPoint, Graph* graph){

    std::cout << "Wave: \n\n";

    graph->wavePathFinderAlgorithm(departmentPoint, destinationPoint);

    std::cout << "\nDijkstra: \n\n";

    graph->dijkstraPathFinderAlgorithm(departmentPoint, destinationPoint);

    std::cout << "\nBellman-Ford: \n\n";

    graph->bellmanFordPathFinderAlgorithm(departmentPoint, destinationPoint);

}

void defaultTest(){

    auto* graph = new Graph();

    graph->addPoint("A");

    graph->addPoint("B");

    graph->addPoint("C");

    graph->addPoint("D");

    graph->adArc("A", "B", 1);

    graph->adArc("B", "A", 3);

    graph->adArc("A", "C", 8);

    graph->adArc("B", "D", 6);

    graph->adArc("B", "C", 5);

    graph->adArc("C", "D", 4);

    graph->adArc("D", "C", 4);

    graph->print();

    testAll("A", "C", graph);
}

void bellmanFordTest(){

    auto* graph = new Graph();

    graph->addPoint("A");

    graph->addPoint("B");

    graph->addPoint("C");

    graph->addPoint("D");

    graph->adArc("A", "C", 2);

    graph->adArc("A", "B", 3);

    graph->adArc("B", "C", -2);

    graph->adArc("C", "D", 1);

    graph->print();

    testAll("A", "D", graph);
}

void loop(){

    auto* graph = new Graph();

    graph->addPoint("A");

    graph->addPoint("B");

    graph->addPoint("C");

    graph->addPoint("D");

    graph->addPoint("E");

    graph->addPoint("F");

    graph->adArc("A", "B", 1);

    graph->adArc("B", "E", 2);

    graph->adArc("E", "F", 1);

    graph->adArc("C", "B", -2);

    graph->adArc("D", "C", 2);

    graph->adArc("E", "D", -4);

    graph->print();

    testAll("A", "F", graph);

}

int main()
{
    std::cout << "\nDefault test:\n\n";

    defaultTest();

    std::cout << "\nBellman-Ford test:\n\n";

    bellmanFordTest();

    std::cout << "\nNegative circle test:\n\n";

    loop();

    return 0;
}

