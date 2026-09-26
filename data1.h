
#pragma once
#define MAX_LEN 80/* 定义水文监测站的最大长度 */
#define SHUI_NUM 40		/* 定义水文监测站的最多数 */
typedef struct shuiwenjiancezhan {
    int stationCode;
    char stationName[MAX_LEN];
    float highestWaterLevel;
    float lowestWaterLevel;
    float dailyRainfall;
    char recordDate[20];
    char responsiblePerson[50];
    char phoneNumber[11];
}Shui;