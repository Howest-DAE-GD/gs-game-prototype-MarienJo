#pragma once
class Player
{
public:
	Player(Point2f location);

	void Draw();
	void Update(Point2f pos);
	void PlayerDead(Point2f enemy);
	bool GetDeadStatus();

private:
	Point2f m_Location;
	float m_Radius;
	bool m_Dead;

};

