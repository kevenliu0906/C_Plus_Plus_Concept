#pragma once
#include "Tools\Test_A_CS.h"

//-----------------------------------------------------
// <<使用friend函式來重載運算子>>
// 使用類別成員來重載二元運算子，會有一個限制，就是運算子的左邊一定要是原物件
// 如果使用類別成員重載，你就無法讓運算子重載的左邊是常數
// reference: https://openhome.cc/Gossip/CppGossip/friendOverLoadOperator.html

// 使用friend函式重載二元運算子時，你要指定兩個參數型態，分別表示運算子的左右邊的運算元型態。

//-----------------------------------------------------
TestA_CS operator +(TestA_CS &temp_A_cs, int Num_i)
//使用friend函式來重載運算子
//例如 TestA_cs+10
{
	TestA_CS   Sum_cs(temp_A_cs.x_i + Num_i, temp_A_cs.y_i + Num_i);

	return (Sum_cs);
}
//-----------------------------------------------------
TestA_CS operator +(int Num_i, TestA_CS &temp_A_cs)
//使用friend函式來重載運算子
//例如 10+TestA_cs
{
	TestA_CS    Sum_cs(Num_i + temp_A_cs.x_i, Num_i + temp_A_cs.y_i);

	return (Sum_cs);
}
//-----------------------------------------------------
