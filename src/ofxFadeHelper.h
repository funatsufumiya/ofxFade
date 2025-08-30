#pragma once

#include "ofMain.h"
#include "ofxEasing.h"

class ofxFadeHelper {
public:
    enum class Phase {
        FADEIN,
        STATIC,
        FADEOUT
    };

    static void advanced(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float rateEasing, float rate, Phase phase)> draw_fn, ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out);
    static void advanced(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float rateEasing, Phase phase)> draw_fn, ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out);
    static void alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float)> draw_fn, ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out);
    static void alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float, float)> draw_fn, ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out);
    static void alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float, float, float)> draw_fn, ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out);
    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, float fadeout_sec, T delta, std::function<void(T)> draw_fn, ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out){
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            if(phase == Phase::FADEIN){
                draw_fn(r * delta);
            }else if(phase == Phase::STATIC){
                draw_fn(1.0f * delta);
            }else if(phase == Phase::FADEOUT){
                draw_fn(r * delta);
            }
        }, easing_func, easing_type);
    }
    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, float fadeout_sec, T delta, std::function<void(T, float)> draw_fn, ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out){
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            if(phase == Phase::FADEIN){
                draw_fn(r * delta, r * 255.0f);
            }else if(phase == Phase::STATIC){
                draw_fn(1.0f * delta, 255.0f);
            }else if(phase == Phase::FADEOUT){
                draw_fn(r * delta, r * 255.0f);
            }
        }, easing_func, easing_type);

    }
    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, float fadeout_sec, T delta, std::function<void(T, float, float)> draw_fn, ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out){
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            if(phase == Phase::FADEIN){
                draw_fn(r * delta, r * 255.0f, r);
            }else if(phase == Phase::STATIC){
                draw_fn(1.0f * delta, 255.0f, 1.0f);
            }else if(phase == Phase::FADEOUT){
                draw_fn(r * delta, r * 255.0f, r);
            }
        }, easing_func, easing_type);
    }
    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, float fadeout_sec, T delta, std::function<void(T, float, float, float)> draw_fn, ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out){
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, float r_orig, Phase phase){
            if(phase == Phase::FADEIN){
                draw_fn(r * delta, r * 255.0f, r, r_orig);
            }else if(phase == Phase::STATIC){
                draw_fn(1.0f * delta, 255.0f, 1.0f, 1.0f);
            }else if(phase == Phase::FADEOUT){
                draw_fn(r * delta, r * 255.0f, r, (1.0f - r_orig));
            }
        }, easing_func, easing_type);
    }
    static std::string phaseToString(Phase phase);

protected:
};
