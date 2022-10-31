#pragma once
#include <Framework.hpp>

namespace UntitledImageViewer
{
    class UIMGUI_PUBLIC_API SaveAs : public UImGui::WindowComponent
    {
    public:
        SaveAs();
        virtual void begin() override;
        virtual void tick(float deltaTime) override;
        virtual void end() override;
        virtual ~SaveAs() override;
    private:

    };
}

