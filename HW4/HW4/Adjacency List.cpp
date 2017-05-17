#include"Adjacency List.h"
#include<iostream>
#include<sstream>
#include<fstream>
#include <algorithm>
#include<string>
#include <algorithm>
#include <limits.h>
#include"PQ.h"

// graph constructor and destructor
Graph::Graph()
{
}

Graph::~Graph()
{
}
// adjlist constructor and destructor
AdjList::AdjList()
{
	head = NULL;
}

AdjList::~AdjList()
{
}

// adjlistnode constructor and destructor
AdjListNode::AdjListNode(std::string des, std::string w) {
	name = des;
	weight = w;
	next = NULL;
}

AdjListNode::AdjListNode(std::string des) {
	name = des;
	next = NULL;
}

AdjListNode::AdjListNode(int des) {
	dest = des;
	next = NULL;
}

AdjListNode::AdjListNode()
{
}

AdjListNode::~AdjListNode()
{
}
//convert the string to the int
int convertStringToNumber(std::string Text) {

	std::stringstream ss(Text);
	int result;
	return ss >> result ? result : 0;

}
//create the graph
void Graph::CreateGraph(int vertices) {

	V = vertices;                                         //initialize the vector
	csvVer = V;
	for (int i = 0; i < V; i++)
	{
		AdjList defa;
		G.push_back(defa);
	}
	

}

//add new vertices
void Graph:: addVertices(std::string name) {         
	AdjList newList;													
	G.push_back(newList);					//add new element to the vector
	G[G.size() - 1].head = new AdjListNode(name);
	V++;
	csvVer++;

}
//remove the vertix
void Graph::RemoVertices(std::string name) {
	int pos;							//ensure the vertix position
	V--;
	csvVer--;
	for (int i = 0; i < G.size(); i++)			// remove all edge associating it
	{
		if (name!=G[i].head->name)
		{
			remoEdge(name, G[i].head->name);
		}
		
	}
	for (int i = 0; i < G.size(); i++)			//remove it
	{
		if (name == G[i].head->name)
		{
			pos = i;
			break;
		}
	}
	G.erase(G.begin() + pos);

}

void Graph::addEdge(std::string src, std::string des) { //add undirected edge

	AdjListNode* newNode = new AdjListNode(des);
	for (int i = 0; i < G.size(); i++)  
	{
		if (G[i].head->name == src)
		{
			newNode->next = G[i].head->next;
			G[i].head->next = newNode;
		}
	}

	newNode = new AdjListNode(src);
	for (int i = 0; i < G.size(); i++)
	{
		if (G[i].head->name == des)
		{
			newNode->next = G[i].head->next;
			G[i].head->next = newNode;
		}
	}
}


void Graph::addEdgeSingle(std::string src, std::string des, std::string weight) {//add weight single edge

	AdjListNode* newNode = new AdjListNode(des,weight);
	
	for (int i = 0; i < G.size(); i++)
	{
		if (G[i].head->name == src)
		{
			newNode->next = G[i].head->next;
			G[i].head->next = newNode;
		}
	}

}


void Graph::addEdgeSingle(std::string src, std::string des) { //add single edge

	AdjListNode* newNode = new AdjListNode(des);
	for (int i = 0; i < G.size(); i++)
	{
		if (G[i].head->name == src)
		{
			newNode->next = G[i].head->next;
			G[i].head->next = newNode;
		}
	}
	
}

void Graph::remoEdgeSingle(std::string src, std::string des) { //remove single edge
	int srcn;
	for (int i = 0; i < G.size(); i++)
	{
		if (G[i].head->name == src) {
		
			srcn = i;

		}
	}
	AdjListNode* cur = G[srcn].head;
	AdjListNode* next = G[srcn].head->next;
	while (cur) {
		if (cur->name == des)
		{
			G[srcn].head->next = cur->next;
			break;
		}
		else if (next->name == des)
		{
			cur->next = next->next;
			break;
		}
		else
		{
			cur = next;
			if (next != NULL)
			{
				next = next->next;
			}


		}
	}

}

void Graph::remoEdge(std::string src, std::string des) {//remove undirected edge
	int srcn, desn;
	for (int i = 0; i < G.size(); i++)
	{
		if (G[i].head->name == src) {

			srcn = i;
			break;
		}
	}
	AdjListNode* cur = G[srcn].head;
	AdjListNode* next = G[srcn].head->next;
	while (cur) {
		if (cur->name == des)
		{
			G[srcn].head->next = cur->next;
			break;
		}
		else if (next!=NULL&&next->name == des)
		{
			cur->next = next->next;
			break;
		}
		else
		{
			cur = next;
			if (next != NULL)
			{
				next = next->next;
			}


		}
	}


	for (int i = 0; i < G.size(); i++)
	{
		if (G[i].head->name == des) {

			desn = i;

		}
	}
	 cur = G[desn].head;
	next = G[desn].head->next;
	while (cur) {
		if (cur->name == src)
		{
			G[srcn].head->next = cur->next;
			break;
		}
		else if (next != NULL&&next->name == src)
		{
			cur->next = next->next;
			break;
		}
		else
		{
			cur = next;
			if (next != NULL)
			{
				next = next->next;
			}


		}
	}
}

void Graph::printGraph() { //print the summary

	for (int i = 0; i < V; i++)
	{
		AdjListNode* pNode = G[i].head;
		std::cout << "\n Adjacency list of vertex " << i+1 << " \n head";
		while (pNode)
		{
			std::cout << "->" << pNode->dest+1;
			pNode = pNode->next;
		}
		std::cout << std::endl;
	}

}

void Graph::printGraph(std::vector<std::string> name) { // embed function , of course for summary

	for (int i = 0; i < V; i++)
	{
		AdjListNode* pNode = G[i].head->next;
		std::cout<<"\n Adjacency list of vertex "<< name[i+1] <<" \n head";
		while (pNode)
		{
			std::cout << "->" << pNode->name;
			pNode = pNode->next;
		}
		std::cout << std::endl;
	}

}

void Graph:: printWeightGraph() { //print weight graph
	for (int i = 0; i < V; i++)
	{
		AdjListNode* pNode = G[i].head->next;
		std::cout << "\n Adjacency list of vertex " << G[i].head->name << " \n head";
		while (pNode)
		{
			std::cout << "->" << pNode->name<<" (Weight is "<<pNode->weight<<")";
			pNode = pNode->next;
		}
		std::cout << std::endl;
	}



}

void Graph::PrintUndirectedWDot(std::string name) { //print undirected weight dot

	std::ofstream stream;
	stream.open(name.c_str());
	if (stream.is_open())
	{
		std::cout << " Create the file " << name << std::endl;
	}

	std::string record;
	stream << "graph G {\n";
	for (int i = 0; i < G.size(); i++)
	{

		record = record + G[i].head->name;
		AdjListNode* cur = G[i].head->next;
		while (cur) {
			if (record.find(cur->name) == std::string::npos)
			{
				stream << G[i].head->name << " -- " << cur->name << std::endl;
				cur = cur->next;
			}
			else
			{
				cur = cur->next;
			}


		}

	}
	stream << "}\n";

	stream.close();

}


void Graph::PrintUndirectedDot(std::string name) { //print undirected dot

	std::ofstream stream;
	stream.open(name.c_str());
	if (stream.is_open())
	{
		std::cout << " Create the file " << name << std::endl;
	}

	std::string record;
	stream << "graph G {\n";
	for (int i = 0; i < G.size(); i++)
	{
		
		record = record + G[i].head->name;
		AdjListNode* cur = G[i].head->next;
		while (cur) {
			if (record.find(cur->name)==std::string::npos)
			{
			stream << G[i].head->name << " -- " << cur->name << "[label=" << "\"" << cur->weight << "\",weight=" << "\"" << cur->weight << "\"];\n";
			cur = cur->next;
			}
			else
			{
				cur = cur->next;
			}
			

		}

	}
	stream << "}\n";

	stream.close();

}

void Graph::CreateGraphByCSV(std::istream& str,std::vector<std::string>& input) { //create graph by reading csv file

	
	int src = 0, des;
	std::vector<std::string>   result;
	std::vector<std::string>   name;
	std::string                line;
	std::getline(str, line);
	std::stringstream          lineStream(line);
	std::string                cell;
	while (std::getline(lineStream, cell, ','))
	{
		name.push_back(cell);
	}
	input = name;
	csvVer = name.size() - 1;
	V = csvVer;
	CreateGraph(csvVer);
	for (int i = 0; i < csvVer; i++)
	{
		G[i].head= new AdjListNode(name[i+1]);
	}
	while (std::getline(str, line))
	{
		std::stringstream          lineStream(line);
		std::string                cell;
		while (std::getline(lineStream, cell, ','))
		{
			result.push_back(cell);
		}
		// This checks for a trailing comma with no data after it.
		if (!lineStream && cell.empty())
		{
			// If there was a trailing comma then add an empty element.
			result.push_back("");
		}
		for (int i = 1; i < result.size(); i++)
		{
			if (result[i] == "1")
			{
				des = i;
				
				addEdgeSingle(name[src+1], name[des]);
			}
		}
		result.clear();
		++src;
	}



}
//read the csv file and modified it and create the graph

void Graph::CreateModifiedWeightedGraphByCSV(std::istream& str, std::vector<std::string>& input) {

	
	int src = 0, des;
	std::vector<std::string>   result;
	std::vector<std::string>   name;
	std::string                line;
	std::getline(str, line);
	std::stringstream          lineStream(line);
	std::string                cell;
	while (std::getline(lineStream, cell, ','))
	{
		name.push_back(cell);
	}
	input = name;
	csvVer = name.size() - 1;
	V = csvVer;
	std::vector<std::vector<std::string>> wei(V ,std::vector<std::string>(V));
	int count = 0;

	CreateGraph(csvVer);
	for (int i = 0; i < csvVer; i++)
	{
		G[i].head = new AdjListNode(name[i + 1]);
	}
	while (std::getline(str, line))
	{
		std::stringstream          lineStream(line);
		std::string                cell;
		while (std::getline(lineStream, cell, ','))
		{
			result.push_back(cell);

		}
		// This checks for a trailing comma with no data after it.
		if (!lineStream && cell.empty())
		{
			// If there was a trailing comma then add an empty element.
			result.push_back("");
		}

		for (int i = 1; i < result.size(); i++)
		{
			wei[count][i-1]=result[i];
		}


		result.clear();
		count++;
	
	}

	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (convertStringToNumber(wei[i][j])<convertStringToNumber(wei[j][i]))
			{
				if (wei[i][j]!="-1")
				{
					wei[j][i] = wei[i][j];
				
					addEdgeSingle(name[i + 1], name[j+1], wei[i][j]);
				}
				else
				{
					wei[i][j] = wei[j][i];
					addEdgeSingle(name[i + 1], name[j + 1], wei[i][j]);
				}
				
				
			}
			else
			{
				if (wei[j][i] != "-1")
				{
					wei[i][j] = wei[j][i];
					addEdgeSingle(name[i + 1], name[j + 1], wei[j][i]);
				}
				else if(wei[i][j] != "-1")
				{
					wei[j][i] = wei[i][j];
					addEdgeSingle(name[i + 1], name[j + 1], wei[i][j]);
				}
				
			
			}

		}
	}

	for (int i = 0; i < G.size(); i++)
	{
		AdjListNode* cur = G[i].head;
		while (cur)
		{
			for (int i = 0; i < name.size(); i++)
			{
				if (cur->name == name[i])
				{
					cur->dest = i - 1;
				}
			}
			cur = cur->next;
		}
	}


}

void Graph::CreateWeightedGraphByCSV(std::istream& str, std::vector<std::string>& input) {//create weight graph


	int src = 0, des;
	std::vector<std::string>   result;
	std::vector<std::string>   name;
	std::string                line;
	std::getline(str, line);
	std::stringstream          lineStream(line);
	std::string                cell;
	while (std::getline(lineStream, cell, ','))
	{
		name.push_back(cell);
	}
	input = name;
	csvVer = name.size() - 1;
	V = csvVer;
	CreateGraph(csvVer);
	for (int i = 0; i < csvVer; i++)
	{
		G[i].head = new AdjListNode(name[i + 1]);
	}
	while (std::getline(str, line))
	{
		std::stringstream          lineStream(line);
		std::string                cell;
		while (std::getline(lineStream, cell, ','))
		{
			result.push_back(cell);
		}
		// This checks for a trailing comma with no data after it.
		if (!lineStream && cell.empty())
		{
			// If there was a trailing comma then add an empty element.
			result.push_back("");
		}
		for (int i = 1; i < result.size(); i++)
		{
			if (result[i] != "-1")
			{
				des = i;

				addEdgeSingle(name[src + 1], name[des],result[i]);
			}
		}
		result.clear();
		++src;
	}
	for (int i = 0; i < G.size(); i++)
	{
		AdjListNode* cur = G[i].head;
		while (cur)
		{
			for (int i = 0; i < name.size(); i++)
			{
				if (cur->name == name[i])
				{
					cur->dest = i-1;
				}
			}
			cur = cur->next;
		}
	}


}

//print dot
void Graph::PrintDot(std::string name) {

	std::ofstream stream;
	stream.open(name.c_str());
	if (stream.is_open())
	{
		std::cout << " Create the file " << name << std::endl;
	}


	stream << "digraph G {\n";
	for (int i = 0; i < G.size(); i++)
	{

		AdjListNode* cur = G[i].head->next;
		if (!cur)
		{
			stream << G[i].head->name <<  std::endl;
		}
		while (cur) {

			stream << G[i].head->name << " -> " << cur->name << std::endl;
			cur = cur->next;

		}

	}
	stream << "}\n";

	stream.close();
}

  // print weight dot
void Graph::PrintWDot(std::string name) {

	std::ofstream stream;
	stream.open(name.c_str());
	if (stream.is_open())
	{
		std::cout << " Create the file " << name << std::endl;
	}


	stream<< "digraph G {\n";
	for (int i = 0; i < G.size(); i++)
	{

		AdjListNode* cur = G[i].head->next;
		while (cur) {
			
			stream << G[i].head->name << " -> " << cur->name << "[label=" << "\"" << cur->weight << "\",weight=" << "\"" << cur->weight << "\"];\n";
			cur = cur->next;
		
		}

	}
	stream << "}\n";

	stream.close();
} 







//print the summary

void Graph::printArr(std::vector<int>dist, int n)
{
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < n; ++i)
		std::cout << G[i].head->name << "\t\t" << dist[i] << std::endl;
}

//print the table summary
void Graph::PrintTable(std::vector<int>dist, int n, int j) {
	std::cout << std::endl;
	std::cout << G[j].head->name;
	for (int i = 0; i < n; ++i)
		std::cout << "\t\t" << dist[i] ;


}

//find the shortest path by Priority queue (minHeap)
void Graph::dijkstra(std::string srcname,int j)
{
	int src;
	for (int i = 0; i < G.size(); i++)
	{
		if (G[i].head->name == srcname)
		{
			src = i;
		}
	}
	int V = this->V;// Get the number of vertices in graph
	std::vector<int> dist(V);      // dist values used to pick minimum weight edge in cut

								   // minHeap represents set E
	struct MinHeap* minHeap = createMinHeap(V);

	// Initialize min heap with all vertices. dist value of all vertices 
	for (int v = 0; v < V; ++v)
	{
		dist[v] = INT_MAX;
		minHeap->array[v] = newMinHeapNode(v, dist[v]);
		minHeap->pos[v] = v;
	}

	// Make dist value of src vertex as 0 so that it is extracted first
	minHeap->array[src] = newMinHeapNode(src, dist[src]);
	minHeap->pos[src] = src;
	dist[src] = 0;
	decreaseKey(minHeap, src, dist[src]);

	// Initially size of min heap is equal to V
	minHeap->size = V;

	// In the followin loop, min heap contains all nodes
	// whose shortest distance is not yet finalized.
	while (!isEmpty(minHeap))
	{
		// Extract the vertex with minimum distance value
		struct MinHeapNode* minHeapNode = extractMin(minHeap);
		int u = minHeapNode->v; // Store the extracted vertex number

								// Traverse through all adjacent vertices of u (the extracted
								// vertex) and update their distance values
		AdjListNode* pCrawl = G[u].head->next;
		while (pCrawl != NULL)
		{
			int v = pCrawl->dest;

			// If shortest distance to v is not finalized yet, and distance to v
			// through u is less than its previously calculated distance
			if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX &&
				convertStringToNumber(pCrawl->weight) + dist[u] < dist[v])
			{
				dist[v] = dist[u] + convertStringToNumber(pCrawl->weight);

				// update distance value in min heap also
				decreaseKey(minHeap, v, dist[v]);
			}
			pCrawl = pCrawl->next;
		}
	}

	// print the calculated shortest distances
	
	PrintTable(dist, V,j);
}

//same as above function
void Graph::dijkstra( std::string srcname)
{
	int src;
	for (int i = 0; i < G.size(); i++)
	{
		if (G[i].head->name == srcname)
		{
			src = i;
		}
	}
	int V = this->V;// Get the number of vertices in graph
	std::vector<int> dist(V);      // dist values used to pick minimum weight edge in cut
	
					  // minHeap represents set E
	struct MinHeap* minHeap = createMinHeap(V);

	// Initialize min heap with all vertices. dist value of all vertices 
	for (int v = 0; v < V; ++v)
	{
		dist[v] = INT_MAX;
		minHeap->array[v] = newMinHeapNode(v, dist[v]);
		minHeap->pos[v] = v;
	}

	// Make dist value of src vertex as 0 so that it is extracted first
	minHeap->array[src] = newMinHeapNode(src, dist[src]);
	minHeap->pos[src] = src;
	dist[src] = 0;
	decreaseKey(minHeap, src, dist[src]);

	// Initially size of min heap is equal to V
	minHeap->size = V;

	// In the followin loop, min heap contains all nodes
	// whose shortest distance is not yet finalized.
	while (!isEmpty(minHeap))
	{
		// Extract the vertex with minimum distance value
		struct MinHeapNode* minHeapNode = extractMin(minHeap);
		int u = minHeapNode->v; // Store the extracted vertex number

								// Traverse through all adjacent vertices of u (the extracted
								// vertex) and update their distance values
		 AdjListNode* pCrawl = G[u].head->next;
		while (pCrawl != NULL)
		{
			int v = pCrawl->dest;

			// If shortest distance to v is not finalized yet, and distance to v
			// through u is less than its previously calculated distance
			if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX &&
			convertStringToNumber(pCrawl->weight) + dist[u] < dist[v])
			{
				dist[v] = dist[u] + convertStringToNumber(pCrawl->weight);

				// update distance value in min heap also
				decreaseKey(minHeap, v, dist[v]);
			}
			pCrawl = pCrawl->next;
		}
	}

	// print the calculated shortest distances
	printArr(dist, V);
}

//same as above function
std::string Graph::dijkstra(std::string srcname,std::string destname)
{
	std::string res;

	int src, des;
	
	for (int i = 0; i < G.size(); i++)
	{
		if (G[i].head->name == srcname)
		{
			src = i;
		}
	}
	for (int i = 0; i < G.size(); i++)
	{
		if (G[i].head->name == destname)
		{
			des = i;
		}
	}
	int V = this->V;// Get the number of vertices in graph
	std::vector<int> dist(V);      // dist values used to pick minimum weight edge in cut
	std::vector<std::string> track(V,srcname);
								   // minHeap represents set E
	struct MinHeap* minHeap = createMinHeap(V);

	// Initialize min heap with all vertices. dist value of all vertices 
	for (int v = 0; v < V; ++v)
	{
		dist[v] = INT_MAX;
		minHeap->array[v] = newMinHeapNode(v, dist[v]);
		minHeap->pos[v] = v;
	}

	// Make dist value of src vertex as 0 so that it is extracted first
	minHeap->array[src] = newMinHeapNode(src, dist[src]);
	minHeap->pos[src] = src;
	dist[src] = 0;
	decreaseKey(minHeap, src, dist[src]);

	// Initially size of min heap is equal to V
	minHeap->size = V;

	// In the followin loop, min heap contains all nodes
	// whose shortest distance is not yet finalized.
	while (!isEmpty(minHeap))
	{
		// Extract the vertex with minimum distance value
		struct MinHeapNode* minHeapNode = extractMin(minHeap);
		int u = minHeapNode->v; // Store the extracted vertex number

								// Traverse through all adjacent vertices of u (the extracted
								// vertex) and update their distance values
		AdjListNode* pCrawl = G[u].head->next;
		while (pCrawl != NULL)
		{
			int v = pCrawl->dest;

			// If shortest distance to v is not finalized yet, and distance to v
			// through u is less than its previously calculated distance
			if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX &&
				convertStringToNumber(pCrawl->weight) + dist[u] < dist[v])
			{
				dist[v] = dist[u] + convertStringToNumber(pCrawl->weight);
				track[v] = track[u] + pCrawl->name;
				// update distance value in min heap also
				decreaseKey(minHeap, v, dist[v]);
				res = track[v];
			}
			/*if (pCrawl->dest == des)
			{

				return res = track[v];

			}*/
			pCrawl = pCrawl->next;
	
		}
	}
	return res;
	
}
//print the track dot for undirected graph
void Graph::PrintUnShortPathDot(std::string name, std::string src, std::string des) {


	int path = 0;
	std::string res = dijkstra(src, des);
	std::stringstream ss;
	char track;
	std::vector<int> pos;
	std::ofstream stream;
	stream.open(name.c_str());
	if (stream.is_open())
	{
		std::cout << " Create the file " << name << std::endl;
	}

	std::string record = res;
	for (int j = 0; j < res.size(); j++)
	{
		for (int i = 0; i < G.size(); i++)
		{
			ss << G[i].head->name;
			ss >> track;
			if (track == res[j])
			{
				pos.push_back(i);

			}

		}
	}
	
	stream << "graph G {\n";

	for (int i = 1; i < pos.size(); i++)
	{
		
		AdjListNode* cur = G[pos[i-1]].head->next;
		if (record.find(cur->name)==std::string::npos)
		{
			record += cur->name;
		}
		while (cur)
		{
			if (cur->name == G[pos[i]].head->name)
			{
				path += convertStringToNumber(cur->weight);
				if (i != pos.size() - 1)
				{
					stream << G[pos[i - 1]].head->name << " -- " << cur->name << "[color=red]" << std::endl;
					cur = cur->next;
				}
				else
				{
					stream << G[pos[i - 1]].head->name << " -- " << cur->name << "[label=" << "\"" << path << "\",weight=" << "\"" << path << "\",color=red]" << std::endl;
					cur = cur->next;
				}
			}
			else if(res.find(cur->name) == std::string::npos)
			{
				
					stream << G[pos[i - 1]].head->name << " -- " << cur->name << std::endl;
					cur = cur->next;
				
			}
			else
			{
			
				cur = cur->next;
			}
			
		}
		
		
	}

	AdjListNode* makeup = G[pos[pos.size() - 1]].head->next;
	while (makeup)
	{
		if (makeup->name != G[pos[pos.size() - 2]].head->name)
		{
			stream << G[pos[pos.size() - 1]].head->name << " -- " << makeup->name << std::endl;
			
		}
		makeup = makeup->next;
	}

	for (int i = 0; i < G.size(); i++)
	{
		
			if (res.find(G[i].head->name) == std::string::npos)
			{
			AdjListNode* cur = G[i].head->next;
			while (cur)
			{
				if (res.find(cur->name) == std::string::npos)
				{
					stream << G[i].head->name << " -- " << cur->name << std::endl;
					
				}
				cur = cur->next;
			}
			
			}
		
	}


	/*for (int i = 0; i < G.size(); i++)
	{
		record = record + G[i].head->name;
		AdjListNode* cur = G[i].head->next;
		while (cur) {
			if (record.find(cur->name) == std::string::npos) {
				if (res.find(G[i].head->name) != res.size() - 1 && res.find(G[i].head->name) != std::string::npos &&res.find(cur->name) != std::string::npos)
				{
					path += convertStringToNumber(cur->weight);
					if (res.find(cur->name) == res.size() - 1)
					{
						stream << G[i].head->name << " -- " << cur->name << "[label=" << "\"" << path << "\",weight=" << "\"" << path << "\",color=red]" << std::endl;
					}
					else
						stream << G[i].head->name << " -- " << cur->name << "[color=red]" << std::endl;
				}
				else
				{
					stream << G[i].head->name << " -- " << cur->name << std::endl;
				}

				cur = cur->next;
			}
			else
			{
				cur = cur->next;
			}
		}

	}*/
	
	stream << "}\n";

	stream.close();

}


//print the track dot for graph
void Graph::PrintShortPathDot(std::string name,std::string src,std::string des) {
	int path = 0;
	std::string res = dijkstra(src,des);
	std::ofstream stream;
	std::stringstream ss;
	std::vector<int> pos;
	char track;
	stream.open(name.c_str());
	if (stream.is_open())
	{
		std::cout << " Create the file " << name << std::endl;
	}

	std::string record = res;
	for (int j = 0; j < res.size(); j++)
	{
		for (int i = 0; i < G.size(); i++)
		{
			ss << G[i].head->name;
			ss >> track;
			if (track == res[j])
			{
				pos.push_back(i);

			}

		}
	}
	stream << "digraph G {\n";
	
	for (int i = 1; i < pos.size(); i++)
	{

		AdjListNode* cur = G[pos[i - 1]].head->next;
		if (record.find(cur->name) == std::string::npos)
		{
			record += cur->name;
		}
		while (cur)
		{
			if (cur->name == G[pos[i]].head->name)
			{
				path += convertStringToNumber(cur->weight);
				if (i != pos.size() - 1)
				{
					stream << G[pos[i - 1]].head->name << " -> " << cur->name << "[color=red]" << std::endl;
					cur = cur->next;
				}
				else
				{
					stream << G[pos[i - 1]].head->name << " -> " << cur->name << "[label=" << "\"" << path << "\",weight=" << "\"" << path << "\",color=red]" << std::endl;
					cur = cur->next;
				}
			}
			else
			{

				stream << G[pos[i - 1]].head->name << " -> " << cur->name << std::endl;
				cur = cur->next;

			}

		}


	}

	AdjListNode* makeup = G[pos[pos.size() - 1]].head->next;
	while (makeup)
	{
			stream << G[pos[pos.size() - 1]].head->name << " -> " << makeup->name << std::endl;

		makeup = makeup->next;
	}

	for (int i = 0; i < G.size(); i++)
	{

		if (res.find(G[i].head->name) == std::string::npos)
		{
			AdjListNode* cur = G[i].head->next;
			while (cur)
			{

					stream << G[i].head->name << " -> " << cur->name << std::endl;


				cur = cur->next;
			}

		}

	}
	//for (int i = 0; i < G.size(); i++)
	//	{
	//	AdjListNode* cur = G[i].head->next;
	//	while (cur) {

	//		if (res.find(G[i].head->name) != res.size() - 1 && res.find(G[i].head->name) != std::string::npos &&res.find(cur->name) != std::string::npos)
	//		{
	//			path += convertStringToNumber(cur->weight);
	//			if (res.find(cur->name) == res.size() - 1)
	//			{
	//				stream << G[i].head->name << " -> " << cur->name <<  "[label=" << "\"" <<path << "\",weight=" << "\"" << path << "\"]" << std::endl;
	//			}
	//			else
	//			stream << G[i].head->name << " -> " << cur->name /*<<"[color=red]"*/<< std::endl;
	//		}
	//		else
	//		{
	//			stream << G[i].head->name << " -> " << cur->name << std::endl;
	//		}
	//		
	//		cur = cur->next;

	//	}

	//}
	stream << "}\n";

	stream.close();
}

