#include <random>
#include <Application.hpp>
#include <defs.hpp>

Application::Application()
	: m_window(sf::VideoMode(WINDOW_SX, WINDOW_SY), "Game of life")
{
	// m_window.setVerticalSyncEnabled(true);
	m_window.setFramerateLimit(1);
	randomize();
}

void Application::run()
{
	while (m_window.isOpen())
	{
		// Update stuff
		
		for (int x = 0; x < WINDOW_SX / CELL_SIZE; x++)
		{
			for (int y = 0; y < WINDOW_SY / CELL_SIZE; y++)
			{
				int counter = 0;
				for (int i = -1; i < 2; i++)
				{
					for (int j = -1; j < 2; j++)
					{
						if
						(
							m_live_cells[!m_tick_state][x + i][y + j] == true
						    && i != 0
						    && j != 0
						)
						{
							counter++;
						}
					}
				}
				// if (m_live_cells[!m_tick_state][x][y] == true)
				// {
				// 	if (counter < 2 || counter > 3)
				// 	{
				// 		m_live_cells[m_tick_state][x][y] = false;
				// 	}
				// }
				// else
				// {
				// 	if (counter == 3)
				// 	{
				// 		m_live_cells[m_tick_state][x][y] = true;
				// 	}
				// }
				if (m_live_cells[!m_tick_state][x][y] == true)
				{
					if (counter > 5) { m_live_cells[m_tick_state][x][y] = false; }
				}
			}
		}

		// ^^^ Horrible code ^^^

		// Draw stuff
		
		m_window.clear(sf::Color::Black);
		for (int x = 0; x < WINDOW_SX / CELL_SIZE; x++)
		{
			for (int y = 0; y < WINDOW_SY / CELL_SIZE; y++)
			{
				if (m_live_cells[!m_tick_state][x][y] == true)
				{
					sf::RectangleShape square(sf::Vector2f(CELL_SIZE, CELL_SIZE));
					square.setPosition
					(
					 	static_cast<float>(x * CELL_SIZE),
						static_cast<float>(y * CELL_SIZE)
					);
					m_window.draw(square);
				}
			}
		}
		m_window.display();
		m_tick_state = !m_tick_state; // next tick

		handleEvents();
		// sf::sleep(sf::milliseconds(20));
	}
}

void Application::handleEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		// "close requested" event: we close the window
		switch (event.type)
		{
			case sf::Event::Closed: 
			{
				m_window.close();
				break;
			}
			case sf::Event::KeyPressed:
			{
				switch (event.key.scancode)
				{
					case sf::Keyboard::Scan::Escape:
					{
						m_window.close();
						break;
					}
					case sf::Keyboard::Scan::Space:
					{
						randomize();
						break;
					}
					default: break;
				}
			}
		default: break;
		}
	}
}

void Application::randomize()
{

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, 10000);
	
	for (int x = 0; x < WINDOW_SX / CELL_SIZE; x++)
	{
		for (int y = 0; y < WINDOW_SY / CELL_SIZE; y++)
		{
			m_live_cells[0][x][y] = dis(gen) % 2;
		}
	}

	m_tick_state = 1;
}
