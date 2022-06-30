#ifndef ACRYLICMATERIAL_H
#define ACRYLICMATERIAL_H

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容

// Windows 头文件
#include <windows.h>

extern "C" _declspec(dllexport) void setAcrylicEffect(HWND hWnd, DWORD accentFlags = 0, DWORD gradientColor = 0, DWORD animationId = 0);
extern "C" _declspec(dllexport) void setAeroEffect(HWND hWnd);
//extern "C" _declspec(dllexport) bool setShadowEffect(bool class_amended, HWND hWnd,bool newShadow);
//extern "C" _declspec(dllexport) void addShadowEffect(bool shadowEnable, HWND hWnd);
//extern "C" _declspec(dllexport) void setWindowFrame(HWND hWnd, int left, int top, int right, int buttom);


#endif // ACRYLICMATERIAL_H
