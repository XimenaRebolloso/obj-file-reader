#include <iostream>
//#include "../include/Edge.hpp"
#include "../include/Face.hpp"
	
Face::Face(vector<Edge> edges)
{
    this->edges = edges;
	
}

void Face::print()
{
    for(Edge edge : edges )
    {
        edge.print();
    }
}

