#pragma once
#include <Framework.hpp>

namespace UntitledImageViewer
{
    class UIMGUI_PUBLIC_API ApplicationSettings : public UImGui::WindowComponent
    {
    public:
        ApplicationSettings();
        virtual void begin() override;
        virtual void tick(float deltaTime) override;
        virtual void end() override;
        virtual ~ApplicationSettings() override;
    private:

    };
}

