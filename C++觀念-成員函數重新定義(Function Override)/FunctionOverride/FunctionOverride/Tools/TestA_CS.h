#pragma once

class TestA_CS
{
public:
	void Show_Fn();
};


class TestAA_CS :public TestA_CS
{
public:
	void Show_Fn();    // 成員函式重新定義(override)
};