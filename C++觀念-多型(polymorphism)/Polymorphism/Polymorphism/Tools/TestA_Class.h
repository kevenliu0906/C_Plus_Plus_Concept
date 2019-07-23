#pragma once

// (如果把TestA_Class.h內的A_CS的Show_Fn()函數前方virtual拿掉，就會有不一樣的輸出)
// <<多型只有在使用 "指標"或是"參考" 才得以發揮作用>>，多型是動態鍵結的概念
// 需要再基底類別把要多型的函式前加上關鍵字virtual，表示這函式是虛擬函式，並且在衍生類別中重新定義虛擬函式，
// 表示此成員函式的操作延遲至執行時期再決定。
// reference: http://monkeycoding.com/?p=936
// reference: http://puremonkey2010.blogspot.com/2014/08/c-gossip-virtual-function.html
// reference: https://www.itread01.com/content/1544437518.html

class A_CS
{
public:
	virtual void Show_Fn();

	virtual void ShowParam_Test_Fn(int i);

	void Test_Fn();

protected:             //宣告成protected類型的話，其子類別的函式是可以使用的
	                   //但若宣告成private類型的話，就只有本身的class函式可以使用
	int     Num_i;
};

class AA_CS :public A_CS
{
public:
	void Show_Fn();

	//void ShowParam_Test_Fn(int temp1_i, int temp2_i);

	void ShowParam_Test_Fn(int TempX_i);

	void Test_Fn();
};