
#include <SFML\Graphics.hpp>

using namespace std;

int main()
{
	int tilesize = 20;
	sf::RenderWindow window{ sf::VideoMode{180,180}, "Auto Tilemap" };

	
	int tilemap[10][10]{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,0,0,1,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,1},
	{1,0,1,1,1,0,0,1,1,1},
	{1,0,0,0,0,0,0,1,0,1},
	{1,1,1,1,1,1,1,1,1,1}
	};

	int vartile = 0;

	sf::Texture texture;
	if (!texture.loadFromFile("tileset.png", sf::IntRect(0, 0, 100, 100)))
	{
		// error...
	}
sf::Sprite sprite[16];
for (int i = 0, j = 0; i < 16; i++) {

	sprite[i].setTexture(texture);


	sprite[i].setTextureRect(sf::IntRect((i&3)*tilesize, (i>>2)*tilesize, tilesize, tilesize));

}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White  );
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				
				vartile = (tilemap[i][j] + tilemap[i+1][j]*2 + tilemap[i][j+1]*4 + tilemap[i+1][j+1]*8);
				sprite[vartile].setPosition(sf::Vector2f(i*20.f, j*20.f));
				window.draw(sprite[vartile]);

			}
		}

		window.display();
	}

	return 0;
}
