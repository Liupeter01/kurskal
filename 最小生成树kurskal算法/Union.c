#include"Union.h"

void UnionInitial(MGraph G, int** UnionArray)	//���鼯�ĳ�ʼ��
{
          *UnionArray = (int*)calloc(G.vexnum, sizeof(int));
          assert(*UnionArray != NULL);
          for (int i = 0; i < G.vexnum; ++i)
          {
                    (*UnionArray)[i] = -1;		  //��ʼ�����鼯����
          }
}

void Union(int* S, int Root1, int Root2)   //���ϵĺϲ�����Root2Ҫ���ϲ�������Root1��
{
          S[Root2] = Root1;   //�޸�Root2��˫�׽��ΪRoot1����
}

int FindItem(int* S, int x)  //���ҵ�ǰ��ֵλ����һ����(���Ҹ��ڵ�)
{
          while (S[x] >= 0 )   //ѭ���Է��ʵ����ڵ�Ϊ����
          {
                    x = S[x];           //����˫�׽��
          }
          return x;
}