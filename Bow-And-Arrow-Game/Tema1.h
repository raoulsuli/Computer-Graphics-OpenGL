#pragma once

#include <Component/SimpleScene.h>
#include <Core/Engine.h>

class Tema1 : public SimpleScene
{
public:
	Tema1();
	~Tema1();

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

protected:
	float const line_width = 4;
	float const line_height = 0.125f;
	float const arrowTip_width = 0.25f;
	float const arrowTip_height = 0.5f;
	float const line_ratio = 0.1f;
	float const arrowTip_ratio = 0.25f;
	float const bow_ratio = 0.2f;
	float const bow_height = 0.75f;
	float const bow_width = 1.5f;
	float const baloon_ratioX = 0.1f;
	float const baloon_ratioY = 0.15f;
	float const baloon_width = 3;
	float const baloon_height = 3;
	float const redBaloon_posX = 2.5f;
	float const yellowBaloon_posX = 4.0f;
	float const baloon_posY = -baloon_height * baloon_ratioX;
	float const multiline_ratio = 0.25f;
	float const multiline_width = 0.45f;
	float const multiline_height = 0.8f;
	float const redMultiline_posX = redBaloon_posX;
	float const yellowMultiline_posX = yellowBaloon_posX;
	float const multiline_posY = baloon_posY - multiline_width * multiline_ratio * 2;
	float const shuriken_ratio = 0.35f;
	float const shuriken_posX = 4;
	float const shuriken_posY = 0.5f;
	//constante pentru afisarea obiectelor

	float redBaloon_translateY = 0, yellowBaloon_translateY = 0, shuriken_translateX = 0;
	float shuriken_rotate = 0;
	float bow_translate = 0;
	float bow_rotation = 0;
	float shoot_arrowX = 0, shoot_arrowY = 0;
	float mouse_posX = 0, mouse_posY = 0;
	float arrow_dirX = 0, arrow_dirY = 0;
	float arrow_rotation_shoot = 0;
	float arrow_posX_initial = 0, arrow_posY_initial = 0;
	float line_posX_initial = 0, line_posY_initial = 0;
	//variabile pentru transformarea obiectelor
	
	float resolution_x = window->GetResolution().x, resolution_y = window->GetResolution().y;
	float redBaloonDestroyRatio = 0;
	float yellowBaloonDestroyRatio = 0;
	bool save_pos = false;
	bool mouse_pressed = false;
	bool redBaloonHit = false;
	bool yellowBaloonHit = false;
	bool max_power = false;

	int player_lifes = 3;
	
	float shooting_power = 0.5f;
	//teste pentru coliziuni si alte efecte aplicate
};
