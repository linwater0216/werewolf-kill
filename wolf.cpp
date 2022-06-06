#include "wolf.h"
wolf::wolf()
{
	for (int i = 1; i <= 15; i++)
	{
		m[i] = 1;
	}
	for (int i = 1; i <= 15; i++)
	{
		s[i] = 0;
	}
	c = 15;//�`�s���H�� 
	sy = 1;//�r��
	jy = 1;//�_����
	for (int i = 1; i <= 15; i++)
	{
		yy[i] = 0;
	}
	day=1;//�Ѽ�
}
void wolf::PrintDiePlayer()//���`�W�� 
{
	cout << "�}�`�W��G" << endl;
	for (int i = 1; i <= 15; i++)
	{
		if (m[i] == 0)
		{
			cout << i << "��,����:" << s[i] << " " << endl;
		}
	}
}
void wolf::OutNumberAndIdentity()//��X�C���̽s���Ψ���
{
	cout << "�A�O" << n << "��" << endl;
	switch (s[n])
	{
	case 1:
		cout << "�A�O�T�H" << endl << endl;
		break;
	case 2:
		cout << "�A�O�w���a" << endl << endl;
		break;
	case 3:
		cout << "�A�O����" << endl << endl;
		break;
	case 4:
		cout << "�A�O�k��" << endl << endl;
		break;
	}
}
void wolf::random()//�H������
{
	n = rand() % 15 + 1;
	int l = 0, w = 0, j = 0, p = 0;
	for (int i = 1; i <= 15; i++)
	{
		for (; s[i] == 0;) {
			int a = rand() % 4 + 1;//�üƨM�w����
			if (a == 1 && l < 2)//���� 
			{
				l++;
				s[i] = 1;
			}
			else if (a == 2 && w < 1)//�w���a 
			{
				w++;
				s[i] = 2;
			}
			else if (a == 4 && p < 1)//�k�� 
			{
				p++;
				s[i] = 4;
			}
			else if (a == 3 && j < 11)//���� 
			{
				j++;
				s[i] = 3;
			}
		}
	}
	//	s[n]=4;//���եγ]�w������ 
		//���t��������
}
void wolf::playwolf()//���a��T ������1
{
	cout << "�A��ܱ���(�ȭ����H)" << endl;
	int a = 0;
	for (; m[a] != 1;)//m[]���s��
	{
		cin >> a;
	}
	m[a] = 0;
	cout << endl;
	cout << "�T�H���F" << a << "��" << endl << "�L�������O�G";
	switch (s[a]) {
	case 1:
		cout << "�T�H" << endl;
		break;
	case 2:
		cout << "�w���a" << endl;
		break;
	case 3:
		cout << "����" << endl;
		break;
	case 4:
		cout << "�k��" << endl;
		break;
	}
	c--;//�s���H�ƴ�1
}
void wolf::playProphet()//���a��w���a ������2 
{
	cout << "�A��ܹw���֪�����(�ȭ����H�A����w���ۤv)" << endl;
	int a = 99;
	for (; m[a] != 1 && s[a] != 2;)//m[]���s��
	{
		cin >> a;
	}
	if (s[a] == 1)
	{
		cout << "�Ъ`�N�I" << a << "���O����" << endl;
		Sleep(1000);
	}
	else
	{
		cout << a << "���O����" << endl;
	}
}
void wolf::playWitchSY(int a)//���a�ϥάr��
{
	if (a == 1)//�ϥάr��
	{
		if (sy > 0)//�r�ļƶq 
		{
			sy--;//�r�Ĵ�� 
			cout << "�A��ܤF�ϥάr��" << endl;
			for (int i = 1; i <= 15; i++) {
				if (m[i] == 1) {
					cout << i << " ";
				}
			}
			cout << endl;
			int b;//�r�� 
			do
			{
				cin >> b;
			} while (m[b] == 0);
			//			cin>>b;
			cout << "�k�Ŭr�F" << b << "��" << endl << "�L�������O�G";
			switch (s[b])
			{
			case 1:
				cout << "����" << endl;

				break;
			case 2:
				cout << "�w���a" << endl;
				break;
			case 3:
				cout << "����" << endl;
				break;
			case 4:
				cout << "�k��" << endl;
				break;
			}
			m[b] = 0;//�]�w"���`"���A 
			c--; //�`�H�ƴ�@ 
		}
		else//�ιL�r�ī� 
		{
			cout << "�r�Ĥ���" << endl;
		}
	}
}
void wolf::playWitchJY(int a)
{
	if (a == 2)//�ϥθ��� 
	{
		if (jy > 0)
		{
			jy--;
			cout << "�A��ܤF�_���Ĥ�" << endl;
			PrintDiePlayer();
			int b;
			do
			{
				cin >> b;
			} while (m[b] == 1);

			cout << "�k�Ŵ_���F" << b << "��" << endl << "�L�������O�G";
			switch (s[b])
			{
			case 1:
				cout << "����";
				break;
			case 2:
				cout << "�w���a";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "�k��";
				break;
			}
			cout << endl << endl;
			m[b] = 1;
			c++;
		}
		else
		{
			cout << "�_���Ĥ�����" << endl;
		}
	}
}
void wolf::playWitchNULL(int a)//���a��w���aNULL
{
	if (a == 3)//���ϥ�
	{
		cout << "�A��ܤ��ϥ��Ī�" << endl;

	}
}
void wolf::PrintSurvivePlayer()//��X�s�����a&�q�� 
{
	cout << "�ثe�s�����a�G";
	for (int j = 1; j <= 15; j++) {
		if (m[j] == 1) {//m[]���s��
			cout << j << " ";
		}
	}
	cout << endl << endl;
}
void wolf::PrintSurvivePlayerOfWolf()//��X�s�����a���F�T�H 
{
	cout << "�A�O�T�H" << endl;
	cout << "�ثe�s�����a�G";
	for (int j = 1; j <= 15; j++) {
		if (m[j] == 1 && s[j] != 1) {//m[]���s��
			cout << j << " ";
		}
	}
	cout << endl << endl;
}
void wolf::PrintSurvivePlayerOfProphet()//��X�s�����a���F�w���a 
{
	cout << "�A�O�w���a" << endl;
	cout << "�ثe�s�����a�G";
	for (int j = 1; j <= 15; j++) {
		if (m[j] == 1 && s[j] != 2) {//m[]���s��
			cout << j << " ";
		}
	}
	cout << endl << endl;
}
void wolf::PrintSurvivePlayerOfWitch()
{
	cout << "�A�����O�G�k��" << endl;
	cout << "�s�����p�G" << endl;
	for (int j = 1; j <= 15; j++) {
		if (m[j] == 1) {//s[]�����աBm[]�O�_�s��1�s��0���` 
			cout << j << " ";//�s���~�|��X 
		}
	}
	cout << endl;
}
//int identity,int Numbering
void wolf::COMwolf()//�q���T�H  ������1
{
	int a;
	do//a�O�ݽֳQ�� 
	{
		a = rand() % 15 + 1;//����ݽ֤��� 
	}//m[a]==0�O�קK�����`��s[a]==1�O�קK������� 
	while (m[a] == 0 || s[a] == 1);//s[]�����աBm[]�O�_�s��1�s��0���`
	cout << "�T�H���F" << a << "��" << endl << "�L�������O�G";
	switch (s[a]) {//a�O��馺�`���X
	case 2:
		cout << "�w���a" << endl << endl;
		break;
	case 3:
		cout << "����" << endl << endl;
		break;
	case 4:
		cout << "�k��" << endl << endl;
		break;
	}
	m[a] = 0;
	c--;
}
void wolf::COMProphet(int i)//�q���w���a  ������2
{
	int a;
	do
	{
		a = rand() % 15 + 1;//a��D���H�B���۪�
	} while (a == i || m[a] == 0);//s[]�����աBm[]�O�_�s��1�s��0���`
//	cout<<"test";
	if (s[a] == 1) {//���T�H 
		yy[a] = 1;//yy[]�إ߹q���{�������� �T 
	}
	if (s[a] == 3) {//��쥭�� 
		//�����벼�Χa !  
		yy[a] = 3;//yy[]�إ߹q���{�������� ���� 
	}
}
void wolf::COMWitchSY(int i, int a)//�q���k�Ŭr 
{
	if (a == 1)//�r�� 
	{
		if (sy > 0)//sy�r�ļƶq 
		{
			sy--;//sy�r�ļƶq 
			int b;
			do
			{
				b = rand() % 15 + 1;//b���Q�r�����X
			} while (b == i || m[b] == 0);//�ư��ۤv�Φ��`���H 
			m[b] = 0;//�]�w"���`"���A
			cout << "�k�Ŭr�F" << b << "��" << endl << "�L�������O�G";
			switch (s[b])
			{
			case 1:
				cout << "����";
				break;
			case 2:
				cout << "�w���a";
				break;
			case 3:
				cout << "����";
				break;
			}
			cout << endl << endl;
			c--;//�`�H�� 
		}
	}
}
void wolf::COMWitchJY(int i, int a)//�q���k�Ÿ� 
{
	if (a == 2 && day > 1)//���� day�j��1��ܽT�w�����`�� 
	{
		if (jy > 0)
		{
			jy--;//���� 
			int b;
			do
			{
				b = rand() % 15 + 1;//��Ͻ� 
			} while (b == i || m[b] == s[b] == 1);

			cout << "�k�Ŵ_���F" << b << "��" << endl << "�L�������O�G";
			switch (s[b])
			{
			case 1:
				cout << "����";
				break;
			case 2:
				cout << "�w���a";
				break;
			case 3:
				cout << "����";
				break;
			case 4:
				cout << "�k��";
				break;
			}
			cout << endl << endl;
			m[b] = 1;
			c++;
		}
	}
}
void wolf::COMWitchNULL(int a)//�q���k�ŵL 
{
	if (a == 3)//�L 
	{
		cout << "�k�ŵL�ϥ���" << endl << endl;
	}
}
void wolf::brc()
{
	system("cls");//�M���e�� 
	srand((int)time(0));
	cout << "���b���t����" << endl;
	//Sleep(1500);
	
		
	random();//���t�����դνs��

//	for(int j=1;j<15;j++){
//		if(s[j]==4){
//			cout<<"test "<<j<<" ";
//			s[j]=3;
//		}
//	}
//	s[n]=1;//���կT�H 
//	s[n]=2;//���չw���a 
//	s[n]=4;//���դk�� 

	OutNumberAndIdentity();//��X�s���Ψ���

	cout << "�C���N�b5���}�l" << endl;
	//	Sleep(5000);
	
	day = 1;
	int wolfplayer = 2;
	int tp[20] = { 0 };
	do
	{
		system("cls");//�M���e���Ҧ��F��
		OutNumberAndIdentity();//��X�s���Ψ��� 
		cout << "��" << day << "�߶}�l" << endl;
		for (int i = 1; i <= 15; i++) //i�O�C������ɨC�H���즸��
		{
			if (i == n && m[n] == 1)//���a���� �w���a �k�� 
			{
				if (s[n] == 1)//s[n]==1�ۤv������ 
				{
					PrintSurvivePlayerOfWolf();//��X�T�H�ݪ��ͦs�H��
					playwolf();//�T�H���H
				}

				if (s[n] == 2)//s[n]==2�ۤv���w���a 
				{
					PrintSurvivePlayerOfProphet();//��X�w���a�ݪ��ͦs�H��
					playProphet();//���a��w���a 
				}

				if (s[n] == 4)//�ۤv���k�� 
				{
					PrintSurvivePlayerOfWitch();
					//playWitch(m,s,jy,sy,c);
					cout << "�A���1.*�ϥάr��* 2.*�ϥθ���*�٬O 3.*�Ҥ��ϥ�*" << endl;
					int a;
					cin >> a;
					playWitchSY(a);
					playWitchJY(a);
					playWitchNULL(a);
				}

			}

			//�q���T�H�w���a�k�� 
			if (s[i] == 1 && m[i] == 1 && i != n)//s[]�����աBm[]�O�_�s��1�s��0���` i!=n�O�קK�C�����a�A�װ���@�� 
			{
				COMwolf();//s[]������1�T�H �q�� 
			}
			if (s[i] == 2 && m[i] == 1 && i != n)//s[]������2�w���a �q�� 
			{
				COMProphet(i);
			}
			if (s[i] == 4 && m[i] == 1 && i != n)//s[]������4�k�� �q�� 
			{

				int a;//��άr���ٸ���
				a = rand() % 3 + 1;
				COMWitchSY(i, a);
				COMWitchJY(i, a);
				COMWitchNULL(a);
			}
		}

		Sleep(1000);
		int p[20] = { 0 };//�벼 
		cout << "��" << day << "�ߵ���" << endl << endl;
		if (m[n] == 0)//�T�{�O�_�ͦs 
		{
			cout << "�A�w�g>>��<<�F";
			break;
		}
		PrintSurvivePlayer();
		cout << "�Ч벼...." << endl;
		for (int i = 1; i <= 15; i++)
		{
			//���a�벼 
			if (i == n && m[n] == 1)
			{
				cout << endl << "�A��ܧ�X��" << endl;
				int a;//�벼���X  
				do
				{
					cin >> a;
					if (a == 99)//���եάݳѤU���H������ 
					{
						for (int i = 1; i <= 15; i++)
						{
							if (m[i] == 1)
							{
								cout << i << "���������F " << s[i] << endl;
							}
						}
					}
				} while (m[a] == 0 || a == n || a == 99);//m[]�s�����A 
				if (s[i] == 3 && day > 4)//s[]=3�O���������ĥ|�ѫ�벼�Ⲽ,������ p[]����
				{
					p[a] += 2;
				}
				else
				{
					p[a]++;
				}
				cout << endl;
				cout << i << "���뵹" << a << "��" << endl;
				//				Sleep(3000);//����
			}


			//�����լO�T�H���q��
			if (s[i] == 1 && m[i] == 1 && i != n) 
			{
				int a;
				do
				{
					a = rand() % 15 + 1;//�T�H���� 
				} while (m[a] == 0 || a == i || s[a] == 1);
				p[a]++;//�p�Ⲽ�� 
				cout << i << "���뵹" << a << "��" << endl;//�֧뵹�� 
//				if(s[a]==3)//�����լO�������q�� 
//				{
//					tp[a]=i;//�����D�b�F�� 
//				}
			}
			//�����լO�w���a���q�� 
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
					cout << i << "���뵹" << a << "��" << endl;
				}
				else
				{

					p[a]++;//�p�Ⲽ��
					cout << i << "���뵹" << a << "��" << endl;
				}
			}
			//�����լO�������q�� 
			if (s[i] == 3 && m[i] == 1 && i != n)
			{
				int a;
				do
				{
					a = rand() % 15 + 1;
				} while (m[a] == 0 || a == i);
				p[a]++;//�벼 
				cout << i << "���뵹" << a << "��" << endl;
			}
			//�����լO�k�Ū��q�� 
			if (s[i] == 4 && m[i] == 1 && i != n)
			{
				int a;
				do
				{
					a = rand() % 15 + 1;
				} while (m[a] == 0 || a == i);
				p[a]++;//�벼 
				cout << i << "���뵹" << a << "��" << endl;
			}
		}
		system("cls");//�M���e�� 
		cout << "�벼���p�G" << endl;
		for (int i = 1; i <= 15; i++)
			if (m[i] == 1)
				cout << i << "��" << "  ���ơG" << p[i] << endl;
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
		cout << sw << "���F" << endl;
		c--;
		cout << sw << "���������O";
		switch (s[sw])
		{
		case 1:
			cout << "����" << endl;
			break;
		case 2:
			cout << "�w���a" << endl;
			break;
		case 3:
			cout << "����" << endl;
			break;
		case 4:
			cout << "�k��" << endl;
			break;
		}
		day++;
		system("pause");
		cout << endl;
	} while (m[n] == 1 && c > 1 && wolfplayer > 0);
	cout << "�C������" << endl;
}
