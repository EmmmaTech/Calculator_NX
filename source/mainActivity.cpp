#include <mainActivity.hpp>

#include <calculatorTab.hpp>
#include <aboutTab.hpp>
#include <updaterTab.hpp>

using namespace brls::literals;

brls::View* MainActivity::createContentView()
{
    brls::TabFrame *frame = new brls::TabFrame();
    frame->setTitle("text/title"_i18n);
    frame->setIconFromRes("icon/Calculator_NX_Icon_Alt.jpg");
    frame->setFooter(brls::getStr("text/footer_text", VERSION_NUM, STABLE));

    frame->addTab("text/tabs/calculator"_i18n, CalculatorTab::create);
    frame->addTab("text/tabs/about"_i18n, AboutTab::create);
    frame->addSeparator();
    frame->addTab("text/tabs/updater"_i18n, UpdaterTab::create);

    return frame;
}