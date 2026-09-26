# define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "data1.h"

/*从键盘输入n个水文监测站的信息*/
void ReadShui(Shui shui[], int n) 
{
	int i;
	for (i = 0; i < n; i++) {
		printf("输入第 %d 个水文监测站的编码: ", i + 1);
		scanf("%d", &shui[i].stationCode);

		printf("输入第 %d 个水文监测站的名称: ", i + 1);
		scanf("%s", shui[i].stationName);

		printf("输入第 %d 个水文监测站的最高水位: ", i + 1);
		scanf("%f", &shui[i].highestWaterLevel);

		printf("输入第 %d 个水文监测站的最低水位: ", i + 1);
		scanf("%f", &shui[i].lowestWaterLevel);

		printf("输入第 %d 个水文监测站的日降雨量: ", i + 1);
		scanf("%f", &shui[i].dailyRainfall);

		printf("输入第 %d 个水文监测站的记录日期: ", i + 1);
		scanf("%s", shui[i].recordDate);

		printf("输入第 %d 个水文监测站的负责人: ", i + 1);
		scanf("%s", shui[i].responsiblePerson);

		printf("输入第 %d 个水文监测站的联系电话: ", i + 1);
		scanf("%s", shui[i].phoneNumber);
	}
}


/*从文件中读取水文监测站信息*/
int ReadfromFile(Shui shui[]) {
	FILE* fp;
	if ((fp = fopen("shuiwenjiancezhan.txt", "r")) == NULL) {
		printf("Failure to open shuiwenjiancezhan.txt!\n");
		exit(0);
	}
	int count = 0;
	while (fscanf(fp, "%d%s%f%f%f%s%s%s",
		&shui[count].stationCode,
		shui[count].stationName,
		&shui[count].highestWaterLevel,
		&shui[count].lowestWaterLevel,
		&shui[count].dailyRainfall,
		shui[count].recordDate,
		shui[count].responsiblePerson,
		shui[count].phoneNumber) != EOF) {
		count++;
	}

	fclose(fp);
	return count;             
}


/*添加水文监测站*/
int appendShui(Shui shui[], int n) {

	if (n >40) {
		printf("水文监测站已满，无法添加!\n");
		return n;
	}
	else {
		
		printf("请输入新水文监测站的编码: ");
		scanf("%d", &shui[n].stationCode);
		printf("请输入新水文监测站的名称: ");
		scanf("%s", shui[n].stationName);
		printf("请输入新水文监测站的最高水位: ");
		scanf("%f", &shui[n].highestWaterLevel);
		printf("请输入新水文监测站的最低水位: ");
		scanf("%f", &shui[n].lowestWaterLevel);
		printf("请输入新水文监测站的日降雨量: ");
		scanf("%f", &shui[n].dailyRainfall);
		printf("请输入新水文监测站的记录日期: ");
		scanf("%s", shui[n].recordDate);
		printf("请输入新水文监测站的负责人: ");
		scanf("%s", shui[n].responsiblePerson);
		printf("请输入新水文监测站的联系电话: ");
		scanf("%s", shui[n].phoneNumber);
		printf("水文监测站添加成功！\n");
		return n + 1;
	}
}

/*删除水文监测站*/
int deleteShui(Shui shui[], int n) {
	int i, k;
	int num;
	printf("请输入删除水文监测站的编号:");
	scanf("%d", &num);
	for (i = 0; i < n; i++)
		if (num == shui[i].stationCode)
			break;
	if (i < n) {
		for (k = i + 1; k < n; k++)
			shui[k - 1] = shui[k];
		printf("删除成功");
		return n - 1;
	}
	else
		printf("未找到该水文监测站！\n");
	return n;
}

/*修改水文监测站信息*/
void modify(Shui shui[], int n) {
	int i, j;
	long num;
	printf("请输入待修改水文监测站的编号:");
	scanf("%ld", &num);
	for (i = 0; i < n; i++)
		if (num == shui[i].stationCode)
			break;
	if (i < n) {
		printf("编号\t名称\t水位监测最高值\t水位监测最低值\t当日降雨量\t日期\t责任人\t手机号\n");
		printf("%d%s\t%.2f\t        %.2f\t        %.2f\t      %s\t %s\t%s\n", shui[i].stationCode, shui[i].stationName, shui[i].highestWaterLevel, shui[i].lowestWaterLevel, shui[i].dailyRainfall, shui[i].recordDate, shui[i].responsiblePerson, shui[i].phoneNumber);

		printf("\n请输入待修改水文院的编号\t名称\t水位监测最高值\t水位监测最低值\t当日降雨量\t日期\t责任人\t手机号\t:\n");
		scanf("%d%s%f%f%f%s%s%s", &shui[i].stationCode, shui[i].stationName, &shui[i].highestWaterLevel, &shui[i].lowestWaterLevel, &shui[i].dailyRainfall, shui[i].recordDate, shui[i].responsiblePerson, shui[i].phoneNumber);
		printf("修改成功");
	}
	else
		printf("未找到该水文监测站！\n");
}

/*计算各水文监测站降雨的总量*/
void SumofEveryShui(Shui shui[], int n) {
	int  j;
	float i=0;
	for (j = 0; j < n; j++) {
	
		i += shui[j].dailyRainfall;
	}
	
		printf("各水文监测站降雨的总量是%.2f\n", i);
	
		
		
	
}
/*计算各水文监测站降雨的占比*/
void percent(Shui shui[], int n) {
	int  j;
	float i = 0;
	for (j = 0; j < n; j++) {

		i += shui[j].dailyRainfall;
	}
	for (j = 0; j <n; j++)
	{
		printf("第%d个水文监测站占比为%.2f%%\n", j + 1, 100 * shui[j].dailyRainfall / i);

	}
}


/*按水文监测最高值排序*/
void SortbyMax(Shui shui[], int n, int (*compare)(float a, float b)) {
	int i, j, k;
	Shui temp1;
	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = i + 1; j < n; j++)
			if ((*compare)(shui[j].highestWaterLevel, shui[k].highestWaterLevel))
				k = j;
		if (k != i) {
			temp1 = shui[k];
			shui[k] = shui[i];
			shui[i] = temp1;
		}
	}
}

/*使数据按升序排序*/
int Ascending(float a, float b) {
	return a < b;
}

/*使数据按降序排序*/
int Descending(float a, float b) {
	return a > b;
}

/*按降雨量排序*/
void SortbyRainfall(Shui shui[], int n, int (*compare)(float a, float b)) {
	int i, j, k;
	Shui temp1;
	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = i + 1; j < n; j++)
			if ((*compare)(shui[j].dailyRainfall, shui[k].dailyRainfall))
				k = j;
		if (k != i) {
			temp1 = shui[k];
			shui[k] = shui[i];
			shui[i] = temp1;
		}
	}
}

/*按水文监测站编号查找并显示查找结果*/
void SearchbyNum(Shui shui[], int n) {
	long number;
	int i, j;
	printf("请输入待查找水文监测站的编号");
	scanf("%ld", &number);
	for (i = 0; i < n; i++) {
		if (shui[i].stationCode == number) {
			printf("编号\t名称\t水位监测最高值\t水位监测最低值\t当日降雨量\t日期\t责任人\t手机号\n");
			printf("%d%s\t%.2f\t        %.2f\t        %.2f\t      %s\t %s\t%s\n", shui[i].stationCode, shui[i].stationName, shui[i].highestWaterLevel, shui[i].lowestWaterLevel, shui[i].dailyRainfall, shui[i].recordDate, shui[i].responsiblePerson, shui[i].phoneNumber);
			return;
		}
	}
	printf("\n 未找到该水文监测站\n");
}

/*按水文监测站名称查找并显示查找结果*/
void SearchbyName(Shui shui[], int n) {
	char x[MAX_LEN];
	int i, j;
	printf("请输入待查找水文监测站的名称:");
	scanf("%s", x);
	for (i = 0; i < n; i++) {
		if (strcmp(shui[i].stationName, x) == 0) {
			printf("编号\t名称\t水位监测最高值\t水位监测最低值\t当日降雨量\t日期\t责任人\t手机号\n");
			printf("%d%s\t%.2f\t        %.2f\t        %.2f\t      %s\t %s\t%s\n", shui[i].stationCode, shui[i].stationName, shui[i].highestWaterLevel, shui[i].lowestWaterLevel, shui[i].dailyRainfall, shui[i].recordDate, shui[i].responsiblePerson, shui[i].phoneNumber);
			
			return;
		}
	}
	printf("\n未找到该水文监测站\n");
}


/*在屏幕上显示所有水文监测站的信息*/
void PrintShui(Shui shui[], int n)
{
	int i;
	printf("编号\t名称\t水位监测最高值\t水位监测最低值\t当日降雨量\t日期\t责任人\t手机号\n");
	for (i = 0; i < n; i++) {
		printf("%d%s\t%.2f\t        %.2f\t        %.2f\t      %s\t %s\t%s\n", shui[i].stationCode, shui[i].stationName, shui[i].highestWaterLevel, shui[i].lowestWaterLevel, shui[i].dailyRainfall, shui[i].recordDate, shui[i].responsiblePerson, shui[i].phoneNumber);
		
	}
}

/*输出所有水文监测站的信息到文件D:\shuiwenjiancezhan.txt中*/
void WritetoFile(Shui shui[], int n) {
	FILE* fp;
	int i, j;
	if ((fp = fopen("shuiwenjiancezhan2.txt", "w")) == NULL) {
		printf("Failure to open shuiwenjiancezhan.txt!\n");
		exit(0);
	}
	for (i = 0; i < n; i++) {
		fprintf(fp, "%d\t%s\t%.2f\t%.2f\t%.2f\t%s\t%s\t%s\n", shui[i].stationCode, shui[i].stationName, shui[i].highestWaterLevel, shui[i].lowestWaterLevel, shui[i].dailyRainfall, shui[i].recordDate, shui[i].responsiblePerson, shui[i].phoneNumber );
		
	}
	fclose(fp);
}
