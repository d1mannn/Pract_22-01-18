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
		cout << "Введите номер задания - ";
		cin >> task;
		switch (task)
		{
			case 1:
			{
				/*Написать, программу, которая вычисляет прибыль фирмы за 6 месяцев.Пользователь вводит прибыль фирмы за каждый месяц.*/
				int money, allmoney = 0;
				for (int i = 1; i <= 6; i++)
				{
					cout << "Введите доход за " << i << "-й месяц - ";
					cin >> money;
					allmoney += money;
				}
				cout << "Доход за 6 месяцев составил " << allmoney << endl;
			} break;

			case 2:
			{
				/*Написать программу, которая выводит одномерный массив в обратном порядке*/
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
				/*Пользователь вводит длину сторон пятиугольника, каждая сторона заноситься в массив, необходимо вычислить периметр пятиугольника(периметр – сумма всех сторон).*/
				int m[5], sum = 0;
				for (int i = 0; i < 5; i++)
				{
					m[i] = 1 + rand() % 10;
					cout << m[i] << "  ";
					sum += m[i];
				}
				cout << "\nПериметр = " << sum << endl;
			} break;

			case 4:
			{
				/*Пользователь вводит прибыль фирмы за год(12 месяцев).Необходимо определить месяц, 
					в котором прибыль была максимальна и месяц, в котором прибыль была минимальна.*/
				int m[12], min = 0, max = 0;
				for (int i = 0; i < 12; i++)
				{
					m[i] = 10 + rand() % 100;
					if (m[i] < min)
						min = m[i];
					if (m[i] > max)
						max = m[i];
					cout << "Прибыль за " << i + 1 << "-й месяц = " << m[i] << endl;
				} cout << "Максимальная прибыль = " << max << "\nМинимальная - " << min << endl;
			} break;

			case 5:
			{
				/*В одномерном массиве, заполненном случайными числами, определить минимальный и максимальный элементы*/
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
				/*Пользователь вводит прибыль фирмы за год(12 месяцев).Затем  пользователь вводит диапазон
				(например, 3 и 6 – поиск между 3 - м и 6 - м месяцем).Необходимо определить месяц, 
					в котором прибыль была максимальна и месяц, в котором прибыль была минимальна с учетом выбранного диапазона.*/
				int m[12], max = 0, min = 0, a, b;
				for (int i = 0; i < 12; i++)
				{
					m[i] = 10 + rand() % 100;
					cout << "За " << i + 1 << "-й месяц прибыль составила  " << m[i] << endl;
				}
				do
				{
					cout << "Введите диапозон месяцев а и b - ";
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
						cout << "Минимальный доход " << min << " был в " << i + 1 << "-м месяце" << endl;
					if (m[i] == max)
						cout << "Максимальный доход " << max << " был в " << i + 1 << "-м месяце" << endl;
				}
			} break;

			case 7:
			{
				/*В одномерном массиве, состоящем из N вещественных чисел вычислить :
				•	Сумму отрицательных элементов.
					•	Произведение элементов, находящихся между min и max элементами.
					•	Произведение элементов с четными номерами.
					•	Сумму  элементов, находящихся между первым и последним отрицательными элементами.*/
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
				cout << "\nСумма отрицательных эл = " << sum1 << endl;
				cout << "Произведение эл-в с четными индексами = " << proiz1 << endl;
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
				} cout << "Произведение эл между мин и макс = " << proiz2 << endl;
				cout << "Сумма элементов между первым и последним отрицательными = " << sum2 << endl;

			} break;

			case 8:
			{
				/*Сжать(сдвинуть элементы) массив, удалив из него все 0, и заполнить освободившиеся справа элементы значениями - 1;*/
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
				/*Написать программу, выполняющую сортировку одномерного массива целых чисел методом пузырька.*/
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
				/*Написать программу, выполняющую сортировку одномерного массива целых чисел методом вставок*/
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
				/*Написать программу, выполняющую сортировку одномерного массива целых чисел методом быстрого поиска.*/
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
				/*12.	***Написать программу «справочник».Создать два одномерных массива.Один массив хранит номера ICQ, второй – телефонные номера.Реализовать меню для пользователя :
				a)	отсортировать по номерам ICQ
				b)	отсортировать по номерам телефона
				c)	вывести список пользователей
				d)	выход*/
				int m1[size], m2[size];
				for (int i = 0; i < length; i++)
				{
					m1[i] = 8000 + rand() % 999;
					m2[i] = 1000000 + rand() % 8999999;
				} cout << "Сортировка по номерам ICQ" << endl;
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
				cout << "\nСортировка по номерам тел" << endl;
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
				/*13.	**Написать программу «успеваемость».Пользователь вводит 10 оценок студента.Реализовать меню для пользователя
					a)	вывод оценок(вывод содержимого массива)
					b)	пересдача экзамена(пользователь вводит номер элемента массива и новую оценку)
					c)	выходит ли стипендия(стипендия выходит, если средний бал не ниже 10.7)*/
				float m[size], srand((float)time(NULL));
				for (int i = 0; i < length; i++)
				{
					m[i] = 5.8 + rand() % 10;
					cout << "Оценка " << i + 1 << "-го студента = " << m[i] << endl;
				}
				for (int i = 0; i < length; i++)
				{
					if (m[i] < 8)
					{
						cout << "У студента № " << i + 1 << " пересдача!!!" << endl;
						m[i] = 8.8 + rand() % 10;
						cout << "Новая оценка - " << m[i] << endl;
					}
				}
				for (int i = 0; i < length; i++)
				{
					if (m[i] > 10.7)
						cout << "У студента № " << i + 1 << " СТЕПЕНДИЯ!!!" << endl;
				}

			} break;
		}
	} while (task < 53);


}