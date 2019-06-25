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
	bool addNode(Node *pNode);//��ͼ�м���ڵ�
	void resetNode();//���ýڵ�
	void resetEdge();//�����߶�
	void EdgeCount();
	bool setValueToMatrixForDirectedGraph(int row,int col,int val=1);//������ͼ�����ڽӾ���
	bool setValueToMatrixForUnDirectedGraph(int row,int col,int val=1);//������ͼ�����ڽӾ���
	void printMatrix();//��ӡ�ڽӾ���
	void depthFitstTraverse(int nodeIndex);//������ȱ���
	void breadthFirstTraverse(int nodeIndex);//������ȱ���
	void primTree(int nodeIndex);//����ķ�㷨
	void kruskalTree();//��³˹�����㷨������
private:
	bool getValueFormMatrix(int row,int col,int&val);//�Ӿ����л�ȡȨֵ
	void breadthFirstTraverseImp(vector<int>preVec);//������ȱ���ʵ�ֺ���

	int getMinEdge(vector<Edge>edgevec);//��ȡ��С��
	bool isInSet(vector<int>nodeSet,int target);//�ж϶����Ƿ��ڵ㼯����
	void mergeNodeSet(vector<int>nodeSetA,vector<int>nodeSetB);//�ϲ��������㼯��
private:
	int m_iCapacity;//ͼ�����������ɵĶ�����
	int m_iNodeCount;//�Ѿ���ӵĶ��㣨�ڵ㣩����
	int m_iEdgeCount;//�Ѿ���ӵ�ͼ�ıߣ��ڵ㣩����
	Node *m_pNodeArray;//������Ŷ�������
	int *m_PMatrix;//��������ڽӾ���

	Edge*m_pEdge;
};

#endif 