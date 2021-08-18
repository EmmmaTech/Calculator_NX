#define TESLA_INIT_IMPL
#include <tesla.hpp>

#include <CalculatorElement.hpp>

struct MainGui : public tsl::Gui
{
    MainGui(){}

    virtual tsl::elm::Element *createUI() override
    {
        auto *frame = new tsl::elm::OverlayFrame(APP_TITLE, "v"s + VERSION_NUM + " | "s + STABLE);
        frame->setContent(new Element::CalculatorElement());
        return frame;
    }
};

struct MainOverlay : public tsl::Overlay
{
    virtual void initServices() override {}
    virtual void exitServices() override {}

    virtual void onShow() override {}
    virtual void onHide() override {}

    virtual std::unique_ptr<tsl::Gui> loadInitialGui() override
    {
        return initially<MainGui>();
    }
};

int main(int argc, char **argv)
{
    return tsl::loop<MainOverlay>(argc, argv);
}