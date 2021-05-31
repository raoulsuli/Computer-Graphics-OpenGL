#include "Tema1.h"
#include <vector>
#include <iostream>

#include <Core/Engine.h>
#include "Transform2D.h"

using namespace std;


Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}

void Tema1::Init()
{

	// Create a mesh box using custom data
	{
		vector<VertexFormat> arrowTipVertices
		{
			VertexFormat(glm::vec3(0, 0,  0), glm::vec3(1, 1, 1)),
			VertexFormat(glm::vec3(0.25f, 0.25f,  0), glm::vec3(1, 1, 1)),
			VertexFormat(glm::vec3(0, 0.5f,  0), glm::vec3(1, 1, 1)),
		};

		vector<unsigned short> arrowTipIndices =
		{
			0, 1, 2
		};

		vector<VertexFormat> lineVertices
		{
			VertexFormat(glm::vec3(0, 0,  0), glm::vec3(1, 1, 1)),
			VertexFormat(glm::vec3(4, 0,  0), glm::vec3(1, 1, 1)),
			VertexFormat(glm::vec3(4, 0.125f,  0), glm::vec3(1, 1, 1)),
			VertexFormat(glm::vec3(0, 0.125f,  0), glm::vec3(1, 1, 1)),

		};

		vector<unsigned short> lineIndices
		{
			0, 1, 3,
			1, 2, 3
		};

		vector<VertexFormat> bowVertices;
		vector<unsigned short> bowIndices;

		for (int i = 0; i < 64; i++) {
			float theta = -3.1415926f / 2.0f + 1.015f * 3.1415926f * float(i) / float(64);
			
			float x = 1.5f * cosf(theta);
			float y = 1.5f * sinf(theta);

			bowVertices.push_back(VertexFormat(glm::vec3(x, y, 0), glm::vec3(1, 1, 1)));
		}
		
		for (int i = 0; i < 63; i++) {
			bowIndices.push_back(i);
			bowIndices.push_back(i + 1);
		}

		vector<VertexFormat> redBaloonVertices;
		vector<VertexFormat> yellowBaloonVertices;
		vector<unsigned short> baloonIndices;

		float triangles = 20;
		float twoPI = 2.0f * 3.1415926f;
		float radius = 1.5f;

		for (int i = 0; i <= triangles; i++) {
			redBaloonVertices.push_back(VertexFormat(glm::vec3(radius * cos(i * twoPI / triangles), radius * sin(i * twoPI / triangles), 0), glm::vec3(1, 0, 0)));
			yellowBaloonVertices.push_back(VertexFormat(glm::vec3(radius * cos(i * twoPI / triangles), radius * sin(i * twoPI / triangles), 0), glm::vec3(1, 1, 0)));
		}

		for (int i = 0; i < 1 + triangles; i++) {
			baloonIndices.push_back(0);
			baloonIndices.push_back(i);
			baloonIndices.push_back(i + 1);
		}

		vector<VertexFormat> redMultiLineVertices
		{
			VertexFormat(glm::vec3(0, 0,  0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(-0.1f, -0.1f,  0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(0.25f, -0.3f,  0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(0, -0.5f,  0), glm::vec3(1, 0, 0)),
			VertexFormat(glm::vec3(0.35f, -0.8f,  0), glm::vec3(1, 0, 0))
		};

		vector<VertexFormat> yellowMultiLineVertices
		{
			VertexFormat(glm::vec3(0, 0,  0), glm::vec3(1, 1, 0)),
			VertexFormat(glm::vec3(-0.1f, -0.1f,  0), glm::vec3(1, 1, 0)),
			VertexFormat(glm::vec3(0.25f, -0.3f,  0), glm::vec3(1, 1, 0)),
			VertexFormat(glm::vec3(0, -0.5f,  0), glm::vec3(1, 1, 0)),
			VertexFormat(glm::vec3(0.35f, -0.8f,  0), glm::vec3(1, 1, 0))
		};

		vector<unsigned short> multiLineIndices
		{
			0, 1,
			1, 2,
			2, 3,
			3, 4,
		};

		vector<VertexFormat> shurikenVertices
		{
			VertexFormat(glm::vec3(0, 0,  0), glm::vec3(1, 1, 1)),
			VertexFormat(glm::vec3(0.5f, 0,  0), glm::vec3(1, 1, 1)),
			VertexFormat(glm::vec3(0.5f, 0.5f,  0), glm::vec3(1, 1, 1)),
			VertexFormat(glm::vec3(0, 0.5f,  0), glm::vec3(1, 1, 1)),
			VertexFormat(glm::vec3(-0.5f, 0.5f,  0), glm::vec3(1, 1, 1)),
			VertexFormat(glm::vec3(-0.5f, 0,  0), glm::vec3(1, 1, 1)),
			VertexFormat(glm::vec3(-0.5f, -0.5f,  0), glm::vec3(1, 1, 1)),
			VertexFormat(glm::vec3(0, -0.5f,  0), glm::vec3(1, 1, 1)),
			VertexFormat(glm::vec3(0.5f, -0.5f,  0), glm::vec3(1, 1, 1)),
		};

		vector<unsigned short> shurikenIndices =
		{
			0, 1, 2,
			0, 3, 4,
			0, 5, 6,
			0, 7, 8
		};

		meshes["arrowTip"] = new Mesh("generated arrow tip");
		meshes["arrowTip"]->InitFromData(arrowTipVertices, arrowTipIndices);

		meshes["line"] = new Mesh("generated line");
		meshes["line"]->InitFromData(lineVertices, lineIndices);
		
		meshes["bow"] = new Mesh("generated bow");
		meshes["bow"]->InitFromData(bowVertices, bowIndices);

		meshes["redBaloon"] = new Mesh("generated red baloon");
		meshes["redBaloon"]->InitFromData(redBaloonVertices, baloonIndices);

		meshes["yellowBaloon"] = new Mesh("generated yellow baloon");
		meshes["yellowBaloon"]->InitFromData(yellowBaloonVertices, baloonIndices);

		meshes["redMultiline"] = new Mesh("generated red multi line");
		meshes["redMultiline"]->InitFromData(redMultiLineVertices, multiLineIndices);

		meshes["yellowMultiline"] = new Mesh("generated yellow multi line");
		meshes["yellowMultiline"]->InitFromData(yellowMultiLineVertices, multiLineIndices);

		meshes["shuriken"] = new Mesh("generated shuriken");
		meshes["shuriken"]->InitFromData(shurikenVertices, shurikenIndices);

		// Create a new mesh from buffer data
		Mesh* arrowTip = CreateMesh("arrow", arrowTipVertices, arrowTipIndices);
		
		Mesh* line = CreateMesh("line", lineVertices, lineIndices);
		
		Mesh* bow = CreateMesh("bow", bowVertices, bowIndices);
		bow->SetDrawMode(GL_LINE_LOOP);
		
		Mesh* redBaloon = CreateMesh("redBaloon", redBaloonVertices, baloonIndices);
		redBaloon->SetDrawMode(GL_TRIANGLE_FAN);

		Mesh* yellowBaloon = CreateMesh("yellowBaloon", yellowBaloonVertices, baloonIndices);
		yellowBaloon->SetDrawMode(GL_TRIANGLE_FAN);

		Mesh* redMultiline = CreateMesh("redMultiline", redMultiLineVertices, multiLineIndices);
		redMultiline->SetDrawMode(GL_LINE_STRIP);
		
		Mesh* yellowMultiline = CreateMesh("yellowMultiline", yellowMultiLineVertices, multiLineIndices);
		yellowMultiline->SetDrawMode(GL_LINE_STRIP);

		Mesh* shuriken = CreateMesh("shuriken", shurikenVertices, shurikenIndices);
	}
}

Mesh* Tema1::CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices)
{
	unsigned int VAO = 0;

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned int VBO = 0;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	unsigned int IBO = 0;
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);
	// ========================================================================
	// This section describes how the GPU Shader Vertex Shader program receives data
	// It will be learned later, when GLSL shaders will be introduced
	// For the moment just think that each property value from our vertex format needs to be send to a certain channel
	// in order to know how to receive it in the GLSL vertex shader

	// set vertex position attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

	// set vertex normal attribute
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

	// set texture coordinate attribute
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

	// set vertex color attribute
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));
	// ========================================================================

	glBindVertexArray(0);

	// Check for OpenGL errors
	CheckOpenGLError();

	// Mesh information is saved into a Mesh object
	meshes[name] = new Mesh(name);
	meshes[name]->InitFromBuffer(VAO, static_cast<unsigned short>(indices.size()));
	return meshes[name];
}

void Tema1::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();

	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema1::Update(float deltaTimeSeconds)
{	
	float bow_posX = 0.1f;
	float bow_posY = 1.0f + bow_translate;

	const float line_posX = bow_posX - 0.225f * bow_ratio;
	const float line_posY = bow_posY + 0.05f * bow_ratio;

	const float arrow_posX = line_posX + line_width * line_ratio;
	const float arrow_posY = line_posY + line_height / 2 * line_ratio - arrowTip_height / 2 * arrowTip_ratio;

	if (save_pos) {
		arrow_posX_initial = arrow_posX;
		arrow_posY_initial = arrow_posY;
		line_posX_initial = line_posX;
		line_posY_initial = line_posY;
		save_pos = false;
	}

	redBaloon_translateY += 0.2f * deltaTimeSeconds;
	yellowBaloon_translateY += 0.4f * deltaTimeSeconds;
	shuriken_translateX += deltaTimeSeconds;
	shuriken_rotate += deltaTimeSeconds * 2.5f;
	
	bow_rotation = atanf(mouse_posY / mouse_posX);

	if (mouse_pressed == false) {
		arrow_dirX = mouse_posX;
		arrow_dirY = mouse_posY;
	}

	if (mouse_pressed) {
		shoot_arrowX += shooting_power * arrow_dirX / (resolution_x / 4) * deltaTimeSeconds;
		shoot_arrowY += shooting_power * arrow_dirY / (resolution_y / 4) * deltaTimeSeconds;
	}
	
	if (redBaloon_translateY >= 6.5f) {
		redBaloon_translateY = 0;
	}

	if (yellowBaloon_translateY >= 6.5f) {
		yellowBaloon_translateY = 0;
	}

	if (shuriken_translateX >= 4.75f) {
		shuriken_translateX = 0;
	}

	if (shoot_arrowX >= 5.5f || shoot_arrowY >= 6.5f || bow_posY + shoot_arrowY <= 0) {
		shoot_arrowX = 0;
		shoot_arrowY = 0;
		mouse_pressed = false;
		shooting_power = 0.5f;
	}

	glm::mat3 modelMatrix;
	
	//linia sagetii
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(shoot_arrowX, shoot_arrowY);
	if (!mouse_pressed) {
		modelMatrix *= Transform2D::Translate(line_posX, line_posY);
		modelMatrix *= Transform2D::Rotate(bow_rotation);
	}
	else {
		modelMatrix *= Transform2D::Translate(line_posX_initial, line_posY_initial);
		modelMatrix *= Transform2D::Rotate(arrow_rotation_shoot);
	}
	modelMatrix *= Transform2D::Scale(line_ratio, line_ratio);
	RenderMesh2D(meshes["line"], shaders["VertexColor"], modelMatrix);
	

	//varful sagetii
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(shoot_arrowX, shoot_arrowY);
	if (!mouse_pressed) {
		modelMatrix *= Transform2D::Translate(arrow_posX, arrow_posY);
	}
	else {
		modelMatrix *= Transform2D::Translate(arrow_posX_initial, arrow_posY_initial);
	}
	modelMatrix *= Transform2D::Translate(-line_width * line_ratio, arrowTip_height * line_ratio + 0.005f);
	if (!mouse_pressed) {
		modelMatrix *= Transform2D::Rotate(bow_rotation);
	}
	else {
		modelMatrix *= Transform2D::Rotate(arrow_rotation_shoot);
	}
	modelMatrix *= Transform2D::Translate(line_width * line_ratio, -arrowTip_height * line_ratio - 0.005f);
	modelMatrix *= Transform2D::Scale(arrowTip_ratio, arrowTip_ratio);
	RenderMesh2D(meshes["arrowTip"], shaders["VertexColor"], modelMatrix);
	

	//arcul
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(bow_posX, bow_posY);
	modelMatrix *= Transform2D::Rotate(bow_rotation);
	modelMatrix *= Transform2D::Scale(bow_ratio, bow_ratio);
	RenderMesh2D(meshes["bow"], shaders["VertexColor"], modelMatrix);
	
	//power bar
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(bow_posX, bow_posY - 0.5f);
	modelMatrix *= Transform2D::Scale(line_ratio - 0.15f + shooting_power * 0.075f, line_ratio);
	RenderMesh2D(meshes["line"], shaders["VertexColor"], modelMatrix);


	//balon rosu
	if (redBaloonDestroyRatio > baloon_height * baloon_ratioY) {
		redBaloonDestroyRatio = 0;
		redBaloonHit = false;
		redBaloon_translateY = 0;
	}
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(0, redBaloon_translateY);
	modelMatrix *= Transform2D::Translate(redBaloon_posX, baloon_posY);
	if (redBaloonHit) {
		redBaloonDestroyRatio += 0.2f * deltaTimeSeconds;
		modelMatrix *= Transform2D::Scale(-redBaloonDestroyRatio, -redBaloonDestroyRatio);
	}
	modelMatrix *= Transform2D::Scale(baloon_ratioX, baloon_ratioY);
	RenderMesh2D(meshes["redBaloon"], shaders["VertexColor"], modelMatrix);


	//ata balonului rosu
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(0, redBaloon_translateY);
	modelMatrix *= Transform2D::Translate(redMultiline_posX, multiline_posY);
	if (redBaloonHit) {
		redBaloonDestroyRatio += 0.2f * deltaTimeSeconds;
		modelMatrix *= Transform2D::Scale(-redBaloonDestroyRatio, -redBaloonDestroyRatio);
	}
	modelMatrix *= Transform2D::Scale(multiline_ratio, multiline_ratio);
	RenderMesh2D(meshes["redMultiline"], shaders["VertexColor"], modelMatrix);


	//balon galben
	if (yellowBaloonDestroyRatio > baloon_height * baloon_ratioY) {
		yellowBaloonDestroyRatio = 0;
		yellowBaloonHit = false;
		yellowBaloon_translateY = 0;
	}
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(0, yellowBaloon_translateY);
	modelMatrix *= Transform2D::Translate(yellowBaloon_posX, baloon_posY);
	if (yellowBaloonHit) {
		yellowBaloonDestroyRatio += 0.2f * deltaTimeSeconds;
		modelMatrix *= Transform2D::Scale(-yellowBaloonDestroyRatio, -yellowBaloonDestroyRatio);
	}
	modelMatrix *= Transform2D::Scale(baloon_ratioX, baloon_ratioY);
	RenderMesh2D(meshes["yellowBaloon"], shaders["VertexColor"], modelMatrix);
	

	//ata balonului galben
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(0, yellowBaloon_translateY);
	modelMatrix *= Transform2D::Translate(yellowMultiline_posX, multiline_posY);
	if (yellowBaloonHit) {
		yellowBaloonDestroyRatio += 0.2f * deltaTimeSeconds;
		modelMatrix *= Transform2D::Scale(-yellowBaloonDestroyRatio, -yellowBaloonDestroyRatio);
	}
	modelMatrix *= Transform2D::Scale(multiline_ratio, multiline_ratio);
	RenderMesh2D(meshes["yellowMultiline"], shaders["VertexColor"], modelMatrix);


	//shuriken
	modelMatrix = glm::mat3(1);
	modelMatrix *= Transform2D::Translate(-shuriken_translateX, 0);
	modelMatrix *= Transform2D::Translate(shuriken_posX, shuriken_posY);
	modelMatrix *= Transform2D::Rotate(shuriken_rotate);
	modelMatrix *= Transform2D::Scale(shuriken_ratio, shuriken_ratio);
	RenderMesh2D(meshes["shuriken"], shaders["VertexColor"], modelMatrix);

	//prelucrare coliziuni
	float arrowTip_pointX = arrow_posX + arrowTip_width * arrowTip_ratio + shoot_arrowX;
	float arrowTip_pointY = arrow_posY + arrowTip_height * arrowTip_ratio / 2 + shoot_arrowY;

	if (arrowTip_pointX >= redBaloon_posX && arrowTip_pointX <= redBaloon_posX + baloon_width * baloon_ratioX &&
		arrowTip_pointY >= baloon_posY + redBaloon_translateY && arrowTip_pointY <= baloon_posY + redBaloon_translateY + baloon_height * baloon_ratioY) {
		redBaloonHit = true;
	}

	if (arrowTip_pointX >= yellowBaloon_posX && arrowTip_pointX <= yellowBaloon_posX + baloon_width * baloon_ratioX &&
		arrowTip_pointY >= baloon_posY + yellowBaloon_translateY && arrowTip_pointY <= baloon_posY + yellowBaloon_translateY + baloon_height * baloon_ratioY) {
		yellowBaloonHit = true;
	}

	if (arrowTip_pointX >= redMultiline_posX && arrowTip_pointX <= redMultiline_posX + multiline_width * multiline_ratio &&
		arrowTip_pointY >= multiline_posY + redBaloon_translateY && arrowTip_pointY <= multiline_posY + redBaloon_translateY + multiline_height * multiline_ratio) {
		redBaloonHit = true;
	}

	if (arrowTip_pointX >= yellowMultiline_posX && arrowTip_pointX <= yellowMultiline_posX + multiline_width * multiline_ratio &&
		arrowTip_pointY >= multiline_posY + yellowBaloon_translateY && arrowTip_pointY <= multiline_posY + yellowBaloon_translateY + multiline_height * multiline_ratio) {
		yellowBaloonHit = true;
	}

	if (shuriken_posY >= bow_posY && shuriken_posY <= bow_posY + bow_height * bow_ratio &&
		shuriken_posX - shuriken_translateX >= bow_posX && shuriken_posX - shuriken_translateX <= bow_posX + bow_width * bow_ratio) {
		player_lifes -= 1;
		shuriken_translateX = 0;
	}
	
	if (player_lifes == 0) {
		printf("PLAYER DEAD! GAME OVER!");
		bow_translate = -2;
		player_lifes = -1;
	}
}

void Tema1::FrameEnd()
{
	DrawCoordinatSystem();
}

void Tema1::OnInputUpdate(float deltaTime, int mods)
{
	if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT)) {
		if (window->KeyHold(GLFW_KEY_W)) {
			bow_translate += deltaTime;
		}
		if (window->KeyHold(GLFW_KEY_S)) {
			bow_translate -= deltaTime;
		}
	}

	if (window->MouseHold(GLFW_MOUSE_BUTTON_LEFT) && max_power == false) {
		shooting_power += 2.0f * deltaTime;
		if (shooting_power >= 8.0f) {
			max_power = true;
		}
	}
}

void Tema1::OnKeyPress(int key, int mods)
{
}

void Tema1::OnKeyRelease(int key, int mods)
{
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	mouse_posY = resolution_y / 2 - mouseY;
	mouse_posX = (float)max(mouseX - (int)resolution_x / 2, 0);
}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_2 && mouse_pressed == false) {
		mouse_pressed = true;
		arrow_rotation_shoot = bow_rotation;
		save_pos = true;
		max_power = false;
	}
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
}