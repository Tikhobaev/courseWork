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
void setData(houseDatabase* base){
	(*base).houseRoomers = (roomer*)malloc(sizeof(roomer));
	(*base).sortedByName = (int*)malloc(sizeof(int));
	(*base).sortedBySurname = (int*)malloc(sizeof(int));
	(*base).sortedByFlatNum = (int*)malloc(sizeof(int));
	(*base).sortedByAge = (int*)malloc(sizeof(int));
	(*base).sortedByDebt = (int*)malloc(sizeof(int));
	(*base).count = 0;
}
void printAllRoomers(houseDatabase* base)   //������� ��� ������ ���� ������� �� ����� 
{
	if (base->count == 0){
		printf("���� �����\n");
		return;
	}
	printf("\n\n��������, �������������� �� ������ ��������� ������� ���������� � �������\n"
		"	* 1 - �� �����\n"
		"	* 2 - �� �������\n"
		"	* 3 - �� ������ ��������\n"
		"	* 4 - �� ��������\n"
		"	* 5 - �� ������� �������������\n");
	int userInput = 1;
	scanf("%d", &userInput);
	if (userInput == 1){
		printf("\n\n**********������ ������� ���� ����� %d**********\n\n", base->houseNum);
		for (int i = 0; i < (*base).count; i++)
		{
			printf("%d) %s %s  ����� ��������: %d  �������: %d �������������(���): %d \n", i + 1,
				(*base).houseRoomers[base->sortedByName[i]].name,
				(*base).houseRoomers[base->sortedByName[i]].surname,
				(*base).houseRoomers[base->sortedByName[i]].flatNum,
				(*base).houseRoomers[base->sortedByName[i]].age,
				(*base).houseRoomers[base->sortedByName[i]].debt);
		}
	}
	if (userInput == 2){
		printf("\n\n**********������ ������� ���� ����� %d**********\n\n", base->houseNum);
		for (int i = 0; i < (*base).count; i++)
		{
			printf("%d) %s %s  ����� ��������: %d  �������: %d �������������(���): %d \n", i + 1,
				(*base).houseRoomers[base->sortedBySurname[i]].name,
				(*base).houseRoomers[base->sortedBySurname[i]].surname,
				(*base).houseRoomers[base->sortedBySurname[i]].flatNum,
				(*base).houseRoomers[base->sortedBySurname[i]].age,
				(*base).houseRoomers[base->sortedBySurname[i]].debt);
		}
	}
	if (userInput == 3){
		printf("\n\n**********������ ������� ���� ����� %d**********\n\n", base->houseNum);
		for (int i = 0; i < (*base).count; i++)
		{
			printf("%d) %s %s  ����� ��������: %d  �������: %d �������������(���): %d \n", i + 1,
				(*base).houseRoomers[base->sortedByFlatNum[i]].name,
				(*base).houseRoomers[base->sortedByFlatNum[i]].surname,
				(*base).houseRoomers[base->sortedByFlatNum[i]].flatNum,
				(*base).houseRoomers[base->sortedByFlatNum[i]].age,
				(*base).houseRoomers[base->sortedByFlatNum[i]].debt);
		}
	}
	if (userInput == 4){
		printf("\n\n**********������ ������� ���� ����� %d**********\n\n", base->houseNum);
		for (int i = 0; i < (*base).count; i++)
		{
			printf("%d) %s %s  ����� ��������: %d  �������: %d �������������(���): %d \n", i + 1,
				(*base).houseRoomers[base->sortedByAge[i]].name,
				(*base).houseRoomers[base->sortedByAge[i]].surname,
				(*base).houseRoomers[base->sortedByAge[i]].flatNum,
				(*base).houseRoomers[base->sortedByAge[i]].age,
				(*base).houseRoomers[base->sortedByAge[i]].debt);
		}
	}
	if (userInput == 5){
		printf("\n\n**********������ ������� ���� ����� %d**********\n\n", base->houseNum);
		for (int i = 0; i < (*base).count; i++)
		{
			printf("%d) %s %s  ����� ��������: %d  �������: %d �������������(���): %d \n", i + 1,
				(*base).houseRoomers[base->sortedByDebt[i]].name,
				(*base).houseRoomers[base->sortedByDebt[i]].surname,
				(*base).houseRoomers[base->sortedByDebt[i]].flatNum,
				(*base).houseRoomers[base->sortedByDebt[i]].age,
				(*base).houseRoomers[base->sortedByDebt[i]].debt);
		}
	}

	printf("\n\n");
}
void addRoomer(houseDatabase* base)   //������� ��������� ������ ������ � ���� ������
{
	simpleAdd(base);
	printf("\n ������� ��� ������ \n");
	scanf("%s", &((*base).houseRoomers[(*base).count - 1].name));
	printf("\n ������� ������� ������ \n");
	scanf("%s", &((*base).houseRoomers[(*base).count - 1].surname));
	printf("\n ������� ����� �������� ������\n");
	scanf("%d", &((*base).houseRoomers[(*base).count - 1].flatNum));
	printf("\n ������� ������� ������ \n");
	scanf("%d", &((*base).houseRoomers[(*base).count - 1].age));
	printf("\n ������� ������������� ������(���) \n");
	scanf("%d", &((*base).houseRoomers[(*base).count - 1].debt));
	simpleSort(base);
}
void deleteRoomer(houseDatabase* base){
	int userInput;
	do {
		printf(" ------���� ��������  ������ �� ����������------ \n");
		printf("������� ���, �������, ����� �������� ��� ������� ������, ���������� � ������� ������ �������������\n");
		printf("\n ������� \n  * 1, ���� �� ������ ��� \n  * 2, ���� ������ ������� \n  * 3, ���� ������ ����� �������� \n  * 4, ���� ������ �������\n");
		printf("  * 5, ���� ������ ������ �������������\n\n");
		printf("**** ������� ����� ������������� ����� ����� ��� ������ �� ���� �������� ****\n");
		scanf("%d", &userInput);
		if (userInput == 1)    //
		{
			char userName[nameLen];
			printf("������� ��� ������ \n");
			scanf("%s", &userName);
			printf("\n\n*******************���������� ������***********************\n");
			int foundIndex = binSearchName(userName, base->houseRoomers, base->sortedByName, base->count);
			if (foundIndex < 0){
				printf("������ � ����� ������ �� �������\n");
			}
			else{
				int justNumber = 1;
				for (int i = foundIndex; i < base->count && strcmp(base->houseRoomers[base->sortedByName[i]].name, userName) == 0; i++)
				{
					printf("\n %d) %s %s ����� ��������: %d �������: %d �������������(���): %d \n", justNumber,
						base->houseRoomers[base->sortedByName[i]].name,
						base->houseRoomers[base->sortedByName[i]].surname,
						base->houseRoomers[base->sortedByName[i]].flatNum,
						base->houseRoomers[base->sortedByName[i]].age,
						base->houseRoomers[base->sortedByName[i]].debt);
					justNumber++;
				}
				justNumber--;
				printf("\n\n");
				printf("-----������� ����� ������ �� ������������� ������-----\n");
				int input = 0;
				scanf("%d", &input);
				if (input <= justNumber && input >= 1){
					//�� ����� ���������� ������ �������������� ���������� ������
					strcpy(base->houseRoomers[base->sortedByName[foundIndex + input - 1]].name, base->houseRoomers[base->count - 1].name);
					strcpy(base->houseRoomers[base->sortedByName[foundIndex + input - 1]].surname, base->houseRoomers[base->count - 1].surname);
					base->houseRoomers[base->sortedByName[foundIndex + input - 1]].flatNum = base->houseRoomers[base->count - 1].flatNum;
					base->houseRoomers[base->sortedByName[foundIndex + input - 1]].age = base->houseRoomers[base->count - 1].age;
					base->houseRoomers[base->sortedByName[foundIndex + input - 1]].debt = base->houseRoomers[base->count - 1].debt;
					//��������� �� 1 ������ 5 ��������(��������� ������� ����� �����)
					(*base).houseRoomers = (roomer*)realloc((*base).houseRoomers, ((*base).count - 1)*sizeof(roomer));
					(*base).sortedByName = (int*)realloc((*base).sortedByName, ((*base).count - 1)*sizeof(int));
					(*base).sortedBySurname = (int*)realloc((*base).sortedBySurname, ((*base).count - 1)*sizeof(int));
					(*base).sortedByFlatNum = (int*)realloc((*base).sortedByFlatNum, ((*base).count - 1)*sizeof(int));
					(*base).sortedByAge = (int*)realloc((*base).sortedByAge, ((*base).count - 1)*sizeof(int));
					(*base).sortedByDebt = (int*)realloc((*base).sortedByDebt, ((*base).count - 1)*sizeof(int));
					(*base).count--;
					//����� � �������� � ��������� sortedBy �������� ������ ������ ��� �������, ��������� � ������� �� 0 �� ������ count
					for (int i = 0; i < base->count; i++){
						base->sortedByName[i] = i;
						base->sortedBySurname[i] = i;
						base->sortedByFlatNum[i] = i;
						base->sortedByAge[i] = i;
						base->sortedByDebt[i] = i;
					}
					simpleSort(base);
				}
			}
		}
		if (userInput == 2)
		{
			char userSurname[surnameLen];
			printf("������� ������� ������\n");
			scanf("%s", &userSurname);
			printf("\n\n*******************���������� ������***********************\n");
			int foundIndex = binSearchSurname(userSurname, base->houseRoomers, base->sortedBySurname, base->count);
			if (foundIndex < 0){
				printf("������ � ����� �������� �� �������\n");
			}
			else{
				int justNumber = 1;
				for (int i = foundIndex; i < base->count && strcmp(base->houseRoomers[base->sortedBySurname[i]].surname, userSurname) == 0; i++)
				{
					printf("\n %d) %s %s ����� ��������: %d �������: %d �������������(���): %d \n", justNumber,
						base->houseRoomers[base->sortedBySurname[i]].name,
						base->houseRoomers[base->sortedBySurname[i]].surname,
						base->houseRoomers[base->sortedBySurname[i]].flatNum,
						base->houseRoomers[base->sortedBySurname[i]].age,
						base->houseRoomers[base->sortedBySurname[i]].debt);
					justNumber++;
				}
				justNumber--;
				printf("\n\n");
				printf("-----������� ����� ������ �� ������������� ������-----\n");
				int input = 0;
				scanf("%d", &input);
				if (input <= justNumber && input >= 1){
					//�� ����� ���������� ������ �������������� ���������� ������
					strcpy(base->houseRoomers[base->sortedBySurname[foundIndex + input - 1]].name, base->houseRoomers[base->count - 1].name);
					strcpy(base->houseRoomers[base->sortedBySurname[foundIndex + input - 1]].surname, base->houseRoomers[base->count - 1].surname);
					base->houseRoomers[base->sortedBySurname[foundIndex + input - 1]].flatNum = base->houseRoomers[base->count - 1].flatNum;
					base->houseRoomers[base->sortedBySurname[foundIndex + input - 1]].age = base->houseRoomers[base->count - 1].age;
					base->houseRoomers[base->sortedBySurname[foundIndex + input - 1]].debt = base->houseRoomers[base->count - 1].debt;
					//��������� �� 1 ������ 5 ��������(��������� ������� ����� �����)
					(*base).houseRoomers = (roomer*)realloc((*base).houseRoomers, ((*base).count - 1)*sizeof(roomer));
					(*base).sortedByName = (int*)realloc((*base).sortedByName, ((*base).count - 1)*sizeof(int));
					(*base).sortedBySurname = (int*)realloc((*base).sortedBySurname, ((*base).count - 1)*sizeof(int));
					(*base).sortedByFlatNum = (int*)realloc((*base).sortedByFlatNum, ((*base).count - 1)*sizeof(int));
					(*base).sortedByAge = (int*)realloc((*base).sortedByAge, ((*base).count - 1)*sizeof(int));
					(*base).sortedByDebt = (int*)realloc((*base).sortedByDebt, ((*base).count - 1)*sizeof(int));
					(*base).count--;
					//����� � �������� � ��������� sortedBy �������� ������ ������ ��� �������, ��������� � ������� �� 0 �� ������ count
					for (int i = 0; i < base->count; i++){
						base->sortedByName[i] = i;
						base->sortedBySurname[i] = i;
						base->sortedByFlatNum[i] = i;
						base->sortedByAge[i] = i;
						base->sortedByDebt[i] = i;
					}
					simpleSort(base);
				}
			}
		}
		if (userInput == 3)
		{
			int userFlatNum;
			printf("������� ����� �������� ������ \n");
			scanf("%d", &userFlatNum);
			printf("\n\n*******************���������� ������***********************\n");
			int foundIndex = binSearchFlatNum(userFlatNum, base->houseRoomers, base->sortedByFlatNum, base->count);
			if (foundIndex < 0){
				printf("������ � ����� ������� �������� �� �������\n");
			}
			else{
				int justNumber = 1;
				for (int i = foundIndex; i < base->count && base->houseRoomers[base->sortedByFlatNum[i]].flatNum == userFlatNum; i++)
				{
					printf("\n %d) %s %s ����� ��������: %d �������: %d �������������(���): %d \n", justNumber,
						base->houseRoomers[base->sortedByFlatNum[i]].name,
						base->houseRoomers[base->sortedByFlatNum[i]].surname,
						base->houseRoomers[base->sortedByFlatNum[i]].flatNum,
						base->houseRoomers[base->sortedByFlatNum[i]].age,
						base->houseRoomers[base->sortedByFlatNum[i]].debt);
					justNumber++;
				}
				justNumber--;
				printf("\n\n");
				printf("-----������� ����� ������ �� ������������� ������-----\n");
				int input = 0;
				scanf("%d", &input);
				if (input <= justNumber && input >= 1){
					//�� ����� ���������� ������ �������������� ���������� ������
					strcpy(base->houseRoomers[base->sortedByFlatNum[foundIndex + input - 1]].name, base->houseRoomers[base->count - 1].name);
					strcpy(base->houseRoomers[base->sortedByFlatNum[foundIndex + input - 1]].surname, base->houseRoomers[base->count - 1].surname);
					base->houseRoomers[base->sortedByFlatNum[foundIndex + input - 1]].flatNum = base->houseRoomers[base->count - 1].flatNum;
					base->houseRoomers[base->sortedByFlatNum[foundIndex + input - 1]].age = base->houseRoomers[base->count - 1].age;
					base->houseRoomers[base->sortedByFlatNum[foundIndex + input - 1]].debt = base->houseRoomers[base->count - 1].debt;
					//��������� �� 1 ������ 5 ��������(��������� ������� ����� �����)
					(*base).houseRoomers = (roomer*)realloc((*base).houseRoomers, ((*base).count - 1)*sizeof(roomer));
					(*base).sortedByName = (int*)realloc((*base).sortedByName, ((*base).count - 1)*sizeof(int));
					(*base).sortedBySurname = (int*)realloc((*base).sortedBySurname, ((*base).count - 1)*sizeof(int));
					(*base).sortedByFlatNum = (int*)realloc((*base).sortedByFlatNum, ((*base).count - 1)*sizeof(int));
					(*base).sortedByAge = (int*)realloc((*base).sortedByAge, ((*base).count - 1)*sizeof(int));
					(*base).sortedByDebt = (int*)realloc((*base).sortedByDebt, ((*base).count - 1)*sizeof(int));
					(*base).count--;
					//����� � �������� � ��������� sortedBy �������� ������ ������ ��� �������, ��������� � ������� �� 0 �� ������ count
					for (int i = 0; i < base->count; i++){
						base->sortedByName[i] = i;
						base->sortedBySurname[i] = i;
						base->sortedByFlatNum[i] = i;
						base->sortedByAge[i] = i;
						base->sortedByDebt[i] = i;
					}
					simpleSort(base);
				}
			}
		}
		if (userInput == 4)
		{
			int userAge;
			printf("������� ������� ������ \n");
			scanf("%d", &userAge);
			printf("\n\n*******************���������� ������***********************\n");
			int foundIndex = binSearchAge(userAge, base->houseRoomers, base->sortedByAge, base->count);
			if (foundIndex < 0){
				printf("������ � ����� ��������� �� �������\n");
			}
			else{
				int justNumber = 1;
				for (int i = foundIndex; i < base->count && base->houseRoomers[base->sortedByAge[i]].age == userAge; i++)
				{
					printf("\n %d) %s %s ����� ��������: %d �������: %d �������������(���): %d \n", justNumber,
						base->houseRoomers[base->sortedByAge[i]].name,
						base->houseRoomers[base->sortedByAge[i]].surname,
						base->houseRoomers[base->sortedByAge[i]].flatNum,
						base->houseRoomers[base->sortedByAge[i]].age,
						base->houseRoomers[base->sortedByAge[i]].debt);
					justNumber++;
				}
				justNumber--;
				printf("\n\n");
				printf("-----������� ����� ������ �� ������������� ������-----\n");
				int input = 0;
				scanf("%d", &input);
				if (input <= justNumber && input >= 1){
					//�� ����� ���������� ������ �������������� ���������� ������
					strcpy(base->houseRoomers[base->sortedByAge[foundIndex + input - 1]].name, base->houseRoomers[base->count - 1].name);
					strcpy(base->houseRoomers[base->sortedByAge[foundIndex + input - 1]].surname, base->houseRoomers[base->count - 1].surname);
					base->houseRoomers[base->sortedByAge[foundIndex + input - 1]].flatNum = base->houseRoomers[base->count - 1].flatNum;
					base->houseRoomers[base->sortedByAge[foundIndex + input - 1]].age = base->houseRoomers[base->count - 1].age;
					base->houseRoomers[base->sortedByAge[foundIndex + input - 1]].debt = base->houseRoomers[base->count - 1].debt;
					//��������� �� 1 ������ 5 ��������(��������� ������� ����� �����)
					(*base).houseRoomers = (roomer*)realloc((*base).houseRoomers, ((*base).count - 1)*sizeof(roomer));
					(*base).sortedByName = (int*)realloc((*base).sortedByName, ((*base).count - 1)*sizeof(int));
					(*base).sortedBySurname = (int*)realloc((*base).sortedBySurname, ((*base).count - 1)*sizeof(int));
					(*base).sortedByFlatNum = (int*)realloc((*base).sortedByFlatNum, ((*base).count - 1)*sizeof(int));
					(*base).sortedByAge = (int*)realloc((*base).sortedByAge, ((*base).count - 1)*sizeof(int));
					(*base).sortedByDebt = (int*)realloc((*base).sortedByDebt, ((*base).count - 1)*sizeof(int));
					(*base).count--;
					//����� � �������� � ��������� sortedBy �������� ������ ������ ��� �������, ��������� � ������� �� 0 �� ������ count
					for (int i = 0; i < base->count; i++){
						base->sortedByName[i] = i;
						base->sortedBySurname[i] = i;
						base->sortedByFlatNum[i] = i;
						base->sortedByAge[i] = i;
						base->sortedByDebt[i] = i;
					}
					simpleSort(base);
				}
			}
		}
		if (userInput == 5)
		{
			int userDebt;
			printf("������� ������ ������������� ������(���) \n");
			scanf("%d", &userDebt);
			printf("\n\n*******************���������� ������***********************\n");
			int foundIndex = binSearchDebt(userDebt, base->houseRoomers, base->sortedByDebt, base->count);
			if (foundIndex < 0){
				printf("������ � ����� �������������� �� �������\n");
			}
			else{
				int justNumber = 1;
				for (int i = foundIndex; i < base->count && base->houseRoomers[base->sortedByDebt[i]].debt == userDebt; i++)
				{
					printf("\n %d) %s %s ����� ��������: %d �������: %d �������������(���): %d \n", justNumber,
						base->houseRoomers[base->sortedByDebt[i]].name,
						base->houseRoomers[base->sortedByDebt[i]].surname,
						base->houseRoomers[base->sortedByDebt[i]].flatNum,
						base->houseRoomers[base->sortedByDebt[i]].age,
						base->houseRoomers[base->sortedByDebt[i]].debt);
					justNumber++;
				}
				justNumber--;
				printf("\n\n");
				printf("-----������� ����� ������ �� ������������� ������-----\n");
				int input = 0;
				scanf("%d", &input);
				if (input <= justNumber && input >= 1){
					//�� ����� ���������� ������ �������������� ���������� ������
					strcpy(base->houseRoomers[base->sortedByDebt[foundIndex + input - 1]].name, base->houseRoomers[base->count - 1].name);
					strcpy(base->houseRoomers[base->sortedByDebt[foundIndex + input - 1]].surname, base->houseRoomers[base->count - 1].surname);
					base->houseRoomers[base->sortedByDebt[foundIndex + input - 1]].flatNum = base->houseRoomers[base->count - 1].flatNum;
					base->houseRoomers[base->sortedByDebt[foundIndex + input - 1]].age = base->houseRoomers[base->count - 1].age;
					base->houseRoomers[base->sortedByDebt[foundIndex + input - 1]].debt = base->houseRoomers[base->count - 1].debt;
					//��������� �� 1 ������ 5 ��������(��������� ������� ����� �����)
					(*base).houseRoomers = (roomer*)realloc((*base).houseRoomers, ((*base).count - 1)*sizeof(roomer));
					(*base).sortedByName = (int*)realloc((*base).sortedByName, ((*base).count - 1)*sizeof(int));
					(*base).sortedBySurname = (int*)realloc((*base).sortedBySurname, ((*base).count - 1)*sizeof(int));
					(*base).sortedByFlatNum = (int*)realloc((*base).sortedByFlatNum, ((*base).count - 1)*sizeof(int));
					(*base).sortedByAge = (int*)realloc((*base).sortedByAge, ((*base).count - 1)*sizeof(int));
					(*base).sortedByDebt = (int*)realloc((*base).sortedByDebt, ((*base).count - 1)*sizeof(int));
					(*base).count--;
					//����� � �������� � ��������� sortedBy �������� ������ ������ ��� �������, ��������� � ������� �� 0 �� ������ count
					for (int i = 0; i < base->count; i++){
						base->sortedByName[i] = i;
						base->sortedBySurname[i] = i;
						base->sortedByFlatNum[i] = i;
						base->sortedByAge[i] = i;
						base->sortedByDebt[i] = i;
					}
					simpleSort(base);
				}
			}
		}
	} while (userInput > 0);
}

void setDataFromFile(houseDatabase* base, char* filename){
	FILE* streamIn;
	streamIn = fopen(filename, "r");
	if (streamIn == NULL){
		printf("���� �� ������� �������\n");
		return;
	}
	fseek(streamIn, 0, SEEK_END);
	int filelen = ftell(streamIn);
	fseek(streamIn, 0, SEEK_SET);
	while (ftell(streamIn) < filelen){
		simpleAdd(base);
		fscanf(streamIn, " %s %s %d %d %d", 
			(*base).houseRoomers[base->count - 1].name, 
			(*base).houseRoomers[base->count - 1].surname,
			&((*base).houseRoomers[base->count - 1].flatNum), 
			&((*base).houseRoomers[base->count - 1].age), 
			&((*base).houseRoomers[base->count - 1].debt));
		simpleSort(base);
	}
	fclose(streamIn);
}
void writeBase(houseDatabase* base){
	char filename[maxFilenameLength];
	int userInput = 1;
	printf("\n\n�� ������ �������� ������ ��������� �� ������ ����������� ������?\n"
		"	* 1 - ������������ �� �����\n"
		"	* 2 - ������������ �� �������\n"
		"	* 3 - ������������ �� ������ ��������\n"
		"	* 4 - ������������ �� ��������\n"
		"	* 5 - ������������ �� ������� �������������\n");
	scanf("%d", &userInput);
	printf("������� �������� �����, ���� � ���������� ����� �������� ������\n");
	scanf("%s", filename);
	FILE* streamIn;
	streamIn = fopen(filename, "a");
	if (streamIn == NULL){
		printf("���� �� ������� �������\n");
		return;
	}
	if (userInput == 1){
		fseek(streamIn, 0, SEEK_END);
		int filelen = ftell(streamIn);
		fseek(streamIn, 0, SEEK_SET);
		for (int i = 0; i < (*base).count; i++){
			fprintf(streamIn, "%s %s %d %d %d",
				(*base).houseRoomers[base->sortedByName[i]].name,
				(*base).houseRoomers[base->sortedByName[i]].surname,
				(*base).houseRoomers[base->sortedByName[i]].flatNum,
				(*base).houseRoomers[base->sortedByName[i]].age,
				(*base).houseRoomers[base->sortedByName[i]].debt);
			if (i != (base->count - 1)){
				fprintf(streamIn, "\n");
			}
		}
	}
	if (userInput == 2){
		fseek(streamIn, 0, SEEK_END);
		int filelen = ftell(streamIn);
		fseek(streamIn, 0, SEEK_SET);
		for (int i = 0; i < (*base).count; i++){
			fprintf(streamIn, "%s %s %d %d %d",
				(*base).houseRoomers[base->sortedBySurname[i]].name,
				(*base).houseRoomers[base->sortedBySurname[i]].surname,
				(*base).houseRoomers[base->sortedBySurname[i]].flatNum,
				(*base).houseRoomers[base->sortedBySurname[i]].age,
				(*base).houseRoomers[base->sortedBySurname[i]].debt);
			if (i != (base->count - 1)){
				fprintf(streamIn, "\n");
			}
		}
	}
	if (userInput == 3){
		fseek(streamIn, 0, SEEK_END);
		int filelen = ftell(streamIn);
		fseek(streamIn, 0, SEEK_SET);
		for (int i = 0; i < (*base).count; i++){
			fprintf(streamIn, "%s %s %d %d %d",
				(*base).houseRoomers[base->sortedByFlatNum[i]].name,
				(*base).houseRoomers[base->sortedByFlatNum[i]].surname,
				(*base).houseRoomers[base->sortedByFlatNum[i]].flatNum,
				(*base).houseRoomers[base->sortedByFlatNum[i]].age,
				(*base).houseRoomers[base->sortedByFlatNum[i]].debt);
			if (i != (base->count - 1)){
				fprintf(streamIn, "\n");
			}
		}
	}
	if (userInput == 4){
		fseek(streamIn, 0, SEEK_END);
		int filelen = ftell(streamIn);
		fseek(streamIn, 0, SEEK_SET);
		for (int i = 0; i < (*base).count; i++){
			fprintf(streamIn, "%s %s %d %d %d",
				(*base).houseRoomers[base->sortedByAge[i]].name,
				(*base).houseRoomers[base->sortedByAge[i]].surname,
				(*base).houseRoomers[base->sortedByAge[i]].flatNum,
				(*base).houseRoomers[base->sortedByAge[i]].age,
				(*base).houseRoomers[base->sortedByAge[i]].debt);
			if (i != (base->count - 1)){
				fprintf(streamIn, "\n");
			}
		}
	}
	if (userInput == 5){
		fseek(streamIn, 0, SEEK_END);
		int filelen = ftell(streamIn);
		fseek(streamIn, 0, SEEK_SET);
		for (int i = 0; i < (*base).count; i++){
			fprintf(streamIn, "%s %s %d %d %d",
				(*base).houseRoomers[base->sortedByDebt[i]].name,
				(*base).houseRoomers[base->sortedByDebt[i]].surname,
				(*base).houseRoomers[base->sortedByDebt[i]].flatNum,
				(*base).houseRoomers[base->sortedByDebt[i]].age,
				(*base).houseRoomers[base->sortedByDebt[i]].debt);
			if (i != (base->count - 1)){
				fprintf(streamIn, "\n");
			}
		}
	}
	fclose(streamIn);
}

void searchRoomer(houseDatabase* base){
	int userInput;
	do {
		printf(" ------���� ������ ������ �� ����������------ ");
		printf("\n ������� \n  * 1, ���� �� ������ ��� \n  * 2, ���� ������ ������� \n  * 3, ���� ������ ����� �������� \n  * 4, ���� ������ ������� \n");
		printf("  * 5, ���� ������ ������ �������������\n\n");
		printf("**** ������� ����� ������������� ����� ����� ��� ������ �� ���� ������ ****\n");
		scanf("%d", &userInput);
		if (userInput == 1)    //
		{
			char userName[nameLen];
			printf("������� ��� ������ \n");
			scanf("%s", &userName);
			printf("\n\n*******************���������� ������***********************\n");
			int foundIndex = binSearchName(userName, base->houseRoomers, base->sortedByName, base->count);
			if (foundIndex < 0){
				printf("������ � ����� ������ �� �������\n");
			}
			else{
				int justNumber = 1;
				for (int i = foundIndex; i < base->count && strcmp(base->houseRoomers[base->sortedByName[i]].name, userName) == 0; i++)
				{
					printf("\n %d) %s %s ����� ��������: %d �������: %d  �������������(���) %d\n", justNumber,
						base->houseRoomers[base->sortedByName[i]].name,
						base->houseRoomers[base->sortedByName[i]].surname,
						base->houseRoomers[base->sortedByName[i]].flatNum,
						base->houseRoomers[base->sortedByName[i]].age,
						base->houseRoomers[base->sortedByName[i]].debt);
					justNumber++;
				}
				printf("\n\n");
			}
		}
		if (userInput == 2)
		{
			char userSurname[surnameLen];
			printf("������� ������� ������\n");
			scanf("%s", &userSurname);
			printf("\n\n*******************���������� ������***********************\n");
			int foundIndex = binSearchSurname(userSurname, base->houseRoomers, base->sortedBySurname, base->count);
			if (foundIndex < 0){
				printf("������ � ����� �������� �� �������\n");
			}
			else{
				int justNumber = 1;
				for (int i = foundIndex; i < base->count && strcmp(base->houseRoomers[base->sortedBySurname[i]].surname, userSurname) == 0; i++)
				{
					printf("\n %d) %s %s ����� ��������: %d �������: %d �������������(���) %d \n", justNumber,
						base->houseRoomers[base->sortedBySurname[i]].name,
						base->houseRoomers[base->sortedBySurname[i]].surname,
						base->houseRoomers[base->sortedBySurname[i]].flatNum,
						base->houseRoomers[base->sortedBySurname[i]].age,
						base->houseRoomers[base->sortedBySurname[i]].debt);
					justNumber++;
				}
				printf("\n\n");
			}
		}
		if (userInput == 3)
		{
			int userFlatNum;
			printf("������� ����� �������� ������ \n");
			scanf("%d", &userFlatNum);
				printf("\n\n*******************���������� ������***********************\n");
				int foundIndex = binSearchFlatNum(userFlatNum, base->houseRoomers, base->sortedByFlatNum, base->count);
				if (foundIndex < 0){
					printf("������ � ����� ������� �������� �� �������\n");
				}
				else{
					int justNumber = 1;
					for (int i = foundIndex; i < base->count && base->houseRoomers[base->sortedByFlatNum[i]].flatNum == userFlatNum; i++)
					{
							printf("\n %d) %s %s ����� ��������: %d �������: %d �������������(���) %d \n", justNumber, 
								base->houseRoomers[base->sortedByFlatNum[i]].name,
								base->houseRoomers[base->sortedByFlatNum[i]].surname,
								base->houseRoomers[base->sortedByFlatNum[i]].flatNum,
								base->houseRoomers[base->sortedByFlatNum[i]].age,
								base->houseRoomers[base->sortedByFlatNum[i]].debt);
							justNumber++;
					}
					printf("\n\n");
				}
		}
		if (userInput == 4)
		{
			int userAge;
			printf("������� ������� ������ \n");
			scanf("%d", &userAge);
			printf("\n\n*******************���������� ������***********************\n");
			int foundIndex = binSearchAge(userAge, base->houseRoomers, base->sortedByAge, base->count);
			if (foundIndex < 0){
				printf("������ � ����� ��������� �� �������\n");
			}
			else{
				int justNumber = 1;
				for (int i = foundIndex; i < base->count && base->houseRoomers[base->sortedByAge[i]].age == userAge; i++)
				{
					printf("\n %d) %s %s ����� ��������: %d �������: %d �������������(���) %d \n", justNumber,
						base->houseRoomers[base->sortedByAge[i]].name,
						base->houseRoomers[base->sortedByAge[i]].surname,
						base->houseRoomers[base->sortedByAge[i]].flatNum,
						base->houseRoomers[base->sortedByAge[i]].age,
						base->houseRoomers[base->sortedByAge[i]].debt);
					justNumber++;
				}
				printf("\n\n");
			}
		}
		if (userInput == 5)
		{
			int userDebt;
			printf("������� ������ ������������� ������ \n");
			scanf("%d", &userDebt);
			printf("\n\n*******************���������� ������***********************\n");
			int foundIndex = binSearchDebt(userDebt, base->houseRoomers, base->sortedByDebt, base->count);
			if (foundIndex < 0){
				printf("������ � ����� �������������� �� �������\n");
			}
			else{
				int justNumber = 1;
				for (int i = foundIndex; i < base->count && base->houseRoomers[base->sortedByDebt[i]].debt == userDebt; i++)
				{
					printf("\n %d) %s %s ����� ��������: %d �������: %d �������������(���) %d \n", justNumber,
						base->houseRoomers[base->sortedByDebt[i]].name,
						base->houseRoomers[base->sortedByDebt[i]].surname,
						base->houseRoomers[base->sortedByDebt[i]].flatNum,
						base->houseRoomers[base->sortedByDebt[i]].age,
						base->houseRoomers[base->sortedByDebt[i]].debt);
					justNumber++;
				}
				printf("\n\n");
			}
		}
	} while (userInput > 0);
}
void changeRoomer(houseDatabase* base){
	int userInput;
	do {
		printf(" ------���� �������������� ������ �� ����������------ \n");
		printf("������� ���, �������, ����� �������� ��� ������� ������, ���������� � ������� ������ �������������\n");
		printf("\n ������� \n  * 1, ���� �� ������ ��� \n  * 2, ���� ������ ������� \n  * 3, ���� ������ ����� �������� \n  * 4, ���� ������ ������� \n");
		printf("  * 5, ���� ������ ������ �������������\n\n");
		printf("**** ������� ����� ������������� ����� ����� ��� ������ �� ���� ������ ****\n");
		scanf("%d", &userInput);
		if (userInput == 1)    //
		{
			char userName[nameLen];
			printf("������� ��� ������ \n");
			scanf("%s", &userName);
			printf("\n\n*******************���������� ������***********************\n");
			int foundIndex = binSearchName(userName, base->houseRoomers, base->sortedByName, base->count);
			if (foundIndex < 0){
				printf("������ � ����� ������ �� �������\n");
			}
			else{
				int justNumber = 1;
				for (int i = foundIndex; i < base->count && strcmp(base->houseRoomers[base->sortedByName[i]].name, userName) == 0; i++)
				{
					printf("\n %d) %s %s ����� ��������: %d �������: %d �������������(���): %d \n", justNumber,
						base->houseRoomers[base->sortedByName[i]].name,
						base->houseRoomers[base->sortedByName[i]].surname,
						base->houseRoomers[base->sortedByName[i]].flatNum,
						base->houseRoomers[base->sortedByName[i]].age,
						base->houseRoomers[base->sortedByName[i]].debt);
					justNumber++;
				}
				justNumber--;
				printf("\n\n");
				printf("-----������� ����� ������ �� ������������� ������-----\n");
				int input = 0;
				scanf("%d", &input);
				if (input <= justNumber && input >= 1){
					printf("\n ������� ��� ������ \n");
					scanf("%s", &(base->houseRoomers[base->sortedByName[foundIndex + input - 1]].name));
					printf("\n ������� ������� ������ \n");
					scanf("%s", &(base->houseRoomers[base->sortedByName[foundIndex + input - 1]].surname));
					printf("\n ������� ����� �������� ������\n");
					scanf("%d", &(base->houseRoomers[base->sortedByName[foundIndex + input - 1]].flatNum));
					printf("\n ������� ������� ������ \n");
					scanf("%d", &(base->houseRoomers[base->sortedByName[foundIndex + input - 1]].age));
					printf("\n ������� ������ ������������� ������(���) \n");
					scanf("%d", &(base->houseRoomers[base->sortedByName[foundIndex + input - 1]].debt));
					simpleSort(base);
				}
			}
		}
		if (userInput == 2)
		{
			char userSurname[surnameLen];
			printf("������� ������� ������\n");
			scanf("%s", &userSurname);
			printf("\n\n*******************���������� ������***********************\n");
			int foundIndex = binSearchSurname(userSurname, base->houseRoomers, base->sortedBySurname, base->count);
			if (foundIndex < 0){
				printf("������ � ����� �������� �� �������\n");
			}
			else{
				int justNumber = 1;
				for (int i = foundIndex; i < base->count && strcmp(base->houseRoomers[base->sortedBySurname[i]].surname, userSurname) == 0; i++)
				{
					printf("\n %d) %s %s ����� ��������: %d �������: %d �������������(���): %d \n", justNumber,
						base->houseRoomers[base->sortedBySurname[i]].name,
						base->houseRoomers[base->sortedBySurname[i]].surname,
						base->houseRoomers[base->sortedBySurname[i]].flatNum,
						base->houseRoomers[base->sortedBySurname[i]].age,
						base->houseRoomers[base->sortedBySurname[i]].debt);
					justNumber++;
				}
				justNumber--;
				printf("\n\n");
				printf("-----������� ����� ������ �� ������������� ������-----\n");
				int input = 0;
				scanf("%d", &input);
				if (input <= justNumber && input >= 1){
					printf("\n ������� ��� ������ \n");
					scanf("%s", &(base->houseRoomers[base->sortedBySurname[foundIndex + input - 1]].name));
					printf("\n ������� ������� ������ \n");
					scanf("%s", &(base->houseRoomers[base->sortedBySurname[foundIndex + input - 1]].surname));
					printf("\n ������� ����� �������� ������\n");
					scanf("%d", &(base->houseRoomers[base->sortedBySurname[foundIndex + input - 1]].flatNum));
					printf("\n ������� ������� ������ \n");
					scanf("%d", &(base->houseRoomers[base->sortedBySurname[foundIndex + input - 1]].age));
					printf("\n ������� ������ ������������� ������(���) \n");
					scanf("%d", &(base->houseRoomers[base->sortedBySurname[foundIndex + input - 1]].debt));
					simpleSort(base);
				}
			}
		}
		if (userInput == 3)
		{
			int userFlatNum;
			printf("������� ����� �������� ������ \n");
			scanf("%d", &userFlatNum);
			printf("\n\n*******************���������� ������***********************\n");
			int foundIndex = binSearchFlatNum(userFlatNum, base->houseRoomers, base->sortedByFlatNum, base->count);
			if (foundIndex < 0){
				printf("������ � ����� ������� �������� �� �������\n");
			}
			else{
				int justNumber = 1;
				for (int i = foundIndex; i < base->count && base->houseRoomers[base->sortedByFlatNum[i]].flatNum == userFlatNum; i++)
				{
					printf("\n %d) %s %s ����� ��������: %d �������: %d �������������(���): %d \n", justNumber,
						base->houseRoomers[base->sortedByFlatNum[i]].name,
						base->houseRoomers[base->sortedByFlatNum[i]].surname,
						base->houseRoomers[base->sortedByFlatNum[i]].flatNum,
						base->houseRoomers[base->sortedByFlatNum[i]].age,
						base->houseRoomers[base->sortedByFlatNum[i]].debt);
					justNumber++;
				}
				justNumber--;
				printf("\n\n");
				printf("-----������� ����� ������ �� ������������� ������-----\n");
				int input = 0;
				scanf("%d", &input);
				if (input <= justNumber && input >= 1){
					printf("\n ������� ��� ������ \n");
					scanf("%s", &(base->houseRoomers[base->sortedByFlatNum[foundIndex + input - 1]].name));
					printf("\n ������� ������� ������ \n");
					scanf("%s", &(base->houseRoomers[base->sortedByFlatNum[foundIndex + input - 1]].surname));
					printf("\n ������� ����� �������� ������\n");
					scanf("%d", &(base->houseRoomers[base->sortedByFlatNum[foundIndex + input - 1]].flatNum));
					printf("\n ������� ������� ������ \n");
					scanf("%d", &(base->houseRoomers[base->sortedByFlatNum[foundIndex + input - 1]].age));
					printf("\n ������� ������ ������������� ������ \n");
					scanf("%d", &(base->houseRoomers[base->sortedByFlatNum[foundIndex + input - 1]].debt));
					simpleSort(base);
				}
			}
		}
		if (userInput == 4)
		{
			int userAge;
			printf("������� ������� ������ \n");
			scanf("%d", &userAge);
			printf("\n\n*******************���������� ������***********************\n");
			int foundIndex = binSearchAge(userAge, base->houseRoomers, base->sortedByAge, base->count);
			if (foundIndex < 0){
				printf("������ � ����� ��������� �� �������\n");
			}
			else{
				int justNumber = 1;
				for (int i = foundIndex; i < base->count && base->houseRoomers[base->sortedByAge[i]].age == userAge; i++)
				{
					printf("\n %d) %s %s ����� ��������: %d �������: %d �������������(���): %d \n", justNumber,
						base->houseRoomers[base->sortedByAge[i]].name,
						base->houseRoomers[base->sortedByAge[i]].surname,
						base->houseRoomers[base->sortedByAge[i]].flatNum,
						base->houseRoomers[base->sortedByAge[i]].age,
						base->houseRoomers[base->sortedByAge[i]].debt);
					justNumber++;
				}
				justNumber--;
				printf("\n\n");
				printf("-----������� ����� ������ �� ������������� ������-----\n");
				int input = 0;
				scanf("%d", &input);
				if (input <= justNumber && input >= 1){
					printf("\n ������� ��� ������ \n");
					scanf("%s", &(base->houseRoomers[base->sortedByAge[foundIndex + input - 1]].name));
					printf("\n ������� ������� ������ \n");
					scanf("%s", &(base->houseRoomers[base->sortedByAge[foundIndex + input - 1]].surname));
					printf("\n ������� ����� �������� ������\n");
					scanf("%d", &(base->houseRoomers[base->sortedByAge[foundIndex + input - 1]].flatNum));
					printf("\n ������� ������� ������ \n");
					scanf("%d", &(base->houseRoomers[base->sortedByAge[foundIndex + input - 1]].age));
					printf("\n ������� ������ ������������� ������ \n");
					scanf("%d", &(base->houseRoomers[base->sortedByAge[foundIndex + input - 1]].debt));
					simpleSort(base);
				}
			}
		}
		if (userInput == 5)
		{
			int userDebt;
			printf("������� ������ ������������� ������ \n");
			scanf("%d", &userDebt);
			printf("\n\n*******************���������� ������***********************\n");
			int foundIndex = binSearchDebt(userDebt, base->houseRoomers, base->sortedByDebt, base->count);
			if (foundIndex < 0){
				printf("������ � ����� �������������� �� �������\n");
			}
			else{
				int justNumber = 1;
				for (int i = foundIndex; i < base->count && base->houseRoomers[base->sortedByDebt[i]].debt == userDebt; i++)
				{
					printf("\n %d) %s %s ����� ��������: %d �������: %d �������������(���): %d \n", justNumber,
						base->houseRoomers[base->sortedByDebt[i]].name,
						base->houseRoomers[base->sortedByDebt[i]].surname,
						base->houseRoomers[base->sortedByDebt[i]].flatNum,
						base->houseRoomers[base->sortedByDebt[i]].age,
						base->houseRoomers[base->sortedByDebt[i]].debt);
					justNumber++;
				}
				justNumber--;
				printf("\n\n");
				printf("-----������� ����� ������ �� ������������� ������-----\n");
				int input = 0;
				scanf("%d", &input);
				if (input <= justNumber && input >= 1){
					printf("\n ������� ��� ������ \n");
					scanf("%s", &(base->houseRoomers[base->sortedByDebt[foundIndex + input - 1]].name));
					printf("\n ������� ������� ������ \n");
					scanf("%s", &(base->houseRoomers[base->sortedByDebt[foundIndex + input - 1]].surname));
					printf("\n ������� ����� �������� ������\n");
					scanf("%d", &(base->houseRoomers[base->sortedByDebt[foundIndex + input - 1]].flatNum));
					printf("\n ������� ������� ������ \n");
					scanf("%d", &(base->houseRoomers[base->sortedByDebt[foundIndex + input - 1]].age));
					printf("\n ������� ������ ������������� ������ \n");
					scanf("%d", &(base->houseRoomers[base->sortedByDebt[foundIndex + input - 1]].debt));
					simpleSort(base);
				}
			}
		}
	} while (userInput > 0);
}


void qSortName(roomer* roomers, int* index, int left, int right)
{
	char pivot[nameLen]; // ����������� �������
	int l_hold = left; //����� �������
	int ind_l_hold = index[l_hold];
	int r_hold = right; // ������ �������
	strcpy(pivot, roomers[index[left]].name);
	while (left < right) // ���� ������� �� ���������
	{
		while ((strcmp(roomers[index[right]].name, pivot) >= 0) && (left < right))
			right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			index[left] = index[right]; // ���������� ������� [right] �� ����� ������������
			left++; // �������� ����� ������� ������ 
		}
		while ((strcmp(roomers[index[left]].name, pivot) <= 0) && (left < right))
			left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			index[right] = index[left]; // ���������� ������� [left] �� ����� [right]
			right--; // �������� ������ ������� ������ 
		}
	}
	index[left] = ind_l_hold; // ������ ����������� ������� �� �����
	int rightH = left;
	int leftH = l_hold;
	right = r_hold;
	if (left < rightH) // ���������� �������� ���������� ��� ����� � ������ ����� �������
		qSortName(roomers, index, leftH, rightH - 1);
	if (right > rightH)
		qSortName(roomers, index, rightH + 1, right);
}
void qSortSurname(roomer* roomers, int* index, int left, int right)
{
	char pivot[surnameLen]; // ����������� �������
	int l_hold = left; //����� �������
	int ind_l_hold = index[l_hold];
	int r_hold = right; // ������ �������
	strcpy(pivot, roomers[index[left]].surname);
	while (left < right) // ���� ������� �� ���������
	{
		while ((strcmp(roomers[index[right]].surname, pivot) >= 0) && (left < right))
			right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			index[left] = index[right]; // ���������� ������� [right] �� ����� ������������
			left++; // �������� ����� ������� ������ 
		}
		while ((strcmp(roomers[index[left]].surname, pivot) <= 0) && (left < right))
			left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			index[right] = index[left]; // ���������� ������� [left] �� ����� [right]
			right--; // �������� ������ ������� ������ 
		}
	}
	index[left] = ind_l_hold; // ������ ����������� ������� �� �����
	int rightH = left;
	int leftH = l_hold;
	right = r_hold;
	if (left < rightH) // ���������� �������� ���������� ��� ����� � ������ ����� �������
		qSortSurname(roomers, index, leftH, rightH - 1);
	if (right > rightH)
		qSortSurname(roomers, index, rightH + 1, right);
}
void qSortFlatNum(roomer* roomers, int* index, int left, int right)
{
	int pivot; // ����������� �������
	int l_hold = left; //����� �������
	int ind_l_hold = index[l_hold];
	int r_hold = right; // ������ �������
	pivot = roomers[index[left]].flatNum;
	while (left < right) // ���� ������� �� ���������
	{
		while ((roomers[index[right]].flatNum >= pivot) && (left < right))
			right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			index[left] = index[right]; // ���������� ������� [right] �� ����� ������������
			left++; // �������� ����� ������� ������ 
		}
		while ((roomers[index[left]].flatNum <= pivot) && (left < right))
			left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			index[right] = index[left]; // ���������� ������� [left] �� ����� [right]
			right--; // �������� ������ ������� ������ 
		}
	}
	index[left] = ind_l_hold; // ������ ����������� ������� �� �����
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
		qSortFlatNum(roomers, index, left, pivot - 1);
	if (right > pivot)
		qSortFlatNum(roomers, index, pivot + 1, right);
}
void qSortAge(roomer* roomers, int* index, int left, int right)
{
	int pivot; // ����������� �������
	int l_hold = left; //����� �������
	int ind_l_hold = index[l_hold];
	int r_hold = right; // ������ �������
	pivot = roomers[index[left]].age;
	while (left < right) // ���� ������� �� ���������
	{
		while ((roomers[index[right]].age >= pivot) && (left < right))
			right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			index[left] = index[right]; // ���������� ������� [right] �� ����� ������������
			left++; // �������� ����� ������� ������ 
		}
		while ((roomers[index[left]].age <= pivot) && (left < right))
			left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			index[right] = index[left]; // ���������� ������� [left] �� ����� [right]
			right--; // �������� ������ ������� ������ 
		}
	}
	index[left] = ind_l_hold; // ������ ����������� ������� �� �����
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
		qSortAge(roomers, index, left, pivot - 1);
	if (right > pivot)
		qSortAge(roomers, index, pivot + 1, right);
}
void qSortDebt(roomer* roomers, int* index, int left, int right)
{
	int pivot; // ����������� �������
	int l_hold = left; //����� �������
	int ind_l_hold = index[l_hold];
	int r_hold = right; // ������ �������
	pivot = roomers[index[left]].debt;
	while (left < right) // ���� ������� �� ���������
	{
		while ((roomers[index[right]].debt >= pivot) && (left < right))
			right--; // �������� ������ ������� ���� ������� [right] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			index[left] = index[right]; // ���������� ������� [right] �� ����� ������������
			left++; // �������� ����� ������� ������ 
		}
		while ((roomers[index[left]].debt <= pivot) && (left < right))
			left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
		if (left != right) // ���� ������� �� ����������
		{
			index[right] = index[left]; // ���������� ������� [left] �� ����� [right]
			right--; // �������� ������ ������� ������ 
		}
	}
	index[left] = ind_l_hold; // ������ ����������� ������� �� �����
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
		qSortDebt(roomers, index, left, pivot - 1);
	if (right > pivot)
		qSortDebt(roomers, index, pivot + 1, right);
}

void simpleAdd(houseDatabase* base){
	(*base).houseRoomers = (roomer*)realloc((*base).houseRoomers, ((*base).count + 1)*sizeof(roomer));
	(*base).sortedByName = (int*)realloc((*base).sortedByName, ((*base).count + 1)*sizeof(int));
	(*base).sortedBySurname = (int*)realloc((*base).sortedBySurname, ((*base).count + 1)*sizeof(int));
	(*base).sortedByFlatNum = (int*)realloc((*base).sortedByFlatNum, ((*base).count + 1)*sizeof(int));
	(*base).sortedByAge = (int*)realloc((*base).sortedByAge, ((*base).count + 1)*sizeof(int));
	(*base).sortedByDebt = (int*)realloc((*base).sortedByDebt, ((*base).count + 1)*sizeof(int));
	(*base).count++;
	base->sortedByName[base->count - 1] = base->count - 1;
	base->sortedBySurname[base->count - 1] = base->count - 1;
	base->sortedByFlatNum[base->count - 1] = base->count - 1;
	base->sortedByAge[base->count - 1] = base->count - 1;
	base->sortedByDebt[base->count - 1] = base->count - 1;
}
void simpleSort(houseDatabase* base){
	qSortName(base->houseRoomers, base->sortedByName, 0, base->count - 1);
	qSortSurname(base->houseRoomers, base->sortedBySurname, 0, base->count - 1);
	qSortFlatNum(base->houseRoomers, base->sortedByFlatNum, 0, base->count - 1);
	qSortAge(base->houseRoomers, base->sortedByAge, 0, base->count - 1);
	qSortDebt(base->houseRoomers, base->sortedByDebt, 0, base->count - 1);
}

int binSearchName(char* val, roomer* houseRoomers, int* arrInd, int count){
	int left = 0, right = count - 1, mid = (count - 1) / 2;
	while (left < right){
		mid = (left + right) / 2;
		if (strcmp(houseRoomers[arrInd[left]].name, val) == 0)
			return left;
		if (strcmp(houseRoomers[arrInd[mid]].name, val) == 0)
		{
			if (mid == left + 1)
				return mid;
			else
				right = mid + 1;
		}
		else{
			if (strcmp(houseRoomers[arrInd[mid]].name, val) > 0){
				right = mid;
			}
			else{
				left = mid + 1;
			}
		}
	}
	if (strcmp(houseRoomers[arrInd[left]].name, val) == 0){
		return left;
	}
	return -1;
}
int binSearchSurname(char* val, roomer* houseRoomers, int* arrInd, int count){
	int left = 0, right = count - 1, mid = (count - 1) / 2;
	while (left < right){
		mid = (left + right) / 2;
		if (strcmp(houseRoomers[arrInd[left]].surname, val) == 0)
			return left;
		if (strcmp(houseRoomers[arrInd[mid]].surname, val) == 0)
		{
			if (mid == left + 1)
				return mid;
			else
				right = mid + 1;
		}
		else{
			if (strcmp(houseRoomers[arrInd[mid]].surname, val) > 0){
				right = mid;
			}
			else{
				left = mid + 1;
			}
		}
	}
	if (strcmp(houseRoomers[arrInd[left]].surname, val) == 0){
		return left;
	}
	return -1;
}
int binSearchFlatNum(int val, roomer* houseRoomers, int* arrInd, int count){
	int left = 0, right = count - 1, mid = (count - 1) / 2;
	while (left < right){
		mid = (left + right) / 2;
		if (houseRoomers[arrInd[left]].flatNum == val)
			return left;
		if (houseRoomers[arrInd[mid]].flatNum == val)
		{
			if (mid == left + 1)
				return mid;
			else
				right = mid + 1;
		}
		else{
			if (houseRoomers[arrInd[mid]].flatNum > val){
				right = mid;
			}
			else{
				left = mid + 1;
			}
		}
	}
	if (houseRoomers[arrInd[left]].flatNum == val){
		return left;
	}
	return -1;
}
int binSearchAge(int val, roomer* houseRoomers, int* arrInd, int count){
	int left = 0, right = count - 1, mid = (count - 1) / 2;
	while (left < right){
		mid = (left + right) / 2;
		if (houseRoomers[arrInd[left]].age == val)
			return left;
		if (houseRoomers[arrInd[mid]].age == val)
		{
			if (mid == left + 1)
				return mid;
			else
				right = mid + 1;
		}
		else{
			if (houseRoomers[arrInd[mid]].age > val){
				right = mid;
			}
			else{
				left = mid + 1;
			}
		}
	}
	if (houseRoomers[arrInd[left]].age == val){
		return left;
	}
	return -1;
}
int binSearchDebt(int val, roomer* houseRoomers, int* arrInd, int count){
	int left = 0, right = count - 1, mid = (count - 1) / 2;
	while (left < right){
		mid = (left + right) / 2;
		if (houseRoomers[arrInd[left]].debt == val)
			return left;
		if (houseRoomers[arrInd[mid]].debt == val)
		{
			if (mid == left + 1)
				return mid;
			else
				right = mid + 1;
		}
		else{
			if (houseRoomers[arrInd[mid]].debt > val){
				right = mid;
			}
			else{
				left = mid + 1;
			}
		}
	}
	if (houseRoomers[arrInd[left]].debt == val){
		return left;
	}
	return -1;
}

