// FP_HW_29_Svyrydov.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "Task_1.h"
#include "Task_2.h"

using namespace std;

#define Task 2

int main()
{
#if Task == 1
	Task1();
#elif Task == 2
	Task2();
#endif

}