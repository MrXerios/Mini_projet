#include <gui/pong_screen/PongView.hpp>

PongView::PongView()
{

}

void PongView::setupScreen()
{
    PongViewBase::setupScreen();
    Unicode::snprintf(areaHigh_1Buffer,AREAHIGH_1_SIZE, "%d", presenter->getBestScore());
    areaHigh_1.invalidate();
}

void PongView::tearDownScreen()
{
    PongViewBase::tearDownScreen();
}
