#ifndef HCPWIDGET_HPP
#define HCPWIDGET_HPP

#include <glm/glm.hpp>
#include <string>
#include <stack>

class HCPWidget
{
public:
    enum Type
    {
        WIDGET,
        BUTTON,
        VIEWPORT,
        WINDOW
    };

    static int getCurrentZLevel();
    static void setCurrentZLevel(int zLevel);

    HCPWidget();
    HCPWidget(const HCPWidget& copy) = delete;
    virtual ~HCPWidget();

    bool isHovered() const;
    bool isVisible() const;
    bool isEnabled() const;
    bool isOnCurrentZLevel() const;
    bool isHeld() const;
    bool isPressed() const;
    bool isReleased() const;

    void setEnabled(bool enabled);
    void setVisible(bool visible);
    void setZLevel(int zLevel);
    void setText(const char* text);

    Type getType() const;
    int getZLevel() const;
    const char* getText() const;

    float localCursorX() const;
    float localCursorY() const;

    void draw();

    float x, y, width, height;
protected:
    // Clipping (with viewports)
    struct ClippingState
    {
        glm::mat4 modelView;
        float left, right, top, bottom;
        bool clipping = false;
    };
    static std::stack<ClippingState> m_clippingStack;

    glm::mat4 m_modelView;

    // Other Types of Widgets Overrides this
    virtual void doDraw();
    Type m_type;
private:
    bool m_hovered;
    bool m_visible;
    bool m_enabled;
    int m_zLevel;

    glm::vec2 m_localCursor;

    bool m_justPressed;
    bool m_pressed;
    bool m_justReleased;
    std::string m_text;

    void updateHoverState();
};

#endif // HCPWIDGET_HPP