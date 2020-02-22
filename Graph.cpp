//Stanley Lim

#include "Graph.hpp"
#include "Vertex.hpp"

//makes a graph with numvertices
//adds the vertex number to the verticeslist
//indegree = 0
Graph::Graph(int numVertices)
{
    amountOfVertices = numVertices;
    for(int i = 0; i < numVertices; i++)
    {
        Vertex* vertex = new Vertex;
        verticesList.push_back(vertex);
        verticesList[i] -> changeVertex(i + 1);
        indegree.push_back(0);
    }
}

//adds an edge by also adding weight and changing the name of the vertex
//and changes indegrees
void Graph::addEdge(int vertex1, int vertex2, double weight)
{
    Adjacent adjacentVertex;
    adjacentVertex.changeWeight(weight);
    adjacentVertex.changeVertex(vertex2);
    verticesList[vertex1 - 1] -> addAdjacent(adjacentVertex);
    
    indegree[vertex2 - 1] += 1;
}

//dijkstra's pathfinding algorithm implementation using priority queue
void Graph::dijkstra(const int startingVertex)
{
    std::priority_queue<Vertex*, std::vector<Vertex*> > pq;
    
    Vertex* startVertex = verticesList[startingVertex - 1];
    startVertex -> changeDistance(0);
    pq.push(startVertex);
    
    while(!pq.empty())
    {
        Vertex* top = pq.top();
        pq.pop();
        top -> visit();
        auto startingList = top -> getAdjacents();
        for(auto i = startingList.begin(); i != startingList.end(); i++)
        {
            Vertex* hold = verticesList[(i -> getVertex()) - 1];
            if(!hold -> visited() and top -> getDistance() + i -> getWeight() < hold -> getDistance())
            {
                hold -> changeDistance(top -> getDistance() + i -> getWeight());
                hold -> changePath(top);
                pq.push(hold);
            }
        }
    }
}

//displays dijkstra's shortest path using the starting vertex
void Graph::display(const int startingVertex)
{
    std::vector<int> path;
    for(int i = 1; i < verticesList.size(); i++)
    {
        std::cout << i << ": ";
        Vertex* temp = verticesList[i - 1];
        int weight = temp -> getDistance();
        while(temp != nullptr)
        {
            if(temp -> getVertex() == 0)
                temp -> changeVertex(i);
            path.push_back(temp -> getVertex());
            temp = temp -> getPath();
        }
        std::reverse(path.begin(), path.end());
        for(int i = 0; i < path.size() - 1; i++)
            std::cout << path[i] << ", ";
        std::cout << path[path.size() - 1];
        path.clear();
        
        std::cout << " (Cost: " << weight << ")\n";
    }
}

//topsort algorithm. if there's a cycle, a nullptr is pushed
//if no cycle, the caller prints out the path
std::vector<Vertex*> Graph::topSort()
{
    std::queue<Vertex*> queue;
    for(int i = 0; i < amountOfVertices; i++)
    {
        if(indegree[i] == 0)
            queue.push(verticesList[i]);
    }
    int counter = 0;
    std::vector<Vertex*> topsort;
    topsort.reserve(amountOfVertices);
    while(!queue.empty())
    {
        Vertex* v = queue.front();
        queue.pop();
        topsort.push_back(v);
        const auto& start = v -> getAdjacents();
        for(auto i = start.begin(); i != start.end(); i++)
        {
            if(indegree[(i -> getVertex()) - 1] == 0)
            {
                --indegree[(i -> getVertex()) - 1];
                queue.push(verticesList[(i -> getVertex()) - 1]);
            }
        }
        counter++;
    }
    if(counter != amountOfVertices)
        topsort.push_back(nullptr);
        
    return topsort;
}
