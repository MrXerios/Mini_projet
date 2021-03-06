#ifndef PONGPRESENTER_HPP
#define PONGPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class PongView;

class PongPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    PongPresenter(PongView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~PongPresenter() {};

    int16_t getBestScore()
    {
        return model->getBestScore();
    }

private:
    PongPresenter();

    PongView& view;
};

#endif // PONGPRESENTER_HPP
