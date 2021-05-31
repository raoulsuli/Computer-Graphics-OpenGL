#include "Tema3.h"
#include <vector>
#include <iostream>

#include <Core/Engine.h>
#include "Transform3D.h"

using namespace std;


Tema3::Tema3()
{
}

Tema3::~Tema3()
{
}

string platforms[5] = { "redPlatform", "greenPlatform", "yellowPlatform", "bluePlatform", "orangePlatform" };
string p1;
string p2;
string p3;
string p11;
string p12;
string p13;
string p21;
string p22;
string p23;
string p14, p24, p34;
int o1, o2, o3, x1;
int s1, s2, s3, x2;

void Tema3::Init()
{	
	//Light & material properties
	{
		lightPosition = glm::vec3(0, 1, 1);
		lightDirection = glm::vec3(0, -1, 0);
		materialShininess = 30;
		materialKd = 0.5;
		materialKs = 0.5;
	}

	{ //Load Textures
		const string textureLoc = "Source/Laboratoare/Tema3/Textures/";

		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc + "clouds.jpg").c_str(), GL_REPEAT);
		mapTextures["clouds"] = texture;
	}

	Mesh* sphere = new Mesh("sphere");
	sphere->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "sphere.obj");
	meshes[sphere->GetMeshID()] = sphere;

	Mesh* star = new Mesh("star");
	star->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "star.obj");
	meshes[star->GetMeshID()] = star;

	p1 = platforms[rand() % 5];
	p2 = platforms[rand() % 5];
	p3 = platforms[rand() % 5];
	p11 = platforms[rand() % 5];
	p12 = platforms[rand() % 5];
	p13 = platforms[rand() % 5];
	p21 = platforms[rand() % 5];
	p22 = platforms[rand() % 5];
	p23 = platforms[rand() % 5];
	p14 = platforms[1], p24 = platforms[1], p34 = platforms[1];
	o1 = rand() % 2;
	o2 = rand() % 2;
	o3 = rand() % 2;
	s1 = rand() % 2;
	s2 = rand() % 2;
	s3 = rand() % 2;
	x1 = rand() % 2;
	x2 = rand() % 2;
	if (x2 == s2) {
		if (s2 == 0) x2 = 1;
		else x2 = 0;
	}


	vector<VertexFormat> whiteRectangleV
	{
		VertexFormat(glm::vec3(0, 0,  0), glm::vec3(1, 1, 1)),
		VertexFormat(glm::vec3(1, 0,  0), glm::vec3(1, 1, 1)),
		VertexFormat(glm::vec3(1, 0.2f,  0), glm::vec3(1, 1, 1)),
		VertexFormat(glm::vec3(0, 0.2f,  0), glm::vec3(1, 1, 1))
	};

	vector<VertexFormat> greyRectangleV
	{
		VertexFormat(glm::vec3(0, 0,  0), glm::vec3(0.5f, 0.5f, 0.5f)),
		VertexFormat(glm::vec3(1, 0,  0), glm::vec3(0.5f, 0.5f, 0.5f)),
		VertexFormat(glm::vec3(1, 0.2f,  0), glm::vec3(0.5f, 0.5f, 0.5f)),
		VertexFormat(glm::vec3(0, 0.2f,  0), glm::vec3(0.5f, 0.5f, 0.5f))
	};

	vector<VertexFormat> turqoiseRectangleV
	{
		VertexFormat(glm::vec3(0, 0,  0), glm::vec3(0.25f, 0.87f, 0.81f)),
		VertexFormat(glm::vec3(1, 0,  0), glm::vec3(0.25f, 0.87f, 0.81f)),
		VertexFormat(glm::vec3(1, 0.2f,  0), glm::vec3(0.25f, 0.87f, 0.81f)),
		VertexFormat(glm::vec3(0, 0.2f,  0), glm::vec3(0.25f, 0.87f, 0.81f))
	};

	vector<VertexFormat> blueVertices
	{
		VertexFormat(glm::vec3(0, 0,  0), glm::vec3(0, 0, 1)),
		VertexFormat(glm::vec3(1.5f, 0,  0), glm::vec3(0, 0, 1)),
		VertexFormat(glm::vec3(1.5f, 0.2f,  0), glm::vec3(0, 0, 1)),
		VertexFormat(glm::vec3(0, 0.2f,  0), glm::vec3(0, 0, 1)),
		VertexFormat(glm::vec3(0, 0,  4), glm::vec3(0, 0, 1)),
		VertexFormat(glm::vec3(1.5f, 0,  4), glm::vec3(0, 0, 1)),
		VertexFormat(glm::vec3(1.5f, 0.2f,  4), glm::vec3(0, 0, 1)),
		VertexFormat(glm::vec3(0, 0.2f,  4), glm::vec3(0, 0, 1))
	};

	vector<VertexFormat> redVertices
	{
		VertexFormat(glm::vec3(0, 0,  0), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(1.5f, 0,  0), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(1.5f, 0.2f,  0), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(0, 0.2f,  0), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(0, 0,  4), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(1.5f, 0,  4), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(1.5f, 0.2f,  4), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(0, 0.2f,  4), glm::vec3(1, 0, 0))
	};

	vector<VertexFormat> yellowVertices
	{
		VertexFormat(glm::vec3(0, 0,  0), glm::vec3(1, 1, 0)),
		VertexFormat(glm::vec3(1.5f, 0,  0), glm::vec3(1, 1, 0)),
		VertexFormat(glm::vec3(1.5f, 0.2f,  0), glm::vec3(1, 1, 0)),
		VertexFormat(glm::vec3(0, 0.2f,  0), glm::vec3(1, 1, 0)),
		VertexFormat(glm::vec3(0, 0,  4), glm::vec3(1, 1, 0)),
		VertexFormat(glm::vec3(1.5f, 0,  4), glm::vec3(1, 1, 0)),
		VertexFormat(glm::vec3(1.5f, 0.2f,  4), glm::vec3(1, 1, 0)),
		VertexFormat(glm::vec3(0, 0.2f,  4), glm::vec3(1, 1, 0))
	};

	vector<VertexFormat> orangeVertices
	{
		VertexFormat(glm::vec3(0, 0,  0), glm::vec3(1, 0.65f, 0)),
		VertexFormat(glm::vec3(1.5f, 0,  0), glm::vec3(1, 0.65f, 0)),
		VertexFormat(glm::vec3(1.5f, 0.2f,  0), glm::vec3(1, 0.65f, 0)),
		VertexFormat(glm::vec3(0, 0.2f,  0), glm::vec3(1, 0.65f, 0)),
		VertexFormat(glm::vec3(0, 0,  4), glm::vec3(1, 0.65f, 0)),
		VertexFormat(glm::vec3(1.5f, 0,  4), glm::vec3(1, 0.65f, 0)),
		VertexFormat(glm::vec3(1.5f, 0.2f,  4), glm::vec3(1, 0.65f, 0)),
		VertexFormat(glm::vec3(0, 0.2f,  4), glm::vec3(1, 0.65f, 0))
	};

	vector<VertexFormat> greenVertices
	{
		VertexFormat(glm::vec3(0, 0,  0), glm::vec3(0, 1, 0)),
		VertexFormat(glm::vec3(1.5f, 0,  0), glm::vec3(0, 1, 0)),
		VertexFormat(glm::vec3(1.5f, 0.2f,  0), glm::vec3(0, 1, 0)),
		VertexFormat(glm::vec3(0, 0.2f,  0), glm::vec3(0, 1, 0)),
		VertexFormat(glm::vec3(0, 0,  4), glm::vec3(0, 1, 0)),
		VertexFormat(glm::vec3(1.5f, 0,  4), glm::vec3(0, 1, 0)),
		VertexFormat(glm::vec3(1.5f, 0.2f,  4), glm::vec3(0, 1, 0)),
		VertexFormat(glm::vec3(0, 0.2f,  4), glm::vec3(0, 1, 0))
	};

	vector<VertexFormat> purpleVertices
	{
		VertexFormat(glm::vec3(0, 0,  0), glm::vec3(0.5f, 0, 0.5f)),
		VertexFormat(glm::vec3(1.5f, 0,  0), glm::vec3(0.5f, 0, 0.5f)),
		VertexFormat(glm::vec3(1.5f, 0.2f,  0), glm::vec3(0.5f, 0, 0.5f)),
		VertexFormat(glm::vec3(0, 0.2f,  0), glm::vec3(0.5f, 0, 0.5f)),
		VertexFormat(glm::vec3(0, 0,  4), glm::vec3(0.5f, 0, 0.5f)),
		VertexFormat(glm::vec3(1.5f, 0,  4), glm::vec3(0.5f, 0, 0.5f)),
		VertexFormat(glm::vec3(1.5f, 0.2f,  4), glm::vec3(0.5f, 0, 0.5f)),
		VertexFormat(glm::vec3(0, 0.2f,  4), glm::vec3(0.5f, 0, 0.5f))
	};

	vector<unsigned short> indices =
	{
		0, 1, 2,
		0, 2, 3,
		3, 2, 6,
		3, 6, 7,
		1, 5, 6,
		1, 6, 2,
		0, 5, 1,
		0, 4, 5,
		0, 7, 4,
		0, 3, 7,
		4, 6, 5,
		4, 7, 6
	};

	vector<VertexFormat> obstacleVertices
	{
		VertexFormat(glm::vec3(0, 0,  0), glm::vec3(0.5f, 0.5f, 0.5f)),
		VertexFormat(glm::vec3(1.5f, 0,  0), glm::vec3(0.5f, 0.5f, 0.5f)),
		VertexFormat(glm::vec3(1.5f, 0.75f,  0), glm::vec3(0.5f, 0.5f, 0.5f)),
		VertexFormat(glm::vec3(0, 0.75f,  0), glm::vec3(0.5f, 0.5f, 0.5f)),
		VertexFormat(glm::vec3(0, 0,  0.2f), glm::vec3(0.5f, 0.5f, 0.5f)),
		VertexFormat(glm::vec3(1.5f, 0,  0.2f), glm::vec3(0.5f, 0.5f, 0.5f)),
		VertexFormat(glm::vec3(1.5f, 0.75f,  0.2f), glm::vec3(0.5f, 0.5f, 0.5f)),
		VertexFormat(glm::vec3(0, 0.75f,  0.2f), glm::vec3(0.5f, 0.5f, 0.5f))
	};

	vector<unsigned short> rectangleIndices =
	{
		0, 1, 2,
		0, 2, 3
	};

	vector<VertexFormat> backgroundVertices
	{
		VertexFormat(glm::vec3(0, -10,  0), glm::vec3(1, 1, 1), glm::vec3(0, 0, -1), glm::vec2(0, 1)),//0
		VertexFormat(glm::vec3(0, -10,  0), glm::vec3(1, 1, 1), glm::vec3(-1, 0, 0), glm::vec2(1, 1)),
		VertexFormat(glm::vec3(0, -10,  0), glm::vec3(1, 1, 1), glm::vec3(0, -1, 0), glm::vec2(0, 0)),
		VertexFormat(glm::vec3(0.5f, -10,  0), glm::vec3(1, 1, 1), glm::vec3(0, 0, -1), glm::vec2(1, 1)),//1
		VertexFormat(glm::vec3(0.5f, -10,  0), glm::vec3(1, 1, 1), glm::vec3(1, 0, 0), glm::vec2(0, 1)),
		VertexFormat(glm::vec3(0.5f, -10,  0), glm::vec3(1, 1, 1), glm::vec3(0, -1, 0), glm::vec2(1, 0)),
		VertexFormat(glm::vec3(0.5f, 10,  0), glm::vec3(1, 1, 1), glm::vec3(0, 0, -1), glm::vec2(1, 0)),//2
		VertexFormat(glm::vec3(0.5f, 10,  0), glm::vec3(1, 1, 1), glm::vec3(1, 0, 0), glm::vec2(0, 0)),
		VertexFormat(glm::vec3(0.5f, 10,  0), glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(1, 1)),
		VertexFormat(glm::vec3(0, 10,  0), glm::vec3(1, 1, 1), glm::vec3(0, 0, -1), glm::vec2(0, 0)),//3
		VertexFormat(glm::vec3(0, 10,  0), glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(0, 1)),
		VertexFormat(glm::vec3(0, 10,  0), glm::vec3(1, 1, 1), glm::vec3(-1, 0, 0), glm::vec2(1, 0)),
		VertexFormat(glm::vec3(0, -10,  4), glm::vec3(1, 1, 1), glm::vec3(0, 0, 1), glm::vec2(0, 1)),//4
		VertexFormat(glm::vec3(0, -10,  4), glm::vec3(1, 1, 1), glm::vec3(-1, 0, 0), glm::vec2(0, 1)),
		VertexFormat(glm::vec3(0, -10,  4), glm::vec3(1, 1, 1), glm::vec3(0, -1, 0), glm::vec2(0, 1)),
		VertexFormat(glm::vec3(0.5f, -10,  4), glm::vec3(1, 1, 1), glm::vec3(0, 0, 1), glm::vec2(1, 1)),//5
		VertexFormat(glm::vec3(0.5f, -10,  4), glm::vec3(1, 1, 1), glm::vec3(1, 0, 0), glm::vec2(1, 1)),
		VertexFormat(glm::vec3(0.5f, -10,  4), glm::vec3(1, 1, 1), glm::vec3(0, -1, 0), glm::vec2(1, 1)),
		VertexFormat(glm::vec3(0.5f, 10,  4), glm::vec3(1, 1, 1), glm::vec3(0, 0, 1), glm::vec2(1, 0)),//6
		VertexFormat(glm::vec3(0.5f, 10,  4), glm::vec3(1, 1, 1), glm::vec3(1, 0, 0), glm::vec2(1, 0)),
		VertexFormat(glm::vec3(0.5f, 10,  4), glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(1, 0)),
		VertexFormat(glm::vec3(0, 10,  4), glm::vec3(1, 1, 1), glm::vec3(0, 0, 1), glm::vec2(0, 0)),//7
		VertexFormat(glm::vec3(0, 10,  4), glm::vec3(1, 1, 1), glm::vec3(-1, 0, 0), glm::vec2(0, 0)),
		VertexFormat(glm::vec3(0, 10,  4), glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(0, 0))
	};

	vector<unsigned short> backgroundIndices =
	{
		12, 15, 21,
		15, 18, 21,
		4, 16, 7,
		16, 19, 7,
		0, 3, 9,
		3, 6, 9,
		13, 1, 22,
		1, 11, 22,
		10, 8, 23,
		8, 20, 23,
		14, 17, 2,
		17, 5, 2
	};

	meshes["bluePlatform"] = new Mesh("generated blue platform");
	meshes["bluePlatform"]->InitFromData(blueVertices, indices);
	Mesh* bluePlatform = CreateMesh("bluePlatform", blueVertices, indices);
	
	meshes["redPlatform"] = new Mesh("generated red platform");
	meshes["redPlatform"]->InitFromData(redVertices, indices);
	Mesh* redPlatform = CreateMesh("redPlatform", redVertices, indices);
	
	meshes["yellowPlatform"] = new Mesh("generated yellow platform");
	meshes["yellowPlatform"]->InitFromData(yellowVertices, indices);
	Mesh* yellowPlatform = CreateMesh("yellowPlatform", yellowVertices, indices);
	
	meshes["orangePlatform"] = new Mesh("generated orange platform");
	meshes["orangePlatform"]->InitFromData(orangeVertices, indices);
	Mesh* orangePlatform = CreateMesh("orangePlatform", orangeVertices, indices);

	meshes["greenPlatform"] = new Mesh("generated green platform");
	meshes["greenPlatform"]->InitFromData(greenVertices, indices);
	Mesh* greenPlatform = CreateMesh("greenPlatform", greenVertices, indices);

	meshes["purplePlatform"] = new Mesh("generated purple platform");
	meshes["purplePlatform"]->InitFromData(purpleVertices, indices);
	Mesh* purplePlatform = CreateMesh("purplePlatform", purpleVertices, indices);

	meshes["greyRectangle"] = new Mesh("generated grey rectangle");
	meshes["greyRectangle"]->InitFromData(greyRectangleV, rectangleIndices);
	Mesh* greyRectangle = CreateMesh("greyRectangle", greyRectangleV, rectangleIndices);

	meshes["whiteRectangle"] = new Mesh("generated white rectangle");
	meshes["whiteRectangle"]->InitFromData(whiteRectangleV, rectangleIndices);
	Mesh* whiteRectangle = CreateMesh("whiteRectangle", whiteRectangleV, rectangleIndices);

	meshes["turqoiseRectangle"] = new Mesh("generated turqoise rectangle");
	meshes["turqoiseRectangle"]->InitFromData(turqoiseRectangleV, rectangleIndices);
	Mesh* turqoiseRectangle = CreateMesh("turqoiseRectangle", turqoiseRectangleV, rectangleIndices);

	meshes["background"] = new Mesh("generated background decorations");
	meshes["background"]->InitFromData(backgroundVertices, backgroundIndices);
	Mesh* background = CreateMesh("background", backgroundVertices, backgroundIndices);

	meshes["obstacle"] = new Mesh("generated obstacle");
	meshes["obstacle"]->InitFromData(obstacleVertices, indices);
	Mesh* obstacle = CreateMesh("obstacle", obstacleVertices, indices);

	{
		Shader* shader = new Shader("ShaderTema3");
		shader->AddShader("Source/Laboratoare/Tema3/Shaders/VertexShader.glsl", GL_VERTEX_SHADER);
		shader->AddShader("Source/Laboratoare/Tema3/Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}
}

Mesh* Tema3::CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices)
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
	meshes[name]->vertices = vertices;
	meshes[name]->indices = indices;
	return meshes[name];
}

void Tema3::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();

	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema3::RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, Texture2D *texture1)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;

	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);

	int location_model = glGetUniformLocation(shader->program, "Model");
	glUniformMatrix4fv(location_model, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	int location_view = glGetUniformLocation(shader->program, "View");

	glm::mat4 viewMatrix = GetSceneCamera()->GetViewMatrix();
	glUniformMatrix4fv(location_view, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	int location_projection = glGetUniformLocation(shader->program, "Projection");

	glm::mat4 projectionMatrix = GetSceneCamera()->GetProjectionMatrix();
	glUniformMatrix4fv(location_projection, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	int light_position = glGetUniformLocation(shader->program, "light_position");
	glUniform3f(light_position, lightPosition.x, lightPosition.y, lightPosition.z);

	int light_direction = glGetUniformLocation(shader->program, "light_direction");
	glUniform3f(light_direction, lightDirection.x, lightDirection.y, lightDirection.z);

	int material_shininess = glGetUniformLocation(shader->program, "material_shininess");
	glUniform1i(material_shininess, materialShininess);

	int material_kd = glGetUniformLocation(shader->program, "material_kd");
	glUniform1f(material_kd, materialKd);

	int material_ks = glGetUniformLocation(shader->program, "material_ks");
	glUniform1f(material_ks, materialKs);

	if (texture1 != NULL)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1->GetTextureID());
		glUniform1i(glGetUniformLocation(shader->GetProgramID(), "texture_1"), 0);
	}

	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_SHORT, 0);
}

typedef struct {
	float x;
	float y;
	float z;
} pos;

float firstTranslationZ = 0;

float translationZ = 0;
float translationZ1 = 0;
float translationZ2 = 0;

float fuelScale = 1.0f;
float rotStar = 0;
int score = 0;
bool starHit = false;

void Tema3::Update(float deltaTimeSeconds)
{
	glm::mat4 modelMatrix;
	glm::ivec2 resolution = window->props.resolution;

	glClearColor(0, 0, 0, 1);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glViewport(0, 0, resolution.x, resolution.y);

	if (!start_platform) {
		if (fuelScale > 0) fuelScale -= (speed / 50.0f) * deltaTimeSeconds;
		else falling = true;
	}

	if (start_platform) firstTranslationZ += speed * deltaTimeSeconds;
	if (done_platform || !start_platform) {
		translationZ += speed * deltaTimeSeconds;
		translationZ1 += speed * deltaTimeSeconds;
		translationZ2 += speed * deltaTimeSeconds;
	}

	if (jumpLeft && currentSphereX == -2.0f) jumpLeft = false;
	if (jumpRight && currentSphereX == 2.0f) jumpRight = false;

	if (jumpLeft && currentSphereX >= 0) {
		sphereX -= speed * deltaTimeSeconds;
		sphereRotationZ += deltaTimeSeconds * 45;

		if (sphereX <= -2.0f && currentSphereX == 0) {
			sphereX = -2.0f;
			sphereY = 0;
			sphereDirection = false;
			jumpLeft = false;
			sphereRotationZ = 0;
		}

		if (sphereX <= 0 && currentSphereX == 2.0f) {
			sphereX = 0;
			sphereY = 0;
			sphereDirection = false;
			jumpLeft = false;
			sphereRotationZ = 0;
		}

		if (sphereY >= 0.5f) {
			sphereDirection = true;
		}

		if (!sphereDirection) {
			sphereY += (speed / 2) * deltaTimeSeconds;
		}
		else {
			sphereY -= (speed / 2) * deltaTimeSeconds;
		}
	}

	if (jumpRight && currentSphereX <= 0) {
		sphereX += speed * deltaTimeSeconds;
		sphereRotationZ -= deltaTimeSeconds * 45;

		if (sphereX >= 2.0f && currentSphereX == 0) {
			sphereX = 2.0f;
			sphereY = 0;
			sphereDirection = false;
			jumpRight = false;
			sphereRotationZ = 0;
		}

		if (sphereX >= 0 && currentSphereX == -2.0f) {
			sphereX = 0;
			sphereY = 0;
			sphereDirection = false;
			jumpRight = false;
			sphereRotationZ = 0;
		}

		if (sphereY >= 0.5f) {
			sphereDirection = true;
		}

		if (!sphereDirection) {
			sphereY += (speed / 2) * deltaTimeSeconds;
		}
		else {
			sphereY -= (speed / 2) * deltaTimeSeconds;
		}
	}

	if (jumpFront) {
		sphereRotationX -= deltaTimeSeconds * 45;

		if (!sphereDirection) {
			sphereY += (speed / 2.0f) * deltaTimeSeconds;
		}
		else {
			sphereY -= (speed / 2.0f) * deltaTimeSeconds;
		}

		if (sphereY <= 0) {
			sphereY = 0;
			sphereDirection = false;
			jumpFront = false;
			sphereRotationX = 0;
		}

		if (sphereY >= 0.7f) {
			sphereDirection = true;
		}
	}


	if (start_platform) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				modelMatrix = glm::mat4(1);
				modelMatrix *= Transform3D::Translate(0, 0, firstTranslationZ);
				modelMatrix *= Transform3D::Translate(-0.75f + j * 1.5f, 0, -5.0f - 4.0f * i);
				RenderMesh(meshes["bluePlatform"], shaders["VertexColor"], modelMatrix);
			}
			for (int j = 1; j < 3; j++) {
				modelMatrix = glm::mat4(1);
				modelMatrix *= Transform3D::Translate(0, 0, firstTranslationZ);
				modelMatrix *= Transform3D::Translate(-0.75f - 1.5f * j, 0, -5.0f - 4.0f * i);
				RenderMesh(meshes["bluePlatform"], shaders["VertexColor"], modelMatrix);
			}

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0, 0, firstTranslationZ);
			modelMatrix *= Transform3D::Translate(3.75f, 0, -5.0f - 4.0f * i);
			RenderSimpleMesh(meshes["background"], shaders["ShaderTema3"], modelMatrix, mapTextures["clouds"]);

			modelMatrix = glm::mat4(1);
			modelMatrix *= Transform3D::Translate(0, 0, firstTranslationZ);
			modelMatrix *= Transform3D::Translate(-4, 0, -5.0f - 4.0f * i);
			RenderSimpleMesh(meshes["background"], shaders["ShaderTema3"], modelMatrix, mapTextures["clouds"]);
		}
		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, firstTranslationZ);
		modelMatrix *= Transform3D::Translate(-0.75f, 0, -13.0f);
		RenderMesh(meshes["bluePlatform"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, firstTranslationZ);
		modelMatrix *= Transform3D::Translate(-4, 0, -15.0f);
		RenderSimpleMesh(meshes["background"], shaders["ShaderTema3"], modelMatrix, mapTextures["clouds"]);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, firstTranslationZ);
		modelMatrix *= Transform3D::Translate(3.75f, 0, -15.0f);
		RenderSimpleMesh(meshes["background"], shaders["ShaderTema3"], modelMatrix, mapTextures["clouds"]);
		
		if (done_platform) {
			if (sphereX == 0) {
				if (firstTranslationZ - 15.0f >= 0) p14 = "purplePlatform";
				else if (sphereY == 0) falling = true;
			}
			else if (sphereX == 2.0f) {
				if (firstTranslationZ - 15.0f >= 0) p34 = "purplePlatform";
				else if (sphereY == 0) falling = true;
			}
			else if (sphereX == -2.0f) {
				if (firstTranslationZ - 15.0f >= 0) p24 = "purplePlatform";
				else if (sphereY == 0) falling = true;
			}
		}

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, firstTranslationZ);
		modelMatrix *= Transform3D::Translate(-0.75f, 0, -19.0f);
		RenderMesh(meshes[p14], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, firstTranslationZ);
		modelMatrix *= Transform3D::Translate(-3.0f, 0, -19.0f);
		RenderMesh(meshes[p24], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, firstTranslationZ);
		modelMatrix *= Transform3D::Translate(1.5f, 0, -19.0f);
		RenderMesh(meshes[p34], shaders["VertexColor"], modelMatrix);
		
		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, firstTranslationZ);
		modelMatrix *= Transform3D::Translate(3.75f, 0, -21.0f);
		RenderSimpleMesh(meshes["background"], shaders["ShaderTema3"], modelMatrix, mapTextures["clouds"]);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, firstTranslationZ);
		modelMatrix *= Transform3D::Translate(-4, 0, -21.0f);
		RenderSimpleMesh(meshes["background"], shaders["ShaderTema3"], modelMatrix, mapTextures["clouds"]);
		
	}

	if (orangeHit && orangeSeconds > 0) {
		speed = 5.0f;
		orangeSeconds--;
	}
	else if (orangeHit && orangeSeconds == 0) {
		orangeHit = false;
		speed = 2.5f;
	}

	if (firstTranslationZ >= 20.0f) {
		start_platform = false;
		firstTranslationZ = 0;
		done_platform = false;
	}

	if (firstTranslationZ >= 13.0f) {
		done_platform = true;
	}

	if (translationZ >= 13.0f) {
		translationZ = -5.0f;
		p11 = platforms[rand() % 5];
		p12 = platforms[rand() % 5];
		p13 = platforms[rand() % 5];
		o1 = rand() % 2;
		s1 = rand() % 2;
	}

	if (translationZ1 >= 19.0f) {
		translationZ1 = 1.0f;
		p21 = platforms[rand() % 5];
		p22 = platforms[rand() % 5];
		p23 = platforms[rand() % 5];
		o2 = rand() % 2;
		s2 = rand() % 2;
		x1 = rand() % 2;
		x2 = rand() % 2;
		if (x2 == s2) {
			if (s2 == 0) x2 = 1;
			else x2 = 0;
		}
		rotStar = 0;
	}

	if (translationZ2 >= 25.0f) {
		translationZ2 = 7.0f;
		p1 = platforms[rand() % 5];
		p2 = platforms[rand() % 5];
		p3 = platforms[rand() % 5];
		o3 = rand() % 2;
		s3 = rand() % 2;
	}

	pos spherePos = { 0, 0.7f, 0 }, tilePos = { -0.75f, 0, -12.0f };
	vector<int> sign = { -1, 1 };

	if (starHit && (tilePos.z + translationZ1 - 4 > 1.5f || translationZ1 == 1.0f)) {
		score += 1;
		starHit = false;
	}
	if (done_platform || !start_platform) {
		if (sphereX == tilePos.x + 0.75f) {
			if (((tilePos.z + translationZ + 2.2f >= 0 && o1 == 0 && tilePos.z + translationZ + 2.2f <= 1.0f) || (tilePos.z + translationZ1 - 3.8f >= 0 && o2 == 0 && tilePos.z + translationZ1 - 3.8f <= 1.0f)
				|| (tilePos.z + translationZ2 - 9.8f >= 0 && o3 == 0 && tilePos.z + translationZ2 - 9.8f <= 1.0f)) && sphereY == 0 && !start_platform) {
				falling = true;
			}
			if (tilePos.z + translationZ + 4.0f >= 0) {
				if (p11 == "redPlatform") {
					falling = true;
				}
				else if (p11 == "yellowPlatform") {
					fuelScale -= speed * 4 * deltaTimeSeconds;
				}
				else if (p11 == "orangePlatform") {
					orangeSeconds += 250;
					orangeHit = true;
				}
				else if (p11 == "greenPlatform") {
					fuelScale += speed * 4 * deltaTimeSeconds;
					fuelScale = min(fuelScale, 1.0f);
				}
				p11 = "purplePlatform";
			}
			else if (tilePos.z + translationZ1 - 2.0f >= 0) {
				if (p21 == "redPlatform") {
				falling = true;
				}
				else if (p21 == "yellowPlatform") {
					fuelScale -= speed * deltaTimeSeconds;
				}
				else if (p21 == "orangePlatform") {
					orangeSeconds += 250;
					orangeHit = true;
				}
				else if (p21 == "greenPlatform") {
					fuelScale += speed * 4 * deltaTimeSeconds;
					fuelScale = min(fuelScale, 1.0f);
				}
				p21 = "purplePlatform";
			}
			else if (tilePos.z + translationZ2 - 8.0f >= 0) {
				if (p1 == "redPlatform") {
					falling = true;
				}
				else if (p1 == "yellowPlatform") {
					fuelScale -= speed * deltaTimeSeconds;
				}
				else if (p1 == "orangePlatform") {
					orangeSeconds += 250;
					orangeHit = true;
				}
				else if (p1 == "greenPlatform") {
					fuelScale += speed * 4 * deltaTimeSeconds;
					fuelScale = min(fuelScale, 1.0f);
				}
				p1 = "purplePlatform";
			}
			else if (sphereY == 0 && !start_platform) falling = true;
		}
		else if (sphereX == tilePos.x - 1.25f) {
			if (((tilePos.z + translationZ + 2.2f >= 0 && o1 == 1 && s1 == 0 && tilePos.z + translationZ + 2.2f <= 1.0f) || (tilePos.z + translationZ1 -3.8f >= 0 && o2 == 1 && s2 == 0 && tilePos.z + translationZ1 - 3.8f <= 1.0f)
				|| (tilePos.z + translationZ2 - 9.8f >= 0 && o3 == 1 &&  s3 == 0 && tilePos.z + translationZ2 - 9.8f <= 1.0f)) && sphereY == 0 && !start_platform) {
				falling = true;
			}
			if (tilePos.z + translationZ + 4.0f >= 0) {
				if (p12 == "redPlatform") {
					falling = true;
				}
				else if (p12 == "yellowPlatform") {
					fuelScale -= speed * deltaTimeSeconds;
				}
				else if (p12 == "orangePlatform") {
					orangeSeconds += 250;
					orangeHit = true;
				}
				else if (p12 == "greenPlatform") {
					fuelScale += speed * 4 * deltaTimeSeconds;
					fuelScale = min(fuelScale, 1.0f);
				}
				p12 = "purplePlatform";
			}
			else if (tilePos.z + translationZ1 - 2.0f >= 0) {
				if (p22 == "redPlatform") {
					falling = true;
				}
				else if (p22 == "yellowPlatform") {
					fuelScale -= speed * 4 * deltaTimeSeconds;
				}
				else if (p22 == "orangePlatform") {
					orangeSeconds += 250;
					orangeHit = true;
				}
				else if (p22 == "greenPlatform") {
					fuelScale += speed * 4 * deltaTimeSeconds;
					fuelScale = min(fuelScale, 1.0f);
				}
				p22 = "purplePlatform";
			}
			else if (tilePos.z + translationZ2 - 8.0f >= 0) {
				if (p2 == "redPlatform") {
					falling = true;
				}
				else if (p2 == "yellowPlatform") {
					fuelScale -= speed * deltaTimeSeconds;
				}
				else if (p2 == "orangePlatform") {
					orangeSeconds += 250;
					orangeHit = true;
				}
				else if (p2 == "greenPlatform") {
					fuelScale += speed * 4 * deltaTimeSeconds;
					fuelScale = min(fuelScale, 1.0f);
				}
				p2 = "purplePlatform";
			}
			else if (sphereY == 0 && !start_platform) falling = true;
		}
		else if (sphereX == tilePos.x + 2.75f) {
			if (((tilePos.z + translationZ + 2.2f >= 0 && o1 == 1 && s1 == 1 && tilePos.z + translationZ + 2.2f <= 1.0f) || (tilePos.z + translationZ1 - 3.8f >= 0 && o2 == 1 && s2 == 1 && tilePos.z + translationZ1 - 3.8f <= 1.0f)
				|| (tilePos.z + translationZ2 - 9.8f >= 0 && o3 == 1 && s3 == 1 && tilePos.z + translationZ2 - 9.8f <= 1.0f)) && sphereY == 0 && !start_platform) {
				falling = true;
			}
			if (tilePos.z + translationZ + 4.0f >= 0) {
				if (p13 == "redPlatform") {
					falling = true;
				}
				else if (p13 == "yellowPlatform") {
					fuelScale -= speed * deltaTimeSeconds;
				}
				else if (p13 == "orangePlatform") {
					orangeSeconds += 250;
					orangeHit = true;
				}
				else if (p13 == "greenPlatform") {
					fuelScale += speed * 4 * deltaTimeSeconds;
					fuelScale = min(fuelScale, 1.0f);
				}
				p13 = "purplePlatform";
			}
			else if (tilePos.z + translationZ1 - 2.0f >= 0) {
				if (p23 == "redPlatform") {
					falling = true;
				}
				else if (p23 == "yellowPlatform") {
					fuelScale -= speed * deltaTimeSeconds;
				}
				else if (p23 == "orangePlatform") {
					orangeSeconds += 250;
					orangeHit = true;
				}
				else if (p23 == "greenPlatform") {
					fuelScale += speed * 4 * deltaTimeSeconds;
					fuelScale = min(fuelScale, 1.0f);
				}
				p23 = "purplePlatform";
			}
			else if (tilePos.z + translationZ2 - 8.0f >= 0) {
				if (p3 == "redPlatform") {
					falling = true;
				}
				else if (p3 == "yellowPlatform") {
					fuelScale -= speed * 4 * deltaTimeSeconds;
				}
				else if (p3 == "orangePlatform") {
					orangeSeconds += 250;
					orangeHit = true;
				}
				else if (p3 == "greenPlatform") {
					fuelScale += speed * 4 * deltaTimeSeconds;
					fuelScale = min(fuelScale, 1.0f);
				}
				p3 = "purplePlatform";
			}
			else if (sphereY == 0 && !start_platform) falling = true;
		}

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ);
		modelMatrix *= Transform3D::Translate(tilePos.x, tilePos.y, tilePos.z);
		RenderMesh(meshes[p11], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ);
		modelMatrix *= Transform3D::Translate(tilePos.x - 2.25f, tilePos.y, tilePos.z);
		RenderMesh(meshes[p12], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ);
		modelMatrix *= Transform3D::Translate(tilePos.x + 2.25f, tilePos.y, tilePos.z);
		RenderMesh(meshes[p13], shaders["VertexColor"], modelMatrix);
		
		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ);
		modelMatrix *= Transform3D::Translate(tilePos.x + 2.25f * o1 * sign[s1], tilePos.y, tilePos.z + 2);
		RenderMesh(meshes["obstacle"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ);
		modelMatrix *= Transform3D::Translate(3.75f, 0, tilePos.z - 2);
		RenderSimpleMesh(meshes["background"], shaders["ShaderTema3"], modelMatrix, mapTextures["clouds"]);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ);
		modelMatrix *= Transform3D::Translate(-4, 0, tilePos.z - 2);
		RenderSimpleMesh(meshes["background"], shaders["ShaderTema3"], modelMatrix, mapTextures["clouds"]);
		
		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ1);
		modelMatrix *= Transform3D::Translate(tilePos.x, tilePos.y, tilePos.z - 6.0f);
		RenderMesh(meshes[p21], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ1);
		modelMatrix *= Transform3D::Translate(tilePos.x - 2.25f, tilePos.y, tilePos.z - 6.0f);
		RenderMesh(meshes[p22], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ1);
		modelMatrix *= Transform3D::Translate(tilePos.x + 2.25f, tilePos.y, tilePos.z - 6.0f);
		RenderMesh(meshes[p23], shaders["VertexColor"], modelMatrix);

		rotStar += 0.25f;

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ1);
		modelMatrix *= Transform3D::Translate(tilePos.x + 2.25f * x1 * sign[x2] + 0.75f, tilePos.y + 0.5f, tilePos.z - 4);
		modelMatrix *= Transform3D::RotateOY(rotStar);
		modelMatrix *= Transform3D::RotateOZ(115);
		modelMatrix *= Transform3D::RotateOX(55);
		modelMatrix *= Transform3D::Scale(0.05f, 0.05f, 0.05f);
		RenderSimpleMesh(meshes["star"], shaders["ShaderTema3"], modelMatrix, NULL);
		if (tilePos.z + translationZ1 - 4 >= 0 && tilePos.z + translationZ1 - 4 <= 1.5f && sphereX == tilePos.x + 2.25f * x1 * sign[x2] + 0.75f && !starHit) {
				starHit = true;
		}

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ1);
		modelMatrix *= Transform3D::Translate(tilePos.x + 2.25f * o2 * sign[s2], tilePos.y, tilePos.z - 4);
		RenderMesh(meshes["obstacle"], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ1);
		modelMatrix *= Transform3D::Translate(3.75f, 0, tilePos.z - 8);
		RenderSimpleMesh(meshes["background"], shaders["ShaderTema3"], modelMatrix, mapTextures["clouds"]);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ1);
		modelMatrix *= Transform3D::Translate(-4, 0, tilePos.z - 8);
		RenderSimpleMesh(meshes["background"], shaders["ShaderTema3"], modelMatrix, mapTextures["clouds"]);
		
		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ2);
		modelMatrix *= Transform3D::Translate(tilePos.x, tilePos.y, tilePos.z - 12.0f);
		RenderMesh(meshes[p1], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ2);
		modelMatrix *= Transform3D::Translate(tilePos.x - 2.25f, tilePos.y, tilePos.z - 12.0f);
		RenderMesh(meshes[p2], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ2);
		modelMatrix *= Transform3D::Translate(tilePos.x + 2.25f, tilePos.y, tilePos.z - 12.0f);
		RenderMesh(meshes[p3], shaders["VertexColor"], modelMatrix);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ2);
		modelMatrix *= Transform3D::Translate(tilePos.x + 2.25f * o3 * sign[s3], tilePos.y, tilePos.z - 10);
		RenderMesh(meshes["obstacle"], shaders["VertexColor"], modelMatrix);
		
		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ2);
		modelMatrix *= Transform3D::Translate(3.75f, 0, tilePos.z - 14);
		RenderSimpleMesh(meshes["background"], shaders["ShaderTema3"], modelMatrix, mapTextures["clouds"]);

		modelMatrix = glm::mat4(1);
		modelMatrix *= Transform3D::Translate(0, 0, translationZ2);
		modelMatrix *= Transform3D::Translate(-4, 0, tilePos.z - 14);
		RenderSimpleMesh(meshes["background"], shaders["ShaderTema3"], modelMatrix, mapTextures["clouds"]);
		
	}

	if (fpFuel) GetSceneCamera()->SetPosition(glm::vec3(sphereX, 1.5f + sphereY, 0));
	modelMatrix = glm::mat4(1);
	modelMatrix *= Transform3D::Translate(sphereX, sphereY, 0);
	if (falling) {
		if (sphereY <= -0.5f) {
			sphereScale -= deltaTimeSeconds;
		}
		if (sphereScale <= 0) {
			falling = false;
		}
		if (firstTranslationZ >= 14.0f || firstTranslationZ == 0) {
			speed = 0;
			sphereY -= 1.5f * deltaTimeSeconds;
		}

		if (start_platform && firstTranslationZ >= 9 && !done_platform && (sphereX == -2 || sphereX == 2)) {
			speed = 0;
			sphereY -= 1.5f * deltaTimeSeconds;
		}
	}
	
	if (start_platform && sphereX != 0 && !done_platform) falling = true;

	modelMatrix *= Transform3D::Translate(spherePos.x, spherePos.y, spherePos.z);
	modelMatrix *= Transform3D::RotateOZ(sphereRotationZ);
	modelMatrix *= Transform3D::RotateOX(sphereRotationX);
	modelMatrix *= Transform3D::Scale(sphereScale, sphereScale, sphereScale);
	RenderSimpleMesh(meshes["sphere"], shaders["ShaderTema3"], modelMatrix, NULL);

	modelMatrix = glm::mat4(1);
	if (fpFuel) modelMatrix *= Transform3D::Translate(1.258f + sphereX, 1.802f + sphereY, -2.51f);
	else modelMatrix *= Transform3D::Translate(1.708f, 2.002f, -0.5f);
	RenderMesh(meshes["whiteRectangle"], shaders["VertexColor"], modelMatrix);
	
	modelMatrix = glm::mat4(1);
	if (fpFuel) modelMatrix *= Transform3D::Translate(1.25f + sphereX, 1.8f + sphereY, -2.5f);
	else modelMatrix *= Transform3D::Translate(1.7f, 2, -0.49f);
	modelMatrix *= Transform3D::Scale(fuelScale, 1, 1);
	RenderMesh(meshes["greyRectangle"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat4(1);
	if (fpFuel) modelMatrix *= Transform3D::Translate(1.258f + sphereX, 1.502f + sphereY, -2.51f);
	else modelMatrix *= Transform3D::Translate(1.708f, 1.702f, -0.5f);
	RenderMesh(meshes["whiteRectangle"], shaders["VertexColor"], modelMatrix);

	modelMatrix = glm::mat4(1);
	if (fpFuel) modelMatrix *= Transform3D::Translate(1.25f + sphereX, 1.5f + sphereY, -2.5f);
	else modelMatrix *= Transform3D::Translate(1.7f, 1.7, -0.49f);
	modelMatrix *= Transform3D::Scale(score / 10.0f, 1, 1);
	RenderMesh(meshes["turqoiseRectangle"], shaders["VertexColor"], modelMatrix);
}

void Tema3::FrameEnd()
{
}

void Tema3::OnInputUpdate(float deltaTime, int mods)
{	
	if (speed == 0) return;
	if (orangeSeconds > 0) return;
	if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT)) return;
	if (window->KeyHold(GLFW_KEY_W)) {
		if (speed >= 5.0f) return;
		speed += 2.5f * deltaTime;
	}
	else if (window->KeyHold(GLFW_KEY_S)) {
		if (speed <= 1.5f) return;
		speed -= 2.5f * deltaTime;
	}
}

void Tema3::OnKeyPress(int key, int mods)
{
	if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT)) return;
	if (falling) return;
	if (key == GLFW_KEY_A && !jumpLeft && !jumpRight && !jumpFront) {
		jumpLeft = true;
		currentSphereX = sphereX;
	} else if (key == GLFW_KEY_D && !jumpRight && !jumpLeft && !jumpFront) {
		jumpRight = true;
		currentSphereX = sphereX;
	} else if (key == GLFW_KEY_SPACE && !jumpRight && !jumpLeft && !jumpFront) {
		jumpFront = true;
	}

	if (key == GLFW_KEY_C) {
		if (cameraPos == glm::vec3(0, 1.6f, 2.5f)) {
			cameraPos = glm::vec3(0, 1.5f, 0);
			GetSceneCamera()->SetPosition(cameraPos);
			fpFuel = true;
		} else {
			cameraPos = glm::vec3(0, 1.6f, 2.5f);
			GetSceneCamera()->SetPosition(cameraPos);
			fpFuel = false;
		}
	}

}

void Tema3::OnKeyRelease(int key, int mods)
{
}

void Tema3::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
}

void Tema3::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
}

void Tema3::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
}

void Tema3::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema3::OnWindowResize(int width, int height)
{
}