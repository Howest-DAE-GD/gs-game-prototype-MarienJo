#include "pch.h"
#include "Utils.h"
#include "Player.h"

Player::Player(Point2f location)
	:m_Location{location}, m_Radius{13.f}, m_Dead{false}
{
}

void Player::Draw()
{
	utils::SetColor(Color4f{ 1.f, 0.f, 0.f, 1.f });
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
