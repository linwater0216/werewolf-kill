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
		cout << "����C��" << endl;
		cout << "1.�}�l�C��" << endl;
		cout << "2.�d�ݹC���W�h" << endl;
		a = _getch();
		if (a == '1')
		{
			cout << "1. 15�H��" << endl;
			cout << "2. 30�H�T�־�(10�y�H)<�q�д���>" << endl;
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
			cout << "�T�H�G�C��ߤW���ɭԥi�ϥα��H�v�����@�H" << endl;//1
			cout << "�w���a�G�C�ѱߤW�i�H���D�@�ӤH������" << endl;//2 
			cout << "�����G�L�ޯ�,���a�O�����ɡA�b��5�Ѿ֦�1.5�����벼�v" << endl;//3
			cout << "�k�šG����~�Ĥ��A�@�~���r�ġA�@�~���_����" << endl;//4
			cout << "�벼�ӫh�G\n�C�������F�A�H�~���O�ѹq���N��" << endl;
			cout << "�T�H���|�������͡A�����]�A�벼���`" << endl;
			cout << "�w���a�p�G�w�������N�@����L�벼�A�p�G�w���쥭���N�û����|��L�벼" << endl;
			cout << "********�Q�Φn�W��AI�C���W�h��X����**********" << endl;
			system("pause");
		}
	}
	return 0;
}