#ifndef WOLF_H
#define WOLF_H
#include <iostream>//C++��J��X�y�w
#include <cstdlib>//�ϥ�srand��ƭn�Ψ�o�Ӯw
#include <ctime>//�ϥ�time��ƭn�Ψ�o�Ӯw
#include <Windows.h>
#include <conio.h>
using namespace std;

class wolf
{
private:
    int m[20];//�s��
    int s[20] = {0};//����
    //int p[20];//����
    int n;//�ۤv���X
    int c;//�`�s���H�� 
    int sy=1;//�r��
    int jy=1;//�_����
    int yy[20];//�q���w���a����
    int day;//�Ѽ�

public:
    wolf();
    void PrintDiePlayer();
    void OutNumberAndIdentity();
    void random();//�H������
    void playwolf();//���a��T ������1
    void playProphet();//���a��w���a ������2 
    void playWitchSY(int a);//�r��
    void playWitchJY(int a);//�_��
    void playWitchNULL(int a);//���a��k��NULL
    void PrintSurvivePlayer();//��X�s�����a&�q�� 
    void PrintSurvivePlayerOfWolf();//��X�s�����a���F�T�H 
    void PrintSurvivePlayerOfProphet();//��X�s�����a���F�w���a 
    void PrintSurvivePlayerOfWitch();//��X�s�����a���F�k�� 
    void COMwolf();//�q���T�H  ������1
    void COMProphet(int i);//�q���w���a  ������2
    void COMWitchSY(int i, int a);//�q���k�Ŭr 
    void COMWitchJY(int i, int a);//�q���k�Ÿ� 
    void COMWitchNULL(int a);//�q���k�ŵL 
    void brc();
};

#endif
