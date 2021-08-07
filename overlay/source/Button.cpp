#include <Button.hpp>

namespace Element
{
    Button::Button(short w, short h, const std::string &buttonText, uint16_t size)
        : tsl::elm::Element(), text(buttonText), fontSize(size), set(false)
    {
        this->setBoundaries(this->getX(), this->getY(), w*2, h*2);
    }

    void Button::setCallback(ButtonCallback callback)
    {
        this->callback = callback;
    }

    void Button::runCallback()
    {
        if (this->callback)
            this->callback();
    }

    tsl::elm::Element *Button::requestFocus(tsl::elm::Element *old, tsl::FocusDirection direction)
    {
        return this;
    }

    void Button::draw(tsl::gfx::Renderer *renderer)
    {
        std::pair<u32, u32> dimensions = renderer->drawString(this->text.c_str(), false, 0, 0, this->fontSize, 0x0);
        if (!this->set)
        {
            this->setBoundaries(this->getX(), this->getY(), this->getWidth() + dimensions.first, this->getHeight() + dimensions.second);
            this->set = true;
        }

        renderer->drawString(this->text.c_str(), false, this->getX() + (this->getWidth() - dimensions.first)/2, this->getY() + (this->getHeight() + dimensions.second)/2, this->fontSize, tsl::style::color::ColorText);
    }

    void Button::layout(u16 px, u16 py, u16 pw, u16 ph) {}

    bool Button::onClick(u64 keyPressed)
    {
        if (keyPressed & HidNpadButton_A)
        {
            this->runCallback();
            return true;
        }
        return false;
    }
} // namespace Element
