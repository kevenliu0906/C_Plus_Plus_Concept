#pragma once

//--> �R�A�����B�R�A�禡(static)

// =========== �R�A���� =============
// �ۦP���O�Ҳ��ͪ�����A�֦��U�۪������ܼ�
// �����Ҧ�������ݭn�@���@�Ӧ����ܼƴN��static�A
// "�R�A�����O�ݩ����O�Ҿ֦�" �A�Ӥ��O�ӧO������C�A�i�H�N�R�A���������C�Ӫ����ҩҦ@�ɪ���Ʀ����C
// �R�A�������H�U�X�ӯS�ʡG
// 1. �R�A�����ݩ����O�A�Ӥ��ݩ�ӧO������
// 2. �Dconst��static�����n�b���O�w�q�϶����~��l��
// 3. �i�H�Ϊ����Ҫ��W�١A�άO���O�W�٥[�W::�B��l�Ӧs���A�q�`�ϥ����O�W�٥[�W::�B��l�Ӧs���A
//    �@�譱�]�i�H�קK�P�D�R�A��Ʀ����V�c
// 4. �R�A�����P�˿�upublic�Bprotected�Bprivate���s������C

// =========== �R�A�禡 =============
// �N�禡�[�W����rstatic�A�N�i�N�禡�]���R�A�禡�A�R�A�禡�q�`�O�@�� "�u�@�禡"
// �R�A�禡�P�˥i�H�z�L���O�W�٨өI�s�A�ѩ��R�A�����O�ݩ����O�Ӥ��O����A
// �ҥH�I�s "�R�A�禡" �ɡA�� "���|�ǤJ���󪺦�}"�A�ҥH�R�A�禡�����|��this���СA�] "�����\�ϥΫD�R�A����"�C


// reference: http://monkeycoding.com/?p=927
// reference: https://openhome.cc/Gossip/CppGossip/staticMember.html
// reference: https://www.itread01.com/content/1546986090.html

class TestA_CS;
int Compare_Fn(TestA_CS  A_cs, TestA_CS  B_cs);

class TestA_CS
{
public:
	TestA_CS(int tempX_i, int tempY_i);

	// �ŧi�R�A����
	static double   PI;  //�Dconst��static�����n�b���O�w�q�϶����~��l��

	// �ŧiconst�����i�H�b���O�w�q����l��(�����b�غc������l��)
	const  double   Test_d = 20.0;
	int  TestA_i;

	// �ŧiconst���R�A����
	//static const double   PI /*= 3.14159*/;
	static double Circle_Area_Fn(double tempRadius_d);

	void Change_TestValue_Fn();
	void Change_StaticValue_Fn(double Value_d);

	friend int Compare_Fn(TestA_CS  A_cs, TestA_CS  B_cs);
private:
	int       X_i;
	int       Y_i;

};
