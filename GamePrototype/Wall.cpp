#include "pch.h"
#include "Utils.h"
#include "Wall.h"
#include "Utils.h"

Wall::Wall(Point2f pos)
	:m_Size{ 75 }, m_WallPos{pos}
{
}

void Wall::DrawWalls()
{
	utils::SetColor(Color4f{ 0, 0, 0, 1 });
	utils::FillRect(GetWall());
}

Rectf Wall::GetWall()
{
	return Rectf(m_WallPos.x - (m_Size/2), m_WallPos.y - (m_Size / 2), m_Size, m_Size);
}

bool Wall::ConnectWall(Circlef cirlce)
{
	return utils::GetDistance(m_WallPos, cirlce.center) <= cirlce.radius + (m_Size / 2);
}


