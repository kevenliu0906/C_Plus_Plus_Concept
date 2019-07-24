#pragma once

//--> 將運算子重載
// 在C++中，預設除了基本資料型態可以使用運算子進行運算，例如int、double、char等，如果您要將兩個物件相加，預設上是不行
// 然而在很多情形下，您會想要將兩個物件的某些屬性值相加，並傳回運算後的結果，例如座標相加，
// 在C++中，這可以透過重載運算子來達到目的
// reference: http://monkeycoding.com/?p=930
// reference: https://openhome.cc/Gossip/CppGossip/OverloadOperator.html

class TestA_CS
{
public:
	TestA_CS();
	TestA_CS(int _x_i, int _y_i);
	TestA_CS operator =(TestA_CS &temp_A_cs);    // re-write the operator =
	bool operator ==(TestA_CS &temp_A_cs);       // re-write the operator ==
	TestA_CS operator + (TestA_CS &temp_A_cs);   // 重載+運算子
	int Get_X_Value_Fn();
	int Get_Y_Value_Fn();
	TestA_CS operator ++();        // 重載++前置，例如++p;
	TestA_CS operator ++(int);     // 重載++後置，例如p++;
	TestA_CS operator --();        // 重載--前置，例如--p;
	TestA_CS operator --(int);     // 重載--後置，例如p--;
	friend TestA_CS operator +(TestA_CS &temp_A_cs, int Num_i);   //使用friend函式來重載運算子
	friend TestA_CS operator +(int Num_i, TestA_CS &temp_A_cs);   //使用friend函式來重載運算子

protected:
	int x_i;
	int y_i;
};
