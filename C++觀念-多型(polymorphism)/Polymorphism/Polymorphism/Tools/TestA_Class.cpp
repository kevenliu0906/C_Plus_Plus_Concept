#include "stdafx.h"
#include "TestA_Class.h"

//-------------------------------------------------------------------------------------------------
void A_CS::Show_Fn()
{
	//----- Initial ...
	CString   Msg_cstr = _T("");

	//---------------------------------

	Num_i++;
	Msg_cstr.Format(_T("Num:%d,  this is A_CS show"), Num_i);
	MessageBox(NULL, Msg_cstr, _T("A_CS show"), MB_OK);

}
//-------------------------------------------------------------------------------------------------
void A_CS::ShowParam_Test_Fn(int i)
{
	//----- Initial ...
	CString   Msg_cstr = _T("");

	//---------------------------------

	Msg_cstr.Format(_T("A_CS::ShowParam_Test_Fn(%d)"), i);
	MessageBox(NULL, Msg_cstr, _T("A_CS show param test"), MB_OK);
}
//-------------------------------------------------------------------------------------------------
void A_CS::Test_Fn()
{
	//------ Initial ...
	CString   Msg_cstr = _T("");

	//---------------------------

	Msg_cstr.Format(_T("A_CS::Test_Fn()"));
	MessageBox(NULL, Msg_cstr, _T(""), MB_OK);

	ShowParam_Test_Fn(0);
}
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------
void AA_CS::Show_Fn()
{
	//------ Initial ...
	CString   Msg_cstr = _T("");

	//---------------------------
	
	Num_i++;   // Num_i是protected類型，所以子類別可以在其函式呼叫使用
	             // 若Num_i宣告成private類型，其子類別的函式也無法使用
	Msg_cstr.Format(_T("Num:%d,  this is AA_CS show"), Num_i);
	MessageBox(NULL, Msg_cstr, _T("AA_CS show"), MB_OK);

}
//-------------------------------------------------------------------------------------------------
//void AA_CS::ShowParam_Test_Fn(int temp1_i, int temp2_i)
//{
//	//------ Initial ...
//	CString   Msg_cstr = _T("");
//
//	//---------------------------
//	Msg_cstr.Format(_T("AA_CS::ShowParam_Test_Fn(%d,%d)"), temp1_i, temp2_i);
//	MessageBox(NULL, Msg_cstr, _T("AA_CS::ShowParam_Test_Fn"), MB_OK);
//}
////-------------------------------------------------------------------------------------------------
void AA_CS::Test_Fn()
{
	//------ Initial ...
	CString   Msg_cstr = _T("");

	//---------------------------

	Msg_cstr.Format(_T("AA_CS::Test_Fn()"));
	MessageBox(NULL, Msg_cstr, _T(""), MB_OK);

	ShowParam_Test_Fn(0);              // 執行AA_CS內的ShowParam_Test_Fn()
	this->A_CS::ShowParam_Test_Fn(0);  // 執行A_CS內的ShowParam_Test_Fn()

							   // 若是AA_CS只有宣告ShowParam_Test_Fn()兩個參數的話，則會compiler error, 
							   // 父類和子類都宣告相同名稱的function時，
							   // 則子類別只會看到本身類別內所定義的function，
							   // 若是想要呼叫父類的function，則需要
							   // 1. 將類別內的function宣告成和父類別一模一樣，並且將父類的function宣告前加上 "virtual"
							   // reference: http://www.cppblog.com/zgysx/archive/2007/03/12/19662.html
							   // 或是
							   // 2. 直接用this->父類別名稱::function名稱即可
							   // reference: https://openhome.cc/Gossip/CppGossip/OverrideMemberFunction.html
}
//-------------------------------------------------------------------------------------------------
void AA_CS::ShowParam_Test_Fn(int TempX_i)
{
	//------ Initial ...
	CString   Msg_cstr = _T("");

	//---------------------------
	Msg_cstr.Format(_T("AA_CS::ShowParam_Test_Fn(%d)"), TempX_i);
	MessageBox(NULL, Msg_cstr, _T("AA_CS::ShowParam_Test_Fn"), MB_OK);
}
//-------------------------------------------------------------------------------------------------