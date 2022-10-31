#include "ImageView.hpp"

UntitledImageViewer::ImageView::ImageView()
{

}

void UntitledImageViewer::ImageView::begin()
{
    beginAutohandle();

}

void UntitledImageViewer::ImageView::tick(float deltaTime)
{
    tickAutohandle(deltaTime);

}

void UntitledImageViewer::ImageView::end()
{
    endAutohandle();

}

UntitledImageViewer::ImageView::~ImageView()
{

}

