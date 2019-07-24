#include "stdafx.h"
#include "TestB_CS.h"

namespace SmallToBig //因為TestB_CS.h和TestA_CS.h有相同的class宣告，彼此會衝突，所以宣告不同的namespace名稱來隔開
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
	void Sort_CS::SortNum_Fn(int *Array_i_pr, int Size_i)  // 從小到大排序
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