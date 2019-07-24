#pragma once

//--> �N�B��l����
// �bC++���A�w�]���F�򥻸�ƫ��A�i�H�ϥιB��l�i��B��A�Ҧpint�Bdouble�Bchar���A�p�G�z�n�N��Ӫ���ۥ[�A�w�]�W�O����
// �M�Ӧb�ܦh���ΤU�A�z�|�Q�n�N��Ӫ��󪺬Y���ݩʭȬۥ[�A�öǦ^�B��᪺���G�A�Ҧp�y�Ьۥ[�A
// �bC++���A�o�i�H�z�L�����B��l�ӹF��ت�
// reference: http://monkeycoding.com/?p=930
// reference: https://openhome.cc/Gossip/CppGossip/OverloadOperator.html

class TestA_CS
{
public:
	TestA_CS();
	TestA_CS(int _x_i, int _y_i);
	TestA_CS operator =(TestA_CS &temp_A_cs);    // re-write the operator =
	bool operator ==(TestA_CS &temp_A_cs);       // re-write the operator ==
	TestA_CS operator + (TestA_CS &temp_A_cs);   // ����+�B��l
	int Get_X_Value_Fn();
	int Get_Y_Value_Fn();
	TestA_CS operator ++();        // ����++�e�m�A�Ҧp++p;
	TestA_CS operator ++(int);     // ����++��m�A�Ҧpp++;
	TestA_CS operator --();        // ����--�e�m�A�Ҧp--p;
	TestA_CS operator --(int);     // ����--��m�A�Ҧpp--;
	friend TestA_CS operator +(TestA_CS &temp_A_cs, int Num_i);   //�ϥ�friend�禡�ӭ����B��l
	friend TestA_CS operator +(int Num_i, TestA_CS &temp_A_cs);   //�ϥ�friend�禡�ӭ����B��l

protected:
	int x_i;
	int y_i;
};
