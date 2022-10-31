#include "KeybindingsSettings.hpp"

UntitledImageViewer::KeybindingsSettings::KeybindingsSettings()
{

}

void UntitledImageViewer::KeybindingsSettings::begin()
{
    beginAutohandle();

}

void UntitledImageViewer::KeybindingsSettings::tick(float deltaTime)
{
    tickAutohandle(deltaTime);

}

void UntitledImageViewer::KeybindingsSettings::end()
{
    endAutohandle();

}

UntitledImageViewer::KeybindingsSettings::~KeybindingsSettings()
{

}

