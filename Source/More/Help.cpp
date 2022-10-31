#include "Help.hpp"

UntitledImageViewer::Help::Help()
{
    state = UImGui::UIMGUI_COMPONENT_STATE_PAUSED;
}

void UntitledImageViewer::Help::begin()
{
    beginAutohandle();

}

void UntitledImageViewer::Help::tick(float deltaTime)
{
    tickAutohandle(deltaTime);
    static bool bShow = state;
    bShow = state;

    if (!ImGui::IsPopupOpen("Help"))
        ImGui::OpenPopup("Help");
    if (ImGui::BeginPopupModal("Help", &bShow))
    {
        constexpr char* link1 = (char*)"https://github.com/MadLadSquad/UntitledImageViewer";
        constexpr char* link2 = (char*)"https://github.com/MadLadSquad/UntitledImageViewer/wiki";
        constexpr char* link3 = (char*)"https://discord.gg/4wgH8ZE";

        ImGui::Text("Github Repo: ");
        ImGui::InputText("##in", link1, strlen(link1), ImGuiInputTextFlags_ReadOnly);

        ImGui::Text("Documentation: ");
        ImGui::InputText("##i", link2, strlen(link2), ImGuiInputTextFlags_ReadOnly);

        ImGui::Text("Discord Server: ");
        ImGui::InputText("##id", link3, strlen(link3),  ImGuiInputTextFlags_ReadOnly);

        if (ImGui::Button("Close##Help"))
            bShow = false;
        ImGui::EndPopup();
    }
    state = (UImGui::ComponentState)bShow;
}

void UntitledImageViewer::Help::end()
{
    endAutohandle();

}

UntitledImageViewer::Help::~Help()
{

}

