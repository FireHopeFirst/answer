#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main()
{
	srand(time(0 ));
	setlocale(LC_ALL, "Russian");
	int arr_card[9][4],n_n,n;
	for(int i=0;i<9;i++)//������ ���� �� 6 �� 14
	{
		for(int j=0;j<4;j++)
		{
			arr_card[i][j]=0;
			arr_card[i][j]+=6+i;
		}
	}
    char arr_Trump_suit[0][0][7];//�������� �����
    
	char arr_suit_first[9][4][7]={
	{"�����", "����", "������","����"},
	{"�����", "����", "������","����"},
	{"�����", "����", "������","����"},
	{"�����", "����", "������","����"},
	{"�����", "����", "������","����"},
	{"�����", "����", "������","����"},
	{"�����", "����", "������","����"},
	{"�����", "����", "������","����"},
	{"�����", "����", "������","����"}
	};
	char arr_suit_second[4][7]={"�","�","�","�"};//������ ��� ����������� ����� �� 11 �� 14 � ������ ����
	
	cin>>n_n;//������ ���� ���������� ����� �� 2 �� 6
	
	if(n_n<=6&&n_n>=2)
	{
		n=n_n;
	}
	int p=0,k=0;
	int arr_player[n][6];//������ ������� ����
	char arr_number[n][6][7];//������ ������� ������ ��� ������ ����(arr_player[n][6])
	int h=0,t=0,q=0,w=0;
	
	for(int i(0);i<n;i++)
	{
		for(int j(0);j<6;j++)
		{
			p=rand()%9;//��������� ������������� 
			k=rand()%4;//��������� ������������� 
			
			if(arr_card[p][k]!=0)//��� ��� ����� ����	
			{
				//��������� ������������� ���� � ����� � ������ ��������� �������� �� ���� ,��� �� ��� �� ����������� � ������� ����
				//��������� ���� ��� �� ������� (���������� ����� � ������� � ���� ) ������ �� � ����� ������������ ����� ��� ����� ����
				arr_player[i][j]=0;
				arr_player[i][j]=arr_card[p][k];
				arr_card[p][k]=0;
				if(	arr_card[p][k]==0)//� ��� ��� ����� ������ 
				{
					for(int z=0;z<7;z++)
							arr_number[q][w][z]=arr_suit_first[p][k][z];
							w++;
							if(w==6)
								{
									q++;
									w=0;
								}				
				}
			}
			else
			{
				j--;
			}
		}
	}
	w=rand()%4;
 	int y=w;
	for(int i(0);i<7;i++)
	{
		arr_Trump_suit[0][0][i]=arr_suit_first[0][w][i];//����� �� ����� ��� ������ 
	}
		cout<<"�������� �����"<<" "<<arr_Trump_suit[0][0]<<endl;//������� ��� ������ 
		cout<<endl;
	w=0;	
	int z=0;
	int test[n][6];//������ ��� ��� �������� ������ ,�� ���� ����� ������ ����� ����,������ ���� ��� � ��� �����
	for(int i(0);i<n;i++)//������������ ��� ������ ����� ����
		{
			for(int j(0);j<6;j++)
				{
					if(arr_player[i][j]==11)
						cout<<arr_suit_second[0]<<" "<<arr_number[i][j]<<endl;
					if(arr_player[i][j]==12)
						cout<<arr_suit_second[1]<<" "<<arr_number[i][j]<<endl;
					if(arr_player[i][j]==13)
						cout<<arr_suit_second[2]<<" "<<arr_number[i][j]<<endl;
					if(arr_player[i][j]==14)
						cout<<arr_suit_second[3]<<" "<<arr_number[i][j]<<endl;
					if(arr_player[i][j]!=11&&arr_player[i][j]!=12&&arr_player[i][j]!=13&&arr_player[i][j]!=14)
						cout<<arr_player[i][j]<<" "<<arr_number[i][j]<<endl;
							
					if(arr_number[i][j][z]==arr_suit_first[1][0][z])
						test[i][j]=1;
					if(arr_number[i][j][z]==arr_suit_first[1][1][z])
						test[i][j]=2;
					if(arr_number[i][j][z]==arr_suit_first[1][2][z])
						test[i][j]=3;
					if(arr_number[i][j][z]==arr_suit_first[1][3][z])
						test[i][j]=4;
					}
					cout<<endl;
			}
	y+=1;
	k=0;
	p=0;
	for(int i(0);i<n;i++)//�������� ������������ �����
	{
		for(int j(0);j<6;j++)
		{
			if(test[i][j]==y)
			{
//				����� ��������� �� ����� �����������
//				6 ����� = 6 ����� ���� ������ ,�� 15 ����� ,������ ��� �������� ����� ���� �� ����������� 
//				7 ���� = 7 ����� ���� ������ ,�� 16 �����
//				������(�) ������ =13 ����� ���� ������ ,�� 22 �����
//				���(�) ����=14 ����� ���� ������ ,�� 23 �����
				w+=9;
				w+=arr_player[i][j];
			}
			else
			{
				w+=arr_player[i][j];
			}
			
			}
				if(w>=k)
				{

					k=w;	
				}
				cout<<w<<" "<<(i+1)<<" "<<"���� �����"<<endl;
				w=0;
    	}
	w=0;
	for(int i(0);i<n;i++)
	{
		for(int j(0);j<6;j++)
		{
			if(test[i][j]==y)
			{
				w+=9;
				w+=arr_player[i][j];
			}
			else
			{
				w+=arr_player[i][j];
			}
			
	}
		if(k==w)//����� �������� ������ 
			{
				
				cout<<endl;
				cout<<"����� ������� ����� ����"<<endl;
				for(int z(0);z<6;z++)
				{
					if(arr_player[i][z]==11)
							cout<<arr_suit_second[0]<<" "<<arr_number[i][z]<<endl;
						if(arr_player[i][z]==12)
							cout<<arr_suit_second[1]<<" "<<arr_number[i][z]<<endl;
						if(arr_player[i][z]==13)
							cout<<arr_suit_second[2]<<" "<<arr_number[i][z]<<endl;
						if(arr_player[i][z]==14)
							cout<<arr_suit_second[3]<<" "<<arr_number[i][z]<<endl;
						if(arr_player[i][z]!=11&&arr_player[i][z]!=12&&arr_player[i][z]!=13&&arr_player[i][z]!=14)
							cout<<arr_player[i][z]<<" "<<arr_number[i][z]<<endl;
				}
			}
			w=0;
    	}
	system("pause");
	return 0;
}
