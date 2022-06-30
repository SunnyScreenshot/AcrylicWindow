#include "acrylicmaterial.h"
#include "AcrylicAttribute.h"

//#pragma comment (lib,"Dwmapi.lib") // 使用阴影

void setAcrylicEffect(HWND hWnd, DWORD accentFlags, DWORD gradientColor, DWORD animationId)
{

    //开启亚克力效果
    HMODULE hUser = GetModuleHandle(L"user32.dll");
    if (hUser)
    {

        pfnSetWindowCompositionAttribute setWindowCompositionAttribute = (pfnSetWindowCompositionAttribute)GetProcAddress(hUser, "SetWindowCompositionAttribute");
        if (setWindowCompositionAttribute)
        {
            ACCENT_POLICY accent = { ACCENT_ENABLE_ACRYLICBLURBEHIND, accentFlags, gradientColor, animationId };
            WINDOWCOMPOSITIONATTRIBDATA data;
            data.Attrib = WCA_ACCENT_POLICY;
            data.pvData = &accent;
            data.cbData = sizeof(accent);
            setWindowCompositionAttribute(hWnd, &data);
        }
    }
}

void setAeroEffect(HWND hWnd)
{
    //开启Aero效果
    HMODULE hUser = GetModuleHandle(L"user32.dll");
    if (hUser)
    {

        pfnSetWindowCompositionAttribute setWindowCompositionAttribute = (pfnSetWindowCompositionAttribute)GetProcAddress(hUser, "SetWindowCompositionAttribute");
        if (setWindowCompositionAttribute)
        {
            ACCENT_POLICY accent = { ACCENT_ENABLE_BLURBEHIND, 0,0,0 };
            WINDOWCOMPOSITIONATTRIBDATA data;
            data.Attrib = WCA_ACCENT_POLICY;
            data.pvData = &accent;
            data.cbData = sizeof(accent);
            setWindowCompositionAttribute(hWnd, &data);
        }
    }
}

//bool setShadowEffect(bool class_amended, HWND hWnd,bool newShadow)
//{
//    //如果没有去除旧的阴影就先去掉

//    if (class_amended == false)
//    {
//        class_amended = true;
//        DWORD class_style = ::GetClassLong(hWnd, GCL_STYLE);
//        class_style &= ~CS_DROPSHADOW;
//        ::SetClassLong(hWnd, GCL_STYLE, class_style);
//    }

//    //根据newShadow决定是否添加新的阴影
//    DWMNCRENDERINGPOLICY val = DWMNCRP_ENABLED;
//    ::DwmSetWindowAttribute(hWnd, DWMWA_NCRENDERING_POLICY, &val, sizeof(DWMNCRENDERINGPOLICY));

//    MARGINS m = { -1 };
//    if (!newShadow) m = { 0 };
//    HRESULT hr = ::DwmExtendFrameIntoClientArea(hWnd, &m);
//    if (SUCCEEDED(hr))
//    {

//    }

//    return class_amended;

//}

////直接添加阴影
//void addShadowEffect(bool shadowEnable, HWND hWnd)
//{
//    if (shadowEnable)
//    {
//        BOOL bEnable = false;
//        ::DwmIsCompositionEnabled(&bEnable);
//        if (bEnable)
//        {
//            DWMNCRENDERINGPOLICY ncrp = DWMNCRP_ENABLED;
//            ::DwmSetWindowAttribute(hWnd, DWMWA_NCRENDERING_POLICY, &ncrp, sizeof(ncrp));
//            MARGINS margins = { -1 };
//            ::DwmExtendFrameIntoClientArea(hWnd, &margins);
//        }
//    }
//}

//void setWindowFrame(HWND hWnd,int left, int top, int right, int buttom)
//{
//    SetWindowLongPtr(hWnd, GWL_STYLE, WS_POPUP | WS_CAPTION | WS_THICKFRAME | WS_MAXIMIZEBOX | WS_MINIMIZEBOX);
//    //把client区域扩展到标题栏上和边框上，只留1个像素的余量
//    const MARGINS shadow = { left,top,right,buttom };
//    DwmExtendFrameIntoClientArea(hWnd, &shadow);
//}
