#pragma once
class Wall
{
public:
	Wall(Point2f pos);
	void DrawWalls();
	Rectf GetWall();
	bool ConnectWall(Circlef cirlce);
private:
	int m_Size;
	Point2f m_WallPos;
	Rectf Rectangle;

};

