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

    static void advanced(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float rateEasing, float rateTime, Phase phase)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out);
    static void advanced(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float rateEasing, Phase phase)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out);
    static void advanced(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float rateEasing, float rateTime, Phase phase)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out
    );
    static void advanced(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float rateEasing, Phase phase)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out
    );

    static void alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float alpha)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out);
    static void alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float alpha, float rateEasing)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out);
    static void alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float alpha, float rateEasing, float rateTime)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear,ofxeasing::Type easing_type = ofxeasing::Type::Out);
    static void alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float alpha)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out);
    static void alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float alpha, float rateEasing)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out);
    static void alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float alpha, float rateEasing, float rateTime)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out);

    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, float fadeout_sec, T delta, std::function<void(T)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out)
    {
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            draw_fn(r * delta);
        }, easing_func, easing_type);
    }

    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, float fadeout_sec, T delta, std::function<void(T, float alpha)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out)
    {
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            draw_fn(r * delta, r * 255.0f);
        }, easing_func, easing_type);

    }

    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, float fadeout_sec, T delta,
        std::function<void(T, float alpha, float rateEasing)> draw_fn, ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out)
    {
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            draw_fn(r * delta, r * 255.0f, r);
        }, easing_func, easing_type);
    }

    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, float fadeout_sec, T delta, std::function<void(T, float alpha, float rateEasing, float rateTime)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out)
    {
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, float rt, Phase phase){
            draw_fn(r * delta, r * 255.0f, r, rt);
        }, easing_func, easing_type);
    }

    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, float fadeout_sec, T delta, std::function<void(T)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out)
    {
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            draw_fn(r * delta);
        }, easing_func_in, easing_type_in, easing_func_out, easing_type_out);
    }

    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, float fadeout_sec, T delta, std::function<void(T, float alpha)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out)
    {
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            draw_fn(r * delta, r * 255.0f);
        }, easing_func_in, easing_type_in, easing_func_out, easing_type_out);
    }

    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, float fadeout_sec, T delta, std::function<void(T, float alpha, float rateEasing)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out)
    {
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            draw_fn(r * delta, r * 255.0f, r);
        }, easing_func_in, easing_type_in, easing_func_out, easing_type_out);
    }

    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, float fadeout_sec, T delta, std::function<void(T, float alpha, float rateEasing, float rateTime)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out)
    {
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, float rt, Phase phase){
            draw_fn(r * delta, r * 255.0f, r, rt);
        }, easing_func_in, easing_type_in, easing_func_out, easing_type_out);
    }

    static std::string phaseToString(Phase phase);

protected:
};
