#pragma once


#include <memory>
#include <iostream>
#include <optional>

#include <ImGui/imgui.h>
#include <ImGui/backends/imgui_impl_opengl3.h>
#include <ImGui/backends/imgui_impl_glfw.h>

#include <GLFW/glfw3.h>


namespace GUI {

class Window
{
public:
    Window();
    ~Window();

    Window(const Window& window) = delete;
    Window(Window&& window) = delete;

    void RunRenderingLoop();

private:

    // Funkcja pomocnicza służąca do wypisania błędów inijalizacji OpenGL
    // za pomocą standardowego potoku.
    static void ErrorCallbackFunctionGLFW(int errorCode, const char* errorDescription)
    {
        std::cout << "Błąd inicjalizacji GLFW - Error: " << errorCode << " Opis: " << errorDescription << std::endl;
    }

    bool InitialiseGLFW();
    bool InitialiseImGui();

    std::optional<GLFWwindow*> m_WindowBackendGLFW;

    bool m_ShowDemoWidget = true;
    bool m_ShowHelperWidget = false;

    const ImVec4 m_WindowBackground = ImVec4(0.01f, 0.01f, 0.01f, 1.00f);
};


}

