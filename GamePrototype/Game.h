#pragma once
#include "Enemys.h"
#include "Wall.h"
#include "BaseGame.h"
#include <vector>
#include "Player.h"
class Game : public BaseGame
{
public:
	explicit Game( const Window& window );
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game( Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rh-override
	~Game();

	void Update( float elapsedSec ) override;
	void Draw( ) const override;

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e ) override;
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e ) override;
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e ) override;

private:

	// FUNCTIONS
	void Initialize();
	void Cleanup( );
	void ClearBackground( ) const;

	//Functions
	

	// Classes
	
	std::vector<Enemys*> m_pEnemys;
	Player* m_pPlayer;
	// Enemys* m_pEnemy;

	// Members
	Point2f m_PlayerPos{ 40.f, GetViewPort().height / 2 };
	bool m_PlayerUp{};
	bool m_PlayerDown{};
	bool m_PlayerLeft{};
	bool m_PlayerRight{};
	float m_SpawnRectSize{ 80.f };
	Rectf m_Finish{ GetViewPort().width - m_SpawnRectSize, GetViewPort().height / 2 - m_SpawnRectSize / 2, m_SpawnRectSize, m_SpawnRectSize }; 
	Rectf m_Spawn{ 0, GetViewPort().height / 2 - m_SpawnRectSize / 2 ,m_SpawnRectSize, m_SpawnRectSize }; 

	std::vector<Wall*> m_pWalls;
	int m_Level{};
	int m_LevelTest{};
	int m_LevelToWall{3};
	int m_AmountOfEnemys{};

	int m_TotalSwaps{3};
	


};