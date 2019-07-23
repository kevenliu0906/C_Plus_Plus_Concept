#include "stdafx.h"
#include "Integer_CS.h"

//-----------------------------------------------------------------
Integer_CS::Integer_CS()
{
	Value_i = 0;
}
//-----------------------------------------------------------------
Integer_CS::Integer_CS(int Num_i)
{
	Value_i = Num_i;
}
//-----------------------------------------------------------------
int Integer_CS::GetValue_Fn()
{
	return (Value_i);
}
//-----------------------------------------------------------------
bool Integer_CS::operator==(Integer_CS &temp_cs)
// ����==�B��l
{
	if (Value_i != temp_cs.Value_i)
		return false;
	return true;
}
//-----------------------------------------------------------------
Integer_CS Integer_CS::operator=(Integer_CS &temp_cs)
// ����=�B��l
{
	Value_i = temp_cs.Value_i;
	return (*this);
}
//-----------------------------------------------------------------
Integer_CS::operator int()
// �ۭq���A�ഫ
// ��ݭn�NInteger�ഫ��int�ɦp�����
// <����>: ���F�䴩�Pint�򥻫��A��������N�欰�A�i�H�ϥ�operator int()�w�q�p���ഫ�A
//         ��sĶ���ݭn�@int���A�ഫ�ɡA�N�|�ϥΧA�۩w�q���欰
//         operator����۪��Y�O�ഫ�� "�ؼЫ��A" �A�۩w�q���A�ഫ���u�i�H�ഫ�ܰ򥻫��A�A�]�i�H���w�ഫ���۩w�q���A
// <�`�N>: �ഫ�禡���঳�ѼƦC
// reference: https://openhome.cc/Gossip/CppGossip/UserDefinedConversions.html
{
	return (Value_i);
}
//-----------------------------------------------------------------