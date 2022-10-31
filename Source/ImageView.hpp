#pragma once
#include <Framework.hpp>

namespace UntitledImageViewer
{
    class UIMGUI_PUBLIC_API ImageView : public UImGui::WindowComponent
    {
    public:
        ImageView();
        virtual void begin() override;
        virtual void tick(float deltaTime) override;
        virtual void end() override;
        virtual ~ImageView() override;
    private:

    };
}

