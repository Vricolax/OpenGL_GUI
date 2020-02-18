#include <iostream>
#include "glut.h"
#include "Vector2D.h"
#include "Handlers.h"
#include "Texture.h"
#include "Renderer.h"
#include "WindowManager.h"


using namespace std;

// used by opengl function
bool Down = false;

// initial size of the OpenGL window
int Width = 800;
int Height = 800;

// init GLUT
void InitGL(int argc, char **argv);

// clear screen
void ClearScreen();

// display function
void Display();

// motion function, while mouse pressed
void Motion(int x, int y);

// motion function, while mouse not pressed
void PassMotion(int x, int y);

// resize function for OpenGL
void Resize(int width, int height);

// Mouse Event Handling function for OpenGL
void ClickFunc(int button, int state, int x, int y);

// Main Renderer
Renderer *renderer;

// Main GUI manager
WindowManager *window_mgr;

int main (int argc, char **argv){

	// Create a window manager, a renderer
	WindowManager::Create();
	window_mgr = WindowManager::Get();

	renderer = new Renderer(Width, Height);
	window_mgr->SetRenderer(renderer);


	// Create a background texture for the GUI
	Texture *background = new Texture("background_galaxy.bmp",1920,1080);

	// add the background to the window manager
	window_mgr->AddBackground(background);


	// Create some random labels and buttons and set them up
	Label label = Label("Change Color");
	label.SetPosition(10, 10);
	
	Label label2 = Label("New Window");
	label2.SetPosition(10,10);

	Button *button = new Button(label, 50, 150);
	Button *button2 = new Button(label2, 50, 200);

	// Create New Window Handler for the main window
	EventHandler *create_window_h = new CreateNewWindowHandler(window_mgr);
	button2->SetEventHandler(create_window_h);

	Window *window = new Window(20, 20, 300, 400);
	window->SetTitle(new Label("Window 1"));
	
	Window *window2 = new Window(350, 50, 300, 400);
	window2->SetTitle(new Label("Window 2"));
	
	window->SetColor(0.7f, 0.5f, 0.5f);
	window2->SetColor(0.4f, 0.5f, 0.4f);

	window->AddChild(button);
	window->AddChild(button2);

	Label title = Label("File");


	// Create some selections for a popup menu in window 1
	Selection create_window = Selection(Label("Create Window"));
	Selection exit_selection1 = Selection(Label ("Exit"));

	create_window.SetEventHandler(create_window_h);

	ExitWindowHandler *exit_handler = new ExitWindowHandler(window);
	exit_selection1.SetEventHandler(exit_handler);

	//Initialize menu for window1
	Menu menu1 = Menu(title, 2.0f, 2.0f, 50.0f, 32);
	menu1.SetPosition(0, 34);
	menu1.SetRenderer(renderer);
	menu1.AddSelection(&create_window);
	menu1.AddSelection(&exit_selection1);


	// Creating some selections for a popup menu in window 2
	Selection new_selection = Selection(Label("New Document"));
	Selection open_selection = Selection(Label("Open Document"));
	Selection save_selection = Selection(Label("Save"));
	Selection exit_selection2 = Selection(Label("Exit"));


	ExitWindowHandler *exit2_handler = new ExitWindowHandler(window2);
	exit_selection2.SetEventHandler(exit2_handler);


	ChangeWindowColorHandler *changeColor_handler = new ChangeWindowColorHandler(window);
	button->SetEventHandler(changeColor_handler);

	//Initialize menu for window2
	Menu menu = Menu(title, 2.0f, 2.0f, 50.0f, 32);
	menu.SetPosition(0, 34);
	menu.SetRenderer(renderer);
	menu.AddSelection(&new_selection);
	menu.AddSelection(&open_selection);
	menu.AddSelection(&save_selection);
	menu.AddSelection(&exit_selection2);


	// add menus to appropriate windows
	window2->AddChild(&menu);
	window->AddChild(&menu1);
	

	// add windows to vector
	vector<Window*> windows = vector<Window*>();
	windows.push_back(window);
	windows.push_back(window2);
	
	// add windows vector to window manager
	window_mgr->AddWindows(windows);

	// initialize glut
	InitGL(argc, argv);
	window_mgr->Destroy();
	return 0;
} 

void InitGL(int argc, char **argv) {
	glutInit (&argc, argv);
	glutInitWindowPosition (250, 200);
	glutInitWindowSize (Width,Height);
	glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("Appication GUI");	
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,Width,0,Height);
	glutDisplayFunc (Display);
	
	glutMouseFunc(ClickFunc);
	glutReshapeFunc(Resize);
	glutMotionFunc(Motion);
	glutPassiveMotionFunc(PassMotion);

	
	glutMainLoop();
}

void ClearScreen()
{
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Display()
{
	ClearScreen();
	
	//Rendering the Background
	window_mgr->draw();
	

	glFlush();
}

void Resize(int width, int height)
{
	renderer->ResizeWindow(width, height);
	glViewport(0, 0, width, height);
	glutPostRedisplay();
}

void Motion(int x, int y){
	window_mgr->MouseMove(x, y);
	glutPostRedisplay();
}

void PassMotion(int x, int y){
	window_mgr->MouseMove(x, y);
	glutPostRedisplay();
}

void ClickFunc(int button, int state, int x, int y) 
{
	// mouse down (change appearence of guiitem)
	if(button == GLUT_LEFT_BUTTON && state==GLUT_DOWN)// && x>=246 && x<=368 && y>=432 && y<=475) 
	{
		Down = true;
	}
	// mouse up - click
	else if (Down && button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		Down = false;
	}
	
	// run window manager's event generators
	if (Down)
		window_mgr->MouseLBDown(x, y);
	else
		window_mgr->MouseLBUp(x, y);
	glutPostRedisplay();
}


