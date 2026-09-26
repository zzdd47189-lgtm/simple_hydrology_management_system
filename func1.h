#pragma once
#include "data1.h"
int Ascending(float, float);   /*使数据按升序排序*/
int Descending(float, float);   /*使数据按降序排序*/
void ReadShui(Shui shui[], int n);  /*从键盘输入n个水文监测站的信息*/
int ReadfromFile(Shui shui[]);    /*从文件中读取水文监测站信息*/
int appendShui(Shui shui[], int n);   /*添加水文监测站*/
int deleteShui(Shui shui[], int n);   /*删除水文监测站*/
void modify(Shui shui[], int n);    /*修改水文监测站信息*/
void SumofEveryShui(Shui shui[],int n);  /*计算各水文监测站降雨的总量*/
void percent(Shui shui[], int n);     /*计算各水文监测站降雨的占比*/
void SortbyMax(Shui shui[], int n, int (*compare)(float a, float b)); /*按水文监测最高值排序*/
void SearchbyNum(Shui shui[], int n);     /*按水文监测站编号查找并显示查找结果*/
void SearchbyName(Shui shui[], int n);                   /*按水文监测站名称查找并显示查找结果*/
void PrintShui(Shui stu[], int n);                    /*在屏幕上显示所有水文监测站的信息*/
void WritetoFile(Shui stu[], int n);                   /*输出所有水文监测站的信息到文件D:\shuiwenjiancezhan.txt中*/
void SortbyRainfall(Shui shui[], int n, int (*compare)(float a, float b));/*按降雨量排序*/
