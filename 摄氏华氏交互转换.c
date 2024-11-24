#include <stdio.h>

int main()
{
   float fahr,celsiu;
   printf("请输入要转换的摄氏度:");
   scanf("%f",&celsiu);
   fahr =celsiu/(5.0/9.0)+32.0;
   printf("转换的华氏度数为：%.2f\n",fahr);
}
