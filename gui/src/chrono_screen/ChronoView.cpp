#include <gui/chrono_screen/ChronoView.hpp>

ChronoView::ChronoView()
{

}

void ChronoView::setupScreen()
{
    ChronoViewBase::setupScreen();
}

void ChronoView::tearDownScreen()
{
    ChronoViewBase::tearDownScreen();
}


void ChronoView::functionAddToMinute()
{
    minute++;
    if (minute >= 100)
        minute = 0;
    Unicode::snprintf(textTimeBuffer1,TEXTTIMEBUFFER1_SIZE, "%02d", minute);
    textTime.invalidate();
}

void ChronoView::functionSubToMinute()
{
    minute--;
    if (minute < 0)
        minute = 99;
    Unicode::snprintf(textTimeBuffer1,TEXTTIMEBUFFER1_SIZE, "%02d", minute);
    textTime.invalidate();
}

void ChronoView::functionAddToSecond()
{
    second++;
    if (second >= 60)
    {
        second = 0;
        functionAddToMinute();
    }
    Unicode::snprintf(textTimeBuffer2,TEXTTIMEBUFFER2_SIZE, "%02d", second);
    textTime.invalidate();
}

void ChronoView::functionSubToSecond()
{
    second--;
    if (second < 0)
    {
        second = 59;
        functionSubToMinute();
    }
    Unicode::snprintf(textTimeBuffer2,TEXTTIMEBUFFER2_SIZE, "%02d", second);
    textTime.invalidate();
}

void ChronoView::functionGo()
{
    buttonUpMinute.setTouchable(false);
    buttonUpSecond.setTouchable(false);
    buttonDownMinute.setTouchable(false);
    buttonDownSecond.setTouchable(false);
    buttonGo.setTouchable(false);

    chronoRunning = true;
    tickCount = 0;
}

void ChronoView::handleTickEvent()
{
    if (chronoRunning)
    {
        if((!second) & (!minute))
        {
            chronoRunning = false;

            buttonUpMinute.setTouchable(true);
            buttonUpSecond.setTouchable(true);
            buttonDownMinute.setTouchable(true);
            buttonDownSecond.setTouchable(true);
            buttonGo.setTouchable(true);

            buttonGo.setVisible(true);
            buttonStop.setVisible(false);
            buttonGo.invalidate();
            buttonStop.invalidate();
        }
        tickCount++;
        if (tickCount >= 60)
        {
            functionSubToSecond();
            tickCount = 0;
        }
    }
}

void ChronoView::functionStop()
{
    chronoRunning = false;

    buttonUpMinute.setTouchable(true);
    buttonUpSecond.setTouchable(true);
    buttonDownMinute.setTouchable(true);
    buttonDownSecond.setTouchable(true);
    buttonGo.setTouchable(true);
}
