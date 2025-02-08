// V=1.1
#include <stdio.h>
#include <stdlib.h>

// compute函数用于处理温度转换
float compute(char content[], float temperature_0, float temperature_1, int bool)
{
   float i;
   if (bool == 0)
   {
      i = temperature_0;
      return temperature_0;
   }
   else
   {
      printf("转换的%s数为:%.2f°K\n", content, temperature_1);
      return temperature_1;
   }
}

// munging函数是主要的核心运算代码，根据输入类型进行温度转换
float munging(char type, float temperature, int bool)
{
   float i;
   switch (type)
   {
   case '1': // 开尔文转开尔文
   case 'K': // 开尔文转开尔文
   case 'k':
      i = compute("开尔文", temperature, temperature, bool);
      return i;
   case '2': // 开尔文转摄氏度
   case 'C': // 开尔文转摄氏度
   case 'c':
      i = compute("摄氏度", temperature + 273.15, temperature - 273.15, bool);
      return i;
   case '3': // 开尔文转华氏度
   case 'F': // 开尔文转华氏度
   case 'f':
      i = compute("华氏度", (temperature + 459.67) * 5 / 9, temperature * 9 / 5 - 459.67, bool);
      return i;
   default:
      printf("数据错误\n");
      return -1;
   }
}

// User_choose函数作为用户输入字符串的简单集成
char User_choose(char content[])
{
   char parameter;
   printf("%s\n", content);
   scanf("%s", &parameter);
   getchar() != '\n';
   return parameter;
}

int main(int argc, char **argv)
{
   float temperature = 0;
   char choice_1 = '0';
   char choice_2 = '0';

   // 如果参数符合特定条件，执行参数运行代码，否则进入交互式界面
   if (argc >= 4 && argv[1][0] == '-' && argv[3][0] == '-')
   {
      temperature = strtof(argv[2], NULL);
      munging(argv[3][1], munging(argv[1][1], temperature, 0), 1);
   }
   else
   {
      // 如果没有参数，进入交互式界面
      while (argc == 1)
      {
         char choice_1 = '0';
         char choice_2 = '0';
         choice_1 = User_choose("(0.结束代码;1.开尔文;2.摄氏度;3.华氏度;)\n请输入要从被转换的温度单位:");
         if (choice_1 == '0')
         {
            return 0;
         }
         choice_2 = User_choose("（开尔文=1;摄氏度=2;华氏度=3;)\n请输入要从需要转换的温度单位:");
         printf("请输入要转换的温度数值:");
         scanf("%f", &temperature);
         getchar() != '\n';
         munging(choice_2, munging(choice_1, temperature, 0), 1);
      }
   }
   return 0;
}