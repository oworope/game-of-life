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
		bool m_live_cells[2][WINDOW_SX / CELL_SIZE][WINDOW_SY / CELL_SIZE];
		bool m_tick_state = 0;

		// ^Basically we have 2 arrays of world state
		// We will switch between them on each "tick"
		// To avoid copying them

		// So if you want to use previous tick
		// just say m_livecells[!m_tick_state]...
	
	public:
		Application();
		void run();
		void randomize();
};

#endif
