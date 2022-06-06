#include "wolf.h"
using namespace std;
int main()
{
	wolf wolf1;
	srand((int)time(0));
	char a = '1';
	while (1)
	{
		system("cls");
		cout << "殺手遊戲" << endl;
		cout << "1.開始遊戲" << endl;
		cout << "2.查看遊戲規則" << endl;
		a = _getch();
		if (a == '1')
		{
			cout << "1. 15人場" << endl;
			cout << "2. 30人娛樂戰(10獵人)<敬請期待>" << endl;
			a = '2';
			while (a == '2')
			{
				a = _getch();
				switch (a)
				{
				case '1':
					wolf1.brc();
					break;
				}
				if (a == '1')
					break;
			}
			if (a == '1')
				break;
		}
		else if (a == '2')
		{
			cout << "狼人：每當晚上的時候可使用殺人權殺掉一人" << endl;//1
			cout << "預言家：每天晚上可以知道一個人的身份" << endl;//2 
			cout << "平民：無技能,當玩家是平民時，在第5天擁有1.5票的投票權" << endl;//3
			cout << "女巫：有兩瓶藥水，一瓶為毒藥，一瓶為復活藥" << endl;//4
			cout << "投票細則：\n遊戲中除了你以外全是由電腦代替" << endl;
			cout << "狼人不會殺掉隊友，但不包括投票環節" << endl;
			cout << "預言家如果預言到殺手將一直對他投票，如果預言到平民將永遠不會對他投票" << endl;
			cout << "********利用好超級AI遊戲規則找出殺手**********" << endl;
			system("pause");
		}
	}
	return 0;
}