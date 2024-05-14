#include "pch.h"
#include "Enemys.h"
#include "utils.h"
#include <algorithm>
#include <iostream>

Enemys::Enemys(Point2f location, Color4f color)
	:m_Color{color}, m_Location{ location }, m_Size{17.f}, m_ScanRadius{60.f}, m_TotalRad{ m_Size + m_ScanRadius }
{
}

void Enemys::DrawEnemys()
{
	utils::SetColor(m_Color);
	utils::FillTriangle(Point2f{ m_Location.x - m_Size, m_Location.y - m_Size },
		Point2f{ m_Location.x, m_Location.y + m_Size }, Point2f{ m_Location.x + m_Size, m_Location.y - m_Size }); 
}

void Enemys::UpdateHunt(Point2f playerLocation) 
{
	if (m_Location.x <= playerLocation.x) ++m_Location.x;
	if (m_Location.x > playerLocation.x) --m_Location.x;
	if (m_Location.y <= playerLocation.y) ++m_Location.y;
	if (m_Location.y > playerLocation.y) --m_Location.y;

}

bool Enemys::IsOverlapping(Circlef circle)
{
	bool test{};
	return utils::GetDistance(m_Location, circle.center) <= circle.radius + m_TotalRad;
}

Point2f Enemys::GetLocation()
{
	return m_Location;
}

void Enemys::ResetLocations(Point2f newLocation)
{
	m_Location = newLocation;
}

