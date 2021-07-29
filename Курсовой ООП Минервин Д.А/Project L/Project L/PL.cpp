#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <list>
#include <vector>
#include "Player.h"
#include "map.h"
#include "view.h"

using namespace sf;																	//включаем пространство имен sf, чтобы постоянно не писать sf::

void menu(RenderWindow& window)
{
	Image menuImage1, menuImage2, menuImage3;
	menuImage1.loadFromFile("images/111.png");
	menuImage2.loadFromFile("images/222.png");
	menuImage3.loadFromFile("images/333.png");
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromImage(menuImage1);
	menuTexture2.loadFromImage(menuImage2);
	menuTexture3.loadFromImage(menuImage3);
	aboutTexture.loadFromFile("images/about.png");
	menuBackground.loadFromFile("images/gora.jpg");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(350, 30);
	menu2.setPosition(350, 90);
	menu3.setPosition(350, 150);
	menuBg.setPosition(0, 0);
	about.setPosition(300, 30);

	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(0, 100, 2));
		if (IntRect(350, 30, 550, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
		if (IntRect(350, 90, 550, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
		if (IntRect(350, 150, 550, 50).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Blue); menuNum = 3; }
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) 
				isMenu = false;//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2)
			{
				window.draw(menuBg);
				window.draw(about); 
				window.display(); 
				while (!Keyboard::isKeyPressed(Keyboard::Escape)); 
			}
			if (menuNum == 3) 
			{
				window.close(); 
				isMenu = false;
			}
		}
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.display();
	}
}

bool startGame()
{
	RenderWindow window(VideoMode(890, 720), "HERO");
	menu(window);
	view.reset(FloatRect(0, 0, 640, 480));
	
	Image map_image; //создаем обьект изображение карты 
	map_image.loadFromFile("images/map.png"); //загружаем файл
	
	Texture map; //создаем обьект текстуры
	map.loadFromImage(map_image); // передаем в него обьект Image
	
	Sprite s_map; //создаем обьект спрайт
	s_map.setTexture(map); //передаем в него обьект Texture
	
	Image heroImage; //создаем обьект изображения героя
	heroImage.loadFromFile("images/MilesTailsPrower.gif");  //загружаем файл
	
	Image easyEnemyImage; //создаем обьект изображения врага
	easyEnemyImage.loadFromFile("images/hero1.png");  //загружаем файл
	easyEnemyImage.createMaskFromColor(Color(255, 0, 0));
	
	Player p(heroImage, 50, 900, 40, 30, "Player1");//объект класса игрока
	Enemy easyEnemy1(easyEnemyImage, 850, 1041, 95, 55, "EasyEnemy");//простой враг, объект класса врага
	Enemy easyEnemy2(easyEnemyImage, 150, 1041, 95, 55, "EasyEnemy");
	
	Clock clock;
	Clock gameTimeClock; //переменная игрового времени
	double createObjectMapTime = 0; //перемененая времени добавление на карте сердечек
	double gameTime = 0; //обьявление игрового времени

	Font font;//шрифт 
	font.loadFromFile("CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
	Text text1("", font, 40);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	text1.setFillColor(Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый







	while (window.isOpen())
	{
		Event event;
		float time = clock.getElapsedTime().asMicroseconds();
		
		if (p.isLife) //остановка игры
		{
			gameTime = gameTimeClock.getElapsedTime().asSeconds();
		}
		clock.restart();   //перезагружает время
		time = time / 800; //скорость игры
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		createObjectMapTime += time;
		if (p.isLife) {    //добавление сердечек каждие 7с
			if (createObjectMapTime > 7000)
			{
				randomMapGenerate();
				createObjectMapTime = 0;
			}
		}

		
		
		if (Keyboard::isKeyPressed(Keyboard::Escape)) { return false; }//если эскейп, то выходим из игры
		if (!p.isLife)
		{
			s_map.setColor(Color::White);
			std::ostringstream gameOverTime;
			gameOverTime << gameTime;
			text1.setString("Game Over\n      " +  gameOverTime.str() + "s");
			text1.setPosition(view.getCenter().x-50, view.getCenter().y-50);
			if (createObjectMapTime > 7000)
			{
				return true;
			}
		}

		p.update(time);// Player update function	
		easyEnemy1.update(time, p);//easyEnemy update function
		easyEnemy2.update(time, p);
		window.setView(view);
		window.clear();  //очистка экрана
		
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(160, 0, 32, 32));
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(192, 0, 32, 32));
				if ((TileMap[i][j] == '1')) s_map.setTextureRect(IntRect(224, 0, 32, 32));
				if ((TileMap[i][j] == '2')) s_map.setTextureRect(IntRect(256, 0, 32, 32));
				if ((TileMap[i][j] == '3')) s_map.setTextureRect(IntRect(416, 0, 32, 32));
				if ((TileMap[i][j] == '4')) s_map.setTextureRect(IntRect(448, 0, 32, 32));
				if ((TileMap[i][j] == '5')) s_map.setTextureRect(IntRect(384, 0, 32, 32));
				if ((TileMap[i][j] == '6')) s_map.setTextureRect(IntRect(480, 0, 32, 32));
				if ((TileMap[i][j] == 'f')) s_map.setTextureRect(IntRect(96, 0, 32, 32));
				if ((TileMap[i][j] == 'h')) s_map.setTextureRect(IntRect(128, 0, 32, 32));
				s_map.setPosition(j * 32, i * 32);

				window.draw(s_map);
			}

		
		p.death(easyEnemy1, time);
		p.death(easyEnemy2, time);

		std::ostringstream playerScoreSrting, playerTime;
		playerScoreSrting << p.playerScore; 
		playerTime << gameTime;
		text.setString("Жизнь: " + playerScoreSrting.str() + "\nВремя: " + playerTime.str());
		text.setPosition(view.getCenter().x-50, view.getCenter().y - 240);
		
		window.draw(text);
		window.draw(text1);
		window.draw(easyEnemy1.sprite);
		window.draw(easyEnemy2.sprite);
		window.draw(p.sprite);
		window.display();
	}
	return 0;
}

void gameRunning() {//ф-ция перезагружает игру , если это необходимо
	if (startGame()) 
	{
		gameRunning();
	}
	//если startGame() == true, то вызываем занова ф-цию gameRunning, 
	//которая в свою очередь опять вызывает startGame() 
}

int main()
{
	gameRunning();
	return 0;
}