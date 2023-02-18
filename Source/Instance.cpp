#include "Instance.hpp"

UntitledImageViewer::Instance::Instance()
{
    initInfo =
    {
        .titlebarComponents = { &mainBar },
        .windowComponents = { &help, &aboutus, &exitWidget },
        .globalData = (void*)this
    };
}

void UntitledImageViewer::Instance::begin()
{
    beginAutohandle();

}

void UntitledImageViewer::Instance::tick(float deltaTime)
{
    tickAutohandle(deltaTime);
}

void UntitledImageViewer::Instance::end()
{
    endAutohandle();

}

UntitledImageViewer::Instance::~Instance()
{

}

void UntitledImageViewer::Instance::onEventConfigureStyle(ImGuiStyle& style, ImGuiIO& io)
{

}

