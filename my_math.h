/* Прототипы "самописных" математических функций, описанных в my_math.cpp */
#pragma once

double Abs(double x);
double Sqrt2(double a, int n=10);
long long Fact(int x);
double PwrNat(double x, int n);
double SinRad(double x);
double CosRad(double x);
double TanRad(double x);
double CtgRad(double x);
void SinCosByTable(double x, double* sina, double* cosa);
double ASinRad(double x);
double ACosRad(double x);
double ATanRad(double x);
double ATanRad(float x);
double ACtgRad(double x);
