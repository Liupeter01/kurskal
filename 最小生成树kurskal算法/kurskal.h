#pragma once
#include"QuickSort.h"					//排序
#include"Union.h"						    //并查集

/*初始化Kurskal算法，包括数组以及并查集数组*/
void InitKurskal(MGraph G, EDGE** arr, int** UnionArray);

/*
*Kurskal算法主体部分
*包含排序数组以及并查集
*/
void Kurskal(MGraph G, EDGE* arr, int* UnionArray);

/*Kurskal算法销毁*/
void DestroyKurskal(EDGE* arr, int* UnionArray);