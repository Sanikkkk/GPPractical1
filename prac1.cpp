
#include <Windows.h>
#include <gl/GL.h>
#include <math.h>

#pragma comment (lib, "OpenGL32.lib")

#define WINDOW_TITLE "OpenGL Window"
#define PIE 3.1415926

float color = 0.1f;
float changeX = 0.1f;
float changeY = 0.1f;
float changeZ = 0.1f;
int questionToShow;

//for circle
const float numOfTriangle = 100;
const float angle = PIE * 2.f / numOfTriangle;

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		switch (wParam) {
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		case 0x31:
			questionToShow = 1;
			break;
		case 0x32:
			questionToShow = 2;
			break;
		case 0x33:
			questionToShow = 3;
			break;
		case 0x34:
			questionToShow = 4;
			break;
		case 0x35:
			questionToShow = 5;
			break;
		case 0x36:
			questionToShow = 6;
			break;
		case 0x37:
			questionToShow = 7;
			break;
		case 0x38:
			questionToShow = 8;
			break;
		case 0x39:
			questionToShow = 9;
			break;
		}

		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void display()
{
	switch (questionToShow) {
	case 1:
		glClearColor(color, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
		glTranslatef(changeX, changeY, changeZ);
		glBegin(GL_TRIANGLES),
			glLineWidth(5.0f);
		// we need some point here	
		glColor3f(1, 0, 0);
		glVertex2f(-0.5, 0);
		glColor3f(0, 1, 0);
		glVertex2f(0.5, 0);
		glColor3f(0, 0, 1);
		glVertex2f(0, 0.5);
		glEnd();
		break;
	case 2:
		glClearColor(color, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
		glTranslatef(changeX, changeY, changeZ);
		glBegin(GL_QUADS),
			glColor3f(1, 0, 0);
		glVertex2f(-0.5, 0.5);
		glColor3f(0, 1, 0);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.5, -0.5);
		glColor3f(0, 0, 1);
		glVertex2f(-0.5, -0.5);
		glEnd();
		break;
	case 3: //pahang flag
		glClearColor(color, 0.1f, 0.1f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();
		glBegin(GL_QUADS);
		glColor3f(255, 255, 255);
		glVertex2f(-0.7, 0.5);
		glColor3f(255, 255, 255);
		glVertex2f(0.7, 0.5);
		glColor3f(255, 255, 255);
		glVertex2f(0.7, 0);
		glColor3f(255, 255, 255);
		glVertex2f(-0.7, 0);


		glColor3f(0, 0, 0);
		glVertex2f(-0.7, 0);
		glColor3f(0, 0, 0);
		glVertex2f(0.7, 0);
		glColor3f(0, 0, 0);
		glVertex2f(0.7, -0.5);
		glColor3f(0, 0, 0);
		glVertex2f(-0.7, -0.5);
		glEnd();
		break;
	case 4: //negeri sembilan flag
		glClearColor(color, 0.1f, 0.1f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();

		glBegin(GL_QUADS);
		glColor3f(255, 255, 0);
		glVertex2f(-0.7, 0.5);
		glColor3f(255, 255, 0);
		glVertex2f(0.7, 0.5);
		glColor3f(255, 255, 0);
		glVertex2f(0.7, -0.5);
		glColor3f(255, 255, 0);
		glVertex2f(-0.7, -0.5);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0, 0, 0);
		glVertex2f(-0.7, 0.5);
		glColor3f(0, 0, 0);
		glVertex2f(-0.7, 0);
		glColor3f(0, 0, 0);
		glVertex2f(0, 0);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(255, 0, 0);
		glVertex2f(0, 0);
		glColor3f(255, 0, 0);
		glVertex2f(0, 0.5);
		glColor3f(255, 0, 0);
		glVertex2f(-0.7, 0.5);
		glEnd();
		break;
	case 5:
		glClearColor(color, 0.1f, 0.1f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();

		glBegin(GL_QUADS); // for background
		glColor3f(0.780, 0.780, 0.780);
		glVertex2f(-0.7, 0.5);
		glColor3f(0.850, 0.850, 0.850); 
		glVertex2f(0.7, 0.5);
		glColor3f(0.850, 0.850, 0.850); 
		glVertex2f(0.7, -0.5);
		glColor3f(0.780, 0.780, 0.780); 
		glVertex2f(-0.7, -0.5);

		// for the +, this one is -
		glColor3f(0.5686f, 0.0039f, 0.0039f);
		glVertex2f(-0.7, 0.1);
		glColor3f(0.5686f, 0.0039f, 0.0039f);
		glVertex2f(0.7, 0.1);
		glColor3f(0.5686f, 0.0039f, 0.0039f);
		glVertex2f(0.7, -0.1);
		glColor3f(0.5686f, 0.0039f, 0.0039f);
		glVertex2f(-0.7, -0.1);

		// for the +, this one is |
		glColor3f(0.5686f, 0.0039f, 0.0039f);
		glVertex2f(-0.1, 0.5);
		glColor3f(0.5686f, 0.0039f, 0.0039f);
		glVertex2f(0.1, 0.5);
		glColor3f(0.5686f, 0.0039f, 0.0039f);
		glVertex2f(0.1, -0.5);
		glColor3f(0.5686f, 0.0039f, 0.0039f);
		glVertex2f(-0.1, -0.5);
		glEnd();
		break;
	case 6:
		glClearColor(color, 0.1f, 0.1f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();

		glBegin(GL_QUADS); // for background
		glColor3f(1, 1, 1);
		glVertex2f(-0.7, 0.5);
		glColor3f(1, 1, 1);
		glVertex2f(0.7, 0.5);
		glColor3f(1, 1, 1);
		glVertex2f(0.7, -0.5);
		glColor3f(1, 1, 1);
		glVertex2f(-0.7, -0.5);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.396f, 0.741f);
		glVertex2f(-0.7, 0.4);
		glColor3f(0.0f, 0.396f, 0.741f);
		glVertex2f(-0.7, -0.4);
		glColor3f(0.0f, 0.396f, 0.741f);
		glVertex2f(-0.1, 0);

		glColor3f(0.0f, 0.396f, 0.741f);
		glVertex2f(0.7, 0.4);
		glColor3f(0.0f, 0.396f, 0.741f);
		glVertex2f(0.7, -0.4);
		glColor3f(0.0f, 0.396f, 0.741f);
		glVertex2f(0.1, 0);

		glColor3f(0.0f, 0.396f, 0.741f);
		glVertex2f(-0.55, 0.5);
		glColor3f(0.0f, 0.396f, 0.741f);
		glVertex2f(0.55, 0.5);
		glColor3f(0.0f, 0.396f, 0.741f);
		glVertex2f(0, 0.1);

		glColor3f(0.0f, 0.396f, 0.741f);
		glVertex2f(-0.55, -0.5);
		glColor3f(0.0f, 0.396f, 0.741f);
		glVertex2f(0.55, -0.5);
		glColor3f(0.0f, 0.396f, 0.741f);
		glVertex2f(0, -0.1);
		glEnd();
		break;

	case 7:
		glClearColor(color, 0.1f, 0.1f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT);
		glLoadIdentity();

		// for backgroud
		float x = 0;
		float y = 0;
		float radius = 0.7f;
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.176f, 0.184f, 0.553f);
		glVertex2f(x, y);
		for (int i = 0;i <= numOfTriangle;i++) {
			float newX = x + radius * cos(angle * i);
			float newY = y + radius * sin(angle * i);
			glVertex2f(newX,newY);
		}
		glEnd();

		// for left eye
		float x2 = -0.25;
		float y2 = 0.25;
		float radius2 = 0.125f;
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0, 0, 0);
		glVertex2f(x2, y2);
		for (int i = 0;i <= numOfTriangle;i++) {
			float newX = x2 + radius2 * cos(angle * i);
			float newY = y2 + radius2 * sin(angle * i);
			glVertex2f(newX, newY);
		}
		glEnd();

		// for left eye white
		float x22 = -0.3;
		float y22 = 0.3;
		float radius22 = 0.05f;
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 1, 1);
		glVertex2f(x22, y22);
		for (int i = 0;i <= numOfTriangle;i++) {
			float newX = x22 + radius22 * cos(angle * i);
			float newY = y22 + radius22 * sin(angle * i);
			glVertex2f(newX, newY);
		}
		glEnd();

		// for left eye white
		float x222 = -0.20;
		float y222 = 0.20;
		float radius222 = 0.05f;
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 1, 1);
		glVertex2f(x222, y222);
		for (int i = 0;i <= numOfTriangle;i++) {
			float newX = x222 + radius222 * cos(angle * i);
			float newY = y222 + radius222 * sin(angle * i);
			glVertex2f(newX, newY);
		}
		glEnd();

		// right eye
		float x3 = 0.25;
		float y3 = 0.25;
		float radius3 = 0.125f;
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0, 0, 0);
		glVertex2f(x3, y3);
		for (int i = 0;i <= numOfTriangle;i++) {
			float newX = x3 + radius3 * cos(angle * i);
			float newY = y3 + radius3 * sin(angle * i);
			glVertex2f(newX, newY);
		}
		glEnd();

		// for right eye white
		float x33 = 0.3;
		float y33 = 0.3;
		float radius33 = 0.05f;
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 1, 1);
		glVertex2f(x33, y33);
		for (int i = 0;i <= numOfTriangle;i++) {
			float newX = x33 + radius33 * cos(angle * i);
			float newY = y33 + radius33 * sin(angle * i);
			glVertex2f(newX, newY);
		}
		glEnd();

		// for right eye white
		float x333 = 0.20;
		float y333 = 0.20;
		float radius333 = 0.05f;
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1, 1, 1);
		glVertex2f(x333, y333);
		for (int i = 0;i <= numOfTriangle;i++) {
			float newX = x333 + radius333 * cos(angle * i);
			float newY = y333 + radius333 * sin(angle * i);
			glVertex2f(newX, newY);
		}
		glEnd();

		// mouth
		float x4 = 0;
		float y4 = -0.25;
		float radiusX = 0.3f;    
		float radiusY = 0.2f;    
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(0,0, 0);  

		glVertex2f(x4, y4);

		for (int i = 0; i <= numOfTriangle; i++) {
			float newX = x4 + radiusX * cos(angle * i);
			float newY = y4 + radiusY * sin(angle * i);
			glVertex2f(newX, newY);
		}
		glEnd();

		// inside mouth
		float x5 = 0;
		float y5 = -0.25;
		float radiusX2 = 0.25f;
		float radiusY2 = 0.15f;
		glBegin(GL_TRIANGLE_FAN);
		glColor3f(1.0f, 0.957f, 0.424f);

		glVertex2f(x5, y5);

		for (int i = 0; i <= numOfTriangle; i++) {
			float newX = x5 + radiusX2 * cos(angle * i);
			float newY = y5 + radiusY2 * sin(angle * i);
			glVertex2f(newX, newY);
		}
		glEnd();

		float thetaLeft = -0.3f; 
		float thetaRight = 0.3f; 

		float x6 = -0.009;
		float y6 = -0.22;
		float radius4 = 0.075f;
		glLineWidth(15.0f);
		glBegin(GL_LINE_STRIP);
		glColor3f(0, 0, 0);

		for (int i = 0; i <= numOfTriangle; i++) {
			float angle = PIE + (PIE * i / numOfTriangle);
			float newX = x6 + radius4 * cos(angle);
			float newY = y6 + radius4 * sin(angle);

			// Apply left rotation
			float rotatedX = newX * cos(thetaLeft) - newY * sin(thetaLeft);
			float rotatedY = newX * sin(thetaLeft) + newY * cos(thetaLeft);

			float newX2 = x6 + radius4 * cos(angle);
			float newY2 = y6 - 0.03f + radius4 * sin(angle);

			// Apply left rotation for second vertex
			float rotatedX2 = newX2 * cos(thetaLeft) - newY2 * sin(thetaLeft);
			float rotatedY2 = newX2 * sin(thetaLeft) + newY2 * cos(thetaLeft);

			glVertex2f(rotatedX, rotatedY);
			glVertex2f(rotatedX2, rotatedY2);
		}
		glEnd();

		// Line inside mouth (right side)
		float x7 = 0.009;
		float y7 = -0.22;
		float radius5 = 0.075f;
		glLineWidth(15.0f);
		glBegin(GL_LINE_STRIP);
		glColor3f(0, 0, 0);

		for (int i = 0; i <= numOfTriangle; i++) {
			float angle = PIE + (PIE * i / numOfTriangle);
			float newX = x7 + radius5 * cos(angle);
			float newY = y7 + radius5 * sin(angle);

			// Apply right rotation
			float rotatedX = newX * cos(thetaRight) - newY * sin(thetaRight);
			float rotatedY = newX * sin(thetaRight) + newY * cos(thetaRight);

			float newX2 = x7 + radius5 * cos(angle);
			float newY2 = y7 - 0.03f + radius5 * sin(angle);

			// Apply right rotation for second vertex
			float rotatedX2 = newX2 * cos(thetaRight) - newY2 * sin(thetaRight);
			float rotatedY2 = newX2 * sin(thetaRight) + newY2 * cos(thetaRight);

			glVertex2f(rotatedX, rotatedY);
			glVertex2f(rotatedX2, rotatedY2);
		}
		glEnd();

		// eyebrow left
		float x8 = -0.175;
		float y8 = 0.5;
		float radiusX3 = 0.175f;
		float radiusY3 = 0.03f;
		float theta = 0.25f; // Rotation angle in radians
		glLineWidth(30.0f);
		glBegin(GL_LINE_STRIP);
		glColor3f(0, 0, 0);
		for (int i = 0; i <= numOfTriangle; i++) {
			float angle = PIE * i / numOfTriangle;
			float newX = x8 + radiusX3 * cos(angle);
			float newY = y8 + radiusY3 * sin(angle);

			// Apply rotation for newX and newY
			float rotatedX = newX * cos(theta) - newY * sin(theta);
			float rotatedY = newX * sin(theta) + newY * cos(theta);

			float newX2 = x8 + radiusX3 * cos(angle);
			float newY2 = y8 - 0.05f + radiusY3 * sin(angle);

			// Apply rotation for newX2 and newY2
			float rotatedX2 = newX2 * cos(theta) - newY2 * sin(theta);
			float rotatedY2 = newX2 * sin(theta) + newY2 * cos(theta);

			glVertex2f(rotatedX, rotatedY);
			glVertex2f(rotatedX2, rotatedY2);
		}
		glEnd();

		// eyebrow right
		float x9 = 0.175;
		float y9 = 0.5;
		float radiusX4 = 0.175f;
		float radiusY4 = 0.03f;
		float theta2 = -0.25f; // Rotation angle in radians
		glLineWidth(30.0f);
		glBegin(GL_LINE_STRIP);
		glColor3f(0, 0, 0);
		for (int i = 0; i <= numOfTriangle; i++) {
			float angle = PIE * i / numOfTriangle;
			float newX = x9 + radiusX4 * cos(angle);
			float newY = y9 + radiusY4 * sin(angle);

			// Apply rotation for newX and newY
			float rotatedX = newX * cos(theta2) - newY * sin(theta2);
			float rotatedY = newX * sin(theta2) + newY * cos(theta2);

			float newX2 = x9 + radiusX4 * cos(angle);
			float newY2 = y9 - 0.05f + radiusY4 * sin(angle);

			// Apply rotation for newX2 and newY2
			float rotatedX2 = newX2 * cos(theta2) - newY2 * sin(theta2);
			float rotatedY2 = newX2 * sin(theta2) + newY2 * cos(theta2);

			glVertex2f(rotatedX, rotatedY);
			glVertex2f(rotatedX2, rotatedY2);
		}
		glEnd();
	}
	//--------------------------------
	//	OpenGL drawing
	//--------------------------------



	//--------------------------------
	//	End of OpenGL drawing
	//--------------------------------
}
//--------------------------------------------------------------------

// hinstance hinst is something like provide an ID, like maybe i need to open 5 times the program, but they are in same program, then each of the program has an id
// histance hprevinst rarely use it, it is for security purpose
// lpstr cmdlineparam is command line parameter,OS pass command to program
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR cmdlineparam, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX)); //zeromemory find address, get the size, and fill zero 

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL); //or put hInst, same result
	wc.lpfnWndProc = WindowProcedure; //window procedure incharge on capture input and process it, example is when user wan to close the program, then it will capture it and process
	wc.lpszClassName = WINDOW_TITLE; //classname, can put whatever u wan
	wc.style = CS_HREDRAW | CS_VREDRAW; // horizontal size and vertical size

	if (!RegisterClassEx(&wc)) return false; //define the class, check whether it is correct created or not, the above one

	HWND hWnd = CreateWindow(WINDOW_TITLE, // this one is ur window class name,
		WINDOW_TITLE, // this one is your window title, at left corner
		WS_OVERLAPPEDWINDOW, //style
		CW_USEDEFAULT, //size of the window location
		CW_USEDEFAULT, //size of the window location
		800, //width
		800, //height
		NULL,
		NULL, //menu paramenter, something like this vs 2022 top one punya menu, file,edit.....
		wc.hInstance, //the id
		NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true) // infinite loop, keep track user event
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) // check if got message or not,
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------