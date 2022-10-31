#pragma once
#include <Framework.hpp>

namespace UntitledImageViewer
{
    class UIMGUI_PUBLIC_API Aboutus : public UImGui::WindowComponent
    {
    public:
        Aboutus();
        virtual void begin() override;
        virtual void tick(float deltaTime) override;
        virtual void end() override;
        virtual ~Aboutus() override;
    private:
        UImGui::Texture logo;
    };
}

