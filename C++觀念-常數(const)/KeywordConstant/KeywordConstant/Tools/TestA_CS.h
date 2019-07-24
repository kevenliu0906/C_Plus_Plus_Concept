#pragma once

class TestA_CS
{
public:
	TestA_CS();
	TestA_CS(int tempX_i, int tempZ_i);

	void   Set_X_Value_Fn(int setValue_X_i);

	const int    Get_Y_Const_Value_Fn();

	// �ŧiconst�禡�A�ت��b��q�����禡���|�ܧ�����O�������ƭ�
	int    Get_X_Value_Fn() const;

	// �ŧiconst�禡�A�ت��b��q�����禡���|�ܧ�����O�������ƭ�
	// �]���O "�^�Ǧ������ѦҼƭ�" �A�����^�Ǫ��ܼƥi�H�������^�ǭ�
	// ���F�O�Ҥ��|�ܧ�����O�������ƭȡA�ҥH�禡�e���ٻݭn�[�Wconst��ܱ������ܼƬO�@�`��
	// reference: https://openhome.cc/Gossip/CppGossip/constAndmuttable.html
	const int&    Get_Z_Value_Fn() const;

	// ������ǻ����ѼƳQ�ק�A�b�եΨ禡���ѼƤ���const����r(�Ĥ@�ӰѼƬO�����}�C�A�i�H���������ܼ�)
	bool   FindNum_Fn(const int Array_i_ay[], int FindNumber_i, int ArraySize_i);

protected:
	int    X_i;
	int    Z_i;
	// �ŧiconst�������ܼơA���ܼƬO�`�q
	const  int    Y_Const_i;
};
