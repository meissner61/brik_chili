/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	bal(Vec2{ 285.0f,259.0f }, Vec2{ 300.0f,300.0f }),
    playscreen(0.0f, float(Graphics::ScreenWidth),  0.0f, float(Graphics::ScreenHeight))

{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
    const float dt = ft.Mark();
	

   
    bal.Update(dt);
	bal.WallCollision(playscreen);
	pad.Move(wnd.kbd, dt);
	pad.CheckWallCollision(playscreen);
	pad.TopCollision(bal);


}

void Game::ComposeFrame()
{
	pad.Draw(gfx);
    
    bal.DrawOutline(gfx);
	//bal.ShowRectF(gfx);


	gfx.DrawCircleOutline(54.5324f, 50.5432f, 10, Colors::Cyan);


}
