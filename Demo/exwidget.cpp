#include "exwidget.h"
#include <windows.h>

ExWidget::ExWidget(QWidget *parent)
    : QWidget(parent)
{
    //setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    QColor color(255, 50, 50, 80);


    HWND hMoudle = (HWND)(winId());
    HMODULE hDLL = LoadLibrary(L"AcrylicMaterial");

    using fun = void (*)(HWND hWnd);
    //fun pSetBlur = (fun)GetProcAddress(hDLL, "setAcrylicEffect");
    fun pSetBlur = (fun)GetProcAddress(hDLL, "setAeroEffect");
    pSetBlur((HWND)(winId()));

    //FreeLibrary(hDLL);  // 系统亦会自动释放
}
