#include <iostream>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#define size 10
using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	int length = size, task;
	do
	{
		cout << "������� ����� ������� - ";
		cin >> task;
		switch (task)
		{
			case 1:
			{
				/*��������, ���������, ������� ��������� ������� ����� �� 6 �������.������������ ������ ������� ����� �� ������ �����.*/
				int money, allmoney = 0;
				for (int i = 1; i <= 6; i++)
				{
					cout << "������� ����� �� " << i << "-� ����� - ";
					cin >> money;
					allmoney += money;
				}
				cout << "����� �� 6 ������� �������� " << allmoney << endl;
			} break;

			case 2:
			{
				/*�������� ���������, ������� ������� ���������� ������ � �������� �������*/
				int m[size];
				for (int i = 0; i < length; i++)
				{
					m[i] = -50 + rand() % 100;
					cout << m[i] << "  ";
				}
				cout << endl;
				for (int i = length - 1; i >= 0; i--)
				{
					cout << m[i] << "  ";
				}
			} break;

			case 3:
			{
				/*������������ ������ ����� ������ �������������, ������ ������� ���������� � ������, ���������� ��������� �������� �������������(�������� � ����� ���� ������).*/
				int m[5], sum = 0;
				for (int i = 0; i < 5; i++)
				{
					m[i] = 1 + rand() % 10;
					cout << m[i] << "  ";
					sum += m[i];
				}
				cout << "\n�������� = " << sum << endl;
			} break;

			case 4:
			{
				/*������������ ������ ������� ����� �� ���(12 �������).���������� ���������� �����, 
					� ������� ������� ���� ����������� � �����, � ������� ������� ���� ����������.*/
				int m[12], min = 0, max = 0;
				for (int i = 0; i < 12; i++)
				{
					m[i] = 10 + rand() % 100;
					if (m[i] < min)
						min = m[i];
					if (m[i] > max)
						max = m[i];
					cout << "������� �� " << i + 1 << "-� ����� = " << m[i] << endl;
				} cout << "������������ ������� = " << max << "\n����������� - " << min << endl;
			} break;

			case 5:
			{
				/*� ���������� �������, ����������� ���������� �������, ���������� ����������� � ������������ ��������*/
				int m[size], min = 0, max = 0;
				for (int i = 0; i < length; i++)
				{
					m[i] = -50 + rand() % 100;
					cout << m[i] << "  ";
					if (m[i] < min)
						min = m[i];
					if (m[i] > max)
						max = m[i];
				} cout << "\nMax = " << max << ", Min = " << min << endl;
			} break;

			case 6:
			{
				/*������������ ������ ������� ����� �� ���(12 �������).�����  ������������ ������ ��������
				(��������, 3 � 6 � ����� ����� 3 - � � 6 - � �������).���������� ���������� �����, 
					� ������� ������� ���� ����������� � �����, � ������� ������� ���� ���������� � ������ ���������� ���������.*/
				int m[12], max = 0, min = 0, a, b;
				for (int i = 0; i < 12; i++)
				{
					m[i] = 10 + rand() % 100;
					cout << "�� " << i + 1 << "-� ����� ������� ���������  " << m[i] << endl;
				}
				do
				{
					cout << "������� �������� ������� � � b - ";
					cin >> a >> b;
				} while ((a > 12 || a < 1) || (b > 12 || b < 1) || a > b);
				for (int i = 0; i < 12; i++)
				{
					if (i >= a && i <= b)
					{
						if (m[i] < min)
							min = m[i];
						if (m[i] > max)
							max = m[i];
					}
				} 
				for (int i = 0; i < 12; i++)
				{
					if (m[i] == min)
						cout << "����������� ����� " << min << " ��� � " << i + 1 << "-� ������" << endl;
					if (m[i] == max)
						cout << "������������ ����� " << max << " ��� � " << i + 1 << "-� ������" << endl;
				}
			} break;

			case 7:
			{
				/*� ���������� �������, ��������� �� N ������������ ����� ��������� :
				�	����� ������������� ���������.
					�	������������ ���������, ����������� ����� min � max ����������.
					�	������������ ��������� � ������� ��������.
					�	�����  ���������, ����������� ����� ������ � ��������� �������������� ����������.*/
				int m[20], sum1 = 0, sum2 = 0, proiz1 = 1, proiz2 = 1, min, max;
				for (int i = 0; i < 20; i++)
				{
					m[i] = -100 + rand() % 200;
					cout << m[i] << "  ";
					if (i == 0)
					{
						min = m[i];
						max = m[i];
					}
					else if (m[i] < 0)
						sum1 += m[i];
					else if (i > 0)
					{
						if (m[i] < min)
							min = m[i];
						if (m[i] > max)
							max = m[i];
					}
					else if (i % 2 == 0)
						proiz1 *= m[i];
				}
				cout << "\n����� ������������� �� = " << sum1 << endl;
				cout << "������������ ��-� � ������� ��������� = " << proiz1 << endl;
				for (int i = 0; i < 12; i++)
				{
					if (m[i] >= min && m[i] <= max)
						proiz2 *= m[i];
					if (m[i] < 0)
						for (int j = i + 1; j < 12; j++)
						{
							if (m[j] < 0)
								sum2 += m[j];
						}
				} cout << "������������ �� ����� ��� � ���� = " << proiz2 << endl;
				cout << "����� ��������� ����� ������ � ��������� �������������� = " << sum2 << endl;

			} break;

			case 8:
			{
				/*�����(�������� ��������) ������, ������ �� ���� ��� 0, � ��������� �������������� ������ �������� ���������� - 1;*/
				int m[size];
				for (int i = 0; i < length; i++)
				{
					m[i] = -5 + rand() % 10;
					cout << m[i] << " ";
				} cout << endl;
				for (int i = 0; i < length; i++)
				{
					if (m[i] == 0)
					{
						m[i] = m[i + 1];
						m[i + 1] = 1;
					}
				}
				for (int i = 0; i < length; i++)
				{
					cout << m[i] << " ";
				} cout << endl;
			} break;

			case 9:
			{
				/*�������� ���������, ����������� ���������� ����������� ������� ����� ����� ������� ��������.*/
				int m[size];
				for (int i = 0; i < length; i++)
				{
					m[i] = -50 + rand() % 100;
					cout << m[i] << "  ";
				} cout << endl;
				for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < length; j++)
					{
						if (m[j] < m[j + 1])
						{
							int temp = m[j];
							m[j] = m[j + 1];
							m[j + 1] = temp;
						}
					}
				}
				for (int i = 0; i < length; i++)
				{
					cout << m[i] << "  ";
				} cout << endl;
			} break;

			case 10:
			{
				/*�������� ���������, ����������� ���������� ����������� ������� ����� ����� ������� �������*/
				int m[size], min, temp;
				for (int i = 0; i < size; i++)
				{
					m[i] = -100 + rand() % 200;
					cout << m[i] << "  ";
				}
				cout << endl;
				cout << "=============" << endl;
				for (int i = 0; i < size; i++)
				{
					min = i;
					for (int j = i + 1; j < size; j++)
					{
						if (m[j] > m[min])
							min = j;
					}
					temp = m[i];
					m[i] = m[min];
					m[min] = temp;
				}
				for (int i = 0; i < size; i++)
				{
					cout << m[i] << "  ";
				} cout << endl;
			} break;

			case 11:
			{
				/*�������� ���������, ����������� ���������� ����������� ������� ����� ����� ������� �������� ������.*/
				int m[size];
				for (int i = 0; i <size; i++)
				{
					m[i] = -50 + rand() % 100;
					cout << m[i] << "  ";
				} cout << endl;
				for (int i = 0; i < size; i++)
				{
					int value = m[i]; 
					int index = i; 
					while ((index > 0) && (m[index - 1] > value))
					{
						m[index] = m[index - 1];
						index--; 
					}
					m[index] = value; 
				}
				for (int i = 0; i < size; i++)
				{
					cout << m[i] << "  ";
				} cout << endl;
			} break;

			case 12:
			{
				/*12.	***�������� ��������� �����������.������� ��� ���������� �������.���� ������ ������ ������ ICQ, ������ � ���������� ������.����������� ���� ��� ������������ :
				a)	������������� �� ������� ICQ
				b)	������������� �� ������� ��������
				c)	������� ������ �������������
				d)	�����*/
				int m1[size], m2[size];
				for (int i = 0; i < length; i++)
				{
					m1[i] = 8000 + rand() % 999;
					m2[i] = 1000000 + rand() % 8999999;
				} cout << "���������� �� ������� ICQ" << endl;
				for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < length; j++)
					{
						if (m1[j] < m1[j + 1])
						{
							int temp = m1[j];
							m1[j] = m1[j + 1];
							m1[j + 1] = temp;
						}
					}
				}
				for (int i = 0; i < length; i++)
				{
					cout << i + 1 << ".  == " << m1[i] << endl;
				}
				cout << "\n���������� �� ������� ���" << endl;
				for (int i = 0; i < length; i++)
				{
					for (int j = 0; j < length; j++)
					{
						if (m2[j] < m2[j + 1])
						{
							int temp = m2[j];
							m2[j] = m2[j + 1];
							m2[j + 1] = temp;
						}
					}
				}
				for (int i = 0; i < length; i++)
				{
					cout << i + 1 << ".  == +7 771 " << m2[i] << endl;
				}

			} break;

			case 13:
			{
				/*13.	**�������� ��������� ��������������.������������ ������ 10 ������ ��������.����������� ���� ��� ������������
					a)	����� ������(����� ����������� �������)
					b)	��������� ��������(������������ ������ ����� �������� ������� � ����� ������)
					c)	������� �� ���������(��������� �������, ���� ������� ��� �� ���� 10.7)*/
				float m[size], srand((float)time(NULL));
				for (int i = 0; i < length; i++)
				{
					m[i] = 5.8 + rand() % 10;
					cout << "������ " << i + 1 << "-�� �������� = " << m[i] << endl;
				}
				for (int i = 0; i < length; i++)
				{
					if (m[i] < 8)
					{
						cout << "� �������� � " << i + 1 << " ���������!!!" << endl;
						m[i] = 8.8 + rand() % 10;
						cout << "����� ������ - " << m[i] << endl;
					}
				}
				for (int i = 0; i < length; i++)
				{
					if (m[i] > 10.7)
						cout << "� �������� � " << i + 1 << " ���������!!!" << endl;
				}

			} break;
		}
	} while (task < 53);


}