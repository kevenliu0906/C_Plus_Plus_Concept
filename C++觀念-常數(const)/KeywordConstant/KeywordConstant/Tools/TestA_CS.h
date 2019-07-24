#pragma once

class TestA_CS
{
public:
	TestA_CS();
	TestA_CS(int tempX_i, int tempZ_i);

	void   Set_X_Value_Fn(int setValue_X_i);

	const int    Get_Y_Const_Value_Fn();

	// 宣告const函式，目的在於通知此函式不會變更到類別成員的數值
	int    Get_X_Value_Fn() const;

	// 宣告const函式，目的在於通知此函式不會變更到類別成員的數值
	// 因為是 "回傳成員的參考數值" ，接收回傳的變數可以直接更改回傳值
	// 為了保證不會變更到類別成員的數值，所以函式前方還需要加上const表示接收的變數是一常數
	// reference: https://openhome.cc/Gossip/CppGossip/constAndmuttable.html
	const int&    Get_Z_Value_Fn() const;

	// 為防止傳遞的參數被修改，在調用函式的參數中用const關鍵字(第一個參數是接收陣列，可以視為指標變數)
	bool   FindNum_Fn(const int Array_i_ay[], int FindNumber_i, int ArraySize_i);

protected:
	int    X_i;
	int    Z_i;
	// 宣告const的成員變數，此變數是常量
	const  int    Y_Const_i;
};
