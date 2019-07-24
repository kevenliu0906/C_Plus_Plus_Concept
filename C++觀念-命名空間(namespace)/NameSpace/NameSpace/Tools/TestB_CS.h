#pragma once

namespace SmallToBig //因為TestB_CS.h和TestA_CS.h有相同的class宣告，彼此會衝突，所以宣告不同的namespace名稱來隔開
{
	class Sort_CS
	{
	public:
		Sort_CS();
		Sort_CS(int A_i, CString Data_cstr);
		void   SortNum_Fn(int *Array_i_pr, int Size_i);  // 從小到大排序
	protected:
		int        Num_i;
		CString    Text_cstr;
	};
}