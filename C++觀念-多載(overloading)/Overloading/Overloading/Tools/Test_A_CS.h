#pragma once

class TestA_CS
{
public:
	//--> �h��(overloading)������
	// �禡�h��(overloading)�ɥi�H�ھڨ禡 "�ѼƦC���ѼƸ�ƫ��A" �A�]�i�H�ھ� "�Ѽƪ��Ӽ�" �A�άO "��̪����X"
	// ���n�`�N���O�A"��^�ȫ��A" ����Χ@�P�_�禡�h��(overloading)���̾ڡC
	// reference: https://openhome.cc/Gossip/CppGossip/OverloadedFunction.html
	double Add_Fn(double A_i, double B_i);
	double Add_Fn(double A_i, double B_i, double C_i);
	int    Add_Fn(int A_i, int B_i);
};
