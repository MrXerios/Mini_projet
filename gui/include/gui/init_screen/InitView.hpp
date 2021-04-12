#ifndef INITVIEW_HPP
#define INITVIEW_HPP

#include <gui_generated/init_screen/InitViewBase.hpp>
#include <gui/init_screen/InitPresenter.hpp>

class InitView : public InitViewBase
{
public:
    InitView();
    virtual ~InitView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INITVIEW_HPP
