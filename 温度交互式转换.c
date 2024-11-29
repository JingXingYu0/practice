// V=0.30
#include <stdio.h>
float TemperatureEnter(float temperature1);
int main()
{
    float temperature2 = 0;
    int choice = 0;
    while (printf("(结束代码=0;开尔文=1;华氏度=2;)\n请选择要从摄氏度转换的温度单位:"), scanf("%d", &choice))
    {
        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            temperature2 = TemperatureEnter(0) + 273.15; // 摄氏度转开尔文
            printf("公式为:开尔文(°K)=摄氏度(°C)*5/9+32\n转换的开尔文数为:%.2f°K\n", temperature2);
            break;
        case 2:
            temperature2 = TemperatureEnter(0) / (5.0 / 9.0) + 32.0; // 摄氏度转华氏度
            printf("公式为:华氏度(°F)=摄氏度(°C)*5/9+32\n转换的华氏度数为:%.2f°F\n", temperature2);
            break;
        }
    }
    return 0;
}
float TemperatureEnter(float temperature1)
{
    printf("请输入要转换的摄氏度:");
    scanf("%f", &temperature1);
    return temperature1;
}
