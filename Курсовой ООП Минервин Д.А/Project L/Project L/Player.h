#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <windows.h>
#include "map.h"
#include "view.h"

using namespace sf;


////////////////////////////////////����� ����� ��������//////////////////////////
class Entity {
public:
	float dx, dy, x, y, speed, moveTimer;//�������� ���������� ������ ��� ������� �����
	int w, h, health;
	bool life, isMove, onGround;
	int playerScore;
	Texture texture;
	Sprite sprite;
	Text texts;
	String name;//����� ����� ���� ������, �� �� ����� ������ ������ ����� ��� �������������� �����.����� ���� �������� ������ �� ����� � ����� ������� ���� �������� � update � ����������� �� �����
	Entity(Image& image, float X, float Y, int W, int H, String Name) {
		x = X; y = Y; w = W; h = H; name = Name; moveTimer = 0;
		speed = 0; health = 100; dx = 0; dy = 0;
		life = true; onGround = false; isMove = false;
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setOrigin(w / 2, h / 2);
	}
};
////////////////////////////////////////////////////����� ������////////////////////////
class Player :public Entity {
public:
	enum { left, right, up, down, jump, stay } state;//��������� ��� ������������ - ��������� �������
	//��� ���������� ����� ���� ������ � ������
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
		if (Keyboard::isKeyPressed) {//���� ������ �������
			if (Keyboard::isKeyPressed(Keyboard::Left)) {//� ������ �����
				state = left; speed = 0.1;
				sprite.setTextureRect(IntRect(14, 902, 40, 30));
				
			}
			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				state = right; speed = 0.1;
				sprite.setTextureRect(IntRect(6, 19, 40, 30));
			}
			if ((Keyboard::isKeyPressed(Keyboard::Up)) && (onGround)) {//���� ������ ������� ����� � �� �� �����, �� ����� �������
				state = jump; dy = -0.6; onGround = false;//�������� ������ ������
			}
			if (Keyboard::isKeyPressed(Keyboard::Down)) {
				state = down;
			}
		}
	}
	
	void checkCollisionWithMap(float Dx, float Dy, float time)//� ��� �������� ������������ � ������
	{
		for (int i = y / 32; i < (y + h) / 32; i++)				//���������� �� ��������� �����
		{
			for (int j = x / 32; j < (x + w) / 32; j++)
			{
				if (TileMap[i][j] == '0')//���� ������� ��� ������ �����? ��
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//�� Y ����=>���� � ���(����� �� �����) ��� ������. � ���� ������ ���� ���������� ��������� � ��������� ��� �� �����, ��� ���� ������� ��� �� �� ����� ��� ����� ����� ����� �������
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//������������ � �������� ������ �����(����� � �� �����������)
					if (Dx > 0) { x = j * 32 - w; }//� ������ ����� �����
					if (Dx < 0) { x = j * 32 + 32; }// � ����� ����� �����
				}
				if (TileMap[i][j] == '1')//���� ������� ��� ������ �����? ��
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//�� Y ����=>���� � ���(����� �� �����) ��� ������. � ���� ������ ���� ���������� ��������� � ��������� ��� �� �����, ��� ���� ������� ��� �� �� ����� ��� ����� ����� ����� �������
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//������������ � �������� ������ �����(����� � �� �����������)
					if (Dx > 0) { x = j * 32 - w; }//� ������ ����� �����
					if (Dx < 0) { x = j * 32 + 32; }// � ����� ����� �����
				}
				if (TileMap[i][j] == '2')//���� ������� ��� ������ �����? ��
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//�� Y ����=>���� � ���(����� �� �����) ��� ������. � ���� ������ ���� ���������� ��������� � ��������� ��� �� �����, ��� ���� ������� ��� �� �� ����� ��� ����� ����� ����� �������
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//������������ � �������� ������ �����(����� � �� �����������)
					if (Dx > 0) { x = j * 32 - w; }//� ������ ����� �����
					if (Dx < 0) { x = j * 32 + 32; }// � ����� ����� �����
				}
				if (TileMap[i][j] == '3')//���� ������� ��� ������ �����? ��
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//�� Y ����=>���� � ���(����� �� �����) ��� ������. � ���� ������ ���� ���������� ��������� � ��������� ��� �� �����, ��� ���� ������� ��� �� �� ����� ��� ����� ����� ����� �������
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//������������ � �������� ������ �����(����� � �� �����������)
					if (Dx > 0) { x = j * 32 - w; }//� ������ ����� �����
					if (Dx < 0) { x = j * 32 + 32; }// � ����� ����� �����
				}
				if (TileMap[i][j] == '4')//���� ������� ��� ������ �����? ��
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//�� Y ����=>���� � ���(����� �� �����) ��� ������. � ���� ������ ���� ���������� ��������� � ��������� ��� �� �����, ��� ���� ������� ��� �� �� ����� ��� ����� ����� ����� �������
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//������������ � �������� ������ �����(����� � �� �����������)
					if (Dx > 0) { x = j * 32 - w; }//� ������ ����� �����
					if (Dx < 0) { x = j * 32 + 32; }// � ����� ����� �����
				}
				if (TileMap[i][j] == '5')//���� ������� ��� ������ �����? ��
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//�� Y ����=>���� � ���(����� �� �����) ��� ������. � ���� ������ ���� ���������� ��������� � ��������� ��� �� �����, ��� ���� ������� ��� �� �� ����� ��� ����� ����� ����� �������
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//������������ � �������� ������ �����(����� � �� �����������)
					if (Dx > 0) { x = j * 32 - w; }//� ������ ����� �����
					if (Dx < 0) { x = j * 32 + 32; }// � ����� ����� �����
				}
				//else { onGround = false; }//���� ������ �.� �� ����� ���������� � �� ������ ����������� ��� ��������� ������� �������� ����
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
			if (e.x + e.w >= x && e.x <= x + w && e.y + e.h >= y && e.y <= y + h)				//������ ������������
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
			control();//������� ���������� ����������
			switch (state)//��� �������� ��������� �������� � ����������� �� ���������
			{
			case right:dx = speed; break;//��������� ���� ������
			case left:dx = -speed; break;//��������� ���� �����
			case up: break;//����� ��������� �������� ������ (�������� �� ��������)
			case down: dx = 0; break;//����� ��������� �� ����� ������ ��������� (�������� �� ��������)
			case stay: break;//� ����� ����		
			}
			x += dx * time;
			checkCollisionWithMap(dx, 0, time);//������������ ������������ �� �
			y += dy * time;
			checkCollisionWithMap(0, dy, time);//������������ ������������ �� Y
			sprite.setPosition(x + w / 2, y + h / 2); //������ ������� ������� � ����� ��� ������
			
			if (!isMove) { speed = 0; }
			//if (!onGround) { dy = dy + 0.0015*time; }//������� � ����� ������ ����������� � �����
			if (life) { getplayercoordinateforview(x, y); }
			dy = dy + 0.0015 * time;//��������� ������������� � �����

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
				dx = 0.1;//���� ��������.���� ������ ������ ���������
			else
				dx = 0;
		}
	}
	void checkCollisionWithMap(float Dx, float Dy)//� ��� �������� ������������ � ������
	{
		for (int i = y / 32; i < (y + h) / 32; i++)//���������� �� ��������� �����
			for (int j = x / 32; j < (x + w) / 32; j++)
			{
				if (TileMap[i][j] == '2')//���� ������� ��� ������ �����, ��
				{
					if (Dy > 0) { y = i * 32 - h; }//�� Y ����=>���� � ���(����� �� �����) ��� ������. � ���� ������ ���� ���������� ��������� � ��������� ��� �� �����, ��� ���� ������� ��� �� �� ����� ��� ����� ����� ����� �������
					if (Dy < 0) { y = i * 32 + 32; }//������������ � �������� ������ �����(����� � �� �����������)
					if (Dx > 0) { x = j * 32 - w; dx = -0.1; sprite.scale(-1, 1); }//� ������ ����� �����
					if (Dx < 0) { x = j * 32 + 32; dx = 0.1; sprite.scale(-1, 1); }// � ����� ����� �����
				}
				
			}
	}
	void update(float time, Player p)
	{
		if(isLife)
		{
			if (name == "EasyEnemy") 
			{//��� ��������� � ����� ������ ������ ����� �����
				//moveTimer += time;if (moveTimer>3000){ dx *= -1; moveTimer = 0; }//������ ����������� �������� ������ 3 ���
				checkCollisionWithMap(dx, 0);//������������ ������������ �� �
				x += dx * time;
				sprite.setPosition(x + w / 2, y + h / 2); //������ ������� ������� � ����� ��� ������
				
			}
		
			if (p.x + p.w >= x && p.x <= x + w && p.y + p.h >= y && p.y <= y + h)
			{ //�������� ������������ �� �������� �����

				if (y > p.y)
				{

					playerScore -= 50;

				}
			}
			if (playerScore <= 0) { life = false; speed = 0; }
		}
	}	
};
