#include <iostream>
#include<stdlib.h>
#include <stdio.h>
# include"time.h"
using namespace std;

int main()
{

    cout<<"Game：Lucky Guy"<<endl; //Game name游戏名
    //system("bash ~/Desktop/lucky/gameName.sh");
    cout<<"_(:з」∠)_"<<endl;

    char restart='1'; //restartstart the game's variables 重新开始的变量
    while(restart=='1'){
        char checkpoint; //Level selection variables 选择模式的变量

        cout<<"To measurestart today's lucky index!"<<endl<<endl;
	//system("bash ~/Desktop/lucky/checkpoint.sh");
        cout<<"Select the level: 1. Endless mode 2. After one stop"<<endl;  //选择模式

        scanf("%c",&checkpoint);
        cout<<endl;

        //Level selection module
        if(checkpoint=='2')   //Level 2 关卡2
        {

            int map[10]={0,0,0,0,0,0,0,0,0,0};  //10 numbers 10个数字
            srand((unsigned)time(NULL));    //设置随机数获取位置
            int i=0;
            int j;
            int ran[5]={-1,-1,-1,-1,-1};    //5 mines 存储5个炸弹
            cout<<"Level 2"<<endl;
            cout<<"We randomly generated 5 mines and generated mine numbers between 0 and 9"<<endl; //0~9中有5个炸弹
            cout<<endl;
            cout<<"---------------------"<<endl;
            cout<<"|0|1|2|3|4|5|6|7|8|9|"<<endl;
            cout<<"---------------------"<<endl;
            cout<<"The highest lucky index in the end-stop mode is: 5"<<endl;   //最高幸运值为5

            //To determine if mines are duplicates
            for(i = 0; i < 5; i++) // Subscript increments for later processing
            {
                //rand()Without arguments, it returns an integer from 0 to the maximum random number. The size of the largest random number is usually a fixed large integer.
                ran[i] = rand()%10;//Generates a random integer from 0 to 9 of these 10 integers 生成0~9的随机数
                for(j= 0; j < i; ++j)
                {
                    if ( ran[j] == ran[i]){//If you repeat 如果重复了
                        ran[i]=-1;
                        i--;
                    }
                }
            }
            cout<<endl;

            //Output the result in the mine array

            /*for(i=0;i<5;i++){
                cout<<ran[i]<<" ";
            }
            cout<<endl;
            */
            for(i=0;i<5;i++){
                map[ran[i]]=1;
            }

            //Output options
            /*for(i=0;i<10;i++){
                cout<<map[i]<<" ";
            }
            cout<<endl;
	    */


            //Statistics section
            int X;
            int flag=0; //End the game's game variables 游戏结束的变量
            int luck=0; //Returned lucky index  幸运值
            while(flag==0){
                cout<<"Please enter the number of your choice (don’t choose the one you selected before):";
                cin>>X;
                if(X>9||X<0){   //Exclude numbers that don’t match rules
                    cout<<"Please enter an integer within 0~9."<<endl;
                    continue;
                }
                else if(map[X]==-1)
                {
                    cout<<"This number has already been used"<<endl;
                }
                else{
                    if(map[X]==1){
                        cout<<"Stepping on mines, the current lucky index is:"<<luck<<endl;
                        flag=1;
                    }
                    else{
                        luck++;
                        map[X]=-1;
                        if(luck==5)
                        {
                            cout<<endl;
                            cout<<"Wow, the lucky index is: 5, clearance! You are today's lucky!"<<endl;
                            flag++;
                        }else{
			    //system("luckyindex.sh");
                            cout<<"Good luck, now the lucky index is:"<<luck<<endl;
                        }
                    }
                }
            }
        }else if(checkpoint=='1'){    //first round
            cout<<"Level 1"<<endl;
            cout<<"We randomly generated 5 mines and generated mine numbers between 0 and 9"<<endl; //0~9随机设置5个炸弹
            cout<<endl;
            cout<<"---------------------"<<endl;
            cout<<"|0|1|2|3|4|5|6|7|8|9|"<<endl;
            cout<<"---------------------"<<endl;

            int flag=0; //Variables to the next level
            int luck=0; //Lucky index 幸运值
            while(flag!=1){
                int map[10]={0,0,0,0,0,0,0,0,0,0};//10 numbers 10个数
                srand((unsigned)time(NULL));   //设置随机数获取位置
                int i=0;
                int j;
                int ran[5]={-1,-1,-1,-1,-1};
                for(i = 0; i < 5; i++) // Subscript increments for later processing
                {
                    ran[i] = rand()%10;
                    for(j= 0; j < i; ++j)
                    {
                        if ( ran[j] == ran[i]){//If you repeat
                            ran[i]=-1;
                            i--;
                        }
                    }
                }
                cout<<endl;
                for(i=0;i<5;i++){
                    map[ran[i]]=1;
                }

                //Output array results
                /*for(i=0;i<5;i++){
                    cout<<ran[i]<<" ";
                }
                cout<<endl;
		*/


                //Output options
                /*for(i=0;i<10;i++){
                    cout<<map[i]<<" ";
                }
                cout<<endl;
                */

                int X;  //存储输入的数字
                cout<<"Please enter the number you choose:";    //请输入你选择的数字
                cin>>X;
                if(X>9||X<0){   //Exclude numbers that don’t match rules
                    cout<<"Please enter an integer within 0~9."<<endl;  //输入0~9
                    continue;
                }else{
                    if(map[X]==1){
                    cout<<"Stepping on mines, the current lucky index is:"<<luck<<endl; //选中，显示当前幸运值
                        flag++;
                    }else{
                        luck++;
                        cout<<"Good luck, now the lucky index is:"<<luck<<endl; //结束，返回幸运值
                    }
                }
            }
        }else{  //When entering the wrong number of levels, exclude non-conforming inputs
            cout<<"Please enter the correct number of levels."<<endl;//请输入正确的数字
            continue;
        }

        //游戏结束模块
        cout<<endl<<endl;
        cout<<"********************************************************"<<endl;
        cout<<"* Think you are European Emperor? Then fight it again! *"<<endl;
        cout<<"********************************************************"<<endl;
	//system("bash ~/Desktop/lucky/restart.sh");
        cout<<"Enter 1 to continue the game"<<endl; //输入1继续游戏
        cout<<"Enter any character other than 1 to exit the game"<<endl;    //输入其他任意字符结束游戏
        cin>>restart;
        getchar();

    }

    return 0;
}

