#include"Union.h"

void UnionInitial(MGraph G, int** UnionArray)	//并查集的初始化
{
          *UnionArray = (int*)calloc(G.vexnum, sizeof(int));
          assert(*UnionArray != NULL);
          for (int i = 0; i < G.vexnum; ++i)
          {
                    (*UnionArray)[i] = -1;		  //初始化并查集数组
          }
}

void Union(int* S, int Root1, int Root2)   //集合的合并集合Root2要被合并到集合Root1中
{
          S[Root2] = Root1;   //修改Root2的双亲结点为Root1即可
}

int FindItem(int* S, int x)  //查找当前该值位于哪一个树(查找根节点)
{
          while (S[x] >= 0 )   //循环以访问到根节点为结束
          {
                    x = S[x];           //访问双亲结点
          }
          return x;
}