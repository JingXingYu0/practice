// V=0.10
#include <stdio.h>
int main()
{
    int choice = 0;
    float fahr, celsiu, kelvins;
    celsiu = 0;
    printf("(开尔文=1;华氏度=2;)\n请选择要从摄氏度转换的温度:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        while (choice == 1, printf("(输入其他字符或0查看公式并结束代码)\n目前要转换温度为开尔文\n请输入要转换的摄氏度:"), (scanf("%f", &celsiu)) != EOF)
        {

            kelvins = celsiu + 273.15;
            printf("转换的开尔文数为：%.2f°F\n", kelvins);
            if (celsiu == 0)
            {
                printf("公式为:开尔文(°K)=摄氏度(°C)*5/9+32\n", kelvins);
                break;
            };
        }
        break;
    case 2:
    while (printf("(输入其他字符或0查看公式并结束代码)\n目前要转换的温度为华氏度\n请输入要转换的摄氏度:"), choice == 2, (scanf("%f", &celsiu)) != EOF)
    {

        fahr = celsiu / (5.0 / 9.0) + 32.0;
        printf("转换的华氏度数为：%.2f°F\n", fahr);
        if (celsiu == 0)
        {
            printf("公式为:华氏度(°F)=摄氏度(°C)*5/9+32\n", fahr);
            break;
        };
    }
    break;
    default:
        break;
    }
    return 0;
}
