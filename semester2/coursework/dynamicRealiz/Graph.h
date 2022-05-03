//
// Created by Администратор on 06.04.2022.
//

#ifndef ALGORITHMS_2021_GRAPH_H
#define ALGORITHMS_2021_GRAPH_H

#include <iterator>
#include <utility>
#include <xstring>
#include <list>

class Graph {

private:

    struct Point{

        struct Edge{

            Point* destinationPoint_;

            int mass_;

            Edge(Graph::Point *destinationPoint, int mass) : destinationPoint_(destinationPoint), mass_(mass) {}

        };

        std::list<Edge*>* edges_;

        std::string name_;

        std::list<Edge*>::iterator it;

        explicit Point(std::string& name) : name_(name){
            edges_ = new std::list<Edge*>;
            it = edges_->begin();
        }

        void addEdge(Point* destinationPoint_, int mass){
            auto edge = new Edge(destinationPoint_, mass);
            edges_->push_back(edge);
        }

        /*bool edgeExists(){

        }*/

    };

    std::list<Point*>* points_;

    int numberOfPoints_;

public:

    Graph(){
        points_ = new std::list<Point*>;
        numberOfPoints_ = 0;
    }

    bool addPoint(std::string& name){
        if(pointExists(name)) return false;
        points_->push_back(new Point(name));
        numberOfPoints_++;
        return true;
    };

    bool pointExists(std::string& name){
        if(numberOfPoints_ == 0) return false;
        auto it = points_->begin();
        Point* temp;
        for (int i = 0; i < numberOfPoints_; ++i) {
            temp = *(it);
            if(temp->name_ == name) return true;
            it++;
        }
        return false;
    };

    bool addEdge(std::string& departPoint, std::string& pointOfDestination, int& mass, bool bilateral = false){

    };

};


#endif //ALGORITHMS_2021_GRAPH_H
