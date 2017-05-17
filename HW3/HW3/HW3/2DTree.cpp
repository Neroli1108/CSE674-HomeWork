#include<iostream>
#include<algorithm>
#include"2DTree.h"
#include<queue>

KdTreeNode::KdTreeNode() {
	Xkey = 0;
	Ykey = 0;
	data = 0;
}


KdTreeNode::KdTreeNode(int xkey, int ykey, int data) :Xkey(xkey), Ykey(ykey), data(data) {
}

KdTreeNode::~KdTreeNode() {
}

int KdTreeNode::height() {


	int l = leftNode ? leftNode->height() : 0;  // height of left child, if any
	int r = rightNode ? rightNode->height() : 0; // idem for right child
	return 1 + std::max(l, r);

}

KdTree::KdTree()
{
}

KdTree::~KdTree()
{
}

void KdTree::update() {

	std::queue<KdTreeNode*> nodeQueue;
	nodeQueue.push(root);
	KdTreeNode* node;
	KdTree temp;
	if (root == NULL)
	{
		return;
	}
	while (!nodeQueue.empty())
	{
		node = nodeQueue.front();
		nodeQueue.pop();
		if (node->leftNode!=NULL)
		{
			nodeQueue.push(node->leftNode);
		}
		if (node->rightNode!=NULL)
		{
			nodeQueue.push(node->rightNode);
		}
		node->leftNode = NULL;
		node->rightNode = NULL;
		temp.insert(node->Xkey,node->Ykey,node->data);
	}

	root = temp.root;

	


}

void KdTree::insert(int xkey, int ykey, int data, KdTreeNode* node,int depth) {

	if (depth%2 == 0)
	{
		if (xkey<=node->Xkey)
		{
			if (node->leftNode == NULL)
			{
				node->leftNode = new KdTreeNode(xkey, ykey, data);
			}
			else
			{
				insert(xkey, ykey,data, node->leftNode,depth+1);
			}
		}
		else
		{
			if (node->rightNode == NULL)
			{
				node->rightNode = new KdTreeNode(xkey, ykey, data);
			}
			else
			{
				insert(xkey, ykey, data, node->rightNode,depth+1);
			}
		}
	}
	else
	{
		if (ykey <= node->Ykey)
		{
			if (node->leftNode == NULL)
			{
				node->leftNode = new KdTreeNode(xkey, ykey, data);
			}
			else
			{
				insert(xkey, ykey, data, node->leftNode,depth+1);
			}
		}
		else
		{
			if (node->rightNode == NULL)
			{
				node->rightNode = new KdTreeNode(xkey, ykey, data);
			}
			else
			{
				insert(xkey, ykey, data, node->rightNode,depth+1);
			}
		}
	}

}

void KdTree::insert(int xkey,int ykey,int data) {

	if (root == NULL)
	{
		root = new KdTreeNode(xkey, ykey, data);
	
	}
	else 
	{
		insert(xkey, ykey, data, root,0);
		
	}

}



bool areSameKey(int x,int y, KdTreeNode* node) {
	//if (node == NULL)
	//{
	//	return false;
	//}

	if (x == node->Xkey&&y == node->Ykey)
	{
		return true;
	}
	else
	{
		return false;
	}

}

KdTreeNode* minNode(KdTreeNode*x,KdTreeNode*y,KdTreeNode*z,int level) {

	KdTreeNode* res = x;


	if (level%2 == 0)
	{
		if (y!=NULL&&y->Xkey<res->Xkey)
		{
			res = y;
		}
		if (z!=NULL&&z->Xkey<res->Xkey)
		{
			res = z;
		}
	}
	else
	{
		if (y != NULL&&y->Ykey<res->Ykey)
		{
			res = y;
		}
		if (z != NULL&&z->Ykey<res->Ykey)
		{
			res = z;
		}
	}
	return res;
}


KdTreeNode* findMin(KdTreeNode* node, int d, int depth) {


	if (node == NULL)
	{
		return NULL;
	}

	int cd = depth % 2;

	if (cd == d)
	{
		if (node->leftNode == NULL)
		{
			return node;
		}
		return findMin(node->leftNode, d, depth + 1);
	}

	return minNode(node, findMin(node->leftNode, d, depth + 1), findMin(node->rightNode, d, depth + 1), d);

}

KdTreeNode* findMin(KdTreeNode*node, int d) {

	return findMin(node, d, 0);

}


KdTreeNode* KdTree::deleteNode(int xkey,int ykey,int depth,KdTreeNode* node) {

	int cd = depth % 2;

	if (areSameKey(xkey,ykey,node))
	{
		if (node->rightNode!=NULL)
		{
			KdTreeNode* min = findMin(node->rightNode, cd);

			node->Xkey = min->Xkey;
			node->Ykey = min->Ykey;
			node->data = min->data;

			node->rightNode = deleteNode(min->Xkey, min->Ykey, depth + 1, node->rightNode);
		}
		else if (node->leftNode != NULL)
		{
			KdTreeNode* min = findMin(node->leftNode, cd);

			node->Xkey = min->Xkey;
			node->Ykey = min->Ykey;
			node->data = min->data;


			node->rightNode = deleteNode(min->Xkey, min->Ykey, depth + 1, node->leftNode);
			node->leftNode = NULL;
		}
		else
		{
		/*	node->Xkey = 0;
			node->Ykey = 0;
			node->data = 0;
			node->leftNode = NULL;
			node->rightNode = NULL;
			node = NULL;*/

			free(node);
			return NULL;
		}

		return node;
	}

	if (cd%2 == 0)
	{
		if (node->Xkey>=xkey)
		{
			node->leftNode = deleteNode(xkey, ykey, depth + 1, node->leftNode);
		}
		else
		{
			node->rightNode = deleteNode(xkey, ykey, depth + 1, node->rightNode);
		}
	}
	else
	{
		if (node->Ykey>=ykey)
		{
			node->leftNode = deleteNode(xkey, ykey, depth + 1, node->leftNode);
		}
		else
		{
			node->rightNode = deleteNode(xkey, ykey, depth + 1, node->rightNode);
		}
	}
	return node;
}


void KdTree::deleteNode(int xkey, int ykey) {

	if (root == NULL)
	{
		return;
	}
	else
	{
		root = deleteNode(xkey, ykey, 0, root);
	}

}


KdTreeNode* KdTree::search(int x, int y, int depth,KdTreeNode*node) {

	if (node == NULL)
	{
		return NULL;
	}
	if (areSameKey(x,y,node))
	{
		return node;
	}
	
	unsigned cd = depth % 2;

	if (cd%2 == 0)
	{
		if (x<=node->Xkey)
		{
			return(x, y, depth + 1, node->leftNode);
		}
		else
		{
			return(x, y, depth + 1, node->rightNode);
		}
	}
	else
	{
		if (y <= node->Ykey)
		{
			return(x, y, depth + 1, node->leftNode);
		}
		else
		{
			return(x, y, depth + 1, node->rightNode);
		}
	}

}

KdTreeNode* KdTree::search(int x, int y) {

	return search(x, y, 0, root);

}

int KdTree::Height() {

	if (root == NULL)
	{
		return -1;
	}
	else
	{
		return root->height();
	}


}


//print function
void KdTree:: bst_print_dot_null(int xkey,int ykey, int data, int nullcount, FILE* stream)
{
	fprintf(stream, "    null%d [shape=point];\n", nullcount);
	fprintf(stream, "   \"%d,%d,%d\"-> null%d;\n", xkey,ykey, data, nullcount);
}

void KdTree::bst_print_dot_aux(KdTreeNode* node, FILE* stream)
{
	static int nullcount = 0;

	if (node->leftNode)
	{
		fprintf(stream, " \"%d,%d,%d\" -> \"%d,%d,%d\";\n", node->Xkey,node->Ykey, node->data, node->leftNode->Xkey,node->leftNode->Ykey, node->leftNode->data);
		bst_print_dot_aux(node->leftNode, stream);
	}
	else
		bst_print_dot_null(node->Xkey,node->Ykey, node->data, nullcount++, stream);

	if (node->rightNode)
	{
		fprintf(stream, "\"%d,%d,%d\" ->\"%d,%d,%d\";\n", node->Xkey,node->Ykey, node->data, node->rightNode->Xkey,node->rightNode->Ykey, node->rightNode->data);
		bst_print_dot_aux(node->rightNode, stream);
	}
	else
		bst_print_dot_null(node->Xkey,node->Ykey, node->data, nullcount++, stream);
}

void KdTree::bst_print_dot(KdTreeNode* tree, FILE* stream)
{
	fprintf(stream, "digraph BST {\n");
	fprintf(stream, "    node [fontname=\"Arial\"];\n");

	if (!tree)
		fprintf(stream, "\n");
	else if (!tree->rightNode && !tree->leftNode)
		fprintf(stream, "\"%d,%d,%d\";\n", tree->Xkey,tree->Xkey, tree->data);
	else
		bst_print_dot_aux(tree, stream);

	fprintf(stream, "}\n");
}

void KdTree::clear() {

	root = NULL;
	root->leftNode = NULL;
	root->rightNode = NULL;

}
