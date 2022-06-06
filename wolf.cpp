#include "wolf.h"
wolf::wolf()
{
	for (int i = 1; i <= 15; i++)
	{
		m[i] = 1;//生存狀態
	}
	for (int i = 1; i <= 15; i++)
	{
		s[i] = 0;
	}
	c = 15;//總存活人數 
	sy = 1;//毒藥
	jy = 1;//復活藥
	for (int i = 1; i <= 15; i++)
	{
		yy[i] = 0;
	}
	day=1;//天數
}
void wolf::PrintDiePlayer()//死亡名單 
{
	cout << "陣亡名單：" << endl;
	for (int i = 1; i <= 15; i++)
	{
		if (m[i] == 0)
		{
			cout << i << "號,身份:" << s[i] << " " << endl;
		}
	}
}
void wolf::OutNumberAndIdentity()//輸出遊戲者編號及身分
{
	cout << "你是" << n << "號" << endl;
	switch (s[n])
	{
	case 1:
		cout << "你是狼人" << endl << endl;
		break;
	case 2:
		cout << "你是預言家" << endl << endl;
		break;
	case 3:
		cout << "你是平民" << endl << endl;
		break;
	case 4:
		cout << "你是女巫" << endl << endl;
		break;
	}
}
void wolf::random()//隨機身分
{
	n = rand() % 15 + 1;
	int l = 0, w = 0, j = 0, p = 0;
	for (int i = 1; i <= 15; i++)
	{
		for (; s[i] == 0;) {
			int a = rand() % 4 + 1;//亂數決定身分
			if (a == 1 && l < 2)//殺手 
			{
				l++;
				s[i] = 1;
			}
			else if (a == 2 && w < 1)//預言家 
			{
				w++;
				s[i] = 2;
			}
			else if (a == 4 && p < 1)//女巫 
			{
				p++;
				s[i] = 4;
			}
			else if (a == 3 && j < 11)//平民 
			{
				j++;
				s[i] = 3;
			}
		}
	}
	//	s[n]=4;//測試用設定身分組 
		//分配身分結束
}
void wolf::playwolf()//玩家當狼 身分組1
{
	cout << "你選擇殺掉(僅限活人)" << endl;
	int a = 0;
	for (; m[a] != 1;)//m[]為存活
	{
		cin >> a;
	}
	m[a] = 0;
	cout << endl;
	cout << "狼人殺了" << a << "號" << endl << "他的身分是：";
	switch (s[a]) {
	case 1:
		cout << "狼人" << endl;
		break;
	case 2:
		cout << "預言家" << endl;
		break;
	case 3:
		cout << "平民" << endl;
		break;
	case 4:
		cout << "女巫" << endl;
		break;
	}
	c--;//存活人數減1
}
void wolf::playProphet()//玩家當預言家 身分組2 
{
	cout << "你選擇預言誰的身份(僅限活人，不能預言自己)" << endl;
	int a = 99;
	for (; m[a] != 1 && s[a] != 2;)//m[]為存活
	{
		cin >> a;
	}
	if (s[a] == 1)
	{
		cout << "請注意！" << a << "號是殺手" << endl;
		Sleep(1000);
	}
	else
	{
		cout << a << "號是平民" << endl;
	}
}
void wolf::playWitchSY(int a)//玩家使用毒藥
{
	if (a == 1)//使用毒藥
	{
		if (sy > 0)//毒藥數量 
		{
			sy--;//毒藥減少 
			cout << "你選擇了使用毒藥" << endl;
			for (int i = 1; i <= 15; i++) {
				if (m[i] == 1) {
					cout << i << " ";
				}
			}
			cout << endl;
			int b;//毒誰 
			do
			{
				cin >> b;
			} while (m[b] == 0);
			//			cin>>b;
			cout << "女巫毒了" << b << "號" << endl << "他的身分是：";
			switch (s[b])
			{
			case 1:
				cout << "殺手" << endl;

				break;
			case 2:
				cout << "預言家" << endl;
				break;
			case 3:
				cout << "平民" << endl;
				break;
			case 4:
				cout << "女巫" << endl;
				break;
			}
			m[b] = 0;//設定"死亡"狀態 
			c--; //總人數減一 
		}
		else//用過毒藥後 
		{
			cout << "毒藥不足" << endl;
		}
	}
}
void wolf::playWitchJY(int a)
{
	if (a == 2)//使用解藥 
	{
		if (jy > 0)
		{
			jy--;
			cout << "你選擇了復活藥水" << endl;
			PrintDiePlayer();
			int b;
			do
			{
				cin >> b;
			} while (m[b] == 1);

			cout << "女巫復活了" << b << "號" << endl << "他的身分是：";
			switch (s[b])
			{
			case 1:
				cout << "殺手";
				break;
			case 2:
				cout << "預言家";
				break;
			case 3:
				cout << "平民";
				break;
			case 4:
				cout << "女巫";
				break;
			}
			cout << endl << endl;
			m[b] = 1;
			c++;
		}
		else
		{
			cout << "復活藥水不足" << endl;
		}
	}
}
void wolf::playWitchNULL(int a)//玩家當預言家NULL
{
	if (a == 3)//不使用
	{
		cout << "你選擇不使用藥物" << endl;

	}
}
void wolf::PrintSurvivePlayer()//輸出存活玩家&電腦 
{
	cout << "目前存活玩家：";
	for (int j = 1; j <= 15; j++) {
		if (m[j] == 1) {//m[]為存活
			cout << j << " ";
		}
	}
	cout << endl << endl;
}
void wolf::PrintSurvivePlayerOfWolf()//輸出存活玩家除了狼人 
{
	cout << "你是狼人" << endl;
	cout << "目前存活玩家：";
	for (int j = 1; j <= 15; j++) {
		if (m[j] == 1 && s[j] != 1) {//m[]為存活
			cout << j << " ";
		}
	}
	cout << endl << endl;
}
void wolf::PrintSurvivePlayerOfProphet()//輸出存活玩家除了預言家 
{
	cout << "你是預言家" << endl;
	cout << "目前存活玩家：";
	for (int j = 1; j <= 15; j++) {
		if (m[j] == 1 && s[j] != 2) {//m[]為存活
			cout << j << " ";
		}
	}
	cout << endl << endl;
}
void wolf::PrintSurvivePlayerOfWitch()
{
	cout << "你身分是：女巫" << endl;
	cout << "存活狀況：" << endl;
	for (int j = 1; j <= 15; j++) {
		if (m[j] == 1) {//s[]身分組、m[]是否存活1存活0死亡 
			cout << j << " ";//存活才會輸出 
		}
	}
	cout << endl;
}
//int identity,int Numbering
void wolf::COMwolf()//電腦狼人  身分組1
{
	int a;
	do//a是看誰被殺 
	{
		a = rand() % 15 + 1;//抽獎看誰中獎 
	}//m[a]==0是避免殺死亡的s[a]==1是避免殺到殺手 
	while (m[a] == 0 || s[a] == 1);//s[]身分組、m[]是否存活1存活0死亡
	cout << "狼人殺了" << a << "號" << endl << "他的身分是：";
	switch (s[a]) {//a是當日死亡號碼
	case 2:
		cout << "預言家" << endl << endl;
		break;
	case 3:
		cout << "平民" << endl << endl;
		break;
	case 4:
		cout << "女巫" << endl << endl;
		break;
	}
	m[a] = 0;
	c--;
}
void wolf::COMProphet(int i)//電腦預言家  身分組2
{
	int a;
	do
	{
		a = rand() % 15 + 1;//a抽非本人且活著的
	} while (a == i || m[a] == 0);//s[]身分組、m[]是否存活1存活0死亡
//	cout<<"test";
	if (s[a] == 1) {//抽到狼人 
		yy[a] = 1;//yy[]建立電腦認知的視野 狼 
	}
	if (s[a] == 3) {//抽到平民 
		//等等投票用吧 !  
		yy[a] = 3;//yy[]建立電腦認知的視野 平民 
	}
}
void wolf::COMWitchSY(int i, int a)//電腦女巫毒 
{
	if (a == 1)//毒藥 
	{
		if (sy > 0)//sy毒藥數量 
		{
			sy--;//sy毒藥數量 
			int b;
			do
			{
				b = rand() % 15 + 1;//b為被毒的號碼
			} while (b == i || m[b] == 0);//排除自己及死亡的人 
			m[b] = 0;//設定"死亡"狀態
			cout << "女巫毒了" << b << "號" << endl << "他的身分是：";
			switch (s[b])
			{
			case 1:
				cout << "殺手";
				break;
			case 2:
				cout << "預言家";
				break;
			case 3:
				cout << "平民";
				break;
			}
			cout << endl << endl;
			c--;//總人數 
		}
	}
}
void wolf::COMWitchJY(int i, int a)//電腦女巫解 
{
	if (a == 2 && day > 1)//解藥 day大於1表示確定有死亡者 
	{
		if (jy > 0)
		{
			jy--;//解藥 
			int b;
			do
			{
				b = rand() % 15 + 1;//抽救誰 
			} while (b == i || m[b] == s[b] == 1);

			cout << "女巫復活了" << b << "號" << endl << "他的身分是：";
			switch (s[b])
			{
			case 1:
				cout << "殺手";
				break;
			case 2:
				cout << "預言家";
				break;
			case 3:
				cout << "平民";
				break;
			case 4:
				cout << "女巫";
				break;
			}
			cout << endl << endl;
			m[b] = 1;
			c++;
		}
	}
}
void wolf::COMWitchNULL(int a)//電腦女巫無 
{
	if (a == 3)//無 
	{
		cout << "女巫無使用藥" << endl << endl;
	}
}
void wolf::brc()
{
	system("cls");//清除畫面 
	srand((int)time(0));
	cout << "正在分配身份" << endl;
	//Sleep(1500);
	
		
	random();//分配身分組及編號

//	for(int j=1;j<15;j++){
//		if(s[j]==4){
//			cout<<"test "<<j<<" ";
//			s[j]=3;
//		}
//	}
//	s[n]=1;//測試狼人 
//	s[n]=2;//測試預言家 
//	s[n]=4;//測試女巫 

	OutNumberAndIdentity();//輸出編號及身分

	cout << "遊戲將在5秒後開始" << endl;
		Sleep(5000);
	int wolfplayer = 2;
	int tp[20] = { 0 };
	do
	{
		system("cls");//清除畫面所有東西
		OutNumberAndIdentity();//輸出編號及身分 
		cout << "第" << day << "晚開始" << endl;
		for (int i = 1; i <= 15; i++) //i是遊戲執行時每人輪到次數
		{
			if (i == n && m[n] == 1)//玩家殺手 預言家 女巫 
			{
				if (s[n] == 1)//s[n]==1自己為殺手 
				{
					PrintSurvivePlayerOfWolf();//輸出狼人看的生存人類
					playwolf();//狼人殺人
				}

				if (s[n] == 2)//s[n]==2自己為預言家 
				{
					PrintSurvivePlayerOfProphet();//輸出預言家看的生存人類
					playProphet();//玩家當預言家 
				}

				if (s[n] == 4)//自己為女巫 
				{
					PrintSurvivePlayerOfWitch();
					//playWitch(m,s,jy,sy,c);
					cout << "你選擇1.*使用毒藥* 2.*使用解藥*還是 3.*皆不使用*" << endl;
					int a;
					cin >> a;
					playWitchSY(a);
					playWitchJY(a);
					playWitchNULL(a);
				}

			}

			//電腦狼人預言家女巫 
			if (s[i] == 1 && m[i] == 1 && i != n)//s[]身分組、m[]是否存活1存活0死亡 i!=n是避免遊戲玩家再度執行一次 
			{
				COMwolf();//s[]身分組1狼人 電腦 
			}
			if (s[i] == 2 && m[i] == 1 && i != n)//s[]身分組2預言家 電腦 
			{
				COMProphet(i);
			}
			if (s[i] == 4 && m[i] == 1 && i != n)//s[]身分組4女巫 電腦 
			{

				int a;//抽用毒藥還解藥
				a = rand() % 3 + 1;
				COMWitchSY(i, a);
				COMWitchJY(i, a);
				COMWitchNULL(a);
			}
		}

		Sleep(1000);
		int p[20] = { 0 };//投票 
		cout << "第" << day << "晚結束" << endl << endl;
		if (m[n] == 0)//確認是否生存 
		{
			cout << "你已經>>死<<了";
			break;
		}
		PrintSurvivePlayer();
		cout << "請投票...." << endl;
		for (int i = 1; i <= 15; i++)
		{
			//玩家投票 
			if (i == n && m[n] == 1)
			{
				cout << endl << "你選擇投幾號" << endl;
				int a;//投票號碼  
				do
				{
					cin >> a;
					if (a == 99)//測試用看剩下的人的身分 
					{
						for (int i = 1; i <= 15; i++)
						{
							if (m[i] == 1)
							{
								cout << i << "號身分為； " << s[i] << endl;
							}
						}
					}
				} while (m[a] == 0 || a == n || a == 99);//m[]存活狀態 
				if (s[i] == 3 && day > 4)//s[]=3是平民身分第四天後投票兩票,身分組 p[]票數
				{
					p[a] += 2;
				}
				else
				{
					p[a]++;
				}
				cout << endl;
				cout << i << "號投給" << a << "號" << endl;
				//				Sleep(3000);//測試
			}


			//身分組是狼人的電腦
			if (s[i] == 1 && m[i] == 1 && i != n) 
			{
				int a;
				do
				{
					a = rand() % 15 + 1;//狼人票誰 
				} while (m[a] == 0 || a == i || s[a] == 1);
				p[a]++;//計算票數 
				cout << i << "號投給" << a << "號" << endl;//誰投給誰 
//				if(s[a]==3)//身分組是平民的電腦 
//				{
//					tp[a]=i;//不知道在幹嘛 
//				}
			}
			//身分組是預言家的電腦 
			if (s[i] == 2 && m[i] == 1 && i != n)
			{
				int a;
				do
				{
					a = rand() % 15 + 1;
				} while (m[a] == 0 || a == i || yy[a] == 3);

				if (yy[a] == 1)
				{
					p[a]++;
					cout << i << "號投給" << a << "號" << endl;
				}
				else
				{

					p[a]++;//計算票數
					cout << i << "號投給" << a << "號" << endl;
				}
			}
			//身分組是平民的電腦 
			if (s[i] == 3 && m[i] == 1 && i != n)
			{
				int a;
				do
				{
					a = rand() % 15 + 1;
				} while (m[a] == 0 || a == i);
				p[a]++;//投票 
				cout << i << "號投給" << a << "號" << endl;
			}
			//身分組是女巫的電腦 
			if (s[i] == 4 && m[i] == 1 && i != n)
			{
				int a;
				do
				{
					a = rand() % 15 + 1;
				} while (m[a] == 0 || a == i);
				p[a]++;//投票 
				cout << i << "號投給" << a << "號" << endl;
			}
		}
		system("cls");//清除畫面 
		cout << "投票情況：" << endl;
		for (int i = 1; i <= 15; i++)
			if (m[i] == 1)
				cout << i << "號" << "  票數：" << p[i] << endl;
		int sw, max = -100;
		for (int i = 1; i <= 15; i++)
		{
			if (p[i] > max)
			{
				sw = i;
				max = p[i];
			}
		}
		m[sw] = 0;
		cout << sw << "死了" << endl;
		c--;
		cout << sw << "號的身份是";
		switch (s[sw])
		{
		case 1:
			cout << "殺手" << endl;
			break;
		case 2:
			cout << "預言家" << endl;
			break;
		case 3:
			cout << "平民" << endl;
			break;
		case 4:
			cout << "女巫" << endl;
			break;
		}
		day++;
		system("pause");
		cout << endl;
	} while (m[n] == 1 && c > 1 && wolfplayer > 0);
	cout << "遊戲結束" << endl;
}
