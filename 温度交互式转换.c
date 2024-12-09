// V=0.45
#include <stdio.h>
float munging_1(int type_1, float temperature_1);
float munging_2(int type_2, float temperature_2);
int main()
{
    float temperature1 = 0;
    int choice = 0;
    while (printf("(结束代码=0;开尔文=1;摄氏度=2;华氏度=3;)\n请选择要从被转换的温度单位:"), scanf("%d", &choice), getchar() != '\n', 0 < choice && choice <= 3)
    {
        printf("请输入要转换的摄氏度:");
        scanf("%f", &temperature1);
        getchar() != '\n';
        temperature1 = munging_1(choice, temperature1);
        printf("（开尔文=1;摄氏度=2;华氏度=3;)\n请选择要从需要转换的温度单位:");
        scanf("%d", &choice);
        getchar() != '\n';
        munging_2(choice, temperature1);
    };
    return 0;
}

float munging_1(int type_1, float temperature_1)
{
    float i;
    switch (type_1)
    {
    case 1: // 开尔文转开尔文
        i = temperature_1;
        printf("开尔文转开尔文\n");
        break;

    case 2: // 开尔文转摄氏度
        i = temperature_1 + 273.15;
        printf("开尔文转摄氏度\n");
        break;
    case 3: // 开尔文转华氏度
        i = (temperature_1 + 459.67) * 5 / 9;
        printf("开尔文转华氏度\n");
        break;
    default:
        printf("输入类型错误！\n");
        return -1;
        break;
    }
    return i;
}
float munging_2(int type_2, float temperature_2)
{
    float i;
    while (0==0)
    {
        switch (type_2)
        {
        case 1: // 开尔文转开尔文
            i = temperature_2;
            printf("开尔文转开尔文\n");
            printf("转换的开尔文数为:%.2f°K\n", i);
            return i;
            break;
        case 2: // 开尔文转摄氏度
            i = temperature_2 - 273.15;
            printf("开尔文转摄氏度\n");
            printf("转换的摄氏度数为:%.2f°C\n", i);
            return i;
            break;
        case 3: // 开尔文转华氏度
            i = temperature_2 * 9 / 5 - 459.67;
            printf("开尔文转华氏度\n");
            printf("转换的华氏度数为:%.2f°F\n", i);
            return i;
            break;
        default:
            printf("输入类型错误！\n请重新输入!\n(开尔文=1;摄氏度=2;华氏度=3;)\n请选择要从需要转换的温度单位:");
            scanf("%d", &type_2);
            break;
        }
        
    }

}
