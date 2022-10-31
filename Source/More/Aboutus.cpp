#include "Aboutus.hpp"

UntitledImageViewer::Aboutus::Aboutus()
{
    state = UImGui::UIMGUI_COMPONENT_STATE_PAUSED;
}

void UntitledImageViewer::Aboutus::begin()
{
    beginAutohandle();
    static bool bFirst = true;
    if (bFirst)
    {
        logo.init("../Content/madladsquadlogo.png");
        logo.loadImGui();
        bFirst = false;
    }
}

void UntitledImageViewer::Aboutus::tick(float deltaTime)
{
    tickAutohandle(deltaTime);
    //static bool bShow = false;
    static bool bShow = state;
    bShow = state;
    if (!ImGui::IsPopupOpen("About us"))
        ImGui::OpenPopup("About us");
    if (ImGui::BeginPopupModal("About us", &bShow))
    {
        ImGui::TextWrapped("UntitledImageViewer, version: v1.0.0.0");
        ImGui::Separator();
        ImGui::TextWrapped("The UntitledImageViewer is brought to you by MadLad Squad");
        ImGui::TextWrapped("Project created and maintained by Stanislav Vasilev (Madman10K)");
        ImGui::Image((void*)(intptr_t)logo.get(), ImVec2(50.0f, 50.0f));

        if (ImGui::Button("Close##AboutUS"))
            bShow = false;
        ImGui::EndPopup();
    }
    state = (UImGui::ComponentState)bShow;
}

void UntitledImageViewer::Aboutus::end()
{
    endAutohandle();
}

UntitledImageViewer::Aboutus::~Aboutus()
{
    logo.clear();
}

