#include "stdafx.h"
#include "Circle_CS.h"

double Circle_CS::PI = 3.14159;

int   Compare_Fn(Circle_CS &A_Circle_cs, Circle_CS &B_Circle_cs)
{
	if (A_Circle_cs.Radius_d > B_Circle_cs.Radius_d)
		return (1);
	else if (A_Circle_cs.Radius_d == B_Circle_cs.Radius_d)
		return (0);
	else
		return (-1);
}

//--------------------------------------------------------------------
//--------------------------------------------------------------------
Circle_CS::Circle_CS()
{
	Radius_d = 0;
}
//--------------------------------------------------------------------
Circle_CS::Circle_CS(double tempR_d)
{
	Radius_d = tempR_d;
}
//--------------------------------------------------------------------
void Circle_CS::Set_Radius_Fn(double radius_d)
{
	Radius_d = radius_d;
}
//--------------------------------------------------------------------
double Circle_CS::Get_Radius_Fn()
{
	return (Radius_d);
}
//--------------------------------------------------------------------
double Circle_CS::Get_Area_Fn()
{
	return (PI*Radius_d*Radius_d);
}
//--------------------------------------------------------------------
