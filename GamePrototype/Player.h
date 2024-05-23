#pragma once
class Player
{
public:
	Player(Point2f location);

	void Draw();
	void Update(Point2f pos);
	void PlayerDead(Point2f enemy);
	bool GetDeadStatus();
	bool GetHidden();
	void SetHidden(bool IsHidden);
	void UpdateHidden();

private:
	Point2f m_Location;
	float m_Radius;
	bool m_Dead;
	Color4f m_Red;
	Color4f m_Green;
	bool m_Hidden;

	int m_MaxChanged;
	int m_TimesChanged;
	bool m_Save{};

};

