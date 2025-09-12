#pragma once

#include "ofMain.h"
#include "ofxEasing.h"

#if __cplusplus >= 201703L
#if __has_include(<optional>)

#define OFXFADE_USE_STD_OPTIONAL
#include <optional>

#endif // __has_include(<optional>)
#endif // __cplusplus >= 201703L

namespace ofxfade {

#ifdef OFXFADE_USE_STD_OPTIONAL
    using std::optional;

    static const std::nullopt_t nullopt = std::nullopt;
#else

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
        T& operator*() { return value_; }
        const T& operator*() const { return value_; }

    private:
        T value_;
        bool has_value_;
    };

#endif // USE_STD_OPTIONAL

} // namespace ofxfade

class ofxFade {
public:
    enum Flag {
        OFXFADE_NO_PUSH_POP = 1 << 0
        // OFXFADE_ANOTHER_FLAG = 1 << 1, // 2
        // OFXFADE_THIRD_FLAG   = 1 << 2  // 4
    };

    enum class Phase {
        FADEIN,
        STATIC,
        FADEOUT
    };

    /// Timer interface
    class Fader {
    public:
        virtual float getElapsedTime() const = 0;
        virtual float getStaticSec() const = 0;
        virtual float getFadeInSec() const = 0;
        virtual ofxfade::optional<float> getFadeOutSec() const = 0;

        bool isFinished() const {
            if(getFadeOutSec().has_value()){
                return getElapsedTime() > getFadeInSec() + getStaticSec() + getFadeOutSec().value();
            }else{
                return false; // WORKAROUND
            }
        }

        void advanced(std::function<void(float rateEasing, float rateTime, Phase phase)> draw_fn,
            ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out) const
        {
            ofxFade::advanced(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func, easing_type
            );
        }
        void advanced(std::function<void(float rateEasing, Phase phase)> draw_fn,
            ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out) const
        {
            ofxFade::advanced(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func, easing_type
            );
        }
        void advanced(std::function<void(float rateEasing, float rateTime, Phase phase)> draw_fn,
            ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
            ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out
        ) const
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
        ) const
        {
            ofxFade::advanced(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func_in, easing_type_in,
                easing_func_out, easing_type_out
            );
        }

        void alpha(std::function<void(float alpha)> draw_fn,
            ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out) const
        {
            ofxFade::alpha(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func, easing_type
            );
        }
        void alpha(std::function<void(float alpha, float rateEasing)> draw_fn,
            ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out) const
        {
            ofxFade::alpha(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func, easing_type
            );
        }
        void alpha(std::function<void(float alpha, float rateEasing, float rateTime, Phase phase)> draw_fn,
            ofxeasing::Function easing_func = ofxeasing::Function::Linear,ofxeasing::Type easing_type = ofxeasing::Type::Out) const
        {
            ofxFade::alpha(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func, easing_type
            );
        }
        void alpha(std::function<void(float alpha)> draw_fn,
            ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
            ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out) const
        {
            ofxFade::alpha(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func_in, easing_type_in,
                easing_func_out, easing_type_out
            );
        }
        void alpha(std::function<void(float alpha, float rateEasing)> draw_fn,
            ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
            ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out) const
        {
            ofxFade::alpha(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func_in, easing_type_in,
                easing_func_out, easing_type_out
            );
        }
        void alpha(std::function<void(float alpha, float rateEasing, float rateTime, Phase phase)> draw_fn,
            ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
            ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out) const
        {
            ofxFade::alpha(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), draw_fn,
                easing_func_in, easing_type_in,
                easing_func_out, easing_type_out
            );
        }

        template<typename T>
        void delta(T delta, std::function<void(T delta)> draw_fn,
            ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out) const
        {
            ofxFade::delta(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), delta, draw_fn,
                easing_func, easing_type
            );
        }

        template<typename T>
        void delta(T delta, std::function<void(T delta, float alpha)> draw_fn,
            ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out) const
        {
            ofxFade::delta(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), delta, draw_fn,
                easing_func, easing_type
            );
        }

        template<typename T>
        void delta(T delta,
            std::function<void(T delta, float alpha, float rateEasing)> draw_fn, ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out) const
        {
            ofxFade::delta(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), delta, draw_fn,
                easing_func, easing_type
            );
        }

        template<typename T>
        void delta(T delta, std::function<void(T delta, float alpha, float rateEasing, float rateTime, Phase phase)> draw_fn,
            ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out) const
        {
            ofxFade::delta(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), delta, draw_fn,
                easing_func, easing_type
            );
        }

        template<typename T>
        void delta(T delta, std::function<void(T)> draw_fn,
            ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
            ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out) const
        {
            ofxFade::delta(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), delta, draw_fn,
                easing_func_in, easing_type_in,
                easing_func_out, easing_type_out
            );
        }

        template<typename T>
        void delta(T delta, std::function<void(T delta, float alpha)> draw_fn,
            ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
            ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out) const
        {
            ofxFade::delta(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), delta, draw_fn,
                easing_func_in, easing_type_in,
                easing_func_out, easing_type_out
            );
        }

        template<typename T>
        void delta(T delta, std::function<void(T delta, float alpha, float rateEasing)> draw_fn,
            ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
            ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out) const
        {
            ofxFade::delta(
                getElapsedTime(), getFadeInSec(), getStaticSec(), getFadeOutSec(), delta, draw_fn,
                easing_func_in, easing_type_in,
                easing_func_out, easing_type_out
            );
        }

        template<typename T>
        void delta(T delta, std::function<void(T delta, float alpha, float rateEasing, float rateTime, Phase phase)> draw_fn,
            ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
            ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out) const
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
        NonInteractiveFader(float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec) :
            fadein_sec(fadein_sec), static_sec(static_sec), fadeout_sec(fadeout_sec) {}

        float fadein_sec = 0.0f;
        float static_sec = 0.0f;
        ofxfade::optional<float> fadeout_sec = 0.0f;

        void setup(float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec){
            this->fadein_sec = fadein_sec;
            this->static_sec = static_sec;
            this->fadeout_sec = fadeout_sec;
        }

        void start(){
            started_timef = ofGetElapsedTimef();
        }

        /// stop means reset
        void stop(){
            started_timef.reset();
        }

        bool isStarted() const{
            return started_timef.has_value();
        }

        bool isFadeInEnded() const{
            return getElapsedTime() > getFadeInSec();
        }

        bool isFadeOutStarted() const{
            return getElapsedTime() > getFadeInSec() + getStaticSec();
        }

        float getElapsedTime() const override {
            if(started_timef.has_value()){
                return ofGetElapsedTimef() - started_timef.value();
            }else{
                return 0.0f;
            }
        }

        float getStaticSec() const override {
            return static_sec;
        }

        float getFadeInSec() const override {
            return fadein_sec;
        }

        ofxfade::optional<float> getFadeOutSec() const override {
            return fadeout_sec;
        }

    protected:
        ofxfade::optional<float> started_timef = ofxfade::nullopt;
    };
    
    // Timer for interactive fadeout
    class InteractiveFader : public Fader {
    public: 
        InteractiveFader() {}
        InteractiveFader(float fadein_sec, ofxfade::optional<float> fadeout_sec) :
            fadein_sec(fadein_sec), fadeout_sec(fadeout_sec) {}

        float fadein_sec = 0.0f;
        ofxfade::optional<float> fadeout_sec = 0.0f;

        void setup(float fadein_sec, ofxfade::optional<float> fadeout_sec){
            this->fadein_sec = fadein_sec;
            this->fadeout_sec = fadeout_sec;
        }

        void fadeInStart(){
            started_timef = ofGetElapsedTimef();
            fadeout_started_timef.reset();
        }

        /// @param immediate execute fade-out soon (keeping fade-in rate). if false, execute fade-out after fade-in.
        void fadeOutStart(bool immediate = true){
            if(fadeout_sec.has_value()){
                if(started_timef.has_value() == false){
                    fadeInStart();
                }
                fadeout_started_timef = ofGetElapsedTimef();

                if(immediate){
                    if(!isFadeInEnded()){
                        // NOTE: apply incomplete fade_in rate for fade_out
                        float diff_in = getFadeInSec() - getElapsedTime();
                        float diff_in_rate = diff_in / getFadeInSec();
                        float diff_out = diff_in_rate * getFadeOutSec().value();
                        started_timef = started_timef.value() - (diff_in + diff_out);
                        fadeout_started_timef = fadeout_started_timef.value() - (diff_in + diff_out);
                    }
                }
            }else{
                // if no fadeout, do nothing.
                ofLogWarning("ofxFade") << "fadeOutStart() called but no fadeout specified";
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

        bool isStarted() const{
            return started_timef.has_value();
        }

        bool isFadeInEnded() const{
            return getElapsedTime() > getFadeInSec();
        }

        bool isFadeOutStarted() const{
            return fadeout_started_timef.has_value();
        }

        float getElapsedTime() const override {
            if(started_timef.has_value()){
                return ofGetElapsedTimef() - started_timef.value();
            }else{
                return 0.0f;
            }
        }

        float getStaticSec() const override {
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

        float getFadeInSec() const override {
            return fadein_sec;
        }

        /// @brief NOTE that this is not real fadeout_sec value. (returns nullopt if not still fading-out.)
        /// If you need real fadeout_sec value, use fadeout_sec instead.
        ofxfade::optional<float> getFadeOutSec() const override {
            if(fadeout_started_timef.has_value() == false){
                return ofxfade::nullopt;
            }else{
                return fadeout_sec;
            }
        }

    protected:
        ofxfade::optional<float> started_timef = ofxfade::nullopt;
        ofxfade::optional<float> fadeout_started_timef = ofxfade::nullopt;
    };

    // ------------

protected:
    static int global_flags;

public:

    static void setFlag(Flag flag, bool status = true){
        if(status){
            global_flags = global_flags | static_cast<int>(flag);
        }else{
            global_flags = global_flags & ~static_cast<int>(flag);
        }
    }
    
    static void setFlags(int flag, bool status = true){
        if(status){
            global_flags = global_flags | flag;
        }else{
            global_flags = global_flags & ~flag;
        }
    }

    static void withFlag(Flag flag, std::function<void()> fn, bool status = true) {
        int prev_flag = global_flags;
        setFlag(flag, status);
        fn();
        global_flags = prev_flag;
    }
    
    static void withFlags(int flag, std::function<void()> fn, bool status = true) {
        int prev_flag = global_flags;
        setFlags(flag, status);
        fn();
        global_flags = prev_flag;
    }

    static bool getFlag(Flag flag) {
        return (global_flags & flag) == flag;
    }

    static void advanced(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, std::function<void(float rateEasing, float rateTime, Phase phase)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out);
    static void advanced(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, std::function<void(float rateEasing, Phase phase)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out);
    static void advanced(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, std::function<void(float rateEasing, float rateTime, Phase phase)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out
    );
    static void advanced(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, std::function<void(float rateEasing, Phase phase)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out
    );

    static void alpha(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, std::function<void(float alpha)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out);
    static void alpha(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, std::function<void(float alpha, float rateEasing)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out);
    static void alpha(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, std::function<void(float alpha, float rateEasing, float rateTime, Phase phase)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear,ofxeasing::Type easing_type = ofxeasing::Type::Out);
    static void alpha(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, std::function<void(float alpha)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out);
    static void alpha(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, std::function<void(float alpha, float rateEasing)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out);
    static void alpha(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, std::function<void(float alpha, float rateEasing, float rateTime, Phase phase)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out);

    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, T delta, std::function<void(T delta)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out)
    {
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            draw_fn(r * delta);
        }, easing_func, easing_type);
    }

    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, T delta, std::function<void(T delta, float alpha)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out)
    {
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            draw_fn(r * delta, r * 255.0f);
        }, easing_func, easing_type);

    }

    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, T delta,
        std::function<void(T delta, float alpha, float rateEasing)> draw_fn, ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out)
    {
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            draw_fn(r * delta, r * 255.0f, r);
        }, easing_func, easing_type);
    }

    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, T delta, std::function<void(T delta, float alpha, float rateEasing, float rateTime, Phase phase)> draw_fn,
        ofxeasing::Function easing_func = ofxeasing::Function::Linear, ofxeasing::Type easing_type = ofxeasing::Type::Out)
    {
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, float rt, Phase phase){
            draw_fn(r * delta, r * 255.0f, r, rt, phase);
        }, easing_func, easing_type);
    }

    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, T delta, std::function<void(T delta)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out)
    {
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            draw_fn(r * delta);
        }, easing_func_in, easing_type_in, easing_func_out, easing_type_out);
    }

    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, T delta, std::function<void(T delta, float alpha)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out)
    {
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            draw_fn(r * delta, r * 255.0f);
        }, easing_func_in, easing_type_in, easing_func_out, easing_type_out);
    }

    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, T delta, std::function<void(T delta, float alpha, float rateEasing)> draw_fn,
        ofxeasing::Function easing_func_in, ofxeasing::Type easing_type_in,
        ofxeasing::Function easing_func_out, ofxeasing::Type easing_type_out)
    {
        advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn, &delta](float r, Phase phase){
            draw_fn(r * delta, r * 255.0f, r);
        }, easing_func_in, easing_type_in, easing_func_out, easing_type_out);
    }

    template<typename T>
    static void delta(float t, float fadein_sec, float static_sec, ofxfade::optional<float> fadeout_sec, T delta, std::function<void(T delta, float alpha, float rateEasing, float rateTime, Phase phase)> draw_fn,
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
