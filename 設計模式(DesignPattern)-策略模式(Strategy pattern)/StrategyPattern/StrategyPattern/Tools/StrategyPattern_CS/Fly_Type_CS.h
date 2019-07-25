#pragma once

//------------------------------------------------------
/////     Fly_Type_CS     //////
class Fly_Type_CS
{
public:
	virtual void    Fly_Fn();
};

class Fly_Nowing_CS :public Fly_Type_CS
{
public:
	void    Fly_Fn();
};

class Fly_Wing_CS :public Fly_Type_CS
{
public:
	void    Fly_Fn();
};

//------------------------------------------------------
