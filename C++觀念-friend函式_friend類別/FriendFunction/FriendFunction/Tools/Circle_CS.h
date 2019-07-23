#pragma once

class Circle_CS;   // 必須要加入這行讓下一行的Compare_Fn()函式可以找到參數Circle_CS
int   Compare_Fn(Circle_CS &A_Circle_cs, Circle_CS &B_Circle_cs);

class Circle_CS
{
public:
	Circle_CS();
	Circle_CS(double tempR_d);
	void    Set_Radius_Fn(double   radius_d);
	double  Get_Radius_Fn();
	double  Get_Area_Fn();

	static double PI;

	// 在定義類別成員時，私用成員只能被同一個類別定義的成員存取，不可以直接由外界進行存取，然而有時候，
	// 你會希望提供私用成員給某些外部函式來存取，這時你可以設定類別的 "好友" ，只有好友才可以直接存取
	// 自家的私用成員。
	// 下面這個程式中使用 "friend" 關鍵字來設定類別的好友函式，該好友可以直接存取該類別的私用成員
	// reference: https://openhome.cc/Gossip/CppGossip/friendFunctionClass.html
	// 
	// 使用friend函式通常是基於效率的考量，以直接存取私用成員而不透過函式呼叫的方式，來省去函式呼叫的負擔
	//
	friend int   Compare_Fn(Circle_CS &A_Circle_cs, Circle_CS &B_Circle_cs);

private:
	double  Radius_d;
	
};
