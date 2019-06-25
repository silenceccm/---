#include "CMap.h"
#include <iostream>
using namespace std;
/*
图的存储于图的遍历

		 A
	   /   \
	 B       D
    / \     /  \
   C   F   G -- H
    \ /
	 E
*/
int main(void)
{
 
  	CMap *pMap=new CMap(8);
  
  	Node *pNodeA=new Node('A');
  	Node *pNodeB=new Node('B');
  	Node *pNodeC=new Node('C');
  	Node *pNodeD=new Node('D');
  	Node *pNodeE=new Node('E');
  	Node *pNodeF=new Node('F');
  	Node *pNodeG=new Node('G');
  	Node *pNodeH=new Node('H');
  
  	pMap->addNode(pNodeA);
  	pMap->addNode(pNodeB);
  	pMap->addNode(pNodeC);
  	pMap->addNode(pNodeD);
  	pMap->addNode(pNodeE);
  	pMap->addNode(pNodeF);
  	pMap->addNode(pNodeG);
  	pMap->addNode(pNodeH);
  
  
  	pMap->setValueToMatrixForUnDirectedGraph(0,1,2);
  	pMap->setValueToMatrixForUnDirectedGraph(0,3,4);
  	pMap->setValueToMatrixForUnDirectedGraph(1,2,3);
  	pMap->setValueToMatrixForUnDirectedGraph(1,5,5);
  
  	pMap->setValueToMatrixForUnDirectedGraph(3,6,9);
  	pMap->setValueToMatrixForUnDirectedGraph(3,7,6);
  	pMap->setValueToMatrixForUnDirectedGraph(6,7,2);
  	pMap->setValueToMatrixForUnDirectedGraph(2,4,6);
  
  	pMap->setValueToMatrixForUnDirectedGraph(4,5,4);
  	pMap->setValueToMatrixForUnDirectedGraph(1,6,2);
  	pMap->setValueToMatrixForUnDirectedGraph(5,7,7);
  	pMap->setValueToMatrixForUnDirectedGraph(0,4,5);
 	

	pMap->printMatrix();
	cout<<endl;

// 	pMap->primTree(2);
// 	pMap->primTree(3);
// 	pMap->primTree(4);
// 	pMap->primTree(5);
// 
//   	cout<<endl;
//   	pMap->resetNode();
  	pMap->depthFitstTraverse(0);
//   
	cout<<endl;
	pMap->resetNode();
	pMap->breadthFirstTraverse(0);
 
  
//   	CMap *pMap=new CMap(6);
//   
//   	Node *pNodeA=new Node('A');
//   	Node *pNodeB=new Node('B');
//   	Node *pNodeC=new Node('C');
//   	Node *pNodeD=new Node('D');
//   	Node *pNodeE=new Node('E');
//   	Node *pNodeF=new Node('F');
//   
//   
//   	pMap->addNode(pNodeA);
//   	pMap->addNode(pNodeB);
//   	pMap->addNode(pNodeC);
//   	pMap->addNode(pNodeD);
//   	pMap->addNode(pNodeE);
//   	pMap->addNode(pNodeF);
//   
//   
//   
//   	pMap->setValueToMatrixForUnDirectedGraph(0,1,6);
//   	pMap->setValueToMatrixForUnDirectedGraph(0,4,5);
//   	pMap->setValueToMatrixForUnDirectedGraph(0,5,1);
//   	pMap->setValueToMatrixForUnDirectedGraph(1,2,3);
//   	pMap->setValueToMatrixForUnDirectedGraph(1,5,2);
//   	pMap->setValueToMatrixForUnDirectedGraph(2,5,8);
//   	pMap->setValueToMatrixForUnDirectedGraph(2,3,7);
//   	pMap->setValueToMatrixForUnDirectedGraph(3,5,4);
//   	pMap->setValueToMatrixForUnDirectedGraph(3,4,2);
//   	pMap->setValueToMatrixForUnDirectedGraph(4,5,9);
  
  	//pMap->primTree(2);
	pMap->kruskalTree();

	system("pause");
	return 0;

}

