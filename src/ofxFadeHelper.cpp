#include "ofxFadeHelper.h"

namespace utils {
    inline float clamp(float value, float min=0.0f, float max=1.0f){
		if(value < min){
			return min;
		}else if(value > max){
			return max;
		}else{
			return value;
		}
	}

    inline void pushAll(){
        ofPushStyle();
        ofPushMatrix();
    }

    inline void popAll(){
        ofPopMatrix();
        ofPopStyle();
    }

    inline float fadeInRate(float r, ofxeasing::Function easing_func, ofxeasing::Type easing_type){
        auto&& easing_fn = ofxeasing::easing(easing_func, easing_type);
        float r2 = ofxeasing::map_clamp(r, 0.0f, 1.0f, 0.0f, 1.0f, easing_fn);

        return r2;
    }

    inline float fadeOutRate(float r, ofxeasing::Function easing_func, ofxeasing::Type easing_type){
        auto&& easing_fn = ofxeasing::easing(easing_func, easing_type);
        float r2 = ofxeasing::map_clamp(1.0f - r, 0.0f, 1.0f, 0.0f, 1.0f, easing_fn);

        return r2;
    }
}

std::string ofxFadeHelper::phaseToString(Phase phase){
    if(phase == Phase::FADEIN){
        return "FADEIN";
    }else if(phase == Phase::STATIC){
        return "STATIC";
    }else if(phase == Phase::FADEOUT){
        return "FADEOUT";
    }else{
        assert(false);
    }
}

void ofxFadeHelper::advanced(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float rateEasing, float rateTime, Phase phase)> draw_fn, ofxeasing::Function easing_func, ofxeasing::Type easing_type){
    utils::pushAll();

    if(fadeout_sec >= 0){
        // fadein
        if(t < fadein_sec){
            float r = utils::clamp(t / fadein_sec);
            float r2 = utils::fadeInRate(r, easing_func, easing_type);

            draw_fn(r2, r, Phase::FADEIN);

        // static
        }else if(t < fadein_sec + static_sec){
            float t2 = t - fadein_sec;
            float r = utils::clamp(t2 / static_sec);

            draw_fn(1.0f, r, Phase::STATIC);

        // fadeout
        }else{
            float t3 = t - fadein_sec - static_sec;
            float r = utils::clamp(t3 / fadeout_sec);
            float r2 = utils::fadeOutRate(r, easing_func, easing_type);

            draw_fn(r2, r, Phase::FADEOUT);
        }
    }else{
        // fadein
        if(t < fadein_sec){
            float r = utils::clamp(t / fadein_sec);
            float r2 = utils::fadeInRate(r, easing_func, easing_type);

            draw_fn(r2, r, Phase::FADEIN);

        // static
        }else{
            float r = 1.0f;

            draw_fn(1.0f, r, Phase::STATIC);
        }
    }

    utils::popAll();
}

void ofxFadeHelper::advanced(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float rateEasing, Phase phase)> draw_fn, ofxeasing::Function easing_func, ofxeasing::Type easing_type){
    auto draw_fn2 = [&draw_fn](float rateEasing, float rate, Phase phase){
        draw_fn(rateEasing, phase);
    };
    advanced(t, fadein_sec, static_sec, fadeout_sec, draw_fn2, easing_func, easing_type);
}

void ofxFadeHelper::alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float alpha)> draw_fn, ofxeasing::Function easing_func, ofxeasing::Type easing_type){
    advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn](float r, Phase phase){
        draw_fn(r * 255.0f);
    }, easing_func, easing_type);
}

void ofxFadeHelper::alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float alpha, float rateEasing)> draw_fn, ofxeasing::Function easing_func, ofxeasing::Type easing_type){
    advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn](float r, Phase phase){
        draw_fn(r * 255.0f, r);
    }, easing_func, easing_type);
}

void ofxFadeHelper::alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float alpha, float rateEasing, float rateTime)> draw_fn, ofxeasing::Function easing_func, ofxeasing::Type easing_type){
    advanced(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn](float r, float rt, Phase phase){
        draw_fn(r * 255.0f, r, rt);
    }, easing_func, easing_type);
}