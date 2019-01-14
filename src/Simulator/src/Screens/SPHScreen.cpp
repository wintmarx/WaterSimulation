#define _USE_MATH_DEFINES
#include "Screens/SPHScreen.h"
#include <cmath>

SPHScreen::~SPHScreen()
{
}

SPHScreen::SPHScreen(int width, int height) : Screen(width, height)
{
	glClearColor(1.f, 1.f, 1.f, 1.f);
	float scaleCoeff = 1. / width;
	projection = glm::ortho(0.0f, width * 1.0f * scaleCoeff, 0.0f, height * 1.0f * scaleCoeff, 1.0f, -1.0f);
	view = glm::mat4(1);//glm::scale(glm::vec3(0.15/width, 0.15/width, 1));
	SPHFluidParams p;
	p.restDensity = 1000;
	p.restPressure = 0.001;
	p.viscocity = 3.5;
	p.dt = 0.01;
	p.stiffness = 2;
	p.surfaceTension = 0.0728;
	p.tensionTreshold = 4.065;
	p.particleMass = 0.0005;
	p.particlesCount = 20 * 20;
	p.effectiveRadius = pow(3. * p.particleMass * M_1_PI * 0.25 / p.restDensity * 20, 1./3.);
	p.particleRadius = pow(3. * p.particleMass * M_1_PI * 0.25 / p.restDensity, 1./3.);
	fluid = new SPHFluid(p);
}

void SPHScreen::Update(float delta)
{
	//fluid->Update(delta);
}

void SPHScreen::Render(Graphics *graphics)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	fluid->Render(graphics, &projection, &view);
	//std::cout << glGetError() << std::endl;
}

void SPHScreen::OnKeyPress(int buttonID, bool isPressed)
{
	switch (buttonID)
	{
	case GLFW_KEY_Q:
		if (!isPressed)
		{
		}
		break;
	case GLFW_KEY_ENTER:
		if (!isPressed)
		{
			fluid->Init();
		}
		break;
	case GLFW_KEY_SPACE:
		if (!isPressed)
		{
			fluid->Update(0.);
		}
		break;
	case GLFW_KEY_E:
		//if (!isPressed)
		//{
			fluid->Update(0.);
		//}
		//if (!isPressed)
		//{
		//}
		break;
	case GLFW_KEY_R:
		//if (!isPressed)
		//{
		//}
		break;
	case GLFW_KEY_A:
		if (!isPressed)
		{
		}
		break;
	case GLFW_KEY_S:
		if (!isPressed)
		{
		}
		break;
	case GLFW_KEY_D:
		//if (!isPressed)
		//{
		//}
		break;
	case GLFW_KEY_F:
		//if (!isPressed)
		//{
		//}
		break;
	case GLFW_KEY_EQUAL:
		//if (!isPressed)
		//{
		//}
		break;
	case GLFW_KEY_MINUS:
		//if (!isPressed)
		//{
		//}
		break;
	case GLFW_KEY_B:
		if (!isPressed)
		{
		}
		break;
	}
}

void SPHScreen::OnKeyRelease(int buttonID)
{
	switch (buttonID)
	{
	case GLFW_KEY_B:
		break;
	}
}

void SPHScreen::Initialize()
{

}
