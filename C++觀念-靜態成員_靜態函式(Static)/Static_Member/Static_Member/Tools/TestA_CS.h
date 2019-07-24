#pragma once

//--> 靜態成員、靜態函式(static)

// =========== 靜態成員 =============
// 相同類別所產生的物件，擁有各自的成員變數
// 但對於所有的物件需要共有一個成員變數就用static，
// "靜態成員是屬於類別所擁有" ，而不是個別的物件。你可以將靜態成員視為每個物件實例所共享的資料成員。
// 靜態成員有以下幾個特性：
// 1. 靜態成員屬於類別，而不屬於個別的物件
// 2. 非const的static成員要在類別定義區塊之外初始化
// 3. 可以用物件實例的名稱，或是類別名稱加上::運算子來存取，通常使用類別名稱加上::運算子來存取，
//    一方面也可以避免與非靜態資料成員混淆
// 4. 靜態成員同樣遵守public、protected、private的存取限制。

// =========== 靜態函式 =============
// 將函式加上關鍵字static，就可將函式設為靜態函式，靜態函式通常是作為 "工作函式"
// 靜態函式同樣可以透過類別名稱來呼叫，由於靜態成員是屬於類別而不是物件，
// 所以呼叫 "靜態函式" 時，並 "不會傳入物件的位址"，所以靜態函式中不會有this指標，也 "不允許使用非靜態成員"。


// reference: http://monkeycoding.com/?p=927
// reference: https://openhome.cc/Gossip/CppGossip/staticMember.html
// reference: https://www.itread01.com/content/1546986090.html

class TestA_CS;
int Compare_Fn(TestA_CS  A_cs, TestA_CS  B_cs);

class TestA_CS
{
public:
	TestA_CS(int tempX_i, int tempY_i);

	// 宣告靜態成員
	static double   PI;  //非const的static成員要在類別定義區塊之外初始化

	// 宣告const成員可以在類別定義中初始化(直接在建構式中初始化)
	const  double   Test_d = 20.0;
	int  TestA_i;

	// 宣告const的靜態成員
	//static const double   PI /*= 3.14159*/;
	static double Circle_Area_Fn(double tempRadius_d);

	void Change_TestValue_Fn();
	void Change_StaticValue_Fn(double Value_d);

	friend int Compare_Fn(TestA_CS  A_cs, TestA_CS  B_cs);
private:
	int       X_i;
	int       Y_i;

};
