// V=1.1
#include <stdio.h>
#include <stdlib.h>

float compute(char content[], float temperature_0, float temperature_1, int bool)//函数的输出与转换，虽然转换不在这里直接弄出来了
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

float munging(char type, float temperature, int bool) // 主要的核心运算代码，其中type是选项值。bool算是一个布尔是用来判断到那一步了
{
   float i;
   switch (type)
   {
   case '1':
   case 'K':
   case 'k': // 开尔文转开尔文
      i = compute("开尔文", temperature, temperature, bool);
      return i;
   case '2':
   case 'C':
   case 'c': // 开尔文转摄氏度
      i = compute("摄氏度", temperature + 273.15, temperature - 273.15, bool);
      return i;
   case '3':
   case 'F':
   case 'f': // 开尔文转华氏度
      i = compute("华氏度", (temperature + 459.67) * 5 / 9, temperature * 9 / 5 - 459.67, bool);
      return i;
   default:
      printf("数据错误\n");
      return -1;
   }
}

char User_choose(char content[]) // 作为用户输入字符串的简单集成，说白了就是简化代码偷得懒
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
   // printf("程序名称: %s\n参数数量%d\n", argv[0], argc);没有什么意义，用来确定程序在那里的

   if (argc >= 4 && argv[1][0] == '-' && argv[3][0] == '-') // 作为参数时运行的代码否则转为交互式界面
   {
      temperature = strtof(argv[2], NULL);
      munging(argv[3][1], munging(argv[1][1], temperature, 0), 1);
   }
   else
   {
      while (argc == 1)
      {
         char choice_1 = '0';
         char choice_2 = '0';
         choice_1 = User_choose("(0.结束代码;1.开尔文;2.摄氏度;3.华氏度;)\n请输入要从被转换的温度单位:");
         if (choice_1 == '0')
         {
            return 0;
         } // 输入字符0立即结束代码，但在其他地方输入就不行了，不过也没有必要
         choice_2 = User_choose("（开尔文=1;摄氏度=2;华氏度=3;)\n请输入要从需要转换的温度单位:");
         printf("请输入要转换的温度数值:");
         scanf("%f", &temperature), getchar() != '\n';
         munging(choice_2, munging(choice_1, temperature, 0), 1);
      };
   }
   return 0;
}
