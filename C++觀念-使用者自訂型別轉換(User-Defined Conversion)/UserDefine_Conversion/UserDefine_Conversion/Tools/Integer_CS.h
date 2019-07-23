#pragma once

class Integer_CS
{
public:
	Integer_CS();
	Integer_CS(int Num_i);
	int   GetValue_Fn();

	// 重載==運算子
	bool operator==(Integer_CS &temp_cs);
	// 重載=運算子
	Integer_CS operator=(Integer_CS &temp_cs);

	// 自訂型態轉換(目前例子是以物件需要轉換成int型態來舉例說明)
	// 當需要將Integer轉換為int時如何執行
	// <說明>: 為了支援與int基本型態的直接算術行為，可以使用operator int()定義如何轉換，
	//         當編譯器需要作int型態轉換時，就會使用你自定義的行為
	//         operator後緊跟著的即是轉換的 "目標型態" ，自定義型態轉換不只可以轉換至基本型態，也可以指定轉換為自定義型態
	// <注意>: 轉換函式不能有參數列
	// reference: https://openhome.cc/Gossip/CppGossip/UserDefinedConversions.html
	operator int();

private:
	int  Value_i;
};
