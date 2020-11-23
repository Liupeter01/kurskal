#pragma once
#include"MGraph.h"

void UnionInitial(MGraph G,int** UnionArray);			//并查集的初始化
void Union(int* S, int Root1, int Root2);    //集合的合并集合Root2要被合并到集合Root1中
int FindItem(int* S, int x);  //查找当前该值位于哪一个树，S为并查集，x为被查找元素