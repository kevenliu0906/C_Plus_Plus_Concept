#pragma once

class Integer_CS
{
public:
	Integer_CS();
	Integer_CS(int Num_i);
	int   GetValue_Fn();

	// ����==�B��l
	bool operator==(Integer_CS &temp_cs);
	// ����=�B��l
	Integer_CS operator=(Integer_CS &temp_cs);

	// �ۭq���A�ഫ(�ثe�Ҥl�O�H����ݭn�ഫ��int���A���|�һ���)
	// ��ݭn�NInteger�ഫ��int�ɦp�����
	// <����>: ���F�䴩�Pint�򥻫��A��������N�欰�A�i�H�ϥ�operator int()�w�q�p���ഫ�A
	//         ��sĶ���ݭn�@int���A�ഫ�ɡA�N�|�ϥΧA�۩w�q���欰
	//         operator����۪��Y�O�ഫ�� "�ؼЫ��A" �A�۩w�q���A�ഫ���u�i�H�ഫ�ܰ򥻫��A�A�]�i�H���w�ഫ���۩w�q���A
	// <�`�N>: �ഫ�禡���঳�ѼƦC
	// reference: https://openhome.cc/Gossip/CppGossip/UserDefinedConversions.html
	operator int();

private:
	int  Value_i;
};
