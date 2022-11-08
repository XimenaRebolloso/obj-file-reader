#include <iostream>
#include "../include/Edge.hpp"

using namespace std; 

Edge::Edge(Vertex vi, Vertex vf)
{
	this-> vi = vi;
    this->vf = vf;
}

void Edge::print()
{
    this->vi.print();
    this->vf.print();
}
