#include "stdafx.h"
#include "TestA_CS.h"

//-----------------------------------------------
void TestA_CS::Pass2DArray_Fn(int **A_i_ay)
{
	//----- Initial...
	CString   Msg_cstr = _T("");
	
	//---------------------------------

	Msg_cstr = _T("TestA_CS::Pass2DArray_Fn()");
	MessageBox(NULL, Msg_cstr, _T(""), MB_OK);
}
//-----------------------------------------------
void TestA_CS::Pass2DArray_Correct_Fn(int (*temp_i_pr_ay)[3])
{
	//----- Initial...
	CString    Msg_cstr = _T("");
	int        RowCount_i = 0;
	int        ColCount_i = 0;
	int        Temp_size_i = 0;

	//------------------------------------

	//-- �ѼƬO�@�ӫ��СA���V�@�Ӿ֦�3��int�������}�C
	//-- �ҥH�u�|���D�ǤJ3��(Col)�������j�p�A���O�����D���h�ֵ�(Row)�o�ˤl���}�C�|�ǤJ
	Temp_size_i = sizeof(temp_i_pr_ay);
	Temp_size_i = sizeof(temp_i_pr_ay[0]);
	RowCount_i = sizeof(temp_i_pr_ay) / sizeof(temp_i_pr_ay[0]);       // �o�ӭp��覡�L�k���T�D�X���h��Row
	ColCount_i = sizeof(temp_i_pr_ay[0]) / sizeof(temp_i_pr_ay[0][0]); // �o�ӭp��覡�i�H�D�X���h�֭�Col

	Msg_cstr.Format(_T("TestA_CS::Pass2DArray_Correct_Fn() --> the parameter is temp_i_pr_ay[%d][%d]={{%d,%d,%d},{%d,%d,%d}}"), RowCount_i, ColCount_i, temp_i_pr_ay[0][0], temp_i_pr_ay[0][1], temp_i_pr_ay[0][2],
																																						temp_i_pr_ay[1][0], temp_i_pr_ay[1][1], temp_i_pr_ay[1][2]);
	MessageBox(NULL, Msg_cstr, _T(""), MB_OK);
}
//-----------------------------------------------
void TestA_CS::PassArrayWithPointer_ByPtr_Fn(int **temp_i_pr)
{
	//----- Initial...
	CString    Msg_cstr = _T("");
	int        ArraySize_i = 0;
	int        TestSize_i = 0;

	//------------------------------------

	TestSize_i = sizeof(temp_i_pr);
	TestSize_i = sizeof(temp_i_pr[0]);
	ArraySize_i = sizeof(temp_i_pr) / sizeof(temp_i_pr[0]);  //�]���ѼƬO�Ϋ��Ф覡���V�ǤJ���}�C�A�ҥH���覡�L�k��X���T��ArraySize
	Msg_cstr.Format(_T("TestA_CS::PassArrayWithPointer_ByPtr_Fn() --> the parameter is temp_i_pr[%d]={%x(Value:%d), %x(Value:%d), %x(Value:%d)}"), ArraySize_i, temp_i_pr[0], *temp_i_pr[0], temp_i_pr[1], *temp_i_pr[1], temp_i_pr[2], *temp_i_pr[2]);
	MessageBox(NULL, Msg_cstr, _T(""), MB_OK);
}
//-----------------------------------------------
void TestA_CS::PassArrayWithPointer_ByRef_Fn(int *(&temp_i_ay)[3])
{
	//----- Initial...
	CString    Msg_cstr = _T("");
	int        ArraySize_i = 0;
	int        TestSize_i = 0;

	//------------------------------------

	TestSize_i = sizeof(temp_i_ay);
	TestSize_i = sizeof(temp_i_ay[0]);
	ArraySize_i = sizeof(temp_i_ay) / sizeof(temp_i_ay[0]);  //�]���ѼƬO�ΰѦҤ覡��������ǤJ���}�C�A�ҥH���覡�i�H��X���T��ArraySize
	Msg_cstr.Format(_T("TestA_CS::PassArrayWithPointer_ByRef_Fn() --> the parameter is temp_i_ay[%d]={%x(Value:%d), %x(Value:%d), %x(Value:%d)}"), ArraySize_i, temp_i_ay[0], *temp_i_ay[0], temp_i_ay[1], *temp_i_ay[1], temp_i_ay[2], *temp_i_ay[2]);
	MessageBox(NULL, Msg_cstr, _T(""), MB_OK);
}
//-----------------------------------------------
void TestA_CS::PassArrayWithPointer_Fn(int *temp_i_ay_pr[])
{
	//----- Initial...
	CString    Msg_cstr = _T("");
	int        ArraySize_i = 0;
	int        TestSize_i = 0;

	//------------------------------------

	TestSize_i = sizeof(temp_i_ay_pr);
	TestSize_i = sizeof(temp_i_ay_pr[0]);
	ArraySize_i = sizeof(temp_i_ay_pr) / sizeof(temp_i_ay_pr[0]);  //�]���ѼƬO�Ϋ��Ф覡���V�ǤJ���}�C�A�ҥH���覡�L�k��X���T��ArraySize
	Msg_cstr.Format(_T("TestA_CS::PassArrayWithPointer_Fn() --> the parameter is temp_i_ay[%d]={%x(Value:%d), %x(Value:%d), %x(Value:%d)}"), ArraySize_i, temp_i_ay_pr[0], *temp_i_ay_pr[0], temp_i_ay_pr[1], *temp_i_ay_pr[1], temp_i_ay_pr[2], *temp_i_ay_pr[2]);
	MessageBox(NULL, Msg_cstr, _T(""), MB_OK);
}
//-----------------------------------------------
void TestA_CS::Pass2DIntPtrArray_Fn(int *(*temp_i_ay_pr)[3])
{
	//----- Initial...
	CString    Msg_cstr = _T("");
	int        RowCount_i = 0;
	int        ColCount_i = 0;

	//------------------------------------
	RowCount_i = sizeof(temp_i_ay_pr) / sizeof(temp_i_ay_pr[0]);       // �o�ӭp��覡�L�k���T�D�X���h��Row
	ColCount_i = sizeof(temp_i_ay_pr[0]) / sizeof(temp_i_ay_pr[0][0]); // �o�ӭp��覡�i�H�D�X���h�֭�Col
	
	Msg_cstr.Format(_T("TestA_CS::Pass2DIntPtrArray_Fn() --> the parameter is temp_i_ay_pr[%d][%d]={ {%x(Value:%d), %x(Value:%d), %x(Value:%d)}, {%x(Value:%d), %x(Value:%d), %x(Value:%d)} }"),
		RowCount_i, ColCount_i,
		temp_i_ay_pr[0][0], *temp_i_ay_pr[0][0], temp_i_ay_pr[0][1], *temp_i_ay_pr[0][1], temp_i_ay_pr[0][2], *temp_i_ay_pr[0][2],
		temp_i_ay_pr[1][0], *temp_i_ay_pr[1][0], temp_i_ay_pr[1][1], *temp_i_ay_pr[1][1], temp_i_ay_pr[1][2], *temp_i_ay_pr[1][2]);
	MessageBox(NULL, Msg_cstr, _T(""), MB_OK);
}
//-----------------------------------------------
void TestA_CS::Pass1DArray_ByPtr_Fn(int *A_i_ay)
{
	//----- Initial...
	CString    Msg_cstr = _T("");
	int        ArraySize_i = 0;

	//------------------------------------
	// �Q�Ϋ��Шӱ����ǻ��i�Ӫ��}�C
	// reference: https://www.cnblogs.com/oomusou/archive/2007/02/09/645944.html
	// reference: https://ppt.cc/f7eZZx
	// reference: https://www.cnblogs.com/oomusou/archive/2007/02/09/646440.html

	ArraySize_i = sizeof(A_i_ay) / sizeof(A_i_ay[0]);  //�]���ѼƬO�Ϋ��Ф覡���V�ǤJ���}�C�A�ҥH���覡�L�k��X���T��ArraySize
	Msg_cstr.Format(_T("TestA_CS::Pass1DArray_ByPtr_Fn() --> the parameter is A_i_ay[%d]={%d,%d,%d,%d,%d}"), ArraySize_i, A_i_ay[0], A_i_ay[1], A_i_ay[2], A_i_ay[3], A_i_ay[4]);
	MessageBox(NULL, Msg_cstr, _T(""), MB_OK);
}
//-----------------------------------------------
void TestA_CS::Pass1DArray_ByRef_Fn(int (&A_i_ay)[5])
{
	//----- Initial...
	CString    Msg_cstr = _T("");
	int        ArraySize_i = 0;

	//------------------------------------
	// �Q�ΰѦҨӱ����ǻ��i�Ӫ��}�C
	// reference: https://www.cnblogs.com/oomusou/archive/2007/02/09/645944.html
	// reference: https://ppt.cc/f7eZZx
	// reference: https://www.cnblogs.com/oomusou/archive/2007/02/09/646440.html

	ArraySize_i = sizeof(A_i_ay) / sizeof(A_i_ay[0]);  //�]���ѼƬO�ΰѦҤ覡��������ǤJ���}�C�A�ҥH���覡�i�H��X���T��ArraySize
	Msg_cstr.Format(_T("TestA_CS::Pass1DArray_ByRef_Fn() --> the parameter is A_i_ay[%d]={%d,%d,%d,%d,%d}"), ArraySize_i, A_i_ay[0], A_i_ay[1], A_i_ay[2], A_i_ay[3], A_i_ay[4]);
	MessageBox(NULL, Msg_cstr, _T(""), MB_OK);
}
//-----------------------------------------------
void TestA_CS::Pass1DArray_Fn(int A_i_ay[])
{
	//----- Initial...
	CString    Msg_cstr = _T("");
	int        ArraySize_i = 0;

	//------------------------------------
	// �Q�ΰ}�C�ӱ����ǻ��i�Ӫ��}�C
	// reference: https://www.cnblogs.com/oomusou/archive/2007/02/09/645944.html
	// reference: https://ppt.cc/f7eZZx
	// reference: https://dywang.csie.cyut.edu.tw/dywang/clanguage/node98.html
	// reference: https://programming.im.ncnu.edu.tw/Chapter10.htm ���}�C�Ѽƶǻ�
	// reference: https://www.cnblogs.com/oomusou/archive/2007/02/09/646440.html
	

	ArraySize_i = sizeof(A_i_ay) / sizeof(A_i_ay[0]);  //�]���ѼƬO�Ϋ��Ф覡���V�ǤJ���}�C�A�ҥH���覡�L�k��X���T��ArraySize
	Msg_cstr.Format(_T("TestA_CS::Pass1DArray_Fn() --> the parameter is A_i_ay[%d]={%d,%d,%d,%d,%d}"), ArraySize_i, A_i_ay[0], A_i_ay[1], A_i_ay[2], A_i_ay[3], A_i_ay[4]);
	MessageBox(NULL, Msg_cstr, _T(""), MB_OK);
}
//-----------------------------------------------