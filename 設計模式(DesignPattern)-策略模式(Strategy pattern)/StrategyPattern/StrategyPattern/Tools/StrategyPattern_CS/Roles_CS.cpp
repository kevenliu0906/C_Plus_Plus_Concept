#include "stdafx.h"
#include "Roles_CS.h"
//#include "Attack_Type_CS.h"


//------------------------------------------------------------------
/////           Roles_CS         //////
Roles_CS::Roles_CS()
{
	m_Attack_Type_cs_pr = NULL;
	m_Fly_Type_cs_pr = NULL;
}
//------------------------------------------------------------------
Roles_CS::Roles_CS(Attack_Type_CS *temp_Attack_pr, Fly_Type_CS *temp_Fly_pr)
{
	m_Attack_Type_cs_pr = temp_Attack_pr;
	m_Fly_Type_cs_pr = temp_Fly_pr;
}
//------------------------------------------------------------------
void Roles_CS::Attack_Fn()
{
	if (m_Attack_Type_cs_pr != NULL)
		m_Attack_Type_cs_pr->Attack_Fn();
}
//------------------------------------------------------------------
void Roles_CS::Fly_Fn()
{
	if (m_Fly_Type_cs_pr != NULL)
		m_Fly_Type_cs_pr->Fly_Fn();
}
//------------------------------------------------------------------
void Roles_CS::Set_Attack_Type_Fn(Attack_Type_CS *temp_Attack_type_pr)
{
	m_Attack_Type_cs_pr = temp_Attack_type_pr;
}
//------------------------------------------------------------------
void Roles_CS::Set_Fly_Type_Fn(Fly_Type_CS *temp_Fly_type_pr)
{
	m_Fly_Type_cs_pr = temp_Fly_type_pr;
}
//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
/////           Warrior_CS         //////
Warrior_CS::Warrior_CS()
	:Roles_CS()
{
	//m_Attack_Type_cs_pr = NULL;
	//m_Fly_Type_cs_pr = NULL;
}
//------------------------------------------------------------------
Warrior_CS::Warrior_CS(Attack_Type_CS *temp_Attack_pr, Fly_Type_CS *temp_Fly_pr)
	:Roles_CS(temp_Attack_pr, temp_Fly_pr)
{
	//m_Attack_Type_cs_pr = temp_Attach_pr;
	//m_Fly_Type_cs_pr = temp_Fly_pr;
}
//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------
/////           DragonRidor_CS         //////
DragonRidor_CS::DragonRidor_CS()
	:Roles_CS()
{

}
//------------------------------------------------------------------
DragonRidor_CS::DragonRidor_CS(Attack_Type_CS *temp_Attack_pr, Fly_Type_CS *temp_Fly_pr)
	: Roles_CS(temp_Attack_pr, temp_Fly_pr)
{

}
//------------------------------------------------------------------
//------------------------------------------------------------------
//------------------------------------------------------------------