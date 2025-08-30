#pragma once

#include "ofMain.h"
#include "ofxEasing.h"

class ofxFade {
public:
    enum class Phase {
        FADEIN,
        STATIC,
        FADEOUT
    };

    /// Timer interface
    class Fader {
    public:
        virtual float getElapsedTime() = 0;
        virtual float getStaticSec() = 0;
        virtual float getFadeInSec() = 0;
        virtual float getFadeOutSec() = 0;

        bool isFinished(){
            return getElapsedTime() > getFadeInSec() + getStaticSec() + getFadeOutSec();
        }

        void advanced(std::function<void(float rateEasing, float rateTime, Phase phase)> draw_fn,
            ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out)
        {
            ofxFade::advanced(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func, easing_type
            );
        }
        void advanced(std::function<void(float rateEasing, Phase phase)> draw_fn,
            ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out)
        {
            ofxFade::advanced(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func, easing_type
            );
        }
        void advanced(std::function<void(float rateEasing, float rateTime, Phase phase)> draw_fn,
            ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
            ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out
        )
        {
            ofxFade::advanced(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func_in, easing_type_in,
                easing_func_out, easing_type_out
            );
        }
        void advanced(std::function<void(float rateEasing, Phase phase)> draw_fn,
            ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
            ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out
        )
        {
            ofxFade::advanced(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func_in, easing_type_in,
                easing_func_out, easing_type_out
            );
        }

        void alpha(std::function<void(float alpha)> draw_fn,
            ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out)
        {
            ofxFade::alpha(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func, easing_type
            );
        }
        void alpha(std::function<void(float alpha, float rateEasing)> draw_fn,
            ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out)
        {
            ofxFade::alpha(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func, easing_type
            );
        }
        void alpha(std::function<void(float alpha, float rateEasing, float rateTime, Phase phase)> draw_fn,
            ofxeasing::Function easing_func = ofxeasing::Function::Linear,ofxeasing::Type easing_type = ofxeasing::Type::Out)
        {
            ofxFade::alpha(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func, easing_type
            );
        }
        void alpha(std::function<void(float alpha)> draw_fn,
            ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
            ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out)
        {
            ofxFade::alpha(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func_in, easing_type_in,
                easing_func_out, easing_type_out
            );
        }
        void alpha(std::function<void(float alpha, float rateEasing)> draw_fn,
            ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
            ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out)
        {
            ofxFade::alpha(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func_in, easing_type_in,
                easing_func_out, easing_type_out
            );
        }
        void alpha(std::function<void(float alpha, float rateEasing, float rateTime, Phase phase)> draw_fn,
            ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
            ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out)
        {
            ofxFade::alpha(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func_in, easing_type_in,
                easing_func_out, easing_type_out
            );
        }

        template<typename T>
        void delta(T delta, std::function<void(T)> draw_fn,
            ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out)
        {
            ofxFade::delta(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), delta, draw_fn,
                easing_func, easing_type
            );
        }

        template<typename T>
        void delta(T delta, std::function<void(T, float alpha)> draw_fn,
            ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out)
        {
            ofxFade::delta(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), delta, draw_fn,
                easing_func, easing_type
            );
        }

        template<typename T>
        void delta(T delta,
            std::function<void(T, float alpha, float rateEasing)> draw_fn, ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out)
        {
            ofxFade::delta(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), delta, draw_fn,
                easing_func, easing_type
            );
        }

        template<typename T>
        void delta(T delta, std::function<void(T, float alpha, float rateEasing, float rateTime, Phase phase)> draw_fn,
            ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out)
        {
            ofxFade::delta(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), delta, draw_fn,
                easing_func, easing_type
            );
        }

        template<typename T>
        void delta(T delta, std::function<void(T)> draw_fn,
            ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
            ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out)
        {
            ofxFade::delta(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), delta, draw_fn,
                easing_func_in, easing_type_in,
                easing_func_out, easing_type_out
            );
        }

        template<typename T>
        void delta(T delta, std::function<void(T, float alpha)> draw_fn,
            ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
            ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out)
        {
            ofxFade::delta(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), delta, draw_fn,
                easing_func_in, easing_type_in,
                easing_func_out, easing_type_out
            );
        }

        template<typename T>
        void delta(T delta, std::function<void(T, float alpha, float rateEasing)> draw_fn,
            ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
            ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out)
        {
            ofxFade::delta(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), delta, draw_fn,
                easing_func_in, easing_type_in,
                easing_func_out, easing_type_out
            );
        }

        template<typename T>
        void delta(T delta, std::function<void(T, float alpha, float rateEasing, float rateTime, Phase phase)> draw_fn,
            ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
            ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out)
        {
            ofxFade::delta(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), delta, draw_fn,
                easing_func_in, easing_type_in,
                easing_func_out, easing_type_out
            );
        }
    };

    // Timer for non interactive
    class NonInteractiveFader : public Fader {
    public:
        NonInteractiveFader() {}
        NonInteractiveFader(float fadein_sec, float static_sec, float fadeout_sec) :
            fadein_sec(fadein_sec), static_sec(static_sec), fadeout_sec(fadeout_sec) {}

        float fadein_sec = 0.0f;
        float static_sec = 0.0f;
        float fadeout_sec = 0.0f;

        void start(){
            started_timef = ofGetElapsedTimef();
        }

        /// stop means reset
        void stop(){
            started_timef = -1.0f;
        }

        bool isStarted(){
            return started_timef > 0.0f;
        }

        bool isFadeInEnded(){
            return getElapsedTime() > getFadeInSec();
        }

        bool isFadeOutStarted(){
            return getElapsedTime() > getFadeInSec() + getStaticSec();
        }

        float getElapsedTime() override {
            if(started_timef > 0.0f){
                return ofGetElapsedTimef() - started_timef;
            }else{
                return 0.0f;
            }
        }

        float getStaticSec() override {
            return static_sec;
        }

        float getFadeInSec() override {
            return fadein_sec;
        }

        float getFadeOutSec() override {
            return fadeout_sec;
        }

    protected:
        float started_timef = -1.0f;
    };
    
    // Timer for interactive fadeout
    class InteractiveFader : public Fader {
    public: 
        InteractiveFader() {}
        InteractiveFader(float fadein_sec, float fadeout_sec) :
            fadein_sec(fadein_sec), fadeout_sec(fadeout_sec) {}

        float fadein_sec = 0.0f;
        float fadeout_sec = 0.0f;

        void fadeInStart(){
            started_timef = ofGetElapsedTimef();
            fadeout_started_timef = -1.0f;
        }

        void fadeOutStart(){
            if(started_timef < 0.0f){
                fadeInStart();
            }
            fadeout_started_timef = ofGetElapsedTimef();
        }

        /// alias of fadeInStart()
        void start(){
            fadeInStart();
        }

        /// alias of fadeOutStart(). If you want stop or reset, please call stop().
        void fadeOut(){
            fadeOutStart();
        }

        /// stop means reset
        void stop(){
            started_timef = -1.0f;
            fadeout_started_timef = -1.0f;
        }

        bool isStarted(){
            return started_timef > 0.0f;
        }

        bool isFadeInEnded(){
            return getElapsedTime() > getFadeInSec();
        }

        bool isFadeOutStarted(){
            return fadeout_started_timef > 0.0f;
        }

        float getElapsedTime() override {
            if(started_timef > 0.0f){
                return ofGetElapsedTimef() - started_timef;
            }else{
                return 0.0f;
            }
        }

        float getStaticSec() override {
            if(started_timef > 0.0f){
                if(fadeout_started_timef < 0.0f){
                    float dt = ofGetElapsedTimef() - started_timef - fadein_sec;
                    if(dt < 0.0){
                        return 0.0f;
                    }else{
                        return dt;
                    }
                }else{
                    float dt = fadeout_started_timef - started_timef - fadein_sec;
                    if(dt < 0.0){
                        return 0.0f;
                    }else{
                        return dt;
                    }
                }
            }else{
                return 0.0f;
            }
        }

        float getFadeInSec() override {
            return fadein_sec;
        }

        float getFadeOutSec() override {
            if(fadeout_started_timef < 0.0f){
                return -1.0f;
            }else{
                return fadeout_sec;
            }
        }

    protected:
        float started_timef = -1.0f;
        float fadeout_started_timef = -1.0f;
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
    static void alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float alpha, float rateEasing, float rateTime, Phase phase)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear,ofxeasing::Type easing_type = ofxeasing::Type::Out);
    static void alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float alpha)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out);
    static void alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float alpha, float rateEasing)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out);
    static void alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float alpha, float rateEasing, float rateTime, Phase phase)> draw_fn,
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
    static void delta(float t, float fadein_sec, float static_sec, float fadeout_sec, T delta, std::function<void(T, float alpha, float rateEasing, float rateTime, Phase phase)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out)
    {
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, float rt, Phase phase){
            draw_fn(r * delta, r * 255.0f, r, rt, phase);
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
    static void delta(float t, float fadein_sec, float static_sec, float fadeout_sec, T delta, std::function<void(T, float alpha, float rateEasing, float rateTime, Phase phase)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out)
    {
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, float rt, Phase phase){
            draw_fn(r * delta, r * 255.0f, r, rt, phase);
        }, easing_func_in, easing_type_in, easing_func_out, easing_type_out);
    }

    static std::string phaseToString(Phase phase);

protected:
};
