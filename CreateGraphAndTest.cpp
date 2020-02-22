//Stanley Lim

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

//makes the graph from the graph file and returns it in vector form
std::vector<std::string> makeGraph(const std::string& inputfile)
{
    std::ifstream firstGraph(inputfile);
    if(firstGraph.fail())
    {
        std::cout << "Could not find text file.\n";
        exit(1);
    }
    std::string amountOfVertices;
    std::getline(firstGraph, amountOfVertices);
    int vertices = std::stoi(amountOfVertices);
    
    std::string vertexInfo;
    std::vector<std::string> graph;
    
    for(int i = 0; i < vertices + 1; i++)
        graph.push_back("Filler because I wanna keep each index the same as the vertex");
        
    while(std::getline(firstGraph, vertexInfo))
    {
        std::string parser;
        std::stringstream vertexHelper(vertexInfo);
        std::getline(vertexHelper, parser, ' ');
        int num = parser.length() + 1;
        vertexInfo = vertexInfo.substr(num, vertexInfo.length());
        int vertexNum = std::stoi(parser);
        graph[vertexNum] = vertexInfo;
    }
    return graph;
}

//finds all adjacents in the query file and returns as vector
std::vector<std::string> adjacency(const std::string& queryfile)
{
    std::ifstream query(queryfile);
    if(query.fail())
    {
        std::cout << "Could not find text file.\n";
        exit(1);
    }
    std::string originAndDestination;
    std::vector<std::string> adj;
    while(std::getline(query, originAndDestination))
        adj.push_back(originAndDestination);
    return adj;
}

//if there is a connection between a and b, 
//returns TRUE with the weight that connects them.
//else returns false 
std::pair<bool, double> checkIfAdjacent(const std::vector<std::string>& graph, const std::string& query)
{
    std::pair<bool, double> connection;
    connection.first = false;
    connection.second = 0.0;
    std::stringstream adjacent(query);
    
    std::string origin;
    std::getline(adjacent, origin, ' ');
    std::string destination;
    std::getline(adjacent, destination, ' ');
    
    int originindex = std::stoi(origin);
    if(originindex > graph.size())
    {
        connection.first = false;
        connection.second = 0.0;
        return connection;
    }

    std::stringstream graphadjacent(graph[originindex]);
    std::string graphtemp;
    double weight;
    while(std::getline(graphadjacent, graphtemp, ' '))
    {
        if(graphtemp == destination)
        {
            std::getline(graphadjacent, graphtemp, ' ');
            weight = std::stod(graphtemp);
            connection.first = true;
            connection.second = weight;
        }
    }
    return connection;
}

int main(int argc, char** argv)
{
    std::string inputfile;
    std::string queryfile;
    if(argc != 3)
    {
        std::cout << "Not enough arguments.\n./CreateGraphAndTest <graph_file.txt> <query.txt>\n";
        return 0;
    }
    else
    {
        inputfile = argv[1];
        queryfile = argv[2];
    }
    std::vector<std::string> graph = makeGraph(inputfile);
    std::vector<std::string> query = adjacency(queryfile);
    for(int i = 0; i < query.size(); i++)
    {
        std::pair<bool, double> answer = checkIfAdjacent(graph, query[i]);
        if(answer.first)
            std::cout << query[i] << " Connected, weight of edge is " << answer.second << ".\n";
        else if(!answer.first)
            std::cout << query[i] << " Not connected.\n";
    }
}
