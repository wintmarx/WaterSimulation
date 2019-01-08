#pragma once
#include "GUI/Screen.h"

class SPHScreen :
	public Screen
{
public:
	SPHScreen(int width, int height);
	virtual ~SPHScreen();
	void Update(float delta);
	void Render(Graphics *graphics);
	void OnKeyPress(int buttonID, bool isPressed);
	void OnKeyRelease(int buttonID);
	void Initialize();
};

