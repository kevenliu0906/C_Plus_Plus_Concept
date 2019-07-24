#pragma once
#include "Tools\Test_A_CS.h"

//-----------------------------------------------------
// <<�ϥ�friend�禡�ӭ����B��l>>
// �ϥ����O�����ӭ����G���B��l�A�|���@�ӭ���A�N�O�B��l������@�w�n�O�쪫��
// �p�G�ϥ����O���������A�A�N�L�k���B��l����������O�`��
// reference: https://openhome.cc/Gossip/CppGossip/friendOverLoadOperator.html

// �ϥ�friend�禡�����G���B��l�ɡA�A�n���w��ӰѼƫ��A�A���O��ܹB��l�����k�䪺�B�⤸���A�C

//-----------------------------------------------------
TestA_CS operator +(TestA_CS &temp_A_cs, int Num_i)
//�ϥ�friend�禡�ӭ����B��l
//�Ҧp TestA_cs+10
{
	TestA_CS   Sum_cs(temp_A_cs.x_i + Num_i, temp_A_cs.y_i + Num_i);

	return (Sum_cs);
}
//-----------------------------------------------------
TestA_CS operator +(int Num_i, TestA_CS &temp_A_cs)
//�ϥ�friend�禡�ӭ����B��l
//�Ҧp 10+TestA_cs
{
	TestA_CS    Sum_cs(Num_i + temp_A_cs.x_i, Num_i + temp_A_cs.y_i);

	return (Sum_cs);
}
//-----------------------------------------------------
