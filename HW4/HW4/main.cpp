//File:main
//Descrition: test all testcase
//Author:Yunding Li
//Date: 12/6/2016

#include"Adjacency List.h"
#include<iostream>
#include<sstream>
#include<fstream>
#include <algorithm>
#include<string>
#include <algorithm>
#include <limits.h>

int main() {

	std::vector<std::string> str;

	std::cout << "***********TestCase 1***********" << std::endl;
	std::ifstream file("fig1.csv");
	if (file.is_open())
	{
		std::cout << " open file successfully " << std::endl;
	}
	Graph g1;
	g1.CreateGraphByCSV(file, str);
	g1.PrintUndirectedDot("t1.dot");
	file.close();

	std::cout << "***********TestCase 2***********" << std::endl;
	file.open("fig2.csv");
	if (file.is_open())
	{
		std::cout << " open file successfully " << std::endl;
	}
	Graph g2;
	str.clear();
	g2.CreateGraphByCSV(file, str);
	g2.PrintDot("t2.dot");
	file.close();

	std::cout << "***********TestCase 3***********" << std::endl;
	file.open("fig3-w.csv");
	if (file.is_open())
	{
		std::cout << " open file successfully " << std::endl;
	}
	Graph g3;
	str.clear();
	g3.CreateWeightedGraphByCSV(file, str);
	g3.PrintWDot("t3.dot");
	file.close();

	std::cout << "***********TestCase 4***********" << std::endl;
	g1.addVertices("z");
	g1.addEdge("z", "x");
	g1.addEdge("z", "w");
	g1.addEdge("z", "y");
	g1.PrintUndirectedDot("t4a.dot");
	g1.RemoVertices("s");
	g1.RemoVertices("x");
	g1.remoEdge("u", "t");
	g1.PrintUndirectedDot("t4b.dot");


	std::cout << "***********TestCase 5***********" << std::endl;

	Graph u;
	u.addVertices("6");
	u.addVertices("7");
	u.addVertices("8");
	u.addVertices("9");
	u.addVertices("10");
	u.addEdge("6", "7");
	u.addEdge("7", "8");
	u.addEdge("8", "9");
	u.addEdge("9", "10");
	u.addEdge("10", "6");
	u.addVertices("1");
	u.addVertices("2");
	u.addVertices("3");
	u.addVertices("4");
	u.addVertices("5");
	u.addEdge("1", "6");
	u.addEdge("2", "7");
	u.addEdge("3", "8");
	u.addEdge("4", "9");
	u.addEdge("5", "10");
	u.PrintUndirectedDot("t5a.dot");
	u.RemoVertices("8");
	u.RemoVertices("6");
	u.PrintUndirectedDot("t5b.dot");

	std::cout << "***********TestCase 6***********" << std::endl;

	Graph d;
	std::vector<std::string> vertices;  //{ "2","4","6","8","10" };
	vertices.push_back("2");
	vertices.push_back("4");
	vertices.push_back("6");
	vertices.push_back("8");
	vertices.push_back("10");
	std::random_shuffle(vertices.begin(), vertices.end());
	for (int i = 0; i < vertices.size(); i++)
	{
		d.addVertices(vertices[i]);
	}
	d.addEdgeSingle("2", "4");
	d.addEdgeSingle("2", "6");
	d.addEdgeSingle("4", "6");
	d.addEdgeSingle("4", "8");
	d.addEdgeSingle("6", "8");
	d.addEdgeSingle("6", "10");
	d.addEdgeSingle("8", "10");
	d.addEdgeSingle("8", "2");
	std::vector<std::string> ver;  //{ "1","3","5","7","9" };
	ver.push_back("1");
	ver.push_back("3");
	ver.push_back("5");
	ver.push_back("7");
	ver.push_back("9");
	std::random_shuffle(ver.begin(), ver.end());
	for (int i = 0; i < ver.size(); i++)
	{
		d.addVertices(ver[i]);
	}
	d.addEdgeSingle("1", "2");
	d.addEdgeSingle("3", "4");
	d.addEdgeSingle("5", "6");
	d.addEdgeSingle("7", "8");
	d.addEdgeSingle("9", "10");
	d.PrintDot("t6a.dot");
	std::random_shuffle(ver.begin(), ver.end());
	std::random_shuffle(vertices.begin(), vertices.end());
	d.RemoVertices(vertices[0]);
	d.RemoVertices(ver[0]);
	d.PrintDot("t6b.dot");

	std::cout << "***********TestCase 7***********" << std::endl;
	std::cout << "\t\t";
	for (int i = 0; i < g3.G.size(); i++)
	{
		std::cout << g3.G[i].head->name << "\t\t";
	}
	for (int i = 0; i < g3.G.size(); i++)
	{
		
		g3.dijkstra(g3.G[i].head->name,i);
	}
	std::cout << std::endl;
	std::cout << "***********TestCase 8***********" << std::endl;

	Graph g4;
	file.open("fig3-w.csv");
	str.clear();
	g4.CreateModifiedWeightedGraphByCSV(file,str);

	/*for (int i = 0; i < g4.G.size(); i++)
	{
		std::cout << " the source is " << g4.G[i].head->name << std::endl;
		g4.dijkstra(g4.G[i].head->name);
	}
*/
	std::cout << "\t\t";
	for (int i = 0; i < g4.G.size(); i++)
	{
		std::cout << g4.G[i].head->name << "\t\t";
	}
	for (int i = 0; i < g4.G.size(); i++)
	{

		g4.dijkstra(g4.G[i].head->name, i);
	}
	std::cout << std::endl;

	std::cout << "***********TestCase 9***********" << std::endl;

	std::cout << "The path from sourcr Vertex s to this vertex in G3" << std::endl;
	g3.dijkstra("s");
	std::cout << "The path from sourcr Vertex z to this vertex in G3" << std::endl;
	g3.dijkstra("z");


	std::cout << "***********TestCase 10***********" << std::endl;

	std::cout << "The path from sourcr Vertex s to this vertex in G4" << std::endl;
	g4.dijkstra("s");
	std::cout << "The path from sourcr Vertex z to this vertex in G4" << std::endl;
	g4.dijkstra("z");


	std::cout << "***********TestCase 11***********" << std::endl;
	std::cout << " Vertex V1 is x, Vertex V2 is t, this is shortest path from V1 to v2! " << std::endl;
	g3.PrintShortPathDot("t11.dot","x", "t");

	std::cout << "***********TestCase 12***********" << std::endl;
	std::cout << " Vertex V1 is s, Vertex V2 is x, this is shortest path from V1 to v2! " << std::endl;
	g4.PrintUnShortPathDot("t12.dot", "s", "x");
	
	
	
}
