#define GRAPHICS_EXPORTS
#include "Graphics/Shapes/Circle.h"
#include <iostream>


Circle::Circle() 
	: Sprite(0, 0)
{
	Init();
}

Circle::Circle(float x, float y, float radius, float width, glm::vec4 *color)
	: Sprite(x, y)
{
	Init();
	SetCircle(x, y, radius, width, color);
}

void Circle::Init()
{
	shaderProgram = new CircleShaderProgram("circle.vs", "circle.fs");
}



Circle::~Circle()
{
	delete shaderProgram;
}

void Circle::Draw(glm::mat4 *projection, glm::mat4 *view)
{
	shaderProgram->Enable();
	glUniformMatrix4fv(shaderProgram->mvpShLoc, 1, GL_FALSE, &((*projection) * (*view) * model)[0][0]);
	glUniform4fv(shaderProgram->colorShLoc, 1, &(color)[0]);
	glUniform1f(shaderProgram->innerRadiusShLoc, innerRadius);

	glBindVertexArray(vertexArrayObject);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, (void*)0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
	shaderProgram->Disable();
}

void Circle::SetCircle(float x, float y, float radius, float thickness, glm::vec4 *color)
{
	innerRadius = (radius - thickness) / radius * 0.5;
	SetColor(color);
	SetPosition(x, y);
	SetSize(radius * 2.f, radius * 2.f);
}

void Circle::SetShader(const char * vFilePath, const char * fFilePath)
{

}
