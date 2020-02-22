//Stanley Lim

#include <list>
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

#include "Vertex.hpp"

#ifndef FINDPATHS_HPP
#define FINDPATHS_HPP


class Graph
{
    public:
        Graph(int numVertices);
        void addEdge(int vertex1, int vertex2, double weight);
        void dijkstra(const int startingVertex);
        void display(const int startingVertex);
        std::vector<Vertex*> topSort();
    private:
        std::vector<int> indegree;
        std::vector<Vertex*> verticesList;
        int amountOfVertices;
        
};

#endif
