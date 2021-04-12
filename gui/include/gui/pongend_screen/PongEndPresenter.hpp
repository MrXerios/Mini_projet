#ifndef PONGENDPRESENTER_HPP
#define PONGENDPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class PongEndView;

class PongEndPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    PongEndPresenter(PongEndView& v);

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

    virtual ~PongEndPresenter() {};

    int16_t getScore()
    {
        return model->getScore();
    }

    int16_t getBestScore()
    {
        return model->getBestScore();
    }

private:
    PongEndPresenter();

    PongEndView& view;
};

#endif // PONGENDPRESENTER_HPP
