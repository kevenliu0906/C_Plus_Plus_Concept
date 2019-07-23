#pragma once

class Circle_CS;   // �����n�[�J�o�����U�@�檺Compare_Fn()�禡�i�H���Ѽ�Circle_CS
int   Compare_Fn(Circle_CS &A_Circle_cs, Circle_CS &B_Circle_cs);

class Circle_CS
{
public:
	Circle_CS();
	Circle_CS(double tempR_d);
	void    Set_Radius_Fn(double   radius_d);
	double  Get_Radius_Fn();
	double  Get_Area_Fn();

	static double PI;

	// �b�w�q���O�����ɡA�p�Φ����u��Q�P�@�����O�w�q�������s���A���i�H�����ѥ~�ɶi��s���A�M�Ӧ��ɭԡA
	// �A�|�Ʊ洣�Ѩp�Φ������Y�ǥ~���禡�Ӧs���A�o�ɧA�i�H�]�w���O�� "�n��" �A�u���n�ͤ~�i�H�����s��
	// �ۮa���p�Φ����C
	// �U���o�ӵ{�����ϥ� "friend" ����r�ӳ]�w���O���n�ͨ禡�A�Ӧn�ͥi�H�����s�������O���p�Φ���
	// reference: https://openhome.cc/Gossip/CppGossip/friendFunctionClass.html
	// 
	// �ϥ�friend�禡�q�`�O���Ĳv���Ҷq�A�H�����s���p�Φ����Ӥ��z�L�禡�I�s���覡�A�Ӭ٥h�禡�I�s���t��
	//
	friend int   Compare_Fn(Circle_CS &A_Circle_cs, Circle_CS &B_Circle_cs);

private:
	double  Radius_d;
	
};
