#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <windows.h>
#include "map.h"
#include "view.h"

using namespace sf;


////////////////////////////////////Общий класс родитель//////////////////////////
class Entity {
public:
	float dx, dy, x, y, speed, moveTimer;//добавили переменную таймер для будущих целей
	int w, h, health;
	bool life, isMove, onGround;
	int playerScore;
	Texture texture;
	Sprite sprite;
	Text texts;
	String name;//враги могут быть разные, мы не будем делать другой класс для различающегося врага.всего лишь различим врагов по имени и дадим каждому свое действие в update в зависимости от имени
	Entity(Image& image, float X, float Y, int W, int H, String Name) {
		x = X; y = Y; w = W; h = H; name = Name; moveTimer = 0;
		speed = 0; health = 100; dx = 0; dy = 0;
		life = true; onGround = false; isMove = false;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
	}
};
////////////////////////////////////////////////////КЛАСС ИГРОКА////////////////////////
class Player :public Entity {
public:
	enum { left, right, up, down, jump, stay } state;//добавляем тип перечисления - состояние объекта
	//эта переменная может быть только у игрока
	double minHP_time;
	bool isLife = true;
	
	Player(Image& image, float X, float Y, int W, int H, String Name) :Entity(image, X, Y, W, H, Name) 
	{
		playerScore = 100; state = stay; minHP_time = 0;
		if (name == "Player1") {
			
			sprite.setTextureRect(IntRect(6, 19, w, h));
		}
	}

	void control() 
	{
		if (Keyboard::isKeyPressed) {//если нажата клавиша
			if (Keyboard::isKeyPressed(Keyboard::Left)) {//а именно левая
				state = left; speed = 0.1;
				sprite.setTextureRect(IntRect(14, 902, 40, 30));
				
			}
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				state = right; speed = 0.1;
				sprite.setTextureRect(IntRect(6, 19, 40, 30));
			}
			if ((Keyboard::isKeyPressed(Keyboard::Up)) && (onGround)) {//если нажата клавиша вверх и мы на земле, то можем прыгать
				state = jump; dy = -0.6; onGround = false;//увеличил высоту прыжка
			}
			if (Keyboard::isKeyPressed(Keyboard::Down)) {
				state = down;
			}
		}
	}
	
	void checkCollisionWithMap(float Dx, float Dy, float time)//ф ция проверки столкновений с картой
	{
		for (int i = y / 32; i < (y + h) / 32; i++)				//проходимся по элементам карты
		{
			for (int j = x / 32; j < (x + w) / 32; j++)
			{
				if (TileMap[i][j] == '0')//если элемент наш тайлик земли? то
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
					if (Dx > 0) { x = j * 32 - w; }//с правым краем карты
					if (Dx < 0) { x = j * 32 + 32; }// с левым краем карты
				}
				if (TileMap[i][j] == '1')//если элемент наш тайлик земли? то
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
					if (Dx > 0) { x = j * 32 - w; }//с правым краем карты
					if (Dx < 0) { x = j * 32 + 32; }// с левым краем карты
				}
				if (TileMap[i][j] == '2')//если элемент наш тайлик земли? то
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
					if (Dx > 0) { x = j * 32 - w; }//с правым краем карты
					if (Dx < 0) { x = j * 32 + 32; }// с левым краем карты
				}
				if (TileMap[i][j] == '3')//если элемент наш тайлик земли? то
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
					if (Dx > 0) { x = j * 32 - w; }//с правым краем карты
					if (Dx < 0) { x = j * 32 + 32; }// с левым краем карты
				}
				if (TileMap[i][j] == '4')//если элемент наш тайлик земли? то
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
					if (Dx > 0) { x = j * 32 - w; }//с правым краем карты
					if (Dx < 0) { x = j * 32 + 32; }// с левым краем карты
				}
				if (TileMap[i][j] == '5')//если элемент наш тайлик земли? то
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//столкновение с верхними краями карты(может и не пригодиться)
					if (Dx > 0) { x = j * 32 - w; }//с правым краем карты
					if (Dx < 0) { x = j * 32 + 32; }// с левым краем карты
				}
				//else { onGround = false; }//надо убрать т.к мы можем находиться и на другой поверхности или платформе которую разрушит враг
				if (playerScore < 100)
				{
					if (TileMap[i][j] == 'h')
					{
						playerScore += 20;
						TileMap[i][j] = ' ';
					}
				}
				else if(playerScore >=100)
				{
					if (TileMap[i][j] == 'h')
					{
						TileMap[i][j] = ' ';
					}
				}

				minHP_time += time;

				if (TileMap[i][j] == '6')
				{
					if (minHP_time > 10000)
					{
						playerScore -= 20;
						minHP_time = 0;
					}
				}

			}
		}
	}

	void death(Entity e, float time)
	{
		minHP_time += time;
		if (playerScore > 0)
		{
			if (e.x + e.w >= x && e.x <= x + w && e.y + e.h >= y && e.y <= y + h)				//логика столкновения
			{
				if (y > e.y)
				{
					if (minHP_time > 3000)
					{
						playerScore -= 50;
						minHP_time = 0;
					}
					else if (minHP_time < 3000)
					{
						playerScore -= 0;
						minHP_time = 0;
					}
				}
			}
		}
		else if (playerScore <= 0)
			isLife = false;

	}

	void endGame()
	{
		if (playerScore <= 0)
		{
			isLife = false;
		}
	}

	void update(float time)
	{
		if (isLife) 
		{
			control();//функция управления персонажем
			switch (state)//тут делаются различные действия в зависимости от состояния
			{
			case right:dx = speed; break;//состояние идти вправо
			case left:dx = -speed; break;//состояние идти влево
			case up: break;//будет состояние поднятия наверх (например по лестнице)
			case down: dx = 0; break;//будет состояние во время спуска персонажа (например по лестнице)
			case stay: break;//и здесь тоже		
			}
			x += dx * time;
			checkCollisionWithMap(dx, 0, time);//обрабатываем столкновение по Х
			y += dy * time;
			checkCollisionWithMap(0, dy, time);//обрабатываем столкновение по Y
			sprite.setPosition(x + w / 2, y + h / 2); //задаем позицию спрайта в место его центра
			
			if (!isMove) { speed = 0; }
			//if (!onGround) { dy = dy + 0.0015*time; }//убираем и будем всегда притягивать к земле
			if (life) { getplayercoordinateforview(x, y); }
			dy = dy + 0.0015 * time;//постоянно притягиваемся к земле

			//minHP_time = 0;
			minHP_time += time;
			if (minHP_time > 40000)
			{
				playerScore -= 10;
				minHP_time = 0;
			}
			if (playerScore <= 0) { life = false; speed = 0; }
		}
	}
};

class Enemy :public Entity {
public:
	bool isLife = true;
	Enemy(Image& image, float X, float Y, int W, int H, String Name) :Entity(image, X, Y, W, H, Name) {
		if (name == "EasyEnemy") {
			sprite.setTextureRect(IntRect(91, 234, w, h));
			if (isLife)
				dx = 0.1;//даем скорость.этот объект всегда двигается
			else
				dx = 0;
		}
	}
	void checkCollisionWithMap(float Dx, float Dy)//ф ция проверки столкновений с картой
	{
		for (int i = y / 32; i < (y + h) / 32; i++)//проходимся по элементам карты
			for (int j = x / 32; j < (x + w) / 32; j++)
			{
				if (TileMap[i][j] == '2')//если элемент наш тайлик земли, то
				{
					if (Dy > 0) { y = i * 32 - h; }//по Y вниз=>идем в пол(стоим на месте) или падаем. В этот момент надо вытолкнуть персонажа и поставить его на землю, при этом говорим что мы на земле тем самым снова можем прыгать
					if (Dy < 0) { y = i * 32 + 32; }//столкновение с верхними краями карты(может и не пригодиться)
					if (Dx > 0) { x = j * 32 - w; dx = -0.1; sprite.scale(-1, 1); }//с правым краем карты
					if (Dx < 0) { x = j * 32 + 32; dx = 0.1; sprite.scale(-1, 1); }// с левым краем карты
				}
				
			}
	}
	void update(float time, Player p)
	{
		if(isLife)
		{
			if (name == "EasyEnemy") 
			{//для персонажа с таким именем логика будет такой
				//moveTimer += time;if (moveTimer>3000){ dx *= -1; moveTimer = 0; }//меняет направление примерно каждые 3 сек
				checkCollisionWithMap(dx, 0);//обрабатываем столкновение по Х
				x += dx * time;
				sprite.setPosition(x + w / 2, y + h / 2); //задаем позицию спрайта в место его центра
				
			}
		
			if (p.x + p.w >= x && p.x <= x + w && p.y + p.h >= y && p.y <= y + h)
			{ //Проверка передвижения по границам карты

				if (y > p.y)
				{

					playerScore -= 50;

				}
			}
			if (playerScore <= 0) { life = false; speed = 0; }
		}
	}	
};
