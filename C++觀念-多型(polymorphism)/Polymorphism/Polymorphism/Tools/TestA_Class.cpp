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
	
	Num_i++;   // Num_i�Oprotected�����A�ҥH�l���O�i�H�b��禡�I�s�ϥ�
	             // �YNum_i�ŧi��private�����A��l���O���禡�]�L�k�ϥ�
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

	ShowParam_Test_Fn(0);              // ����AA_CS����ShowParam_Test_Fn()
	this->A_CS::ShowParam_Test_Fn(0);  // ����A_CS����ShowParam_Test_Fn()

							   // �Y�OAA_CS�u���ŧiShowParam_Test_Fn()��ӰѼƪ��ܡA�h�|compiler error, 
							   // �����M�l�����ŧi�ۦP�W�٪�function�ɡA
							   // �h�l���O�u�|�ݨ쥻�����O���ҩw�q��function�A
							   // �Y�O�Q�n�I�s������function�A�h�ݭn
							   // 1. �N���O����function�ŧi���M�����O�@�Ҥ@�ˡA�åB�N������function�ŧi�e�[�W "virtual"
							   // reference: http://www.cppblog.com/zgysx/archive/2007/03/12/19662.html
							   // �άO
							   // 2. ������this->�����O�W��::function�W�٧Y�i
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