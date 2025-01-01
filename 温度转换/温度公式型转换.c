//已经彻底放弃的内容，玩法过于邪门
#include <stdio.h>
#include <math.h>
double pow_if(int x, int y);
double division_if(int x, int y);
double negative_if(int x, int y);
double a_if(int x, int y,double z);

int main()
{
    double temperature = 0;
    int choice_1 = 0;
    int choice_2;
    double temperature_output=0;
    while (printf("(结束代码=0;开尔文=1;摄氏度=2;华氏度=3;)\n请选择要从被转换的温度单位:"), scanf("%d", &choice_1),getchar()!='\n',0<choice_1&&choice_1 <=4)
    {
        //printf("请输入要转换的摄氏度:");
        //scanf("%f", &temperature);getchar()!='\n';
        printf("（开尔文=1;摄氏度=2;华氏度=3;)\n请选择要从需要转换的温度单位:");
        scanf("%d", &choice_2);getchar()!='\n';
        temperature_output =  a_if(choice_1, choice_2, temperature) ; 
        printf("转换温度为%f\n",temperature_output);
    };
    return 0;
}
double a_if(int x, int y,double z)
{
    double i= 0;
    i=z-(273.15*pow_if(x,y)*negative_if( y,  x))*sqrt(9/5)*(pow(1,(1*negative_if( x,  y)*division_if( x,  y)+1) )); 
    return i;
}
double pow_if(int x, int y)
{
    double i = 0;
    i = pow(0, fabs((x - 1) * (x - 4) + (y - 2) * (y - 3)));
    printf("pow_if=%f\n",i);
    return i;
}
double division_if(int x, int y)
{
    double i = 0;
    i = (x - y) / fabs(x - y);
    printf("division_if=%f\n",i);
    return i;
}
double negative_if(int x, int y)
{
    double i = 0;
    i = pow(-1, pow(0, (((x - 2) * (x - 3) * (x - 4) + (y - 4) * (y - 2) * (y - 3)))));
    printf("negative_if=%f\n",i);

    return i;
}
