#pragma once

// (�p�G��TestA_Class.h����A_CS��Show_Fn()��ƫe��virtual�����A�N�|�����@�˪���X)
// <<�h���u���b�ϥ� "����"�άO"�Ѧ�" �~�o�H�o���@��>>�A�h���O�ʺA�䵲������
// �ݭn�A�����O��n�h�����禡�e�[�W����rvirtual�A��ܳo�禡�O�����禡�A�åB�b�l�����O�����s�w�q�����禡�A
// ��ܦ������禡���ާ@����ܰ���ɴ��A�M�w�C
// reference: http://monkeycoding.com/?p=936
// reference: http://puremonkey2010.blogspot.com/2014/08/c-gossip-virtual-function.html
// reference: https://www.itread01.com/content/1544437518.html

class A_CS
{
public:
	virtual void Show_Fn();

	virtual void ShowParam_Test_Fn(int i);

	void Test_Fn();

protected:             //�ŧi��protected�������ܡA��l���O���禡�O�i�H�ϥΪ�
	                   //���Y�ŧi��private�������ܡA�N�u��������class�禡�i�H�ϥ�
	int     Num_i;
};

class AA_CS :public A_CS
{
public:
	void Show_Fn();

	//void ShowParam_Test_Fn(int temp1_i, int temp2_i);

	void ShowParam_Test_Fn(int TempX_i);

	void Test_Fn();
};