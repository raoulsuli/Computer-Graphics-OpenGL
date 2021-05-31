#pragma once

#include <Component/SimpleScene.h>
#include <Core/Engine.h>

class Tema3 : public SimpleScene
{
public:
	Tema3();
	~Tema3();

	void Init() override;
	Mesh* CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned short>& indices);

private:

	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;

	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
	void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;
	void RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, Texture2D *texture1);

protected:
	bool jumpLeft = false, jumpRight = false, jumpFront = false;
	float sphereX = 0, sphereY = 0;
	float currentSphereX = 0;
	bool sphereDirection = false;
	float sphereRotationZ = 0;
	float sphereRotationX = 0;
	float speed = 2.5f;
	float sphereScale = 0.8f;
	int orangeSeconds = 0;
	bool orangeHit = false;
	bool falling = false;
	bool start_platform = true;
	bool done_platform = false;
	glm::vec3 cameraPos = { 0, 1.6f, 2.5f };
	bool fpFuel = false;
	std::unordered_map<std::string, Texture2D*> mapTextures;

	glm::vec3 lightPosition;
	glm::vec3 lightDirection;
	unsigned int materialShininess;
	float materialKd;
	float materialKs;
};