#ifndef HOUSEDATABASE_H
#define HOUSEDATABASE_H
#include <conio.h>
#include "stdafx.h"
#include <locale.h>
#include <malloc.h>
//#include "roomer.h"
#define nameLen 40
#define surnameLen 40
typedef struct{     //создаём структуру жильца квартиры
	char name[nameLen];        //имя жильца
	char surname[surnameLen];  // фамилия
	int flatNum;               //номер его квартиры
	int age;			       // его возраст
	int debt;				   //задолженность по квартплате
}roomer;
typedef struct{
	int houseNum; //номер дома
	roomer *houseRoomers; //указатель на массив структур типа roomer - по сути сама база данных
	int count; //количество человек, находящихся в базе данных
	int* sortedByName;
	int* sortedBySurname;
	int* sortedByFlatNum;
	int* sortedByAge;
	int* sortedByDebt;
}houseDatabase;
void setData(houseDatabase*); //функция инициализирует переменные экземпляра структуры database
void setDataFromFile(houseDatabase*, char*); //функция инициализирует базу данными из файла(второй аргумент - путь файла)
void printAllRoomers(houseDatabase*);   //фукнция для вывода всех жильцов на экран 
void addRoomer(houseDatabase*);   //функция добавляет нового жильца в базу данных
void deleteRoomer(houseDatabase*); //функция удаляет жильца, производится поиск по знаяению поля

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void searchRoomer(houseDatabase*);  //функция для поиска жильцов по значению поля
void changeRoomer(houseDatabase*);    //функция выполняет редактирование информации о жильце
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void writeBase(houseDatabase*); //функция записывает базу данных в файл
void searchRoomerNew(houseDatabase* base);
void changeRoomerNew(houseDatabase* base);
//Сортировка соответствующих массивов индексов по значению различных полей
void qSortName(roomer* roomers, int* index, int left, int right); 
void qSortSurname(roomer* roomers, int* index, int left, int right);
void qSortFlatNum(roomer* roomers, int* index, int left, int right); 
void qSortAge(roomer* roomers, int* index, int left, int right);
void qSortDebt(roomer* roomers, int* index, int left, int right);
//Вывод базы на экран(отсортированной по имени, фамилии, номеру квартиры, возрасту)
void printSortedByName(houseDatabase* base);
void printSortedBySurname(houseDatabase* base);
void printSortedByFlatNum(houseDatabase* base);
void printSortedByAge(houseDatabase* base);
void printSortedByDebt(houseDatabase* base);
//функции поиска для соответствующих полей(имя, фамилия, номер квартиры, возраст, задолженность)
int binSearchName(char* val, roomer* houseRoomers, int* arrInd, int count);
int binSearchSurname(char* val, roomer* houseRoomers, int* arrInd, int count);
int binSearchFlatNum(int val, roomer* houseRoomers, int* arrInd, int count);
int binSearchAge(int val, roomer* houseRoomers, int* arrInd, int count);
int binSearchDebt(int val, roomer* houseRoomers, int* arrInd, int count);
void simpleAdd(houseDatabase*); //добавление нового элемента в массив houseRoomers и в массивы индексов
void simpleSort(houseDatabase*); //сортировка всех массивов индексов
#endif