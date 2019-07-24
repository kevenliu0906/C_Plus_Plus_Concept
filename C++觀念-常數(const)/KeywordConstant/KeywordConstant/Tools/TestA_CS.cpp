#include "stdafx.h"
#include "TestA_CS.h"

//-----------------------------------------------------------------------
TestA_CS::TestA_CS():Y_Const_i(100)  // �ŧiconst�������ܼơA���ܼƬO�`�q(const�����ܼƶȯ�b�غc�禡��l��)
{
	X_i = 0;
	Z_i = 10;
}
//-----------------------------------------------------------------------
TestA_CS::TestA_CS(int tempX_i, int tempZ_i):Y_Const_i(100) // �ŧiconst�������ܼơA���ܼƬO�`�q(const�����ܼƶȯ�b�غc�禡��l��)
{
	X_i = tempX_i;
	Z_i = tempZ_i;
}
//-----------------------------------------------------------------------
int TestA_CS::Get_X_Value_Fn() const
{
	// ---- �b�禡���[�Jconst���ηN�O�i���o�Ө禡�ä��|�ܰʨ����O�������ƭ�
	// ---- �o�Ө禡�ȶȬO������O���������ƭȡA�ҥH���|�ܧ��U�Ӧ����ƭ�
	// reference: https://openhome.cc/Gossip/CppGossip/constAndmuttable.html
	
	//X_i++;       // compiler error�A�]���w�g�i���o�Ө禡�Oconst���禡�A�ҥH���|�ܰʨ�禡�������ƭ�
	return (X_i);
}
//-----------------------------------------------------------------------
void TestA_CS::Set_X_Value_Fn(int setValue_X_i)
{
	X_i = setValue_X_i;
}
//-----------------------------------------------------------------------
bool TestA_CS::FindNum_Fn(const int Array_i_ay[], int FindNumber_i, int ArraySize_i)
{
	//----- Initial...
	bool   Find_fg = false;

	//-----------------------------------

	//----- ���F����ǻ����禡�ѼƳQ�ק�A�b�եΨ禡���ѼƤ���const����r
	//----- �o�ӨҤl�]���O�ǻ��}�C�A�ҥH�ѼƬO���Ы����b�ǻ�
	// reference: https://lalalah.pixnet.net/blog/post/31677924 �� A �ר�

	for (int i_i = 0; i_i < ArraySize_i; i_i++)
	{
		if (Array_i_ay[i_i] == FindNumber_i)
		{
			Find_fg = true;
			//Array_i_ay[i_i] = -1;  // compiler error, Array_i_ay[] is a const parameter and can't change
			break;
		}
	}


	return (Find_fg);
}
//-----------------------------------------------------------------------
const int TestA_CS::Get_Y_Const_Value_Fn()
{
	//Y_Const_i++;    // compiler error, can NOT change value of the const variable

	return (Y_Const_i);
}
//-----------------------------------------------------------------------
const int& TestA_CS::Get_Z_Value_Fn() const
{
	// �ŧiconst�禡�A�ت��b��q�����禡���|�ܧ�����O�������ƭ�
	// �]���O "�^�Ǧ������ѦҼƭ�" �A�I�s�誺�����^�Ǫ��ܼƥi�H�������^�ǭ�
	// ���F�O�Ҥ��|�ܧ�����O�������ƭȡA�ҥH�禡�e���ٻݭn�[�Wconst��ܱ������ܼƬO�@�`��
	//
	// reference: https://openhome.cc/Gossip/CppGossip/constAndmuttable.html

	return (Z_i);
}
//-----------------------------------------------------------------------