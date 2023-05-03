#include "Vertex.h"
#include "Halfedge.h"
#include "Mesh.h"
#include <iostream>

using namespace std;

int main() {
	Vertex v1 = Vertex(1.0f, 1.0f, 0.0f);
	Vertex v2 = Vertex(-1.0f, 1.0f, 0.0f);
	Vertex v3 = Vertex(-1.0f, -1.0f, 0.0f);
	Vertex v4 = Vertex(1.0f, -1.0f, 0.0f);
	
	Halfedge e1 = Halfedge(v1, v2);
	Halfedge e2 = Halfedge(v2, v3);
	Halfedge e3 = Halfedge(v3, v4);
	Halfedge e4 = Halfedge(v4, v1);

	Halfedge oe1 = Halfedge(e1.getTo(), e1.getFrom());
	Halfedge oe2 = Halfedge(e2.getTo(), e2.getFrom());
	Halfedge oe3 = Halfedge(e3.getTo(), e3.getFrom());
	Halfedge oe4 = Halfedge(e4.getTo(), e4.getFrom());

	cout << "e1 From: " << e1.getFrom().getX() << ", " << e1.getFrom().getY() << ", " << e1.getFrom().getZ() << endl;
	cout << "oe1 To: " << oe1.getTo().getX() << ", " << e1.getTo().getY() << ", " << e1.getTo().getZ() << endl;

	map<Halfedge*, Halfedge*> next;
	next.insert({ &e1, &e2 });
	next.insert({ &e2, &e3 });
	next.insert({ &e3, &e4 });
	next.insert({ &e4, &e1 });

	map<Halfedge*, Halfedge*> prev;
	prev.insert({ &e1, &e4 });
	prev.insert({ &e2, &e1 });
	prev.insert({ &e3, &e2 });
	prev.insert({ &e4, &e3 });

	map<Halfedge*, Halfedge*> opposite;
	opposite.insert({ &e1, &oe1 });
	opposite.insert({ &e2, &oe2 });
	opposite.insert({ &e3, &oe3 });
	opposite.insert({ &e4, &oe4 });
	

	cout << "Halfedge 3, To Vertex y, Coordinate: " << e3.getTo().getY() << endl;

	Mesh testMesh = Mesh(next, prev, opposite);
	Halfedge* curr = testMesh.getCurr();
	cout << "Current Halfedge, From: " << curr->getFrom().getX() << ", " << curr->getFrom().getY() << ", " << curr->getFrom().getZ() << endl;
	cout << "Current Halfedge, To: " << curr->getTo().getX() << ", " << curr->getTo().getY() << ", " << curr->getTo().getZ() << endl;

	//testing moveNext
	testMesh.moveNext();
	curr = testMesh.getCurr();
	cout << "Current Halfedge, From: " << curr->getFrom().getX() << ", " << curr->getFrom().getY() << ", " << curr->getFrom().getZ() << endl;
	cout << "Current Halfedge, To: " << curr->getTo().getX() << ", " << curr->getTo().getY() << ", " << curr->getTo().getZ() << endl;

	testMesh.moveNext();
	curr = testMesh.getCurr();
	cout << "Current Halfedge, From: " << curr->getFrom().getX() << ", " << curr->getFrom().getY() << ", " << curr->getFrom().getZ() << endl;
	cout << "Current Halfedge, To: " << curr->getTo().getX() << ", " << curr->getTo().getY() << ", " << curr->getTo().getZ() << endl;

	testMesh.moveNext();
	curr = testMesh.getCurr();
	cout << "Current Halfedge, From: " << curr->getFrom().getX() << ", " << curr->getFrom().getY() << ", " << curr->getFrom().getZ() << endl;
	cout << "Current Halfedge, To: " << curr->getTo().getX() << ", " << curr->getTo().getY() << ", " << curr->getTo().getZ() << endl;

	//testing movePrev
	cout << endl << "Testing movePrev" << endl;
	testMesh.movePrev();
	curr = testMesh.getCurr();
	cout << "Current Halfedge, From: " << curr->getFrom().getX() << ", " << curr->getFrom().getY() << ", " << curr->getFrom().getZ() << endl;
	cout << "Current Halfedge, To: " << curr->getTo().getX() << ", " << curr->getTo().getY() << ", " << curr->getTo().getZ() << endl;

	testMesh.movePrev();
	curr = testMesh.getCurr();
	cout << "Current Halfedge, From: " << curr->getFrom().getX() << ", " << curr->getFrom().getY() << ", " << curr->getFrom().getZ() << endl;
	cout << "Current Halfedge, To: " << curr->getTo().getX() << ", " << curr->getTo().getY() << ", " << curr->getTo().getZ() << endl;

	testMesh.movePrev();
	curr = testMesh.getCurr();
	cout << "Current Halfedge, From: " << curr->getFrom().getX() << ", " << curr->getFrom().getY() << ", " << curr->getFrom().getZ() << endl;
	cout << "Current Halfedge, To: " << curr->getTo().getX() << ", " << curr->getTo().getY() << ", " << curr->getTo().getZ() << endl;

	testMesh.movePrev();
	curr = testMesh.getCurr();
	cout << "Current Halfedge, From: " << curr->getFrom().getX() << ", " << curr->getFrom().getY() << ", " << curr->getFrom().getZ() << endl;
	cout << "Current Halfedge, To: " << curr->getTo().getX() << ", " << curr->getTo().getY() << ", " << curr->getTo().getZ() << endl;

	//testing moveOpposite
	cout << endl << "Testing moveOpposite" << endl;
	testMesh.moveOpposite();
	curr = testMesh.getCurr();
	cout << "Current Halfedge, From: " << curr->getFrom().getX() << ", " << curr->getFrom().getY() << ", " << curr->getFrom().getZ() << endl;
	cout << "Current Halfedge, To: " << curr->getTo().getX() << ", " << curr->getTo().getY() << ", " << curr->getTo().getZ() << endl;
	
}