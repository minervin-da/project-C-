#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

sf::View view;														//�������� sfml ������ "���", ������� � �������� �������

void getplayercoordinateforview(float x, float y) 
{																	//������� ��� ���������� ��������� ������
	float tempX = x; float tempY = y;								//��������� ����� ������ � ��������� ��, ����� ������ ����
	if (x < 352)
		tempX = 352;												//������� �� ���� ����� �������
	if (x > 930)
		tempX = 930;
	if (y < 240)
		tempY = 240;												//������� �������
	if (y > 878) 
		tempY = 878;												//������ �������	
	view.setCenter(tempX, tempY);									//������ �� �������, ��������� ��� ����������. 
}
