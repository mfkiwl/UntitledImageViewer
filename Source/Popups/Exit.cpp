#include "Exit.hpp"

UntitledImageViewer::Exit::Exit()
{

}

void UntitledImageViewer::Exit::begin()
{
    beginAutohandle();

}

void UntitledImageViewer::Exit::tick(float deltaTime)
{
    tickAutohandle(deltaTime);

}

void UntitledImageViewer::Exit::end()
{
    endAutohandle();

}

UntitledImageViewer::Exit::~Exit()
{

}

