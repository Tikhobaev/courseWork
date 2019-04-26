#ifndef HOUSEDATABASE_H
#define HOUSEDATABASE_H
#include <conio.h>
#include "stdafx.h"
#include <locale.h>
#include <malloc.h>
//#include "roomer.h"
#define nameLen 40
#define surnameLen 40
typedef struct{     //������ ��������� ������ ��������
	char name[nameLen];        //��� ������
	char surname[surnameLen];  // �������
	int flatNum;               //����� ��� ��������
	int age;			       // ��� �������
	int debt;				   //������������� �� ����������
}roomer;
typedef struct{
	int houseNum; //����� ����
	roomer *houseRoomers; //��������� �� ������ �������� ���� roomer - �� ���� ���� ���� ������
	int count; //���������� �������, ����������� � ���� ������
	int* sortedByName;
	int* sortedBySurname;
	int* sortedByFlatNum;
	int* sortedByAge;
	int* sortedByDebt;
}houseDatabase;
void setData(houseDatabase*); //������� �������������� ���������� ���������� ��������� database
void setDataFromFile(houseDatabase*, char*); //������� �������������� ���� ������� �� �����(������ �������� - ���� �����)
void printAllRoomers(houseDatabase*);   //������� ��� ������ ���� ������� �� ����� 
void addRoomer(houseDatabase*);   //������� ��������� ������ ������ � ���� ������
void deleteRoomer(houseDatabase*); //������� ������� ������, ������������ ����� �� �������� ����

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void searchRoomer(houseDatabase*);  //������� ��� ������ ������� �� �������� ����
void changeRoomer(houseDatabase*);    //������� ��������� �������������� ���������� � ������
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void writeBase(houseDatabase*); //������� ���������� ���� ������ � ����
void searchRoomerNew(houseDatabase* base);
void changeRoomerNew(houseDatabase* base);
//���������� ��������������� �������� �������� �� �������� ��������� �����
void qSortName(roomer* roomers, int* index, int left, int right); 
void qSortSurname(roomer* roomers, int* index, int left, int right);
void qSortFlatNum(roomer* roomers, int* index, int left, int right); 
void qSortAge(roomer* roomers, int* index, int left, int right);
void qSortDebt(roomer* roomers, int* index, int left, int right);
//����� ���� �� �����(��������������� �� �����, �������, ������ ��������, ��������)
void printSortedByName(houseDatabase* base);
void printSortedBySurname(houseDatabase* base);
void printSortedByFlatNum(houseDatabase* base);
void printSortedByAge(houseDatabase* base);
void printSortedByDebt(houseDatabase* base);
//������� ������ ��� ��������������� �����(���, �������, ����� ��������, �������, �������������)
int binSearchName(char* val, roomer* houseRoomers, int* arrInd, int count);
int binSearchSurname(char* val, roomer* houseRoomers, int* arrInd, int count);
int binSearchFlatNum(int val, roomer* houseRoomers, int* arrInd, int count);
int binSearchAge(int val, roomer* houseRoomers, int* arrInd, int count);
int binSearchDebt(int val, roomer* houseRoomers, int* arrInd, int count);
void simpleAdd(houseDatabase*); //���������� ������ �������� � ������ houseRoomers � � ������� ��������
void simpleSort(houseDatabase*); //���������� ���� �������� ��������
#endif