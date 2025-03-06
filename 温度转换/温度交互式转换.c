// V=1.3
#include <stdio.h>
#include <stdlib.h>

// F_Temperature_Conversion_Output函数用于处理温度的输出
float F_Temperature_Conversion_Output(char content[], float f_Temperature_Input, float f_Temperature_Output, int i_Step_Count,char c_Translating_Unit_Symbols)
{
   float i;
   if (i_Step_Count == 0)
   {
      i = f_Temperature_Input;
      return f_Temperature_Input;
   }
   else
   {
      printf("转换的%s数为:%.2f %c\n", content, f_Temperature_Output,c_Translating_Unit_Symbols);
      return f_Temperature_Output;
   }
}

// F_Temperature_Conversion_Judgment函数是主要的核心运算代码，根据输入类型进行温度转换
float F_Temperature_Conversion_Judgment(char c_Input_Type, char c_Output_Type, float temperature, int i_Step_Count)
{
   char c_Conversion_Type = c_Input_Type;

   float i;
   switch (c_Conversion_Type)
   {
   case '1': // 开尔文转开尔文
   case 'K': // 开尔文转开尔文
   case 'k':
      i = F_Temperature_Conversion_Output("开尔文", temperature, temperature, i_Step_Count,'K');
      break;
   case '2': // 开尔文转摄氏度
   case 'C': // 开尔文转摄氏度
   case 'c':
      i = F_Temperature_Conversion_Output("摄氏度", temperature + 273.15, temperature - 273.15, i_Step_Count,'C');
      break;
   case '3': // 开尔文转华氏度
   case 'F': // 开尔文转华氏度
   case 'f':
      i = F_Temperature_Conversion_Output("华氏度", (temperature + 459.67) * 5 / 9, temperature * 9 / 5 - 459.67, i_Step_Count,'F');
      break;
   default:
      printf("数据错误\n");
      return -1;
   }
      if (i_Step_Count == 0)
   {
      i= F_Temperature_Conversion_Judgment(c_Output_Type, '\0', i, 1);
      
   }
   return i;
}

// C_User_Choose函数作为用户输入字符串的简单集成
char C_User_Choose(char content[])
{
   char parameter;
   printf("%s\n", content);
   scanf("%s", &parameter);
   getchar() != '\n';
   return parameter;
}

// I_Interactive_Interface交互式界面使用了死循环
int I_Interactive_Interface(float temperature)
{
   char f_Unit_Conversion_Input = '0';
   char f_Unit_Conversion_Output = '0';
   f_Unit_Conversion_Input = C_User_Choose("(0.结束代码;1.开尔文;2.摄氏度;3.华氏度;)\n请输入要从被转换的温度单位:");
   if (f_Unit_Conversion_Input == '0')
   {
      return 1;
   }
   f_Unit_Conversion_Output = C_User_Choose("（开尔文=1;摄氏度=2;华氏度=3;)\n请输入要从需要转换的温度单位:");
   printf("请输入要转换的温度数值:");
   scanf("%f", &temperature);
   getchar() != '\n';
   F_Temperature_Conversion_Judgment(f_Unit_Conversion_Input, f_Unit_Conversion_Output, temperature, 0);
}
int main(int argc, char **argv)
{
   float f_Temperature_Input = 0;

   // 如果参数符合特定条件，执行参数运行代码，否则进入交互式界面
   if (argc !=1 &&argv[1][0] == '-' && (argv[1][1] == 'U' || argv[1][1] == 'u')) // 如果提供的是UI那么直接进入交互界面
   {
      while (1)
      {
         if (I_Interactive_Interface(f_Temperature_Input)==1)
         {
            return 0;
         }
         
      }
   }
   else
   {
      if (argc >= 4 && argv[1][0] == '-' && argv[3][0] == '-')//如果参数足够且可能可以使用则运行参数形式的代码，否则直接转向单次交互界面
      {
         char f_Unit_Conversion_Input = argv[1][1];
         char f_Unit_Conversion_Output = argv[3][1];
         f_Temperature_Input = strtof(argv[2], NULL);
         F_Temperature_Conversion_Judgment(f_Unit_Conversion_Input, f_Unit_Conversion_Output, f_Temperature_Input, 0);
      }
      else
      {
         printf("温度转换Ｃ语言小程序。\n by:[JingXingYu]\n使用方法:加参数使用\n -U 使用交互式程序 \n -需要转换任意单位(K,C,F) 温度数值 - 被转换任意单位(K,C,F)");
         I_Interactive_Interface(f_Temperature_Input);
      }
   }

   return 0;
}