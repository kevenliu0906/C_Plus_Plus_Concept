#pragma once

class TestA_CS
{
public:
	/////--> �ǻ��G���}�C(int���A)
	void Pass2DArray_Fn(int **A_i_ay);
	void Pass2DArray_Correct_Fn(int (*temp_i_pr_ay)[3]);  // temp_i_pr_ay�O�@�ӫ��СA���V3��int �������}�C
	
	/////--> �ǻ��@�����а}�C(int *���A)
	void PassArrayWithPointer_ByPtr_Fn(int **temp_i_pr);      // temp_i_pr�O���Ъ�����
	void PassArrayWithPointer_ByRef_Fn(int *(&temp_i_ay)[3]); // temp_i_ay�O�@�Ӧ�3��int *�������}�C�Ѧ�
	void PassArrayWithPointer_Fn(int *temp_i_ay_pr[]);        // temp_i_ay_pr�O�@�Ӱ}�C�A�֦�int *����

	/////--> �ǻ��G�����а}�C(int *���A)
	void Pass2DIntPtrArray_Fn(int *(*temp_i_ay_pr)[3]);   // temp_i_ay_pr�O�@�ӫ��СA���V3��int *�������}�C

	/////--> �ǻ��@���}�C(int���A)
	void Pass1DArray_ByPtr_Fn(int *A_i_ay);         // A_i_ay�O�@��int���A������
	void Pass1DArray_ByRef_Fn(int (&A_i_ay)[5]);    // A_i_ay�O�@�Ӧ�5��int�������}�C�Ѧ�
	void Pass1DArray_Fn(int A_i_ay[]);              // A_i_ay�O�@��int���A���}�C
};
