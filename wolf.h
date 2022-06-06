#ifndef WOLF_H
#define WOLF_H
#include <iostream>//C++輸入輸出流庫
#include <cstdlib>//使用srand函數要用到這個庫
#include <ctime>//使用time函數要用到這個庫
#include <Windows.h>
#include <conio.h>
using namespace std;

class wolf
{
private:
    int m[20];//存活
    int s[20] = {0};//身分
    //int p[20];//票數
    int n;//自己號碼
    int c;//總存活人數 
    int sy=1;//毒藥
    int jy=1;//復活藥
    int yy[20];//電腦預言家視野
    int day;//天數

public:
    wolf();
    void PrintDiePlayer();
    void OutNumberAndIdentity();
    void random();//隨機身分
    void playwolf();//玩家當狼 身分組1
    void playProphet();//玩家當預言家 身分組2 
    void playWitchSY(int a);//毒藥
    void playWitchJY(int a);//復活
    void playWitchNULL(int a);//玩家當女巫NULL
    void PrintSurvivePlayer();//輸出存活玩家&電腦 
    void PrintSurvivePlayerOfWolf();//輸出存活玩家除了狼人 
    void PrintSurvivePlayerOfProphet();//輸出存活玩家除了預言家 
    void PrintSurvivePlayerOfWitch();//輸出存活玩家除了女巫 
    void COMwolf();//電腦狼人  身分組1
    void COMProphet(int i);//電腦預言家  身分組2
    void COMWitchSY(int i, int a);//電腦女巫毒 
    void COMWitchJY(int i, int a);//電腦女巫解 
    void COMWitchNULL(int a);//電腦女巫無 
    void brc();
};

#endif
