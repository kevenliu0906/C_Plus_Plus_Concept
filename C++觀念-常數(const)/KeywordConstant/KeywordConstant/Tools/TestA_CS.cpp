#include "stdafx.h"
#include "TestA_CS.h"

//-----------------------------------------------------------------------
TestA_CS::TestA_CS():Y_Const_i(100)  // 宣告const的成員變數，此變數是常量(const成員變數僅能在建構函式初始化)
{
	X_i = 0;
	Z_i = 10;
}
//-----------------------------------------------------------------------
TestA_CS::TestA_CS(int tempX_i, int tempZ_i):Y_Const_i(100) // 宣告const的成員變數，此變數是常量(const成員變數僅能在建構函式初始化)
{
	X_i = tempX_i;
	Z_i = tempZ_i;
}
//-----------------------------------------------------------------------
int TestA_CS::Get_X_Value_Fn() const
{
	// ---- 在函式後方加入const的用意是告知這個函式並不會變動到類別成員的數值
	// ---- 這個函式僅僅是獲取類別內的成員數值，所以不會變更到各個成員數值
	// reference: https://openhome.cc/Gossip/CppGossip/constAndmuttable.html
	
	//X_i++;       // compiler error，因為已經告知這個函式是const的函式，所以不會變動到函式成員的數值
	return (X_i);
}
//-----------------------------------------------------------------------
void TestA_CS::Set_X_Value_Fn(int setValue_X_i)
{
	X_i = setValue_X_i;
}
//-----------------------------------------------------------------------
bool TestA_CS::FindNum_Fn(const int Array_i_ay[], int FindNumber_i, int ArraySize_i)
{
	//----- Initial...
	bool   Find_fg = false;

	//-----------------------------------

	//----- 為了防止傳遞的函式參數被修改，在調用函式的參數中用const關鍵字
	//----- 這個例子因為是傳遞陣列，所以參數是指標型式在傳遞
	// reference: https://lalalah.pixnet.net/blog/post/31677924 的 A 案例

	for (int i_i = 0; i_i < ArraySize_i; i_i++)
	{
		if (Array_i_ay[i_i] == FindNumber_i)
		{
			Find_fg = true;
			//Array_i_ay[i_i] = -1;  // compiler error, Array_i_ay[] is a const parameter and can't change
			break;
		}
	}


	return (Find_fg);
}
//-----------------------------------------------------------------------
const int TestA_CS::Get_Y_Const_Value_Fn()
{
	//Y_Const_i++;    // compiler error, can NOT change value of the const variable

	return (Y_Const_i);
}
//-----------------------------------------------------------------------
const int& TestA_CS::Get_Z_Value_Fn() const
{
	// 宣告const函式，目的在於通知此函式不會變更到類別成員的數值
	// 因為是 "回傳成員的參考數值" ，呼叫方的接收回傳的變數可以直接更改回傳值
	// 為了保證不會變更到類別成員的數值，所以函式前方還需要加上const表示接收的變數是一常數
	//
	// reference: https://openhome.cc/Gossip/CppGossip/constAndmuttable.html

	return (Z_i);
}
//-----------------------------------------------------------------------