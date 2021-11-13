#pragma once

#include <map>
#include <sstream>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Game
{
private:
	//Window
	sf::RenderWindow* window;
	
	//Resources
	std::map <std::string, sf::Texture*> textures;
	std::vector <Bullet*> bullets;

	//World
	sf::Texture bgTexture;
	sf::Sprite background;

	//Systems
	unsigned points;

	//Player
	Player* player;

	//PlayerGUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	//Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector <Enemy*> enemies;

	//GUI
	sf::Font font;
	sf::Text pointText;

	sf::Text gameOverText;

	//Private functions
	void initWindow();
	void initTextures();
	void initGui();
	void initWorld();
	void initSystems();

	void initPlayer();
	void initEnemies();
public:
	Game();
	virtual ~Game();
	
	//Functions
	void run();

	void processEvents();
	void updateInput();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateBullets();
	void updateEnemies();
	void updateCombat();
	void update();

	void renderWorld();
	void renderGUI();
	void render();
};

