#include "stdafx.h"
#include "TestA_CS.h"

//-------------------------------------------------------------------
void TestA_CS::Show_Fn()
{
	//----- Initial...
	CString     Msg_cstr = _T("");
	//--------------------------------------

	Msg_cstr.Format(_T("TestA_CS::Show_Fn()"));
	MessageBox(NULL, Msg_cstr, _T("TestA_CS"), MB_OK);
}
//-------------------------------------------------------------------
//-------------------------------------------------------------------
//-------------------------------------------------------------------
void TestAA_CS::Show_Fn()
// 成員函式重新定義(override)
// reference: https://openhome.cc/Gossip/CppGossip/OverrideMemberFunction.html
// reference: https://www.geeksforgeeks.org/function-overloading-vs-function-overriding-in-cpp/
// reference: http://www.cppblog.com/zgysx/archive/2007/03/12/19662.html
{
	//----- Initial...
	CString     Msg_cstr = _T("");
	//--------------------------------------
	
	Msg_cstr.Format(_T("TestAA_CS::Show_Fn()"));
	MessageBox(NULL, Msg_cstr, _T("TestAA_CS"), MB_OK);

	this->TestA_CS::Show_Fn();   // 如果在重新定義某個函式，打算先執行父類別中該函式的內容的話，則可以使用
								 // this關鍵字結合::運算子，指定父類別中該函式來執行。
}
//-------------------------------------------------------------------