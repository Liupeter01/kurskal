#include"kurskal.h"

/*��ʼ��Kurskal�㷨�����������Լ����鼯����*/
void InitKurskal(MGraph G, EDGE** arr, int** UnionArray)
{
		  int SizeCounter = EdgeCalculate(G);					  //���ڼ���ߵ�����
		  Initquicksort(arr, SizeCounter);		  //��ʼ������
		  UnionInitial(G, UnionArray);				//��ʼ�����鼯
}

/*
*Kurskal�㷨���岿��
*�������������Լ����鼯
*/
void Kurskal(MGraph G, EDGE* arr, int* UnionArray)
{
		  InitKurskal(G, &arr, &UnionArray);				//��ʼ�����飬���鼯
		  int counter = 0;
		  for (int i = 0; i < G.vexnum; ++i)				//��Kurskal�߼��е����б���ӵ�����
		  {
					for (int j = i + 1; j < G.vexnum; ++j)
					{
							  if (G.Edge[i][j] != -1)
							  {
										arr[counter].length = G.Edge[i][j];
										arr[counter].v1 = G.Vex[i];
										arr[counter++].v2 = G.Vex[j];
							  }
					}
		  }
		  int arraysize = EdgeCalculate(G);
		  QuickSort(0, arraysize, arr);						//���ݱߵĴ�С����������п����������еı�����������
		  int v1_pos = 0, v2_pos = 0;						//�������������±�
		  for (int i = 0; i < arraysize; ++i)				//��ͷ��ʼ�����߼�����
		  {
					/*
					*Ѱ��ÿһ�������������еľ���λ��
					*���ڵ�1��������ԣ�λ�����迼�ǣ�����λ��ĳһ�������л��߸����
					*���ڵ�2��������ԣ�λ����Ҫ����!!���Ҫ������2�ƶ�������1�ļ����У�����Ӹ��ڵ��ƶ�
					*/
					v1_pos = LocateVertex(G, arr[i].v1);			  //����1 v1_pos ����
					if (UnionArray[LocateVertex(G, arr[i].v2)] != -1)	//��ǰ�Ķ���2���ڸ��ڵ�
					{
							  v2_pos = FindItem(UnionArray, LocateVertex(G, arr[i].v2));	//��ȡ���ڵ�
					}
					else //��ǰ�Ķ���2�ڸ��ڵ�
					{
							  v2_pos = LocateVertex(G, arr[i].v2);//�Լ�������Ǹ��ڵ�
					}
					int res_v1 = FindItem(UnionArray, v1_pos);    //���ڶ���1�ĸ��ڵ�����ж�
					int res_v2 = FindItem(UnionArray, v2_pos);	    //���ڶ���2�ĸ��ڵ�����ж�
					if (res_v1 != res_v2)			  //����������ڵ㲻ͬ�������ǰ�ṹ���ǻ�
					{
							  Union(UnionArray, v1_pos, v2_pos);	  //���Լ������в��鼯�Ĳ���
					}
		  }
}

/*Kurskal�㷨����*/
void DestroyKurskal(EDGE* arr, int* UnionArray)
{
		  free(arr);
		  free(UnionArray);
}