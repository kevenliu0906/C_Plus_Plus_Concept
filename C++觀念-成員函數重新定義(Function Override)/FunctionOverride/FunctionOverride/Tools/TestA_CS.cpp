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
// �����禡���s�w�q(override)
// reference: https://openhome.cc/Gossip/CppGossip/OverrideMemberFunction.html
// reference: https://www.geeksforgeeks.org/function-overloading-vs-function-overriding-in-cpp/
// reference: http://www.cppblog.com/zgysx/archive/2007/03/12/19662.html
{
	//----- Initial...
	CString     Msg_cstr = _T("");
	//--------------------------------------
	
	Msg_cstr.Format(_T("TestAA_CS::Show_Fn()"));
	MessageBox(NULL, Msg_cstr, _T("TestAA_CS"), MB_OK);

	this->TestA_CS::Show_Fn();   // �p�G�b���s�w�q�Y�Ө禡�A�������������O���Ө禡�����e���ܡA�h�i�H�ϥ�
								 // this����r���X::�B��l�A���w�����O���Ө禡�Ӱ���C
}
//-------------------------------------------------------------------