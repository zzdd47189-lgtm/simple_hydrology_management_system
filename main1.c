# define _CRT_SECURE_NO_WARNINGS 1
#include "menu1.h"
#include "func1.h"
#include <stdio.h>
#include <stdlib.h>
#include "data1.h"

/*主函数*/
int main() {
	int ch, sch;
	int n, i;
	Shui shuiRecord[SHUI_NUM];
	while (1) {
		ch = MainMenu();                   /*显示主菜单*/
		switch (ch) {
		case 1:
			sch = SubMenu1();             /*显示子菜单1*/
			if (sch == 1) {
				printf("请输入水文监测站数n(n<%d):", SHUI_NUM);
				scanf("%d", &n);
				ReadShui(shuiRecord, n);      /*键盘读入水文监测站*/
			}
			else if (sch == 2)
				n = ReadfromFile(shuiRecord);/*从文件读入水文监测站*/
			break;
		case 2:
			sch = SubMenu2();            /*显示子菜单2*/
			if (sch == 1)
				n = appendShui(shuiRecord, n);    /*添加水文监测站*/
			else if (sch == 2)
				n = deleteShui(shuiRecord, n);/*删除水文监测站*/
			else if (sch == 3)
				modify(shuiRecord, n);  /*修改水文监测站信息*/
			break;
		case 3:
			sch = SubMenu3();            /*显示子菜单5*/
			if (sch == 1)              /*按编号查找水文监测站*/
				SearchbyNum(shuiRecord, n);
			else if (sch == 2)          /*按名称查找水文监测站*/
				SearchbyName(shuiRecord, n);
			break;
		case 4:
			sch = SubMenu4();             /*显示子菜单4*/
			if (sch == 1) {             /*按日降雨量降序排序*/
				SortbyRainfall(shuiRecord, n, Descending);
				printf("\n按日降雨量从高到低排序:\n");
				PrintShui(shuiRecord, n);
			}
			else if (sch == 2) {       /*按日降雨量升序排序*/
				SortbyRainfall(shuiRecord, n, Ascending);
				printf("\n按日降雨量从低到高排序:\n");
				PrintShui(shuiRecord, n);
			}
			else if (sch == 3) {     /*按水文监测最高值排序*/
				SortbyMax(shuiRecord, n, Descending);
				printf("\n按水文监测最高值降序进行排序:\n");
				PrintShui(shuiRecord, n);
			}
			break;
		case 5:
			sch = SubMenu5();
			if (sch == 1)
			{
				SumofEveryShui(shuiRecord, n);
			}
			else if (sch == 2)
			{
				percent(shuiRecord, n);
			}
			break;
		case 6:
			sch = SubMenu6();           /*显示子菜单6*/
			if (sch == 1)             /*在屏幕上显示水文监测站信息*/
				PrintShui(shuiRecord, n);
			else if (sch == 2)          /*将水文监测站信息写入文件*/
				WritetoFile(shuiRecord, n);
			break;

		case 0:
			printf("程序运行结束!\n");      /*程序结束运行*/
			exit(0);
		default:
			printf("输入错误!\n");        /*输入错误，重新输入*/
			break;

		}
	}
		return 0;
	
}