#ifndef PONGVIEW_HPP
#define PONGVIEW_HPP

#include <gui_generated/pong_screen/PongViewBase.hpp>
#include <gui/pong_screen/PongPresenter.hpp>

class PongView : public PongViewBase
{
public:
    PongView();
    virtual ~PongView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // PONGVIEW_HPP
