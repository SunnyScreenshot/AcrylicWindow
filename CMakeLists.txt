cmake_minimum_required(VERSION 3.20)
project(AcrylicWindow)

add_subdirectory(AcrylicMaterial)      # 利用 Windows SDK，制作的 .dll 动态库
add_subdirectory(BlurEffect)           # 奇思妙想，实现的 『等效』 跨平台透明磨砂效果
add_subdirectory(Demo)                 # 测试 .dll
