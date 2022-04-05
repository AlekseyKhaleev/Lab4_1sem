/* Описание "самописных" математических функций */

#include "definitions.h"
#include "my_math.h"
#include <iostream>
#include <math.h>

/* Модуль числа */
double Abs(double x) {
	if (x >= 0) return x;
	else {
		return -x;
	}
}

/* Факториал (до 20 включительно)*/
long long Fact(int x) {
	try {
		if (x > 20) throw -1;
		if (x == 0) return 1;
		else {
			return x * Fact(x - 1);
		}
	}
	catch (int)
	{
		std::cout << "Factorial is overgrow" << std::endl;
		system("pause");
		exit(1);
	}
}

/* Квадратный корень*/
double Sqrt2(double a, int n)
{
	if (n == 0)
		return 0.5 * (1 + a);

	double x = Sqrt2(a, n - 1);
	return 0.5 * (x + a / x);
}

/* Возведение вещественого числа в натуральную степень*/
double PwrNat(double x, int n) { 
	double res = x;
	for (int i = 1; i < n; i++) {
		res *= x;
	}
	return res;
}

/* Синус числа */
double SinRad(double x)
{
	double sina, cosa;
	SinCosByTable(x, &sina, &cosa);
	return sina;
}

/* Косинус числа*/
double CosRad(double x)
{
	double sina, cosa;
	SinCosByTable(x, &sina, &cosa);
	return cosa;
}

/* Тангенс числа*/
double TanRad(double x)
{
	double sina, cosa;
	SinCosByTable(x, &sina, &cosa);
	return sina / cosa;
}

/* Котангенс числа */
double CtgRad(double x)
{
	double sina, cosa;
	SinCosByTable(x, &sina, &cosa);
	return cosa / sina;
}

/* Получение значения синуса и косинуса числа интерполяцией табличных значений
* с использованием многочленов небольших степеней*/
void SinCosByTable(double x, double* sina, double* cosa)
{
	x *= 0.63661977236758134308; // 2/Pi
	int sign = x < 0.0;
	x = sign ? -x : x;
	int xf = (int)x;
	x -= xf;
	int rev = xf & 1;
	if (rev)
		x = 1 - x;
	int per = (xf >> 1) & 1;

	double z = x * 128;
	int zf = (int)z;
	z -= zf;

	double sint = sincostable[zf];
	double cost = sincostable[128 - zf];

	double zz = z * z;
	double ss = z * (0.012271846303085128928 + zz * (-3.0801968454884792651e-7 +
		2.3193461291439683491e-12 * zz));
	double cc = 1.0 - zz * (0.000075299105843272081 + zz * (-9.449925567834354484e-10 +
		4.7437807891647010749e-15 * zz));

	*sina = (sign ^ per) ? -sint * cc - cost * ss : sint * cc + cost * ss;
	*cosa = (rev ^ per) ? sint * ss - cost * cc : cost * cc - sint * ss;
}

/* Арксинус числа*/
double ASinRad(double x) {
	try {
		if (Abs(x) > 1) throw - 1;
		else {
			return ATanRad(x / Sqrt2(1 - PwrNat(x, 2)));
		}
	}
	catch (int)
	{
		std::cerr << "Argument of ASinRad is out of range!" << std::endl;
		system("pause");
		exit(1);
	}
}

/* Арккосинус числа */
double ACosRad(double x) {
	try {
		if (Abs(x) > 1) throw - 1;
		else {
			return MYPI/2 - ASinRad(x);
		}
	}
	catch (int)
	{
		std::cerr << "Argument of ACosRad is out of range!" << std::endl;
		system("pause");
		exit(1);
	}
}

/* Арктангенс числа перебором */
double ATanRad(double x) {
	double res = 0;
	for (double n = -MYPI/2 + 0.0000001; n < MYPI / 2; n+= 0.0000001) {
		double t = TanRad(n);
		if (long long(x * 10000000) == long long(t * 10000000)) return n;
	}
	return 0;

}

/* Перегруженная функция для арктангенса числа без перебора (работает быстрее) */
double ATanRad(float x) {
	int sta = 0, sp = 0;
	float x2, a;
	if (x < 0.F) { x = -x; sta |= 1; }
	if (x > 1.F) { x = 1.F / x; sta |= 2; }
	while (x > MYPI_12) {
		sp++; a = x + SQRT_3; a = 1.F / a; x *= SQRT_3; x -= 1.F; x *= a;
	}
	x2 = x * x; a = x2 + 1.4087812F; a = 0.55913709F / a; a += 0.60310579F;
	a -= 0.05160454F * x2; a *= x;
	while (sp > 0) { a += MYPI_6; sp--; }
	if (sta & 2) a = MYPI_2 - a;
	if (sta & 1) a = -a;
	return(a);
}

/* Арккотангенс числа */
double ACtgRad(double x) {
	return ACosRad(x/ Sqrt2(1 + PwrNat(x, 2)));
}
