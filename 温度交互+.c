#include <stdio.h>


int main(){
    float fahr,celsiu;
    celsiu=0;
    while ( printf("(输入其他字符或0查看公式并结束代码)\n请输入要转换的摄氏度:"),(scanf("%f",&celsiu)) != EOF) {

        fahr =celsiu/(5.0/9.0)+32.0;   
        printf("转换的华氏度数为：%.2f\n",fahr);
        if (celsiu==0)
        {   
            printf("华氏度=摄氏度*5/9+32\n",fahr);
            break;
        };
        
    }
return 0;
}
