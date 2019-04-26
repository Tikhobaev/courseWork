//�������� ���� 18 ��-1, ������ 3
// ���� ������ ������ ����(�������)
// � ���� ����������� ����: ���, �������, ����� ��������, ������� �������
// ���� ������ ����� ��������� �������: ���������� ������ ������, ����� ������ ���� �������, ����� ������� �� �������� ������ �� �����,
//�������������� ���������� � ������ �� ����� � �������

#include <conio.h>
#include "stdafx.h"
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "houseDatabase.h"
#define nameLen 40
#define surnameLen 40
#define maxFilenameLength 40
void main()
{
	setlocale(LC_ALL, "RUS");
	houseDatabase base;
	setData(&base);
	int userInput = -1;
	int houseNum = 0;
	char filename[maxFilenameLength];
	printf("��� ������ ������ � ����� ������, ������� ����� ����: ");
	scanf("%d", &(base.houseNum));
	printf("\n���� �� ������ ������� ���������� � ������� �� ���������� �����, ������� ��� ��������, ����� ������� ENTER: ");
	gets(filename);
	fgets(filename, maxFilenameLength, stdin);
	if (strcmp(filename, "\n") != 0){
		filename[strlen(filename) - 1] = 0;
		setDataFromFile(&base, filename);
	}
	do {
		printf("\n-----------------��� ������������ ���� ������ ������ ���� �%d -----------------\n", base.houseNum);
		printf("�������:\n");
		printf("	 1 - �������� ������ �������� � ���� ������ \n");
		printf("	 2 - ������� ���������� � ���� �������\n");
		printf("	 3 - ������ ������(��) �� ����������\n");
		printf("	 4 - ������������� ���������� � �������\n");
		printf("	 5 - �������� ������ �� ���� ������ � ���� \n");
		printf("	 6 - ������� ������\n");
		printf("	 0 - ����� �� ���� \n");
		scanf("%d", &userInput);
		switch (userInput)
		{
		case 1:
			addRoomer(&base);
			break;
		case 2:
			printAllRoomers(&base);
			break;
		case 3:
			searchRoomer(&base);
			break;
		case 4:
			changeRoomer(&base);
			break;
		case 5:
			writeBase(&base);
			break;
		case 6:
			deleteRoomer(&base);
			break;
		default:
			printf("\n����������� ������� �������\n");
			break;
		}
	} while (userInput != 0);
}

