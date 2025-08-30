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

void ofxFadeHelper::simple(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float r, Phase phase)> draw_fn){
    utils::pushAll();

    if(fadeout_sec >= 0){
        // fadein
        if(t < fadein_sec){
            float r = utils::clamp(t / fadein_sec);

            draw_fn(r, Phase::FADEIN);

        // static
        }else if(t < fadein_sec + static_sec){
            float t2 = t - fadein_sec;
            float r = utils::clamp(t2 / static_sec);

            draw_fn(r, Phase::STATIC);

        // fadeout
        }else{
            float t3 = t - fadein_sec - static_sec;
            float r = utils::clamp(t3 / fadeout_sec);

            draw_fn(r, Phase::FADEOUT);
        }
    }else{
        // fadein
        if(t < fadein_sec){
            float r = utils::clamp(t / fadein_sec);

            draw_fn(r, Phase::FADEIN);

        // static
        }else{
            float r = 1.0f;

            draw_fn(r, Phase::STATIC);
        }
    }

    utils::popAll();
}

void ofxFadeHelper::alpha(float t, float fadein_sec, float static_sec, float fadeout_sec, std::function<void(float)> draw_fn){
    simple(t, fadein_sec, static_sec, fadeout_sec, [&draw_fn](float r, Phase phase){
        if(phase == Phase::FADEIN){
            draw_fn(r * 255.0f);
        }else if(phase == Phase::STATIC){
            draw_fn(255.0f);
        }else if(phase == Phase::FADEOUT){
            draw_fn((1.0f - r) * 255.0f);
        }
    });
}