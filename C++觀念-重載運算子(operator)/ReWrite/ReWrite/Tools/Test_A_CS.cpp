#include "stdafx.h"
#include "Test_A_CS.h"

//-----------------------------------------------------
TestA_CS::TestA_CS()
{
	x_i = 0;
	y_i = 0;
}
//-----------------------------------------------------
TestA_CS::TestA_CS(int _x_i, int _y_i)
{
	x_i = _x_i;
	y_i = _y_i;
}
//-----------------------------------------------------
TestA_CS TestA_CS::operator=(TestA_CS &tempA_cs)
// re-write the operator =
{
	x_i = tempA_cs.x_i;
	y_i = tempA_cs.y_i;

	return (*this);
}
//-----------------------------------------------------
bool TestA_CS::operator==(TestA_CS &tempA_cs)
// re-write the operator ==
{
	if (x_i != tempA_cs.x_i)
		return false;
	if (y_i != tempA_cs.y_i)
		return false;
	return true;
}
//-----------------------------------------------------
TestA_CS TestA_CS::operator + (TestA_CS &temp_A_cs)
// 更+笲衡
{
	TestA_CS   Add_cs(x_i + temp_A_cs.x_i, y_i + temp_A_cs.y_i);

	return (Add_cs);
}
//-----------------------------------------------------
int TestA_CS::Get_X_Value_Fn()
{
	return (x_i);
}
//-----------------------------------------------------
int TestA_CS::Get_Y_Value_Fn()
{
	return (y_i);
}
//-----------------------------------------------------
TestA_CS TestA_CS::operator ++()
//更++玡竚ㄒ++p;
{
	x_i++;
	y_i++;

	return (*this);
}
//-----------------------------------------------------
TestA_CS TestA_CS::operator ++(int)
//更++竚ㄒp++
{
	TestA_CS  tempA_cs(x_i, y_i);

	x_i++;
	y_i++;

	return (tempA_cs);
}
//-----------------------------------------------------
TestA_CS TestA_CS::operator --()
// 更--玡竚ㄒ--p;
{
	x_i--;
	y_i--;

	return (*this);
}
//-----------------------------------------------------
TestA_CS TestA_CS::operator --(int)
// 更--竚ㄒp--;
{
	TestA_CS   tempA_cs(x_i, y_i);

	x_i--;
	y_i--;

	return (tempA_cs);
}
//-----------------------------------------------------