//Stanley Lim

#include <fstream>
#include <iostream>
#include <sstream>

#include "Vertex.hpp"
#include "Graph.hpp"

//graphs and makes the graph according to the input graph file and starting vertex
//calls dijkstra's algorithm and displays the path
void readGraph(const std::string& graphfile, const std::string& inputvertex)
{
    std::ifstream file(graphfile);
    if(file.fail())
    {
        std::cout << "Could not find file.\n";
        exit(1);
    }
    int startingVertex = std::stoi(inputvertex);
    
    std::string verticesline;
    std::getline(file, verticesline);
    int amountOfVertices = std::stoi(verticesline);
    Graph graph(amountOfVertices + 1);
    
    std::string vertexinfo;
    while(std::getline(file, vertexinfo))
    {
        std::string parser;
        std::stringstream vertexHelper(vertexinfo);
        std::getline(vertexHelper, parser, ' ');
        
        int vertexNumber = std::stoi(parser);
        
        int num = parser.length() + 1;
        vertexinfo = vertexinfo.substr(num, vertexinfo.length());
        
        //if(vertexinfo.length() == 0)
          //  std::cout << "nothing to see";
        
        while(std::getline(vertexHelper, parser, ' '))
        {
            std::string vertexstring;
            std::string weightstring;
            //vertex
            vertexstring = parser;
            //weight
            std::getline(vertexHelper, parser, ' ');
            weightstring = parser;
            
            int vertex = std::stoi(vertexstring);
            double weight = std::stod(weightstring);
            graph.addEdge(vertexNumber, vertex, weight);
        }
    }   
    graph.dijkstra(startingVertex);
    graph.display(startingVertex);
}

int main(int argc, char** argv)
{
    std::string graphFile;
    std::string startingVertex;
    if(argc != 3)
    {
        std::cout << "Not enough arguments.\n./FindPaths <graph_file> <starting_vertex>\n";
        return 0;
    }
    else
    {
        graphFile = argv[1];
        startingVertex = argv[2];
    }  
    readGraph(graphFile, startingVertex);
    
}
