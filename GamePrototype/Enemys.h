#pragma once
class Enemys
{
public:
	Enemys(Point2f location, Color4f color);

	void DrawEnemys();
	void UpdateHunt(Point2f playerLocation, int level); //Point2f playerLocation
	bool IsOverlapping(Circlef circle);
	Point2f GetLocation();
	void ResetLocations(Point2f newLocation);

private:
	Point2f m_Location;
	Color4f m_Color;
	float m_Size;
	float m_ScanRadius;
	float m_TotalRad;
};

