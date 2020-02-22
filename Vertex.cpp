//Stanley Lim

#include "Vertex.hpp"

void Adjacent::changeWeight(double amount)
{
    weight = amount;
}

void Adjacent::changeVertex(int num)
{
    vertexNumber = num;
}

double Adjacent::getWeight() const
{
    return weight;
}

int Adjacent::getVertex() const
{
    return vertexNumber;
}






Vertex::Vertex()
{
    distance = INT_MAX;
    isVisited = false;
}

void Vertex::changeDistance(int amount)
{
    distance = amount;
}

void Vertex::changeVertex(int num)
{
    vertexNumber = num;
}

int Vertex::getDistance() const
{
    return distance;
}

int Vertex::getVertex() const
{
    return vertexNumber;
}

std::list<Adjacent> Vertex::getAdjacents()
{
    return listOfAdjacents;
}

Vertex* Vertex::getPath()
{
    return path;
}

void Vertex::changePath(Vertex* inputpath)
{
    path = inputpath;
}

bool Vertex::visited()
{
    return isVisited;
}

void Vertex::visit()
{
    isVisited = true;
}

void Vertex::addAdjacent(Adjacent adj)
{
    listOfAdjacents.push_back(adj);
}
