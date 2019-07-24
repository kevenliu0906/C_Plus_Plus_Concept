#include "stdafx.h"
#include "TestA_CS.h"


int Compare_Fn(TestA_CS  A_cs, TestA_CS  B_cs)
{
	if (A_cs.X_i > B_cs.X_i)
		return 1;
	else if (A_cs.X_i == B_cs.X_i)
		return 0;
	else
		return (2);
}

//--> 非const靜態資料成員要在類別定義外初始化
double TestA_CS::PI = 3.14159;
//const double  TestA_CS::PI = 3.14159;

//-------------------------------------------------------
TestA_CS::TestA_CS(int tempX_i, int tempY_i):Test_d(3)  // const成員直接在建構式中初始化(注意語法)
{
	X_i = tempX_i;
	Y_i = tempY_i;
}
//-------------------------------------------------------
double TestA_CS::Circle_Area_Fn(double tempRadius_d)
{
	// TestA_i++;      // compiler error(static函式只能存取static成員)
	return (PI*tempRadius_d*tempRadius_d);
}
//-------------------------------------------------------
void TestA_CS::Change_TestValue_Fn()
{
	//Test_d = 10;  // compiler error(const成員無法再修改)
}
//-------------------------------------------------------
void TestA_CS::Change_StaticValue_Fn(double Value_d)
{
	PI = Value_d;
}
//-------------------------------------------------------