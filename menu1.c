# define _CRT_SECURE_NO_WARNINGS 1
#pragma warning（disable:6031)
#include<stdio.h>
/*显示主菜单*/
int MainMenu(void)
{
    int sel;
    printf("*************************************\n");
    printf("*   某地区简易水文监测数据管理系统  *\n");
    printf("*作者:zzdd47189 学号:2422040513      *\n");
    printf("*e-mail: ......           *\n");    
    printf("*************************************\n");
    printf("*************************************\n");
    printf("*      主 菜 单        *\n");
    printf("*     1. 输 入         *\n");
    printf("*     2. 修 改         *\n");
    printf("*     3. 查 询         *\n");
    printf("*     4. 排 列         *\n");
    printf("*     5. 统 计         *\n");
    printf("*     6. 输 出         *\n");
    printf("*     0. 退 出         *\n");
    printf("*************************************\n");
    printf("请输入功能选项: ");
    scanf("%d", &sel);
    return sel;
}

/*显示子菜单1*/
int SubMenu1(void)
{
    int sel;
    printf("*************************************\n");
    printf("*     输 入 子 菜 单      *\n");
    printf("*     1. 从键盘录入       *\n");
    printf("*     2. 从文件导入       *\n");
    printf("*************************************\n");
    printf("请输入功能选项: ");
    scanf("%d", &sel);
    return sel;
}

/*显示子菜单2*/
int SubMenu2(void)
{
    int sel;
    printf("**************************************\n");
    printf("*     修 改 子 菜 单    *\n");
    printf("*      1. 添 加         *\n");
    printf("*      2. 删 除         *\n");
    printf("*      3. 修 改         *\n");
    printf("**************************************\n");
    printf("请输入功能选项: ");
    scanf("%d", &sel);
    return sel;
}

/*显示子菜单3*/
int SubMenu3(void)
{
    int sel;
    printf("*************************************\n");
    printf("*       查 询 子 菜 单            *\n");
    printf("*       1. 按水文监测站编码查询   *\n");
    printf("*       2. 按水文监测站名称查询   *\n");
    printf("*************************************\n");
    printf("请输入功能选项: ");
    scanf("%d", &sel);
    return sel;
}

/*显示子菜单4*/
int SubMenu4(void)
{
    int sel;
    printf("********************************************************\n");
    printf("*           排 列 子 菜 单           *\n");
    printf("*       1. 按当日降雨量降序排列      *\n");
    printf("*       2. 按当日降雨量升序排列      *\n");
    printf("*       3. 按水文监测最高值排列      *\n");
    printf("********************************************************\n");
    printf("请输入功能选项: ");
    scanf("%d", &sel);
    return sel;
}

/*显示子菜单5*/
int SubMenu5(void)
{
    int sel;
    printf("*************************************************\n");
    printf("*            统 计 子 菜 单           *\n");
    printf("*     1. 计算各水文监测站降雨总量     *\n");
    printf("*     2. 计算各水文监测站降雨占比     *\n");
    printf("*************************************************\n");
    printf("请输入功能选项: ");
    scanf("%d", &sel);
    return sel;
}


/*显示子菜单6*/
int SubMenu6(void)
{
    int sel;
    printf("*************************************\n");
    printf("*     输 出 子 菜 单      *\n");
    printf("*     1. 输出到屏幕       *\n");
    printf("*     2. 输出到文件       *\n");
    printf("*************************************\n");
    printf("请输入功能选项: ");
    scanf("%d", &sel);
    return sel;
}