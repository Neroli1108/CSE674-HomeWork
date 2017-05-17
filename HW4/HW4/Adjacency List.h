/////////////////////////////////////////////////
//FileName: Ajacency List.h
//FileDescription: Using Ajacency List to Implementate the Graph
//Date: 12/6/2016
//Platform:Windows10
//Author: Yunding Li  Yli327@syr.edu
//////////////////////////////////////////////////
#pragma once

#include<iostream>
#include<vector>




class AdjListNode
{
public:
	AdjListNode();
	AdjListNode(int);
	AdjListNode(std::string);
	AdjListNode(std::string,std::string);
	~AdjListNode();
	int dest;
	int path;
	std::string weight;
	std::string name;
	AdjListNode* next;

};




class AdjList
{
public:
	AdjList();
	~AdjList();
	AdjListNode* head;

};



class Graph
{
public:
	Graph();
	~Graph();
	std::vector<AdjList> G;
	int V; //size of the graph
	
	void addEdgeSingle(std::string, std::string,std::string);//add single edge
	void addEdge(std::string, std::string);//add undirected edge
	void addEdgeSingle(std::string, std::string);//add single edge
	void remoEdgeSingle(std::string, std::string);//remove single edge
	void remoEdge(std::string, std::string);//remove undirected edge
	void printGraph(std::vector<std::string>); // print the graph
	void printWeightGraph();//print weight graph
	void printGraph();//print graph
	void CreateGraphByCSV(std::istream& str,std::vector<std::string>&);//create graph by reding csv file
	void CreateWeightedGraphByCSV(std::istream& str, std::vector<std::string>&);//create weight graph by reading csv file
	void PrintWDot(std::string name);//print weight graph dot file
	void PrintShortPathDot(std::string name,std::string,std::string);//print short path dot file
	void PrintDot(std::string name);//print the dot file
	void PrintUndirectedDot(std::string name);//print the undirected graph dot file
	void PrintUndirectedWDot(std::string name);//print the undirected weight graph dot file
	void PrintUnShortPathDot(std::string name, std::string src, std::string des);//print the shortest path
	void CreateModifiedWeightedGraphByCSV(std::istream& str, std::vector<std::string>& input);//modified weight graph by reading csv file
	void addVertices(std::string);//add new vertices
	void RemoVertices(std::string);//remove vertices
	void dijkstra(std::string srcname);//find short path
	void dijkstra(std::string srcname,int);//same
	std::string dijkstra(std::string srcname, std::string destname);//same
	void printArr(std::vector<int>dist, int n);//print the summary
	void PrintTable(std::vector<int>dist, int n,int);//print the table summary

private:
	int csvVer;
	void CreateGraph(int); //create a graph, int is the size of graph
};

