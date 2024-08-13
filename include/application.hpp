#pragma once
#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include <defs.hpp>

class Application
{
	private:
		Application::Application();
		void handleEvents();

		sf::RenderWindow m_window;
		bool cells[WINDOW_SX / CELL_SIZE][WINDOW_SY / CELL_SIZE];
	
	public:
		void run();
}

#endif
