//Stanley Lim

#include "Graph.hpp"
#include "Vertex.hpp"

#include <fstream>
#include <sstream>

//calls topsort algorithm after making the graph with correct vertices 
//and adjacent vertices and weights. if there's a cycle detected, a nullptr
//is pushed to the end. if the end of the path == nullptr then there is a cycle
//if there is no cycle, it prints out the path
void topSort(const std::string& graphfile)
{
    std::ifstream graph(graphfile);
    if(graph.fail())
    {
        std::cout << "File not found\n";
        return;
    }
    std::string vertices;
    std::getline(graph, vertices);
    int numOfVertices = std::stoi(vertices);
    
    Graph makegraph(numOfVertices);
    std::string graphinfo;
    
    std::string strvertex;
    std::string stradj;
    std::string strweight;
    
    int vertex = 0;
    int adjacent = 0;
    double weight = 0;
    
    while(std::getline(graph, graphinfo))
    {
        std::stringstream extractinfo(graphinfo);
        std::getline(extractinfo, strvertex, ' ');
        vertex = std::stoi(strvertex);

        while(extractinfo)
        {
            std::getline(extractinfo, stradj, ' ');
            if(stradj == "")
                break;
                
            adjacent = std::stoi(stradj);
            
            std::getline(extractinfo, strweight, ' ');
            weight = std::stod(strweight);
            
            if(extractinfo)
                makegraph.addEdge(vertex, adjacent, weight);
        }
    }
    
    std::vector<Vertex*> v = makegraph.topSort();
    if(v[v.size() - 1] == nullptr)
    {
        std::cout << "Cycle detected\n";
        return;
    }
    for(int i = 0; i < v.size(); i++)
    {
        if(i == v.size() - 1)
        {
           std::cout << v[i] -> getVertex();
           break;
        }
        std::cout << v[i] -> getVertex() << ", ";
    }
    std::cout << "\n";
}

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cout << "Not enough arguments.\n./TopologicalSort <graph>\n";
        return 0;
    }
    std::string graphfile = argv[1];
    topSort(graphfile);

}
