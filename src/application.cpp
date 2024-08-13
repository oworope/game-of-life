#include <Application.hpp>
#include <defs.hpp>
#include <ctime>
#include <cstdlib>

Application::Application()
	: m_window(sf::VideoMode(WINDOW_SX, WINDOW_SY), "Game of life")
{
	// m_window.setVerticalSyncEnabled(true);
	m_window.setFramerateLimit(10);
	srand(std::time(nullptr));
	randomize();
}

void Application::run()
{
	while (m_window.isOpen())
	{
		m_window.clear(sf::Color::Black);
		for (int x = 0; x < WINDOW_SX / CELL_SIZE; x++)
		{
			for (int y = 0; y < WINDOW_SY / CELL_SIZE; y++)
			{
				if (m_cells[x][y] == true)
				{
					sf::RectangleShape square(sf::Vector2f(CELL_SIZE, CELL_SIZE));
					square.setPosition(x * CELL_SIZE, y * CELL_SIZE);
					m_window.draw(square);
				}
			}
		}
		m_window.display();

		handleEvents();
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
	for (int x = 0; x < WINDOW_SX / CELL_SIZE; x++)
	{
		for (int y = 0; y < WINDOW_SY / CELL_SIZE; y++)
		{
			m_cells[x][y] = rand() % 2;
		}
	}
}
