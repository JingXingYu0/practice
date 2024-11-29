// V=0.20
#include <stdio.h>
float munging(float temperature1, float temperature2,int choice);
int main()
{
    float temperature1;
    float temperature2;
    int choice;
    printf("(开尔文=1;华氏度=2;)\n请选择要从摄氏度转换的温度:");
    scanf("%d", &choice);
    printf("请输入要转换的摄氏度:");
    scanf("%f", &temperature1);
    printf("转换的开尔文数为：%.2f°F\n",  munging( temperature1,  temperature2, choice));
    return 0;
}
float munging(float temperature1, float temperature2,int choice)
{
        
switch (choice)
    {
    case 1:
    printf("公式为:开尔文(°K)=摄氏度(°C)*5/9+32\n");
     temperature2 = temperature1 + 273.15;//摄氏度转开尔文
    break;
    case 2:
    printf("公式为:华氏度(°F)=摄氏度(°C)*5/9+32\n");
    temperature2 = temperature1 / (5.0 / 9.0) + 32.0;//摄氏度转华氏度
    break;
}
return temperature2;
}
//\n目前要转换温度为开尔文,之后需要实现的内容
//(输入其他字符或0查看公式并结束代码)\n，循环使用之后后需要实现的内容