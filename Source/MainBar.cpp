#include "MainBar.hpp"
#include "Instance.hpp"

UntitledImageViewer::MainBar::MainBar()
{

}

void UntitledImageViewer::MainBar::begin()
{
    beginAutohandle();

}

void UntitledImageViewer::MainBar::tick(float deltaTime)
{
    tickAutohandle(deltaTime);
    if (ImGui::BeginMainMenuBar())
    {
        auto* initInfo = (Instance*)Instance::getGlobal();
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("Open"));
            if (ImGui::MenuItem("Save"));
            if (ImGui::MenuItem("Save As"));
            if (ImGui::MenuItem("Exit"))
                initInfo->exitWidget.state = UImGui::UIMGUI_COMPONENT_STATE_RUNNING;
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Undo"));
            if (ImGui::MenuItem("Redo"));
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Settings"))
        {
            if (ImGui::MenuItem("Application Settings"));
            if (ImGui::MenuItem("Keybindings Settings"));
            ImGui::EndMenu();
        }


        if (ImGui::BeginMenu("More"))
        {
            if (ImGui::MenuItem("Help"))
                initInfo->help.state = UImGui::UIMGUI_COMPONENT_STATE_RUNNING;
            if (ImGui::MenuItem("About us"))
                initInfo->aboutus.state = UImGui::UIMGUI_COMPONENT_STATE_RUNNING;
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }

}

void UntitledImageViewer::MainBar::end()
{
    endAutohandle();

}

UntitledImageViewer::MainBar::~MainBar()
{

}

