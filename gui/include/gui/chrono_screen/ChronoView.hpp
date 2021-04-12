#ifndef CHRONOVIEW_HPP
#define CHRONOVIEW_HPP

#include <gui_generated/chrono_screen/ChronoViewBase.hpp>
#include <gui/chrono_screen/ChronoPresenter.hpp>

class ChronoView : public ChronoViewBase
{
public:
    ChronoView();
    virtual ~ChronoView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void functionAddToMinute();
    virtual void functionSubToMinute();
    virtual void functionAddToSecond();
    virtual void functionSubToSecond();

    virtual void functionGo();
    virtual void functionStop();

    virtual void handleTickEvent();
protected:
    int minute = 0;
    int second = 0;

    int16_t tickCount = 0;
    bool chronoRunning = false;
};

#endif // CHRONOVIEW_HPP
