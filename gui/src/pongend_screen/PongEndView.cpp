#include <gui/pongend_screen/PongEndView.hpp>

PongEndView::PongEndView()
{

}

void PongEndView::setupScreen()
{
    PongEndViewBase::setupScreen();
    Unicode::snprintf(areaScoreBuffer,AREASCORE_SIZE, "%d", presenter->getScore());
    areaScore.invalidate();
    Unicode::snprintf(areaHighBuffer,AREAHIGH_SIZE, "%d", presenter->getBestScore());
    areaHigh.invalidate();
}

void PongEndView::tearDownScreen()
{
    PongEndViewBase::tearDownScreen();
}
