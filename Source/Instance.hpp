#pragma once
#include <Framework.hpp>
#include "MainBar.hpp"
#include "More/Aboutus.hpp"
#include "More/Help.hpp"

namespace UntitledImageViewer
{
    class UIMGUI_PUBLIC_API Instance : public UImGui::Instance
    {
    public:
        Instance();
        virtual void begin() override;
        virtual void tick(float deltaTime) override;
        virtual void end() override;
        virtual ~Instance() override;

        virtual void onEventConfigureStyle(ImGuiStyle& style, ImGuiIO& io) override;
    private:
        friend class MainBar;

        MainBar mainBar;
        Aboutus aboutus;
        Help help;
    };
}

