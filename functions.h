/* Прототипы функций, описанных в functions.cpp */
#pragma once
#include "definitions.h"

int GetXRange(double a, double b, double h);
double Fx(double x);
void InitFxTable(double** Arr, int rows, double a, double h);
double FxTableMax(double** Arr, int rows);
void PrintFxTable(double** Arr, int rows);
int Menu();
void CorrectInit(double& x);
void HandInput(double& a, double& b, double& h);
void RandomInput(double& a, double& b, double& h);
int MyRand();
void __cdecl new_error();
