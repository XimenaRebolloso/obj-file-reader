#ifndef FACE_H
#define FACE_H
#pragma once
	
#include <vector>
#include "Edge.hpp"

using namespace std;

class Face  
{
	private:
	    vector<Edge> edges;

	public:
		Face(vector<Edge> edges);
		void print();

};
#endif