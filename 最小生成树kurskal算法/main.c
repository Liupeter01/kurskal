#include"MGraph.h"
#include"DirectedEdge.h"                   //有向图
#include"UnDirectedEdge.h"              //无向图
#include"kurskal.h"                               //kurskal algorthim

int main()
{
          MGraph Graph;
          InitGraph(&Graph);         //初始化

          /*顶点列表批量添加*/
          VertexType arr[] = { "ABCDEFG" };
          CreateBatchVertex(&Graph, arr, GRAPHWITHVALUE);      //顶点列表批量添加

          VertexType arr1[] = "AAAFFBFGFCDD";
          VertexType arr2[] = "BFGBGCCEEECE";

          int Distance[] = { 12,16,14,7,9,10,6,8,2,5,3,4 };


          for (int i = 0; i < (int)strlen(arr1); ++i)
          {
                    InsertUnDirectEdgeValue(&Graph, *(arr1 + i), *(arr2 + i), Distance[i]);
          }

          Kurskal(Graph, 'A');

          DisplayGraph(Graph);          //图的输出
          DestroyGraph(&Graph);         //图的销毁
          return 0;
}