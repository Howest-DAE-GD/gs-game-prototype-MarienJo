#include "pch.h"
#include <iostream>
#include "Utils.h"
#include "Game.h"

Game::Game( const Window& window ) 
	:BaseGame{ window }
{
	srand(int(time(nullptr)));
	Initialize();
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{


	
	m_AmountOfEnemys = 2;

	m_pPlayer = new Player(Point2f{});
//	m_pEnemys.push_back(new Enemys(Point2f{ 300.f, 200.f }, Color4f{ 0, 1,0,1 }));
	m_pEnemys.push_back(new Enemys(Point2f{ 200.f, 300.f }, Color4f{ 0, 1,0,1 }));
	m_pEnemys.push_back(new Enemys(Point2f{ 500.f, 400.f }, Color4f{ 0, 1,0,1 }));

	
	
}

void Game::Cleanup( )
{
	delete m_pPlayer;
	m_pPlayer = nullptr;

	//for (int i{}; m_pEnemys.size() > 0; ++i)
	//{
	//	m_pEnemys[i].pop_back();
	//  m_pEnemys[i] = nullptr
	//}
	
}

void Game::Update( float elapsedSec )
{
#pragma region SpawnEnemys
	if (m_LevelTest > 1)
	{
		++m_AmountOfEnemys;
		m_LevelTest = 0;
	}
	if (m_pEnemys.size() != m_AmountOfEnemys)
	{
		m_pEnemys.push_back(new Enemys(Point2f{ 300.f, 200.f }, Color4f{ 0, 1,0,1 }));
		std::cout << "Size: " << m_pEnemys.size() << std::endl;
		
	}
#pragma endregion

	if (m_pPlayer->GetDeadStatus() == false)
	{
		for (int i{}; i < m_pEnemys.size(); ++i)
		{
			if (m_pEnemys[i]->IsOverlapping(Circlef{ m_PlayerPos, 20.f }))
			{
				m_pEnemys[i]->UpdateHunt(m_PlayerPos);
			}
			m_pPlayer->PlayerDead(m_pEnemys[i]->GetLocation());
		}
		

		// m_pEnemy->UpdateHunt(m_PlayerPos);
		m_pPlayer->Update(m_PlayerPos);

#pragma region player Move
		const Uint8* pStates = SDL_GetKeyboardState(nullptr); // TODO: Vector2f for moving = cos for upwards and downwords.
		if (pStates[SDL_SCANCODE_RIGHT])
		{
			//std::cout << "Right arrow key is down\n";
			m_PlayerPos.x += 1.1f;
		}
		if (pStates[SDL_SCANCODE_LEFT])
		{
			//std::cout << "Left arrow key is down\n";
			m_PlayerPos.x -= 1.1f;
		}
		if (pStates[SDL_SCANCODE_UP])
		{
			//std::cout << "Up arrow key is down\n";
			m_PlayerPos.y += 1.1f;
		}
		if (pStates[SDL_SCANCODE_DOWN])
		{
			//std::cout << "Down arrow key is down\n";
			m_PlayerPos.y -= 1.1f;
		}
#pragma endregion

		// Got to the other side.
		if (utils::IsPointInRect(m_PlayerPos, m_Finish))
		{
			m_PlayerPos = Point2f{ 10.f, GetViewPort().height / 2 };
			++m_Level;
			++m_LevelTest;
			std::cout << "Level: " << m_Level << std::endl;
			for (int i{}; i < m_pEnemys.size(); ++i)
			{
				m_pEnemys[i]->ResetLocations(Point2f{float(rand() % 600) + 150, float(rand()% 500)});
			}
		}

		if (m_PlayerPos.x >= GetViewPort().width) m_PlayerPos.x = GetViewPort().width - 1;
		if (m_PlayerPos.x < 0) m_PlayerPos.x = 1;
		if (m_PlayerPos.y < 0) m_PlayerPos.y = 1;
		if (m_PlayerPos.y >= GetViewPort().height) m_PlayerPos.y = GetViewPort().height - 1;

	}
	else
	{
		std::cout << "Dead \n";
	}
}

void Game::Draw( ) const
{
	ClearBackground( );

	
	#pragma region DrawSpawn
	utils::SetColor(Color4f{ 0.3f, 0.3f, 0.3f, 1.0f });
	utils::FillRect(m_Spawn);
	#pragma endregion
	#pragma region DrawFinish
	utils::SetColor(Color4f{ 0.2f, 0.2f, 0.2f, 1.0f });
	utils::FillRect(m_Finish);
	#pragma endregion


	if (m_pPlayer->GetDeadStatus() == false) m_pPlayer->Draw();
	
	 
	for (int i{ 0 }; i < m_pEnemys.size(); ++i)
	{
		m_pEnemys[i]->DrawEnemys();
	}
	
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	// switch ( e. )
	// {
	// case SDLK_LEFT:
	// 	m_PlayerLeft = true;
	// 	break;
	// case SDLK_RIGHT:
	// 	m_PlayerRight = true;
	// 	break;
	// case SDLK_UP:
	// 	m_PlayerUp = true;
	// 	break;
	// case SDLK_DOWN:
	// 	m_PlayerDown = true;
	// 	break;
	// }
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	// switch (e.keysym.sym)
	// {
	// case SDLK_LEFT:
	// 	m_PlayerLeft = false;
	// 	break;
	// case SDLK_RIGHT:
	// 	m_PlayerRight = false;
	// 	break;
	// case SDLK_UP:
	// 	m_PlayerUp = false;
	// 	break;
	// case SDLK_DOWN:
	// 	m_PlayerDown = false;
	// 	break;
	// }
	
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
	
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.5f, 0.5f, 0.5f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}


