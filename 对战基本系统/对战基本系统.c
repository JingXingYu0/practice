#include <stdio.h>
#define MAX_GROUP_UNIT 10
#define MAX_UNIT_ATTRIBUTE 5
#define UNIT_HP 1
int attatk(int choose);
void Battle_Selection();
int Player_choose(char content[]);
//int player=0;
int player_attribute[MAX_GROUP_UNIT][MAX_UNIT_ATTRIBUTE]={0};

int main()
{
    player_attribute[1][UNIT_HP]=100;player_attribute[0][UNIT_HP]=100;

    while (player_attribute[0][UNIT_HP]>=0)
    {
        Battle_Selection();
    }
    
    return 0;
}

void Battle_Selection()
{
        int hit,player_choose;
        printf("HP: %d",player_attribute[0][UNIT_HP]);
        player_choose=Player_choose("\n请输入你的行为:");
        /*printf("你的HP: %d\n请输入你的行为:",player_attribute[0][UNIT_HP]);
        scanf("%d",&player_choose);getchar() != '\n';*/
        switch (player_choose)
        {
        case 1:
           /*printf("请输入你要攻击的对象:");
            scanf("%d",&player_choose);getchar() != '\n';*/ 
            hit=attatk(player_choose=Player_choose("请输入你要攻击的对象: "));
            player_attribute[player_choose][UNIT_HP]=player_attribute[player_choose][UNIT_HP]-hit;
            printf("造成伤害%d,对方还剩下%d\n",hit,player_attribute[player_choose][UNIT_HP]);
            break;
        
        default:
            break;
        }        
}

int attatk(int choose)
{
    int i;
    i=1;
    return i;
    return 0;
}
int Player_choose(char content[])
{
    int parameter ;
    printf("%s\n",content);
    scanf("%d",&parameter);getchar() != '\n';
    return parameter;
}