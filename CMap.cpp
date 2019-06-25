#include"CMap.h"
#include<iostream>
#include <vector>
using namespace std;

CMap:: CMap(int capacity)
{
	m_iCapacity=capacity;
	m_iNodeCount=0;
	m_pNodeArray=new Node [m_iCapacity];
	m_PMatrix=new int [m_iCapacity*m_iCapacity];
	memset(m_PMatrix,0,m_iCapacity*m_iCapacity*sizeof(int));
// 	for (int i=0;i<m_iCapacity*m_iCapacity;i++)
// 	{
// 		m_PMatrix[i]=0;
// 	}

	m_pEdge=new Edge[capacity-1];
	
}

CMap::~CMap()
{
	delete[]m_pNodeArray;
	delete[]m_PMatrix;
	delete[]m_pEdge;
}

bool CMap::addNode(Node *pNode)
{
	if (pNode==NULL)
	{
		return false;
	}
	m_pNodeArray[m_iNodeCount].m_cData=pNode->m_cData;
	m_iNodeCount++;
	return true;
}

void CMap::resetNode()
{
	for (int i=0;i<m_iNodeCount;i++)
	{
		m_pNodeArray[i].m_bIsVisited=false;
	}
}

// void Edge::resetEdge();//���ýڵ�
// {
// 	for (int i=0;i<m_iNodeCount;i++)
// 	{
// 		m_pNodeArray[i].m_bIsVisited=false;
// 	}
// }

//void CMap::depthFitstTraverse(int nodeIndex)
//{
//	int value =0;
//	cout<<m_pNodeArray[nodeIndex].m_cData<<" ";
//	m_pNodeArray[nodeIndex].m_bIsVisited=true;
//	//ͨ���ڽӾ����ж��Ƿ��������Ķ��� ������
//	for (int i=0;i<m_iCapacity;i++)
//	{
//		getValueFormMatrix(nodeIndex,i,value);
//		if(value!=0)
//		{
//			if (m_pNodeArray[i].m_bIsVisited)
//			{
//				continue;
//			}
//			else
//			{
//				depthFitstTraverse(i);
//			}
//		}
//		else
//		{
//			continue;
//		}
//	}
//
//}
void CMap::depthFitstTraverse(int nodeIndex)
{
	int value =0;
	cout<<m_pNodeArray[nodeIndex].m_cData<<" ";
	m_pNodeArray[nodeIndex].m_bIsVisited=true;
	//ͨ���ڽӾ����ж��Ƿ��������Ķ��� ������
	for (int i=0;i<m_iCapacity;i++)
	{
		getValueFormMatrix(nodeIndex,i,value);
		if(value!=0&&m_pNodeArray[i].m_bIsVisited!=1)
		{
			depthFitstTraverse(i);
			
		}
		
	}

}


void CMap::breadthFirstTraverse(int nodeIndex)
{
	 cout<<m_pNodeArray[nodeIndex].m_cData<<" ";
	 m_pNodeArray[nodeIndex].m_bIsVisited=true;

	 vector<int> curVec;
	 curVec.push_back(nodeIndex);

	 breadthFirstTraverseImp(curVec);

}
void CMap::breadthFirstTraverseImp(vector<int>preVec)
{
	int value=0;
	vector<int> curVec;

	for (int j=0;j<(int)preVec.size();j++)
	{
		for (int i=0;i<m_iCapacity;i++)
		{
			getValueFormMatrix(preVec[j],i,value);
			if (value!=0&&m_pNodeArray[i].m_bIsVisited!=1)
			{
				cout<<m_pNodeArray[i].m_cData<<" ";
				m_pNodeArray[i].m_bIsVisited=true;
				curVec.push_back(i);
			}
			/*if (value!=0)
			{
				if (m_pNodeArray[i].m_bIsVisited)
				{
					continue;
				}
				else
				{
					cout<<m_pNodeArray[i].m_cData<<" ";
					m_pNodeArray[i].m_bIsVisited=true;

					curVec.push_back(i);

				}
			}*/
		}
	}

	if (curVec.size()==0)
	{
		return;
	}
	else
	{
		breadthFirstTraverseImp(curVec);
	}
}

void CMap::printMatrix()
{
	for(int i=0;i<m_iCapacity;i++)
	{
		for (int k=0;k<m_iCapacity;k++)
		{
			cout<<m_PMatrix[i*m_iCapacity+k]<<" ";
		}
		cout<<endl;
	}
}

bool CMap::setValueToMatrixForDirectedGraph(int row,int col,int val)//����ͼ
{
	if(row<0||row>=m_iCapacity)
	{
		return false;
	}
	if(col<0||row>=m_iCapacity)
	{
		return false;
	}
	m_PMatrix[row*m_iCapacity+col]=val;
	return true;
}

bool CMap::setValueToMatrixForUnDirectedGraph(int row,int col,int val)//����ͼ
{
	if(row<0||row>=m_iCapacity)
	{
		return false;
	}
	if(col<0||row>=m_iCapacity)
	{
		return false;
	}
	m_PMatrix[row*m_iCapacity+col]=val;
	m_PMatrix[col*m_iCapacity+row]=val;
	return true;
}

bool CMap::getValueFormMatrix(int row,int col,int&val)
{
	if(row<0||row>=m_iCapacity)
	{
		return false;
	}
	if(col<0||col>=m_iCapacity)
	{
		return false;
	}
	val=m_PMatrix[row*m_iCapacity+col];
	return true;
}
//����ķ�㷨
void CMap::primTree(int nodeIndex)
{
	int value =0;
	int edgeCount=0;
	vector<int>nodeVec;
	vector<Edge>edgeVec;

	cout<<m_pNodeArray[nodeIndex].m_cData<<endl;

	nodeVec.push_back(nodeIndex);
	m_pNodeArray[nodeIndex].m_bIsVisited=true;

	while(edgeCount<m_iCapacity-1)
	{
		int temp=nodeVec.back();//ȡβԪ��
		for (int i=0;i<m_iCapacity;i++)
		{
			getValueFormMatrix(temp,i,value);
			if (value!=0)
			{
				if (m_pNodeArray[i].m_bIsVisited)
				{
					continue;
				}
				else
				{
					Edge edge(temp,i,value);
					edgeVec.push_back(edge);
				}
			}
			
		}
		//�ӿ�ѡ�߼������ҳ���С��
	int edgeIndex=getMinEdge(edgeVec);
	edgeVec[edgeIndex].m_bSelected=true;

	cout<<edgeVec[edgeIndex].m_iNodeIndexA<<"---"<<edgeVec[edgeIndex].m_iNodeIndexB<<"  "<<edgeVec[edgeIndex].m_iWeightValue<<endl;

	m_pEdge[edgeCount]=edgeVec[edgeIndex];
	edgeCount++;

	int nextNodeIndex=edgeVec[edgeIndex].m_iNodeIndexB;
	nodeVec.push_back(nextNodeIndex);
	m_pNodeArray[nextNodeIndex].m_bIsVisited=true;
	cout<<m_pNodeArray[nextNodeIndex].m_cData<<endl;
	}
}

int CMap::getMinEdge(vector<Edge>edgevec)
{
	int minWeight=0;
	int edgeIndex=0;
	int i =0;
	for (;i<(int)edgevec.size();i++)
	{
		
		 if (!edgevec[i].m_bSelected)
		 {
			 minWeight=edgevec[i].m_iWeightValue;
			 edgeIndex=i;
			 break;
		 }
	}
	if (minWeight==0)
	{
		return -1;
	}
	for (;i<(int)edgevec.size();i++)
	{
		if (edgevec[i].m_bSelected)
		 {
			continue;
		 }
		else
		{
			if (minWeight>edgevec[i].m_iWeightValue)
			{
				minWeight=edgevec[i].m_iWeightValue;
				edgeIndex=i;
			}
		 }
    }
	return edgeIndex;
}


void CMap::kruskalTree() //��³˹�����㷨
{
	int value=0;//Ȩֵ
	int EdgeCount=0;//ȡ����С�������ߵĸ���
	//�����Žڵ㼯�ϵ�����
	vector<vector<int>>nodeSets;
	
	//��һ����ȡ�����б�
	vector<Edge>edgeVec;
	for (int i=0;i<m_iCapacity;i++)
	{
		for (int k=i+1;k<m_iCapacity;k++)
		{
			getValueFormMatrix(i,k,value);
			if (value!=0)
			{
				Edge edge(i,k,value);
				edgeVec.push_back(edge);
			}
		}
	}

	//�ڶ����������б���ȡ�������С�������ı�
	//A���ҵ��㷨��������
	while (EdgeCount<m_iCapacity-1)
	{
		//B���ӱ߼������ҵ���С��
		int minEdgeIndex=getMinEdge(edgeVec);
		edgeVec[minEdgeIndex].m_bSelected=true;

		int nodeAInSetLabel=-1;
		int nodeBInSetLabel=-1;

		//C���ҳ���С�����ӵĵ�
		int nodeAIndex=edgeVec[minEdgeIndex].m_iNodeIndexA;
		int nodeBIndex=edgeVec[minEdgeIndex].m_iNodeIndexB;

		bool nodeAIsInSet=false;
		bool nodeBIsInSet=false;

		//D���ҳ������ڵļ���
		for (int i=0;i<(int)nodeSets.size();i++)
		{
			nodeAIsInSet=isInSet(nodeSets[i],nodeAIndex);
			if (nodeAIsInSet)
			{
				nodeAInSetLabel=i;
			}
		}
		for (int i=0;i<(int)nodeSets.size();i++)
		{
			nodeBIsInSet=isInSet(nodeSets[i],nodeBIndex);
			if (nodeBIsInSet)
			{
				nodeBInSetLabel=i;
			}
		}
		//E:���ݵ����ڵļ��ϵĲ�ͬ������ͬ�Ĵ���
		if (nodeAInSetLabel==-1&&nodeBInSetLabel==-1)
		{
			vector<int>vec;
			vec.push_back(nodeAIndex);
			vec.push_back (nodeBIndex);
			nodeSets.push_back(vec);

		}
		else if(nodeAInSetLabel==-1&&nodeBInSetLabel!=-1)
		{
			nodeSets[nodeBInSetLabel].push_back(nodeAIndex);
		}
		else if(nodeBInSetLabel==-1&&nodeAInSetLabel!=-1)
		{
			nodeSets[nodeAInSetLabel].push_back(nodeBIndex);
		}
		else if (nodeAInSetLabel!=-1&&nodeBInSetLabel!=-1&&nodeAInSetLabel!=nodeBInSetLabel)
		{
			mergeNodeSet(nodeSets[nodeAInSetLabel],nodeSets[nodeBInSetLabel]);
			for (int k=nodeBInSetLabel;k<(int)nodeSets.size()-1;k++)
			{
				nodeSets[k]=nodeSets[k+1];
			}
		}

		else if (nodeAInSetLabel!=-1&&nodeBInSetLabel!=-1&&nodeAInSetLabel==nodeBInSetLabel)
		{
			continue;
		}

	m_pEdge[EdgeCount]=edgeVec[minEdgeIndex];
	EdgeCount++;
	cout<<edgeVec[minEdgeIndex].m_iNodeIndexA<<"  "<<edgeVec[minEdgeIndex].m_iNodeIndexB<<"  "<<edgeVec[minEdgeIndex].m_iWeightValue<<endl;
	}
}

bool CMap::isInSet(vector<int>nodeSet,int target)//�ж϶����Ƿ��ڵ㼯����
{
	for (int i=0;i<(int)nodeSet.size();i++)
	{
		if (nodeSet[i]==target)
		{
			return true;
		}
	}
	return false;
}
void CMap::mergeNodeSet(vector<int>nodeSetA,vector<int>nodeSetB)
{
	for (int i=0;i<(int)nodeSetB.size();i++)
	{
		nodeSetA.push_back(nodeSetB[i]);
	}
}