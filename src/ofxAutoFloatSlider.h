#ifndef ofxAutoFloatSlider_h
#define ofxAutoFloatSlider_h

#include "ofMain.h"
#include "ofxGui.h"

class ofxAutoFloatSlider : public ofxFloatSlider {
public:
    
    enum updateMode{
        FORWARD = 1,
        STOP = 0,
        BACK = -1,
    };
    
    float speed = 1;
    updateMode mode = STOP;
    bool bUpdateAuto = true;
    
    ofxAutoFloatSlider() {
        setFillColor(ofColor(80, 80, 180));
        setUpdateAuto(true);
    }
    
    ~ofxAutoFloatSlider() {
        removeEventHooks();
    }
    
    void setUpdateAuto(bool _auto) {
        if (_auto) {
            addEventHooks();
            bUpdateAuto = true;
        } else {
            removeEventHooks();
            bUpdateAuto = false;
        }
    }
    
    void setSpeed(float _speed) {
        speed = _speed;
    }
    
    void reset() {
        value = getMin();
        mode = STOP;
    }
    
    void addEventHooks(ofCoreEvents* eventHooks = nullptr) {
        if ( eventHooks == nullptr ){
            eventHooks = &ofEvents();
        }else{
            removeEventHooks(&ofEvents());
        }
        ofAddListener(eventHooks->update, this, &ofxAutoFloatSlider::updateAuto, OF_EVENT_ORDER_BEFORE_APP-10);
    }
    
    void removeEventHooks(ofCoreEvents* eventHooks = nullptr) {
        if ( eventHooks == nullptr ){
            eventHooks = &ofEvents();
        }
        ofRemoveListener(eventHooks->update, this, &ofxAutoFloatSlider::updateAuto, OF_EVENT_ORDER_BEFORE_APP-10);
    }
    
    void update(float dt) {
        if ( mode == STOP ) return;
        
        float sign = glm::sign(getMax() - getMin());
        
        value += dt * speed * sign * mode;
        
        if (sign > 0) {
            if (value < getMin()){
                value = getMin();
                mode = STOP;
            } else if (getMax() < value) {
                value = getMax();
                mode = STOP;
            }
        }else {
            if (value > getMin()){
                value = getMin();
                mode = STOP;
            } else if (getMax() > value) {
                value = getMax();
                mode = STOP;
            }
        }
    }
    
    void updateAuto(ofEventArgs &d) {
        if (bUpdateAuto) {
            this->update(ofGetLastFrameTime());
        }
    }
    
    float getRate() {
        float dinominater = std::abs(getMax() - getMin());
        if (dinominater < FLT_MIN) {
            return 0.f;
        } else {
            return std::abs(value - getMin()) / dinominater;
        }
    }
    
    void swicth_FORWARD_STOP() {
        if (mode == FORWARD) {
            mode = STOP;
        } else if (mode == STOP) {
            mode = FORWARD;
        } else {
            mode = STOP;
        }
    }
    
    void swicth_BACK_STOP() {
        if (mode == BACK) {
            mode = STOP;
        } else if (mode == STOP) {
            mode = BACK;
        } else {
            mode = STOP;
        }
    }
    
    bool mousePressed(ofMouseEventArgs & mouse) override{
        if(state==Slider){
            if(mouse.button == OF_MOUSE_BUTTON_RIGHT){
                if(b.inside(mouse)){
                    swicth_FORWARD_STOP();
                    return true;
                }else{
                    return false;
                }
            }else{
                if(bUpdateOnReleaseOnly){
                    value.disableEvents();
                }
                if(setValue(mouse.x, mouse.y, true)){
                    mode = STOP;
                    return true;
                }else{
                    return false;
                }
            }
        }else{
            return isGuiDrawing() && input.mousePressed(mouse);
        }
    }
    
protected:
    
};

#endif /* ofxAutoFloatSlider_h */
