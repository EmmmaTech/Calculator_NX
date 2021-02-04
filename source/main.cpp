// Include libraries for the calculator program
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <vector>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include "calculator.hpp"

// Include additional libraries for the Switch program
#include <switch.h>
#include <borealis.hpp>

struct MainActivity : public brls::Activity {
    CONTENT_FROM_XML_RES("activity/main.xml");
};

struct RecyclingListTab : public brls::Box {
    RecyclingListTab(){
        this->inflateFromXMLRes("xml/tabs/recycling_list.xml");
    }

    static brls::View* create(){
        return new RecyclingListTab();
    }
};

struct ComponentsTab : public brls::Box {
    ComponentsTab(){
        this->inflateFromXMLRes("xml/tabs/components.xml");

        BRLS_REGISTER_CLICK_BY_ID("button_primary", this->onPrimaryButtonClicked);

        brls::Button* highlightButton = (brls::Button*)this->getView("button_highlight");
        highlightButton->registerAction(
        "Honk", brls::BUTTON_A, [](brls::View* view) { return true; }, false, brls::SOUND_HONK);
    }

    static brls::View* create(){
        return new ComponentsTab();
    }

    private:
    bool onPrimaryButtonClicked(brls::View* view){
        brls::Logger::info("Clicked");
        return true;
    }
};

struct CaptionedImage : public brls::Box {
    CaptionedImage() {
        this->inflateFromXMLRes("xml/views/captioned_image.xml");

        this->image = (brls::Image*)this->getView("image");
        this->label = (brls::Label*)this->getView("label");

        this->label->hide([] {});

        this->forwardXMLAttribute("scalingType", this->image);
        this->forwardXMLAttribute("image", this->image);
        this->forwardXMLAttribute("focusUp", this->image);
        this->forwardXMLAttribute("focusRight", this->image);
        this->forwardXMLAttribute("focusDown", this->image);
        this->forwardXMLAttribute("focusLeft", this->image);
        this->forwardXMLAttribute("imageWidth", this->image, "width");
        this->forwardXMLAttribute("imageHeight", this->image, "height");

        this->forwardXMLAttribute("caption", this->label, "text");
    }
 
    void onChildFocusGained(brls::View* directChild, brls::View* focusedView) override {
        Box::onChildFocusGained(directChild, focusedView);

        this->label->show([] {});
    }
    void onChildFocusLost(brls::View* directChild, brls::View* focusedView) override {
        Box::onChildFocusLost(directChild, focusedView);

        this->label->hide([] {});
    }

    static brls::View* create() {
        return new CaptionedImage();
    }

    private:
    brls::Image* image;
    brls::Label* label;
};

int main(int argc, char* argv[]) {
    std::vector<int> StoredInts{};
    MathCalculator calculator{StoredInts};
    std::string operation{};
    std::string App_Version = "v1.3.0 Developer GUI";

    brls::Application::registerXMLView("CaptionedImage", CaptionedImage::create);
    brls::Application::registerXMLView("RecyclingListTab", RecyclingListTab::create);
    brls::Application::registerXMLView("ComponentsTab", ComponentsTab::create);

    brls::Logger::setLogLevel(brls::LogLevel::DEBUG);

    if (!brls::Application::init("Calculator_NX " + App_Version)) {
        brls::Logger::error("Unable to init the Cakculator_NX gui. Please report this to EmreTech");
        return EXIT_FAILURE;
    }

    brls::Application::pushActivity(new MainActivity());

    while (brls::Application::mainLoop());

    return EXIT_SUCCESS;
}
