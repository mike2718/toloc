// 将度分秒格式的经纬度转换为梅登黑德网格定位系统位置字符串的C程序
// 将《业余无线电通信》（第五版）第34页的BASIC程序翻译为C程序，使其能够在现代Linux上运行。
// 使用方法：
// $ pcc -Wall -Wpedantic -Wextra -Werror -Wcast-qual -O0 -std=c11 -o dmstoloc dmstoloc.c && ./dmstoloc

#include <stdio.h>
#include <stdlib.h>

int main() {
    double a, b, c, d, e, f, x, y;
    unsigned char loc[] = "000000";
    /* 输入经度数据 */
    system("clear");
    printf("\n将度分秒格式的经纬度转换为梅登黑德网格定位系统位置字符串的C程序\n");
    printf("===============================================================\n\n");
    printf("请依次输入所求地点经度的度、分、秒，中间用逗号隔开，\n");
    printf("东经为正、西经为负。\n");
    printf("（例：108.73,19.32,58.19、108,19,58）：");
    while (scanf("%lf,%lf,%lf", &a, &b, &c) != EOF && c != 200.0) {
        x = a + b / 60.0 + c / 3600.0 + 1.0 / 1000000.0;
        if ((x < -180) || (x > 180)) {
            system("clear");
            printf("输入错误，请重新输入…!\n");
            printf("\n请依次输入所求地点经度的度、分、秒，中间用逗号隔开，\n");
            printf("东经为正、西经为负。\n");
            printf("（例：108.73,19.32,58.19、108,19,58）：");
        } else
            break;
    }
    /* 输入纬度数据 */
    printf("\n请依次输入所求地点纬度的度、分、秒，中间用逗号隔开，\n");
    printf("北纬为正，南纬为负（例：-40,-41,-21）：");
    while (scanf("%lf,%lf,%lf", &d, &e, &f) != EOF && f != 200.0) {
        y = d + e / 60.0 + f / 3600.0 + 1.0 / 1000000.0;
        if ((y < -90) || (y > 90)) {
            system("clear");
            printf("输入错误，请重新输入…!\n");
            printf("\n请依次输入所求地点纬度的度、分、秒，中间用逗号隔开，\n");
            printf("北纬为正、南纬为负（例：-40,-41,-21）：");
        } else
            break;
    }
    if (c != 200 && f != 200) {
        a = x / 20 + 9; b = (int)a;
        loc[0] = b + 65; c = y / 10 + 9; d = (int)c;
        loc[1] = d + 65; a = (a - b) * 10; b = (int)a;
        loc[2] = b + 48; c = (c - d) * 10; d = (int)c;
        loc[3] = d + 48;
        b = (int)((a - b) * 24); loc[4] = b + 65;
        d = (int)((c - d) * 24); loc[5] = d + 65;
        /* 输出结果 */
        printf("\n");
        printf("******************************\n");
        printf("您所求地点的网格位置是：%s\n", loc);
        printf("******************************\n");
    }
    return 0;
}
