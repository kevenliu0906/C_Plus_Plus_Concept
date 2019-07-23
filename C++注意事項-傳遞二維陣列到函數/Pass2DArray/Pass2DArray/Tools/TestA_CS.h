#pragma once

class TestA_CS
{
public:
	/////--> 傳遞二維陣列(int型態)
	void Pass2DArray_Fn(int **A_i_ay);
	void Pass2DArray_Correct_Fn(int (*temp_i_pr_ay)[3]);  // temp_i_pr_ay是一個指標，指向3個int 元素的陣列
	
	/////--> 傳遞一維指標陣列(int *型態)
	void PassArrayWithPointer_ByPtr_Fn(int **temp_i_pr);      // temp_i_pr是指標的指標
	void PassArrayWithPointer_ByRef_Fn(int *(&temp_i_ay)[3]); // temp_i_ay是一個有3個int *元素的陣列參考
	void PassArrayWithPointer_Fn(int *temp_i_ay_pr[]);        // temp_i_ay_pr是一個陣列，擁有int *元素

	/////--> 傳遞二維指標陣列(int *型態)
	void Pass2DIntPtrArray_Fn(int *(*temp_i_ay_pr)[3]);   // temp_i_ay_pr是一個指標，指向3個int *元素的陣列

	/////--> 傳遞一維陣列(int型態)
	void Pass1DArray_ByPtr_Fn(int *A_i_ay);         // A_i_ay是一個int型態的指標
	void Pass1DArray_ByRef_Fn(int (&A_i_ay)[5]);    // A_i_ay是一個有5個int元素的陣列參考
	void Pass1DArray_Fn(int A_i_ay[]);              // A_i_ay是一個int型態的陣列
};
