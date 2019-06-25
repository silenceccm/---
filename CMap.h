#ifndef CMAP_H
#define CMAP_H
#include<vector>
#include"Node.h"
#include "Edge.h"
using namespace std;


class CMap
{
public:
	CMap(int capacity);
	~CMap();
	bool addNode(Node *pNode);//向图中加入节点
	void resetNode();//重置节点
	void resetEdge();//重置线段
	void EdgeCount();
	bool setValueToMatrixForDirectedGraph(int row,int col,int val=1);//向由向图设置邻接矩阵
	bool setValueToMatrixForUnDirectedGraph(int row,int col,int val=1);//向无向图设置邻接矩阵
	void printMatrix();//打印邻接矩阵
	void depthFitstTraverse(int nodeIndex);//深度优先遍历
	void breadthFirstTraverse(int nodeIndex);//广度优先遍历
	void primTree(int nodeIndex);//普里姆算法
	void kruskalTree();//克鲁斯卡尔算法生成树
private:
	bool getValueFormMatrix(int row,int col,int&val);//从矩阵中获取权值
	void breadthFirstTraverseImp(vector<int>preVec);//广度优先遍历实现函数

	int getMinEdge(vector<Edge>edgevec);//获取最小边
	bool isInSet(vector<int>nodeSet,int target);//判断顶点是否在点集合中
	void mergeNodeSet(vector<int>nodeSetA,vector<int>nodeSetB);//合并两个顶点集合
private:
	int m_iCapacity;//图中最多可以容纳的顶点数
	int m_iNodeCount;//已经添加的顶点（节点）个数
	int m_iEdgeCount;//已经添加的图的边（节点）个数
	Node *m_pNodeArray;//用来存放顶点数组
	int *m_PMatrix;//用来存放邻接矩阵

	Edge*m_pEdge;
};

#endif 