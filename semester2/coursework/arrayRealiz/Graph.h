#ifndef ALGORITHMS_2021_GRAPH_H
#define ALGORITHMS_2021_GRAPH_H


#include "SmartMatrix.h"
#include <stack>
#include <queue>
#include <limits>
#include <vector>

class Graph {
private:

    SmartMatrix* matrix_;

    SmartArray<std::string>* pointNames_;

    int numberOfPoints_;

    int isPointExists(std::string& name){
        if(numberOfPoints_ == 0) return -1;
        for (int i = 0; i < pointNames_->size(); ++i) {
            if(pointNames_->get(i) == name) return i;
        }
        return -1;
    };

    bool hasArcs(int departmentPointIndex){
        if(departmentPointIndex < 0 || departmentPointIndex >= numberOfPoints_) return false;
        for (int i = 0; i < matrix_->operator()(departmentPointIndex)->size(); ++i) {
            if(matrix_->operator()(departmentPointIndex, i) > 0) return true;
        }
        for (int i = 0; i < matrix_->operator()(departmentPointIndex)->size(); ++i) {
            if(matrix_->operator()(i, departmentPointIndex) != 0) return true;
        }
        return false;
    };

public:

    Graph(){
        matrix_ = new SmartMatrix();
        pointNames_ = new SmartArray<std::string>;
        numberOfPoints_ = 0;
    };

    bool addPoint(std::string&& name){
        if(isPointExists(name) != -1) return false;
        if(numberOfPoints_ != 0){ pointNames_->add(); matrix_->add(); }
        pointNames_->get(numberOfPoints_) = name;
        ++numberOfPoints_;
        return true;
    };

    bool deletePoint(std::string&& name){

        int pointIndex = isPointExists(name);
        if(pointIndex == -1) return false;

        for (int i = 0; i < numberOfPoints_; ++i) {
            if(matrix_->operator()(pointIndex, i) != 0){
                matrix_->operator()(pointIndex, i) = 0;
                matrix_->operator()(i, pointIndex) = 0;
            }
        }

        matrix_->cut(pointIndex);
        pointNames_->cut(pointIndex);
        --numberOfPoints_;

        return true;
    };

    void print(){
        if(numberOfPoints_ == 0){ std::cout << "Graph is empty!" << std::endl; return;}
        for (int i = 0; i < numberOfPoints_; ++i) {
            std::cout << pointNames_->get(i) << " ";
            matrix_->operator()(i)->print();
        }
    };

    bool deleteArc(std::string&& departmentPointName,std::string&& destinationPointName){

        int first = isPointExists(departmentPointName);
        int second = isPointExists(destinationPointName);
        if(first == -1 || second == -1) return false;
        if(!isArcExists(departmentPointName, destinationPointName)) return false;

        matrix_->operator()(first, second) = 0;

        return true;
    };

    bool adArc(std::string&& departmentPointName,std::string&& destinationPointName, int mass){

        int first = isPointExists(departmentPointName);
        int second = isPointExists(destinationPointName);
        if(first == -1 || second == -1) return false;
        if(isArcExists(departmentPointName, destinationPointName)) return false;

        matrix_->operator()(first, second) = mass;

        return true;
    }

    bool hasArcs(std::string& departmentPointName){
        int departmentPointIndex = isPointExists(departmentPointName);
        return hasArcs(departmentPointIndex);
    };

    bool isArcExists(std::string&& departmentPointName,std::string&& destinationPointName){
        return matrix_->operator()(isPointExists(departmentPointName), isPointExists(destinationPointName)) != 0;
    }

    bool isArcExists(std::string& departmentPointName,std::string& destinationPointName){
        return matrix_->operator()(isPointExists(departmentPointName), isPointExists(destinationPointName)) != 0;
    }

    void wavePathFinderAlgorithm(std::string& departmentPointName,std::string& destinationPointName){

        int departmentPointIndex = isPointExists(departmentPointName);
        int destinationPointIndex = isPointExists(destinationPointName);

        if(!hasArcs(departmentPointIndex) || !hasArcs(destinationPointIndex)) return;

        bool* isPointVisited = new bool[numberOfPoints_];
        for (int i = 0; i < numberOfPoints_; ++i) {
            isPointVisited[i] = false;
        }

        int* pointsDistance = new int[numberOfPoints_];
        for (int i = 0; i < numberOfPoints_; ++i) {
            pointsDistance[i] = 0;
        }

        auto * curPoints = new std::queue<int>;
        curPoints->push(departmentPointIndex);

        auto * paths = new std::vector<std::vector<int>*>(numberOfPoints_);
        for (int i = 0; i < numberOfPoints_; ++i) {
            paths->at(i) = new std::vector<int>();
        }

        while(!curPoints->empty()){

            int currentIndex = curPoints->front(); curPoints->pop();

            for (int i = 0; i < matrix_->operator()(currentIndex)->size(); ++i) {
                if(matrix_->operator()(currentIndex, i) > 0){

                    if(pointsDistance[i] == 0 || pointsDistance[i] > matrix_->operator()(currentIndex, i) + pointsDistance[currentIndex]) {

                        pointsDistance[i] = matrix_->operator()(currentIndex, i) + pointsDistance[currentIndex];

                        delete paths->at(i);
                        paths->at(i) = new std::vector<int>(paths->at(currentIndex)->size());
                        for (int j = 0; j < paths->at(currentIndex)->size(); ++j) {
                            paths->at(i)->at(j) = paths->at(currentIndex)->at(j);
                        }
                        paths->at(i)->push_back(currentIndex);
                    }

                    if(!isPointVisited[i]) {
                        isPointVisited[i] = true;
                        curPoints->push(i);
                    }
                }
            }
        }

        std::cout << "Distance: " << pointsDistance[destinationPointIndex] << std::endl;
        std::cout << "Way: ";
        for (int i : *paths->at(destinationPointIndex)) {
            std::cout << pointNames_->get(i) << " -> ";
        }
        std::cout << pointNames_->get(destinationPointIndex) << "!" << std::endl;

    };

    void dijkstraPathFinderAlgorithm(std::string& departmentPointName,std::string& destinationPointName) {

        int departmentPointIndex = isPointExists(departmentPointName);
        int destinationPointIndex = isPointExists(destinationPointName);

        if(!hasArcs(departmentPointIndex) || !hasArcs(destinationPointIndex)) return;

        int* pointsDistance = new int[numberOfPoints_];
        for (int i = 0; i < numberOfPoints_; ++i) {
            pointsDistance[i] = std::numeric_limits<int>::max();;
        }
        pointsDistance[departmentPointIndex] = 0;

        bool* isPointFixed = new bool[numberOfPoints_];
        for (int i = 0; i < numberOfPoints_; ++i) {
            isPointFixed[i] = false;
        }
        isPointFixed[departmentPointIndex] = true;

        auto* currentFixed = new std::stack<int>;
        currentFixed->push(departmentPointIndex);

        auto * paths = new std::vector<std::vector<int>*>(numberOfPoints_);
        for (int i = 0; i < numberOfPoints_; ++i) {
            paths->at(i) = new std::vector<int>();
        }

        while (!currentFixed->empty()){

            int currentIndex = currentFixed->top();
            currentFixed->pop();

            for (int i = 0; i < matrix_->operator()(currentIndex)->size(); ++i) {
                if(matrix_->operator()(currentIndex, i) != 0 && !isPointFixed[i] && pointsDistance[i] > pointsDistance[currentIndex] + matrix_->operator()(currentIndex, i)){
                    pointsDistance[i] = pointsDistance[currentIndex] + matrix_->operator()(currentIndex, i);

                    delete paths->at(i);
                    paths->at(i) = new std::vector<int>(paths->at(currentIndex)->size());
                    for (int j = 0; j < paths->at(currentIndex)->size(); ++j) {
                        paths->at(i)->at(j) = paths->at(currentIndex)->at(j);
                    }
                    paths->at(i)->push_back(currentIndex);

                }
            }

            int smallestSize = std::numeric_limits<int>::max();
            int smallestIndex = -1;

            for (int i = 0; i < numberOfPoints_; ++i) {
                if(!isPointFixed[i] && pointsDistance[i] < smallestSize){
                    smallestSize = pointsDistance[i];
                    smallestIndex = i;
                }
            }

            if(smallestIndex == -1 ) {
                break;
            }else{
                isPointFixed[smallestIndex] = true;
                currentFixed->push(smallestIndex);
            }
        }

        std::cout << "Distance: " << pointsDistance[destinationPointIndex] << std::endl;
        std::cout << "Way: ";
        for (int i : *paths->at(destinationPointIndex)) {
            std::cout << pointNames_->get(i) << " -> ";
        }
        std::cout << pointNames_->get(destinationPointIndex) << "!" << std::endl;

        delete [] pointsDistance;
        delete [] isPointFixed;
        delete paths;
        delete currentFixed;
    };


    bool bellmanFordPathFinderAlgorithm(std::string& departmentPointName,std::string& destinationPointName){

        int departmentPointIndex = isPointExists(departmentPointName);
        int destinationPointIndex = isPointExists(destinationPointName);

        if(!hasArcs(departmentPointIndex) || !hasArcs(destinationPointIndex)) return false;

        bool* isVisited =  new bool[numberOfPoints_];
        for (int i = 0; i < numberOfPoints_; ++i) {
            isVisited[i] = false;
        }
        isVisited[departmentPointIndex] = true;

        int* pointsDistance = new int[numberOfPoints_];
        for (int i = 0; i < numberOfPoints_; ++i) {
            pointsDistance[i] = std::numeric_limits<int>::max();;
        }
        pointsDistance[departmentPointIndex] = 0;

        auto * paths = new std::vector<std::vector<int>*>(numberOfPoints_);
        for (int i = 0; i < numberOfPoints_; ++i) {
            paths->at(i) = new std::vector<int>();
        }

        int pointJ, pointI;

        for(int k = 1; k < numberOfPoints_ - 1; ++k){
            for (int i = 0; i < numberOfPoints_ - 1; ++i) {
                for (int j = 0; j < numberOfPoints_; ++j) {
                    if (matrix_->operator()(i, j) != 0) {

                        if (pointsDistance[j] == std::numeric_limits<int>::max()) {

                            if(pointsDistance[i] == std::numeric_limits<int>::max()) pointI = 0;
                            else pointI = pointsDistance[i];

                            pointsDistance[j] = matrix_->operator()(i, j) + pointI;

                            isVisited[j] = true;

                            delete paths->at(j);

                            paths->at(j) = new std::vector<int>(paths->at(i)->size());
                            for (int f = 0; f < paths->at(i)->size(); ++f) {
                                paths->at(j)->at(f) = paths->at(i)->at(f);
                            }
                            paths->at(j)->push_back(j);

                        } else {

                            if(pointsDistance[j] == std::numeric_limits<int>::max()) pointJ = 0;
                            else pointJ = pointsDistance[j];

                            if(pointsDistance[i] == std::numeric_limits<int>::max()) pointI = 0;
                            else pointI = pointsDistance[i];

                            if (pointI + matrix_->operator()(i, j) < pointJ) {
                                pointsDistance[j] = pointI + matrix_->operator()(i, j);

                                isVisited[j] = true;

                                delete paths->at(j);
                                paths->at(j) = new std::vector<int>(paths->at(i)->size());
                                for (int f = 0; f < paths->at(i)->size(); ++f) {
                                    paths->at(j)->at(f) = paths->at(i)->at(f);
                                }
                                paths->at(j)->push_back(j);
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < numberOfPoints_ - 1; ++i) {
            for (int j = 0; j < numberOfPoints_; ++j) {
                if (matrix_->operator()(i, j) != 0) {

                    if(pointsDistance[j] == std::numeric_limits<int>::max()) pointJ = 0;
                    else pointJ = pointsDistance[j];

                    if(pointsDistance[i] == std::numeric_limits<int>::max()) pointI = 0;
                    else pointI = pointsDistance[i];

                    if (pointI + matrix_->operator()(i, j) < pointJ && isVisited[j]) {
                        std::cout << "Negative circle!\n";

                        delete [] isVisited;
                        delete [] pointsDistance;
                        delete paths;

                        return false;
                    }
                }
            }
        }

        std::cout << "Distance: " << pointsDistance[destinationPointIndex] << std::endl;

        std::cout << "Way: " << pointNames_->get(departmentPointIndex);
        for (int i : *paths->at(destinationPointIndex)) {
            std::cout << " -> " << pointNames_->get(i);
        }
        std::cout << "!" << std::endl;

        delete [] isVisited;
        delete [] pointsDistance;
        delete paths;

        return true;
    }

    ~Graph(){
        for (int i = 0; i < numberOfPoints_; ++i) {
            delete [] matrix_->operator()(i);
        }
        delete [] matrix_;
        delete [] pointNames_;
    }

};


#endif //ALGORITHMS_2021_GRAPH_H
