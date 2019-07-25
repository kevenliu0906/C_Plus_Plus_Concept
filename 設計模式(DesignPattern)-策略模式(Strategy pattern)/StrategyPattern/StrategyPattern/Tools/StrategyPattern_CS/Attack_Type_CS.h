#pragma once

//------------------------------------------------------
/////     Attack_Type_CS     //////

class Attack_Type_CS
{
public:
	virtual void Attack_Fn();
};

class Attack_Normal_CS :public Attack_Type_CS
{
public:
	void Attack_Fn();
};

class Attack_Magic_CS :public Attack_Type_CS
{
public:
	void Attack_Fn();
};


