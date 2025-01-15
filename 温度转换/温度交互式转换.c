// V=0.6
#include <stdio.h>
#include <stdlib.h>

int User_choose(char content[], int min, int max);
float munging(int type, float temperature);
void parameter(char Converted_Unit, float Converted_Parameters, char Convert_Units);

int main(int argc, char **argv)
{
    float temperature = 0;
    int choice_1 = 0;
    int choice_2 = 0;
    //printf("程序名称: %s\n参数数量%d\n", argv[0], argc);
    if (argc >= 4)
    {
        temperature = strtof(argv[2], NULL);
        parameter(argv[1][1], temperature, argv[3][1]);
    }
    else
    {
        while (argc == 1)
        {
            choice_1 = User_choose("(结束代码=0;开尔文=1;摄氏度=2;华氏度=3;)\n请选择要从被转换的温度单位:", 0, 3);
            if (choice_1 == 0)
            {
                return 0;
            }
            choice_2 = User_choose("（开尔文=1;摄氏度=2;华氏度=3;)\n请选择要从需要转换的温度单位:", 1, 3) + 3;
            printf("请输入要转换的温度数值:");
            scanf("%f", &temperature), getchar() != '\n';
            munging(choice_2, munging(choice_1, temperature));
        };
    }
}

void parameter(char Converted_Unit, float Converted_Parameters, char Convert_Units)
{
    float i = Converted_Parameters;
    float j;
    switch (Converted_Unit)
    {
    case 'K':
        j = munging(1, i);
        break;
    case 'C':
        j = munging(2, i);
        break;
    case 'F':
        j = munging(3, i);
        break;
    default:
        printf("数据错误\n");
        break;
    }
    switch (Convert_Units)
    {
    case 'K':
        j = munging(1+3, j);
        break;
    case 'C':
        j = munging(2+3, j);
        break;
    case 'F':
        j = munging(3+3, j);
        break;
    default:
        printf("数据错误\n");
        break;
    }
}

float munging(int type, float temperature)
{
    float i;
    switch (type)
    {
    case 1: // 开尔文转开尔文
        return temperature;
    case 2: // 开尔文转摄氏度
        i = temperature + 273.15;
        return i;
    case 3: // 开尔文转华氏度
        i = (temperature + 459.67) * 5 / 9;
        return i;
    case 4: // 开尔文转开尔文
        printf("转换的开尔文数为:%.2f°K\n", temperature);
        return temperature;
    case 5: // 开尔文转摄氏度
        i = temperature - 273.15;
        printf("转换的摄氏度数为:%.2f°C\n", i);
        return i;
    case 6: // 开尔文转华氏度
        i = temperature * 9 / 5 - 459.67;
        printf("转换的华氏度数为:%.2f°F\n", i);
        return i;
    default:
        printf("数据错误\n");
        return -1;
    }
}

int User_choose(char content[], int min, int max)
{
    int parameter;
    while (printf("%s\n", content), scanf("%d", &parameter), getchar() != '\n', min > parameter || parameter > max)
    {
        printf("输入类型错误！\n请重新输入!\n");
    }
    return parameter;
}