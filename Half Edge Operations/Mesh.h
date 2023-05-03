
#pragma once
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include "Halfedge.h"

using namespace std;

class Mesh
{
	int from;
	int to;
	int fromCoordinate[3] = { 0 };
	int toCoordinate[3]{ 0 };
	Halfedge* curr;

	std::map<Halfedge*, Halfedge*> nextEdge;
	std::map<Halfedge*, Halfedge*> prevEdge;
	std::map<Halfedge*, Halfedge*> oppositeEdge;

	//trying stuff
	//std::map<int, vector<int>> vertexCoordinates;
	vector<Vertex> verticies;
	vector<vector<int>> faces;


public:

	//bool load_mesh(string path);



	//HalfEdge(int fromVertex, int toVertex, int fromX, int fromY, int fromZ, int toX, int toY, int toZ);

	Mesh();

	Mesh(map<Halfedge*, Halfedge*> next, map<Halfedge*, Halfedge*> prev, map<Halfedge*, Halfedge*> op);

	Halfedge* getCurr();

	void moveNext();

	void movePrev();

	void moveOpposite();

	/*
	void split(const std::string& in,
		std::vector<std::string>& out,
		std::string token);

	std::string tail(const std::string& in);

	std::string firstToken(const std::string& in);
	*/
};

