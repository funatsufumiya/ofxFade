#pragma once

#include "ofMain.h"

class ofxFadeHelper {
public:
    enum class Phase {
        FADEIN,
        STATIC,
        FADEOUT
    };

    static void simple(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float r, Phase phase)> draw_fn);
    static void alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float)> draw_fn);
    static void alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float, float)> draw_fn);
    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, float fadeout_sec, T delta, std::function<void(T)> draw_fn){
        simple(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            if(phase == Phase::FADEIN){
                draw_fn(r * delta);
            }else if(phase == Phase::STATIC){
                draw_fn(1.0f * delta);
            }else if(phase == Phase::FADEOUT){
                draw_fn((1.0f - r) * delta);
            }
        });
    }
    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, float fadeout_sec, T delta, std::function<void(T, float)> draw_fn){
        simple(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            if(phase == Phase::FADEIN){
                draw_fn(r * delta, r * 255.0f);
            }else if(phase == Phase::STATIC){
                draw_fn(1.0f * delta, 255.0f);
            }else if(phase == Phase::FADEOUT){
                draw_fn((1.0f - r) * delta, (1.0f - r) * 255.0f);
            }
        });

    }
    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, float fadeout_sec, T delta, std::function<void(T, float, float)> draw_fn){
        simple(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            if(phase == Phase::FADEIN){
                draw_fn(r * delta, r * 255.0f, r);
            }else if(phase == Phase::STATIC){
                draw_fn(1.0f * delta, 255.0f, r);
            }else if(phase == Phase::FADEOUT){
                draw_fn((1.0f - r) * delta, (1.0f - r) * 255.0f, r);
            }
        });
    }
    static std::string phaseToString(Phase phase);

protected:
};
