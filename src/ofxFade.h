#pragma once

#include "ofMain.h"
#include "ofxEasing.h"

namespace fade_opt {
    struct nullopt_t {};
    static const nullopt_t nullopt = nullopt_t();

    template<typename T>
    class optional {
    public:
        optional() : has_value_(false) {}
        optional(const T& value) : value_(value), has_value_(true) {}
        optional(nullopt_t) : has_value_(false) {}

        void reset() { has_value_ = false; }
        void set(const T& value) { value_ = value; has_value_ = true; }
        bool has_value() const { return has_value_; }
        T& value() { return value_; }
        const T& value() const { return value_; }
        explicit operator bool() const { return has_value_; }

    private:
        T value_;
        bool has_value_;
    };
} // namespace fade_opt

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
            started_timef.reset();
        }

        bool isStarted(){
            return started_timef.has_value();
        }

        bool isFadeInEnded(){
            return getElapsedTime() > getFadeInSec();
        }

        bool isFadeOutStarted(){
            return getElapsedTime() > getFadeInSec() + getStaticSec();
        }

        float getElapsedTime() override {
            if(started_timef.has_value()){
                return ofGetElapsedTimef() - started_timef.value();
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
        fade_opt::optional<float> started_timef = fade_opt::nullopt;
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
            fadeout_started_timef.reset();
        }

        /// @param immediate execute fade-out soon (keeping fade-in rate). if false, execute fade-out after fade-in.
        void fadeOutStart(bool immediate = true){
            if(started_timef.has_value() == false){
                fadeInStart();
            }
            fadeout_started_timef = ofGetElapsedTimef();

            if(immediate){
                if(!isFadeInEnded()){
                    // NOTE: apply incomplete fade_in rate for fade_out
                    float diff_in = getFadeInSec() - getElapsedTime();
                    float diff_in_rate = diff_in / getFadeInSec();
                    float diff_out = diff_in_rate * getFadeOutSec();
                    started_timef.set(started_timef.value() - (diff_in + diff_out));
                    fadeout_started_timef.set(fadeout_started_timef.value() -= (diff_in + diff_out));
                }
            }
        }

        /// @brief alias of fadeInStart()
        void start(){
            fadeInStart();
        }

        /// @brief alias of fadeOutStart().
        /// @param immediate execute fade-out soon (keeping fade-in rate). if false, execute fade-out after fade-in.
        void fadeOut(bool immediate = true){
            fadeOutStart(immediate);
        }

        /// stop means reset
        void stop(){
            started_timef.reset();
            fadeout_started_timef.reset();
        }

        bool isStarted(){
            return started_timef.has_value();
        }

        bool isFadeInEnded(){
            return getElapsedTime() > getFadeInSec();
        }

        bool isFadeOutStarted(){
            return fadeout_started_timef.has_value();
        }

        float getElapsedTime() override {
            if(started_timef.has_value()){
                return ofGetElapsedTimef() - started_timef.value();
            }else{
                return 0.0f;
            }
        }

        float getStaticSec() override {
            if(started_timef.has_value()){
                if(fadeout_started_timef.has_value() == false){
                    float dt = ofGetElapsedTimef() - started_timef.value() - fadein_sec;
                    if(dt < 0.0){
                        return 0.0f;
                    }else{
                        return dt;
                    }
                }else{
                    float dt = fadeout_started_timef.value() - started_timef.value() - fadein_sec;
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
            if(fadeout_started_timef.has_value() == false){
                return -1.0f;
            }else{
                return fadeout_sec;
            }
        }

    protected:
        fade_opt::optional<float> started_timef = fade_opt::nullopt;
        fade_opt::optional<float> fadeout_started_timef = fade_opt::nullopt;
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
