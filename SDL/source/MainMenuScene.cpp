#include "MainMenuScene.h"

void MainMenuScene::Update()
{
	//Check if the mouse is inside the render rect
	int width = 28 * sampleText.text.length();
	int height = 50;

	int X = sampleText.position[0] - width / 2;
	int Y = sampleText.position[1] - height / 2;
	//sampleText.postition <- x, y
	int mouseX = IM->GetMouseX();
	int mouseY = IM->GetMouseY();

	bool isInsideAABBX = mouseX > X && mouseX < X + width;
	bool isInsideAABBY = mouseY > Y && mouseY < Y + height;

	if (isInsideAABBX && isInsideAABBY) 
	{
		buttonAngle+=0.02f;
		if (IM->CheckKeyState(SDLK_i, PRESSED))
			SM->SetScene("Splash Screen");
	}
	else 
	{
		buttonAngle = 0;
	}
}

void MainMenuScene::Render(SDL_Renderer* renderer, int _width, int _height)
{
	//Text data
	int width = 28 * sampleText.text.length();
	int height = 50;
	SDL_Color color = { 255,255,255 };
	SDL_Surface* surface = TTF_RenderText_Solid(font, sampleText.text.c_str(), color);

	assert(surface != nullptr);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	//255 -> opaque
	//0   -> transparent
	SDL_SetTextureAlphaMod(texture, 255);

	SDL_Rect renderRect = 
	{
		sampleText.position[0]-width/2,
		sampleText.position[1]-height/2,
		width,
		height
	};

	SDL_RenderCopyEx(
		renderer,			//Renderer
		texture,			//Target texture
		NULL,			//Texture part we want to draw
		&renderRect,	//Where do we want to draw and what size
		sin(buttonAngle * (3.14f*2.0f)/180.0f)*10,		//angle
		NULL,			//center of the sprite
		SDL_FLIP_NONE		//flip the sprite
	);

	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void MainMenuScene::OnEnter()
{
	//INIT TTF
	assert(TTF_Init() != -1);

	//Load the font
	font = TTF_OpenFont("resources/fonts/font.ttf", 28);
	assert(font != nullptr);
	sampleText.text = "Billar?";

	sampleText.text = "HOLA K ASE";
	sampleText.position[0] = 250;
	sampleText.position[1] = 250;

	buttonAngle = 0;
}

void MainMenuScene::OnExit()
{
}
