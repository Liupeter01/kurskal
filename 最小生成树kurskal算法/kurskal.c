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
							  if (G.Edge[i][j]!=0 && G.Edge[i][j] != -1)
							  {
										(*arr)[counter].EdgeValue = G.Edge[i][j];		  //��ȡ��ֵ
										(*arr)[counter].v1 = G.Vex[i];					   //��ȡ����1				
										(*arr)[counter++].v2 = G.Vex[j];				  //��ȡ����2
							  }
					}
		  }
		  QuickSort(0, G.arcnum - 1, *arr);		  //�����������
}

void DestroyKurskal(EDGE* arr, int* UnionArray)				//Kurskal�㷨����
{
		  free(arr);
		  free(UnionArray);
}

void Kurskal(MGraph G)			  //Kurskal�㷨���岿��
{
		  EDGE* arr = NULL;
		  int* UnionArray = NULL;
		  InitKurskal(G, &arr, &UnionArray);				//��ʼ�����飬���鼯
		  int v1_pos = -1, v2_pos = -1;						//�������������±�

		  for (int i = 0; i < G.arcnum; ++i)				//��ͷ��ʼ�����߼�����
		  {
					v1_pos = LocateVertex(G, arr[i].v1);			  //ʹ��v1������
					if (UnionArray[LocateVertex(G, arr[i].v2)] != -1)			  //v2���Ǹ��ڵ�
					{
							 v2_pos = FindItem(UnionArray, LocateVertex(G, arr[i].v2)); //Ѱ�Ҷ���2�ĸ��ڵ�
					}
					else
					{
							  v2_pos = LocateVertex(G, arr[i].v2);
					}
					if (v1_pos != -1 || v2_pos != -1)
					{
							  int v1_root = FindItem(UnionArray, v1_pos);		  //Ѱ�Ҷ���1�ĸ��ڵ�
							  int v2_root = FindItem(UnionArray, v2_pos);		  //Ѱ�Ҷ���2�ĸ��ڵ�
							  if (v1_root != v2_root)//����1�Ͷ���2������λ��ͬһ����ͨ��ͼ֮��
							  {
										Union(UnionArray, v1_pos, v2_pos);	  //���Լ������в��鼯�Ĳ���
										printf("%c<--->%c    Distance = %d\n",
												  arr[i].v1, arr[i].v2, arr[i].EdgeValue);
							  }
					}
		  }
		  DestroyKurskal(arr, UnionArray);
}