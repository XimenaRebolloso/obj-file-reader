#include <iostream>
#include "../include/Vertex.hpp" 

using namespace std; 
	
Vertex::Vertex()
{
	//x = y = z = 0.0;
}

Vertex::Vertex(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Vertex::print()
{
    cout << "("<< this->x << " , " << this->y << " , " << this->z << ")" << endl;

}