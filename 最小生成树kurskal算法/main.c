#include"MGraph.h"
#include"DirectedEdge.h"                   //有向图
#include"UnDirectedEdge.h"              //无向图
#include"kurskal.h"                               //kurskal algorthim

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //初始化

          /*顶点列表批量添加*/
          VertexType arr[] = { "ABCDE" };
          CreateBatchVertex(&Graph, arr, GRAPHWITHVALUE);      //顶点列表批量添加

          VertexType arr1[] = "AEACCE";
          VertexType arr2[] = "BACBDC";

          int Distance[] = { 3,4,1,2 ,5,6 };


          for (int i = 0; i < (int)strlen(arr1); ++i)
          {
                    InsertUnDirectEdgeValue(&Graph, *(arr1 + i), *(arr2 + i), Distance[i]);
          }

          DisplayGraph(Graph);          //图的输出

          Kurskal(Graph);
          DestroyGraph(&Graph);         //图的销毁
          return 0;
}