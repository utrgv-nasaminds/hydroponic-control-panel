#ifndef HCP_ANIMATION_HPP
#define HCP_ANIMATION_HPP

class HCPSmoother
{
public:
    HCPSmoother();

    void grab();
    void grab(double grabTo);
    void setValueAndGrab(double value);

    void release();

    bool isGrabbed() const;
    bool isSpringy() const;

    void setSpringy(bool springy);
    void setSpeed(double speed);
    void setFriction(double friciton);
    void setValue(double value);

    double getSpeed() const;
    double getFriction() const;
    double grabbingTo() const;
    double getValue();
    float getValuef();
private:
    double m_acceleration;
    double m_velocity;
    double m_previousTime;
    double m_currentTime;

    bool m_grabbed;
    double m_grabbingTo;
    double m_value;

    bool m_springy;
    double m_speed;
    double m_friction;

    void update();
};

class HCPTimer
{

public:
    HCPTimer(double tps);

    int ticksPassed();
    double getTPS();
    double partialTicks();
    double lerp(double start, double end);
private:
    double m_tps;
    double m_tickDelta;
    double m_nextTick;
};

#endif // HCP_ANIMATION_HPP