//Stanley Lim

#include <list>
#include "limits.h"

#ifndef VERTEX_HPP
#define VERTEX_HPP

//keeps track of all the adjacent vertices 
//also keeps track of all the weights
class Adjacent
{
    public:
        void changeWeight(double amount);
        void changeVertex(int num);
        double getWeight() const;
        int getVertex() const;
    private:
        double weight;  
        int vertexNumber;
};

class Vertex
{
    public:
        Vertex();
        void changeDistance(int amount);
        void changeVertex(int num);
        int getDistance() const ;
        int getVertex() const;
        std::list<Adjacent> getAdjacents();
        Vertex* getPath();
        void changePath(Vertex* inputpath);
        bool visited();
        void visit();
        void addAdjacent(Adjacent adj);
    private:
        std::list<Adjacent> listOfAdjacents;
        int vertexNumber;
        int distance;
        bool isVisited;
        Vertex* path;
};

#endif


