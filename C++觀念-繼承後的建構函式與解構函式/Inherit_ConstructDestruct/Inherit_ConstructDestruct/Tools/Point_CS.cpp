#include "stdafx.h"
#include "Point_CS.h"

//---------------------------------------------------------------
Point2D_CS::Point2D_CS()
{
	MessageBox(NULL, _T("Point2D_CS::Point2D_CS()"), _T("Point2D_CS"), MB_OK);
	X_i = 0;
	Y_i = 0;
}
//---------------------------------------------------------------
Point2D_CS::Point2D_CS(int tempX_i, int tempY_i):X_i(tempX_i), Y_i(tempY_i)
{
	MessageBox(NULL, _T("Point2D_CS::Point2D_CS(int, int)"), _T("Point2D_CS"), MB_OK);
}
//---------------------------------------------------------------
Point2D_CS::~Point2D_CS()
{
	MessageBox(NULL, _T("Point2D_CS::~Point2D_CS()"), _T("Point2D_CS"), MB_OK);
}
//---------------------------------------------------------------
void Point2D_CS::Set_X_Fn(int tempX_i)
{
	X_i = tempX_i;
}
//---------------------------------------------------------------
void Point2D_CS::Set_Y_Fn(int tempY_i)
{
	Y_i = tempY_i;
}
//---------------------------------------------------------------
int Point2D_CS::Get_X_Fn()
{
	return (X_i);
}
//---------------------------------------------------------------
int Point2D_CS::Get_Y_Fn()
{
	return (Y_i);
}
//---------------------------------------------------------------
//---------------------------------------------------------------
//---------------------------------------------------------------
Point3D_CS::Point3D_CS() 
{
	MessageBox(NULL, _T("Point3D_CS::Point3D_CS()"), _T("Point3D_CS"), MB_OK);
	Z_i = 0;
}
//---------------------------------------------------------------
Point3D_CS::Point3D_CS(int tempX_i, int tempY_i, int tempZ_i) :Point2D_CS(tempX_i, tempY_i), Z_i(tempZ_i)
//建構函式，同時指定呼叫父類別建構函式
{
	//Point2D_CS(tempX_i, tempY_i);
	//Z_i = tempZ_i;
	MessageBox(NULL, _T("Point3D_CS::Point3D_CS(int, int, int)"), _T("Point3D_CS"), MB_OK);
}
//---------------------------------------------------------------
Point3D_CS::~Point3D_CS()
{
	MessageBox(NULL, _T("Point3D_CS::~Point3D_CS()"), _T("Point3D_CS"), MB_OK);
}
//---------------------------------------------------------------
void Point3D_CS::Set_Z_Fn(int tempZ_i)
{
	Z_i = tempZ_i;
}
//---------------------------------------------------------------
int Point3D_CS::Get_Z_Fn()
{
	return (Z_i);
}
//---------------------------------------------------------------