#pragma once
#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include <defs.hpp>

class Application
{
	private:
		void handleEvents();

		sf::RenderWindow m_window;
		bool m_cells[WINDOW_SX / CELL_SIZE][WINDOW_SY / CELL_SIZE];
	
	public:
		Application::Application();
		void run();
};

#endif
