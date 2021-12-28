//原神模拟常驻祈愿
//5星物品祈愿的基础概率为0.600%，5星角色祈愿的基础概率为0.300%，
//5星武器祈愿的基础概率为0.300%，最多90次祈愿必定能通过保底获得5星物品。
//特别地，当第73次祈愿未获取5星物品时，逐次增加获取5星的概率。
//4星物品祈愿的基础概率为5.100%，4星角色祈愿的基础概率为2.550%，
//4星武器祈愿的基础概率为2.550%，最多10次祈愿获得4星物品。
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<cstdio>
using namespace std;
int starResult(int sum10,int sum90)//此函数使用随机数计算此次祈愿获得物品的星数
{
    int r[6];
    double p[6];
    int star;
    double pstar;
    p[4]=0.051;
    if(sum10==10)p[4]=1;//四星的概率
    if(sum90<74)p[5]=0.006;
    else if(sum90>=74&&sum90<=90)
    {
        for(int i=74;i<=sum90;i++)
        {
            p[5]=p[5]+0.05847058824;//逐次增加获取概率
        }
    }//五星概率，注意p5将根据sum90而变化
    pstar= (rand()%1000)*0.001;
    if(0<=pstar&&pstar<=p[5])star=5;
    else if(p[5]<pstar&&pstar<=p[5]+p[4])star=4;
    else star=3;//其他情况均为3星
    return star;//函数值表示星数
}

int itemResultOrder(int star)//每个星级都有若干物品，此函数决定获取的物品到底是这个星级的哪一个物品
{
    int order;
    order=rand();
    if(star==5)order=order%15;
    else if(star==4)order=order%39;
    else if(star==3)order=order%13;
    return order;
}

int main ()
{
    
    int sum=0,sum90=0,sum10=0;
    int i;
    int star;
    int itemStar5=0;
    int itemStar4=0;
    srand(time(NULL));
    //---------------------------------------------
    char itemCode[6/*star*/][40/*order*/][20];//三维数组，物品库
    strcpy(itemCode[3][0],"弹弓     ");
    strcpy(itemCode[3][1],"神射手之誓");
    strcpy(itemCode[3][2],"鸦羽弓   ");
    strcpy(itemCode[3][3],"翡玉法球");
    strcpy(itemCode[3][4],"讨龙英杰谭");
    strcpy(itemCode[3][5],"魔导绪论");
    strcpy(itemCode[3][6],"黑缨枪   ");
    strcpy(itemCode[3][7],"以理服人");
    strcpy(itemCode[3][8],"沐浴龙血的剑");
    strcpy(itemCode[3][9],"铁影阔剑");
    strcpy(itemCode[3][10],"飞天御剑");
    strcpy(itemCode[3][11],"黎明神剑");
    strcpy(itemCode[3][12],"冷刃     ");
    //----------------
    strcpy(itemCode[4][0],"九条裟罗");
    strcpy(itemCode[4][1],"早柚     ");
    strcpy(itemCode[4][2],"托马     ");
    strcpy(itemCode[4][3],"烟绯     ");
    strcpy(itemCode[4][4],"罗莎莉亚");
    strcpy(itemCode[4][5],"辛焱     ");
    strcpy(itemCode[4][6],"砂糖     ");
    strcpy(itemCode[4][7],"迪奥娜   ");
    strcpy(itemCode[4][8],"重云     ");
    strcpy(itemCode[4][9],"诺艾尔   ");
    strcpy(itemCode[4][10],"班尼特   ");
    strcpy(itemCode[4][11],"菲谢尔   ");
    strcpy(itemCode[4][12],"凝光     ");
    strcpy(itemCode[4][13],"行秋     ");
    strcpy(itemCode[4][14],"北斗     ");
    strcpy(itemCode[4][15],"香菱     ");
    strcpy(itemCode[4][16],"安柏     ");
    strcpy(itemCode[4][17],"雷泽     ");
    strcpy(itemCode[4][28],"凯亚     ");
    strcpy(itemCode[4][19],"芭芭拉   ");
    strcpy(itemCode[4][20],"丽莎     ");
    strcpy(itemCode[4][21],"弓藏     ");
    strcpy(itemCode[4][22],"祭礼弓   ");
    strcpy(itemCode[4][23],"绝弦     ");
    strcpy(itemCode[4][24],"西风猎弓");
    strcpy(itemCode[4][25],"昭心     ");
    strcpy(itemCode[4][26],"祭礼残章");
    strcpy(itemCode[4][27],"流浪乐章");
    strcpy(itemCode[4][28],"西风秘典");
    strcpy(itemCode[4][29],"西风长枪");
    strcpy(itemCode[4][30],"匣里灭辰");
    strcpy(itemCode[4][31],"雨裁     ");
    strcpy(itemCode[4][32],"祭礼大剑");
    strcpy(itemCode[4][33],"钟剑     ");
    strcpy(itemCode[4][34],"西风大剑");
    strcpy(itemCode[4][35],"匣里龙吟");
    strcpy(itemCode[4][36],"祭礼剑   ");
    strcpy(itemCode[4][37],"笛剑     ");
    strcpy(itemCode[4][38],"西风剑   ");
    //----------------
    strcpy(itemCode[5][0],"刻晴     ");
    strcpy(itemCode[5][1],"莫娜     ");
    strcpy(itemCode[5][2],"七七     ");
    strcpy(itemCode[5][3],"迪卢克   ");
    strcpy(itemCode[5][4],"琴       ");
    strcpy(itemCode[5][5],"阿莫斯之弓");
    strcpy(itemCode[5][6],"天空之翼");
    strcpy(itemCode[5][7],"四风原典");
    strcpy(itemCode[5][8],"天空之卷");
    strcpy(itemCode[5][9],"和璞鸢   ");
    strcpy(itemCode[5][10],"天空之脊");
    strcpy(itemCode[5][11],"狼的末路");
    strcpy(itemCode[5][12],"天空之傲");
    strcpy(itemCode[5][13],"天空之刃");
    strcpy(itemCode[5][14],"风鹰剑   ");
    //---------------------------------------------
    cout<<"说明:该程序实现对《原神》游戏常驻祈愿机制的模拟，在程序退出后，所有历史模拟的祈愿数据将被清除。"<<endl;
    cout<<"请输入祈愿次数（“1”或“10”）进行祈愿，输入“-1”结束祈愿。"<<endl;
    cout<<"输入“check”可以查看当前祈愿次数以及保底的相关信息。"<<endl;//有点问题
    while(1)
    {
        int thisTimes;
        cin>>thisTimes;
        if(thisTimes==-1)return 0;
        else if(thisTimes==0)
        {
            cout<<"一共进行了"<<sum<<"次祈愿。"<<endl;
            cout<<"五星个数"<<itemStar5<<"。"<<endl;
            cout<<"四星个数"<<itemStar4<<"。"<<endl;
            continue;
        }
        else
        {
            for(i=1;i<=thisTimes;i++)
            {
                sum++;
                sum10++;
                sum90++;
                star=starResult(sum10,sum90);
                if(star==5)
                {
                    sum90=0;
                    sum10--;
                    itemStar5++;
                }
                else if(star==4)
                {
                    sum10=0;
                    itemStar4++;
                }
                if(star==5)cout<<itemCode[star][itemResultOrder(star)]<<'\t';
                else if(star==4)cout<<itemCode[star][itemResultOrder(star)]<<'\t';
                else cout<<itemCode[star][itemResultOrder(star)]<<'\t';
                if(i%10==0)cout<<endl;
            }
            if(thisTimes==1)cout<<endl;
        }   
    }
    return 0;
}