#include"kurskal.h"

/*��ʼ��Kurskal�㷨�����������Լ����鼯����*/
void InitKurskal(MGraph G, EDGE** arr, int** UnionArray)
{
		  UnionInitial(G, UnionArray);				//��ʼ�����鼯
		  *arr = (EDGE*)malloc(sizeof(EDGE) * G.arcnum);
		  assert(*arr != NULL);
		  int counter = 0;
		  for (int i = 0; i < G.vexnum; ++i)				//��Kurskal�߼��е����б���ӵ�����
		  {
					for (int j = i + 1; j < G.vexnum; ++j)
					{
							  if (G.Edge[i][j]!=0 && G.Edge[i][j] != -1 && G.Edge[i][j] != INFINITYSIZE)
							  {
										(*arr)[counter].EdgeValue = G.Edge[i][j];		  //��ȡ��ֵ
										(*arr)[counter].v1 = G.Vex[i];					   //��ȡ����1				
										(*arr)[counter++].v2 = G.Vex[j];				  //��ȡ����2
							  }
					}
		  }
}

void DestroyKurskal(EDGE* arr, int* UnionArray)				//Kurskal�㷨����
{
		  free(arr);
		  free(UnionArray);
}

void Kurskal(MGraph G, VertexType V)			  //Kurskal�㷨���岿��
{
		  EDGE* arr = NULL;
		  int* UnionArray = NULL;
		  InitKurskal(G, &arr, &UnionArray);				//��ʼ�����飬���鼯

		  QuickSort(0, G.arcnum - 1, arr);		  //�����������
		  int v1_pos = 0, v2_pos = 0;						//�������������±�
		  for (int i = 0; i < G.arcnum; ++i)				//��ͷ��ʼ�����߼�����
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

					int v1_root = FindItem(UnionArray, v1_pos);		  //Ѱ�Ҷ���1�ĸ��ڵ�
					int v2_root = FindItem(UnionArray, v2_pos);		  //Ѱ�Ҷ���2�ĸ��ڵ�
					if (v1_root != v2_root)//����1�Ͷ���2�������γɻ�·
					{
							  Union(UnionArray, v1_pos, v2_pos);	  //���Լ������в��鼯�Ĳ���
					}
		  }
		  DestroyKurskal(arr, UnionArray);
}