#include <random>
#include <Application.hpp>
#include <defs.hpp>

Application::Application()
	: m_window(sf::VideoMode(WINDOW_SX, WINDOW_SY), "Game of life")
{
	// m_window.setVerticalSyncEnabled(true);
	m_window.setFramerateLimit(10);
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

		handleEvents();
		sf::sleep(sf::milliseconds(20));
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
			m_cells[x][y] = dis(gen) % 2;
		}
	}
}
