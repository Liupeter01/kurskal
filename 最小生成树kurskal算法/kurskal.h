#pragma once
#include"QuickSort.h"					//排序
#include"Union.h"						    //并查集

void InitKurskal(MGraph G, EDGE** arr, int** UnionArray);	//初始化Kurskal算法，包括数组以及并查集数组
void DestroyKurskal(EDGE* arr, int* UnionArray);			//Kurskal算法销毁
void Kurskal(MGraph G);			  //Kurskal算法主体部分