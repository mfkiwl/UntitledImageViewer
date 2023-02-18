#include "Exit.hpp"

UntitledImageViewer::Exit::Exit()
{
    state = UImGui::UIMGUI_COMPONENT_STATE_PAUSED;
}

void UntitledImageViewer::Exit::begin()
{
    beginAutohandle();

}

void UntitledImageViewer::Exit::tick(float deltaTime)
{
    tickAutohandle(deltaTime);
    static bool bShow = state;
    bShow = state;

    if (!ImGui::IsPopupOpen("Exit"))
        ImGui::OpenPopup("Exit");
    if (ImGui::BeginPopupModal("Exit", &bShow))
    {

        ImGui::TextWrapped("Are you sure you want to close the application, any data that has not been saved WILL be discarded!");
        if (ImGui::Button("Exit"))
            UImGui::Instance::shutdown();

        ImGui::SameLine();

        if (ImGui::Button("Cancel"))
            bShow = false;
        ImGui::EndPopup();
    }
    state = (UImGui::ComponentState)bShow;
}

void UntitledImageViewer::Exit::end()
{
    endAutohandle();

}

UntitledImageViewer::Exit::~Exit()
{

}

