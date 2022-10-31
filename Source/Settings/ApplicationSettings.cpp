#include "ApplicationSettings.hpp"

UntitledImageViewer::ApplicationSettings::ApplicationSettings()
{

}

void UntitledImageViewer::ApplicationSettings::begin()
{
    beginAutohandle();

}

void UntitledImageViewer::ApplicationSettings::tick(float deltaTime)
{
    tickAutohandle(deltaTime);

}

void UntitledImageViewer::ApplicationSettings::end()
{
    endAutohandle();

}

UntitledImageViewer::ApplicationSettings::~ApplicationSettings()
{

}

