#pragma once
#include <windows.h>
#include "SpoutLogger.h"

class OpenGLUtils
{
public:
	OpenGLUtils(void);
	~OpenGLUtils(void);
	bool InitOpenGL();
	bool TestLog();
	HWND g_hwnd;
	HDC g_hdc;
};

