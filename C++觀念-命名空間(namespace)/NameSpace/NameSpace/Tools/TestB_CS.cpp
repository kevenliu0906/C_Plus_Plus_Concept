#include "stdafx.h"
#include "TestB_CS.h"

namespace SmallToBig //�]��TestB_CS.h�MTestA_CS.h���ۦP��class�ŧi�A�����|�Ĭ�A�ҥH�ŧi���P��namespace�W�٨ӹj�}
{
	//--------------------------------------------------------------------------
	Sort_CS::Sort_CS()
	{
		Num_i = 0;
		Text_cstr = _T("");
	}
	//--------------------------------------------------------------------------
	Sort_CS::Sort_CS(int A_i, CString Data_cstr)
	{
		Num_i = A_i;
		Text_cstr = Data_cstr;
	}
	//--------------------------------------------------------------------------
	void Sort_CS::SortNum_Fn(int *Array_i_pr, int Size_i)  // �q�p��j�Ƨ�
	{
		//----- Initial ...
		CString   Msg_cstr = _T("");
		int       Temp_i = 0;

		//----------------------------------------

		for (int i_i = 0; i_i < Size_i; i_i++)
		{
			for (int j_i = i_i + 1; j_i < Size_i; j_i++)
			{
				// swap the biggest value into right
				if (Array_i_pr[i_i] > Array_i_pr[j_i])
				{
					Temp_i = Array_i_pr[i_i];
					Array_i_pr[i_i] = Array_i_pr[j_i];
					Array_i_pr[j_i] = Temp_i;
				}
			}
		}

	}
	//--------------------------------------------------------------------------
}