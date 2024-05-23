#include "pch.h"
#include "Utils.h"
#include "Player.h"
#include <iostream>

Player::Player(Point2f location)
	:m_Location{ location }, m_Radius{ 13.f }, m_Dead{ false }, m_Red{ 1, 0, 0, 1 }, m_Green{ 0, 1, 0, 1 }, m_Hidden{ false }, m_MaxChanged{3}, m_TimesChanged{}
{
}

void Player::Draw()
{
	if (m_Hidden == true)
	{
		utils::SetColor(m_Green);
		m_Save == true;
	}
	else 
	{
		utils::SetColor(m_Red);
		m_Save == false;
	}
	utils::FillEllipse(m_Location, m_Radius, m_Radius);
}

void Player::Update(Point2f pos)
{
	m_Location = pos;
}

void Player::PlayerDead(Point2f enemy)
{
	if (utils::GetDistance(m_Location, enemy) <= m_Radius) m_Dead = true;
	
}

bool Player::GetDeadStatus()
{
	return m_Dead;
}

bool Player::GetHidden()
{
	return m_Hidden;
}

void Player::SetHidden(bool IsHidden)
{
	m_Hidden = IsHidden;
	

	 
}

void Player::UpdateHidden()
{
	
}



