#pragma once

namespace SmallToBig //�]��TestB_CS.h�MTestA_CS.h���ۦP��class�ŧi�A�����|�Ĭ�A�ҥH�ŧi���P��namespace�W�٨ӹj�}
{
	class Sort_CS
	{
	public:
		Sort_CS();
		Sort_CS(int A_i, CString Data_cstr);
		void   SortNum_Fn(int *Array_i_pr, int Size_i);  // �q�p��j�Ƨ�
	protected:
		int        Num_i;
		CString    Text_cstr;
	};
}