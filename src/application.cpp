#include <Application.hpp>
#include <ctime>
#include <cstdlib>

Application::Application()
{
	sf::RenderWindow m_window(sf::VideoMode(1200, 800), "Game of life");
	m_window.setVerticalSyncEnabled(true);
	srand(std::time(nullptr));

	for (int x = 0; x < WINDOW_SX / CELL_SIZE; x++)
	{
		for (int y = 0; y < WINDOW_SY / CELL_SIZE; x++)
		{
			this->cells[x][y] = rand() % 2;
		}
	}
}

void Application::run()
{
	while (m_window.isOpen())
	{
		m_window.clear(sf::Color::Black);
		for (int x = 0; x < WINDOW_SX / CELL_SIZE; x++)
		{
			for (int y = 0; y < WINDOW_SY / CELL_SIZE; x++)
			{
				if (this->cells[x][y] == true)
				{
					sf::RectangleShape square(sf::Vector2f(3.0f, 2.0f));
					m_window.draw(square);
				}
			}
		}
		m_window.display();
	}
}

void Application::handleEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		// "close requested" event: we close the window
		if (event.type == sf::Event::Closed) m_window.close();
	}
}
