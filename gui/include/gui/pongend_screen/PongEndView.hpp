#ifndef PONGENDVIEW_HPP
#define PONGENDVIEW_HPP

#include <gui_generated/pongend_screen/PongEndViewBase.hpp>
#include <gui/pongend_screen/PongEndPresenter.hpp>

class PongEndView : public PongEndViewBase
{
public:
    PongEndView();
    virtual ~PongEndView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // PONGENDVIEW_HPP
