#pragma once
#include"MGraph.h"

typedef struct EDGE
{
		  VertexType v1;				//����1
		  VertexType v2;				//����2
		  unsigned int EdgeValue;				//�ߵ�Ȩ
}EDGE;

void SwapEdge(EDGE* edge_1, EDGE* edge_2);				  //��������
void QuickSort(int left, int right, EDGE* edge);	  //��������