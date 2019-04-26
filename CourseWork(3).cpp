//Тихобаев Илья 18 ПИ-1, версия 3
// База данных жилого дома(жильцов)
// В базе реализуются поля: имя, фамилия, номер квартиры, возраст жильцов
// База данных имеет следующие функции: добавление нового жильца, вывод списка всех жильцов, поиск жильцов по значению одного из полей,
//редактирование информации о жильце по имени и фамилии

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
	printf("Для начала работы с базой данных, укажите номер дома: ");
	scanf("%d", &(base.houseNum));
	printf("\nЕсли вы хотите считать информацию о жильцах из текстового файла, введите его название, иначе нажмите ENTER: ");
	gets(filename);
	fgets(filename, maxFilenameLength, stdin);
	if (strcmp(filename, "\n") != 0){
		filename[strlen(filename) - 1] = 0;
		setDataFromFile(&base, filename);
	}
	do {
		printf("\n-----------------Вас приветствует база данных жилого дома №%d -----------------\n", base.houseNum);
		printf("Введите:\n");
		printf("	 1 - добавить нового человека в базу данных \n");
		printf("	 2 - вывести информацию о всех жильцах\n");
		printf("	 3 - искать жильца(ов) по параметрам\n");
		printf("	 4 - редактировать информацию о жильцах\n");
		printf("	 5 - записать данные из базы данных в файл \n");
		printf("	 6 - удалить жильца\n");
		printf("	 0 - выйти из меню \n");
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
			printf("\nНеправильно введена команда\n");
			break;
		}
	} while (userInput != 0);
}

