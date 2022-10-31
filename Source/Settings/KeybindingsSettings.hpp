#pragma once
#include <Framework.hpp>

namespace UntitledImageViewer
{
    class UIMGUI_PUBLIC_API KeybindingsSettings : public UImGui::WindowComponent
    {
    public:
        KeybindingsSettings();
        virtual void begin() override;
        virtual void tick(float deltaTime) override;
        virtual void end() override;
        virtual ~KeybindingsSettings() override;
    private:

    };
}

