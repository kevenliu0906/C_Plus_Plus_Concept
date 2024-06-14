// Console_C++_Polymorphism.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;

class A_CS{
public:
    A_CS();
    ~A_CS();
    virtual void Show_vir();
    void Test();
};

class AA_CS : public A_CS{
public:
    AA_CS();
    ~AA_CS();
    void Show_vir();
    void Test();
};


A_CS::A_CS()
{
    printf("A_CS::A_CS()\n");
}

A_CS::~A_CS()
{
    printf("A_CS::~A_CS()\n");
}

void A_CS::Show_vir()
{
    printf("A_CS::Show_vir()\n");
}

void A_CS::Test()
{
    printf("A_CS::Test()\n");
}

int main()
{
    std::cout << "Hello C++ Concept - Polymorphism!\n";

    printf("------------------ START -------------------\n");

    A_CS* Base_ptr = NULL;
    
    printf("main() --> A_CS construct\n");
    A_CS A_cs;
    

    printf("main() --> AA_CS construct\n");
    AA_CS AA_cs;


    printf("main() --> use common base_ptr to receive A_cs object\n");
    Base_ptr = &A_cs;
    Base_ptr->Show_vir();
    Base_ptr->Test();
    // printf("main() --> use common base_ptr to receive A_cs_ptr pointer object\n");
    // A_CS *A_cs_ptr = &A_cs;
    // Base_ptr = A_cs_ptr;
    // Base_ptr->Show_vir();
    // Base_ptr->Test();

    printf("\n\n");

    printf("main() --> use common base_ptr to receive AA_cs object\n");
    Base_ptr = &AA_cs;
    Base_ptr->Show_vir();
    Base_ptr->Test();
    // printf("main() --> use common base_ptr to receive AA_cs_ptr pointer object\n");
    // AA_CS *AA_cs_ptr = &AA_cs;
    // Base_ptr = AA_cs_ptr;
    // Base_ptr->Show_vir();
    // Base_ptr->Test();

    printf("------------------- END --------------------\n");
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案

AA_CS::AA_CS()
{
    printf("AA_CS::AA_CS()\n");
}

AA_CS::~AA_CS()
{
    printf("AA_CS::~AA_CS()\n");
}

void AA_CS::Show_vir()
{
    printf("AA_CS::Show_vir()\n");
}

void AA_CS::Test()
{
    printf("AA_CS::Test()");
}
