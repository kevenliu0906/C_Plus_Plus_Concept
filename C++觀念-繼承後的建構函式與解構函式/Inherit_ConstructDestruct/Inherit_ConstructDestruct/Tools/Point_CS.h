#pragma once

class Point2D_CS
{
public:
	Point2D_CS();
	Point2D_CS(int tempX_i, int tempY_i);
	~Point2D_CS();
	void Set_X_Fn(int tempX_i);
	void Set_Y_Fn(int tempY_i);
	int  Get_X_Fn();
	int  Get_Y_Fn();


protected:
	int    X_i;
	int    Y_i;
};


class Point3D_CS :public Point2D_CS
{
public:
	Point3D_CS();
	Point3D_CS(int tempX_i, int tempY_i, int tempZ_i);
	~Point3D_CS();
	void Set_Z_Fn(int tempZ_i);
	int  Get_Z_Fn();

protected:
	int     Z_i;
};