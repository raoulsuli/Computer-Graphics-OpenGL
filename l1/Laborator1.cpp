#include "Laborator1.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>

using namespace std;

// Order of function calling can be seen in "Source/Core/World.cpp::LoopUpdate()"
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/World.cpp


bool bgColor = false; // Value for Clear Color
string objs[3] = { "teapot", "box", "sphere" }; // List of objects
int obj_index = 0; // Current object
float posX = 0.0;
float posY = 0.0;
float posZ = 0.0;
//Object positions

Laborator1::Laborator1()
{
}

Laborator1::~Laborator1()
{
}

void Laborator1::Init()
{
	// Load a mesh from file into GPU memory
	{
		Mesh* meshBox = new Mesh("box");
		meshBox->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		Mesh* meshSphere = new Mesh("sphere");
		meshSphere->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
		Mesh* meshTeapot = new Mesh("teapot");
		meshTeapot->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "teapot.obj");
		meshes[meshBox->GetMeshID()] = meshBox;
		meshes[meshSphere->GetMeshID()] = meshSphere;
		meshes[meshTeapot->GetMeshID()] = meshTeapot;
	}
}

void Laborator1::FrameStart()
{

}

void Laborator1::Update(float deltaTimeSeconds)
{
	glm::ivec2 resolution = window->props.resolution;

	// sets the clear color for the color buffer
	if (bgColor == false)
		glClearColor(0, 0, 0, 1);
	else
		glClearColor(1, 0, 0, 1);

	// clears the color buffer (using the previously set color) and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);

	// render the object
	RenderMesh(meshes["box"], glm::vec3(1, 0.5f, 0), glm::vec3(0.5f));

	// render the object again but with different properties
	RenderMesh(meshes["box"], glm::vec3(-1, 0.5f, 0));
	
	string chosen_mesh = objs[obj_index]; // Pick the current object
	glm::vec3 pos(0.25f + posY, 0.5f + posZ, 1.4f + posX); // Set its position
	RenderMesh(meshes[chosen_mesh], pos); // Render it
}

void Laborator1::FrameEnd()
{
	DrawCoordinatSystem();
}

// Read the documentation of the following functions in: "Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/Window/InputController.h

void Laborator1::OnInputUpdate(float deltaTime, int mods)
{
	// treat continuous update based on input
	if (window->KeyHold(GLFW_KEY_W)) {
			posX -= deltaTime; // Add with constant * deltaTime so that the movement
	}												// will be the same on every computer
	if (window->KeyHold(GLFW_KEY_S)) {
			posX += deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_A)) {
			posY -= deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_D)) {
			posY += deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_E)) {
			posZ += deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_Q)) {
			posZ -= deltaTime;
	}
};

void Laborator1::OnKeyPress(int key, int mods)
{
	// add key press event
	if (key == GLFW_KEY_F) {
		bgColor = !bgColor; // Global color value: bgColor == true => Red ClearColor
	}											// bgColor == false => Default ClearColor
	if (key == GLFW_KEY_C) { 
		if (obj_index == 2) {
			obj_index = 0;
		}
		else {
			obj_index++; //Switch the object
		}
	}
};

void Laborator1::OnKeyRelease(int key, int mods)
{
	// add key release event
};

void Laborator1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// add mouse move event
};

void Laborator1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
};

void Laborator1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
}

void Laborator1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
	// treat mouse scroll event
}

void Laborator1::OnWindowResize(int width, int height)
{
	// treat window resize event
}
