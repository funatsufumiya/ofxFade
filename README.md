# ofxFadeHelper

![docs/movie.gif](docs/movie.gif)

Fade-in/out helper for openFrameworks

"Bring Your Own Engine/Framework" style. You can create more compilcated engine or framework using this helper.

This addon basically provides three functions:

- `ofxFadeHelper::alpha()`
- `ofxFadeHelper::delta<T>()`
- `ofxFadeHelper::advanced()`

And two timer classes (which has the same method):

- `ofxFadeHelper::InteractiveFadeTimer`
- `ofxFadeHelper::NonInteractiveFadeTimer`

## Dependencies

- [ofxEasing](https://github.com/funatsufumiya/ofxEasing/)


## [example_simple](./example_simple/src/ofApp.cpp)

![docs/screenshot_simple.png](docs/screenshot_simple.png)

```cpp
#include "ofxFadeHelper.h"

// loop time: 2.5 (sec)
float t = std::fmodf(ofGetElapsedTimef(), 2.5f);

// fadein: 0.5, static: 1.0, fadeout: 0.5
ofxFadeHelper::alpha(t, 0.5f, 1.0f, 0.5f, [](float a){
    ofSetColor(255, 0, 0, a);
    ofDrawEllipse(100, 100, 100, 100);
});

// fadein: 0.5, static: 1.0, fadeout: 0.5
ofxFadeHelper::advanced(t, 0.5f, 1.0f, 0.5f, [](float rateEasing, float rateTime, ofxFadeHelper::Phase phase){
    std::string s1 = "rateEasing: " + ofToString(rateEasing, 2);
    ofDrawBitmapString(s1, 200, 50);

    std::string s2 = "rateTime: " + ofToString(rateTime, 2);
    ofDrawBitmapString(s2, 200, 100);

    std::string s3 = ofxFadeHelper::phaseToString(phase);
    ofDrawBitmapStringHighlight(s3, 200, 150);
});
```

## [example_delta](./example_delta/src/ofApp.cpp)

![docs/screenshot_delta.png](docs/screenshot_delta.png)

```cpp
#include "ofxFadeHelper.h"

// loop time: 2.5 (sec)
float t = std::fmodf(ofGetElapsedTimef(), 2.5f);

// fadein: 0.5, static: 1.0, fadeout: 0.5, delta: 100
ofxFadeHelper::delta<float>(t, 0.5f, 1.0f, 0.5f, 100.0f, [](float delta){
    ofSetColor(255, 0, 0);
    ofDrawEllipse(100, 100 + delta, 100, 100);
});

// fadein: 0.5, static: 1.0, fadeout: 0.5, delta: 100
ofxFadeHelper::delta<float>(t, 0.5f, 1.0f, 0.5f, 100.0f, [](float delta, float alpha){
    ofSetColor(255, 0, 0, alpha);
    ofDrawEllipse(220, 100 + delta, 100, 100);
});

// fadein: 0.5, static: 1.0, fadeout: 0.5, delta: (30, 100)
ofxFadeHelper::delta<ofVec2f>(t, 0.5f, 1.0f, 0.5f, ofVec2f(30, 100), [](ofVec2f delta, float alpha){
    ofSetColor(255, 0, 0, alpha);
    ofDrawEllipse(340 + delta.x, 100 + delta.y, 100, 100);
});
```

## [example_easing](./example_easing/src/ofApp.cpp)

![docs/screenshot_easing.png](docs/screenshot_easing.png)

```cpp
#include "ofxFadeHelper.h"

// loop time: 2.5 (sec)
float t = std::fmodf(ofGetElapsedTimef(), 2.5f);

// fadein: 0.5, static: 1.0, fadeout: 0.5, delta: 100, cubic (out)
ofxFadeHelper::delta<float>(t, 0.5f, 1.0f, 0.5f, 100.0f, [](float delta){
    ofSetColor(255, 0, 0);
    ofDrawEllipse(100, 100 + delta, 100, 100);
}, ofxeasing::Function::Cubic);

// fadein: 0.5, static: 1.0, fadeout: 0.5, delta: 100, bounce in, linear out
ofxFadeHelper::delta<float>(t, 0.5f, 1.0f, 0.5f, 100.0f, [](float delta, float alpha){
    ofSetColor(255, 0, 0, alpha);
    ofDrawEllipse(220, 100 + delta, 100, 100);
}, ofxeasing::Function::Bounce, ofxeasing::Type::Out,
    ofxeasing::Function::Linear, ofxeasing::Type::In);

// fadein: 0.5, static: 1.0, fadeout: 0.5, cubic (in)
ofxFadeHelper::alpha(t, 0.5f, 1.0f, 0.5f, [](float alpha){
    ofSetColor(255, 0, 0, alpha);
    ofDrawEllipse(340, 100, 100, 100);
}, ofxeasing::Function::Cubic, ofxeasing::Type::In);

// fadein: 0.5, static: 1.0, fadeout: 0.5, cubic (out)
ofxFadeHelper::advanced(t, 0.5f, 1.0f, 0.5f, [](float r, float rt, ofxFadeHelper::Phase phase){
    const float x = 460;

    std::string s1 = "rateEasing: " + ofToString(r, 2);
    ofDrawBitmapString(s1, x, 50);

    std::string s2 = "rateTime: " + ofToString(rt, 2);
    ofDrawBitmapString(s2, x, 100);

    std::string s3 = ofxFadeHelper::phaseToString(phase);
    ofDrawBitmapStringHighlight(s3, x, 150);

}, ofxeasing::Function::Cubic);
```

# [example_interactive](./example_interactive/src/ofApp.cpp)

![docs/screenshot_interactive.png](docs/screenshot_interactive.png)

```cpp
#include "ofxFadeHelper.h"

ofxFadeHelper::InteractiveFadeTimer timer;

//--------------------------------------------------------------
void ofApp::setup(){
    timer = ofxFadeHelper::InteractiveFadeTimer(1.0f, 1.0f);
    timer.start();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    timer.alpha([](float a){
        ofSetColor(255, 0, 0, a);
        ofDrawEllipse(100, 100, 100, 100);
    });

    ofDrawBitmapString("click to toggle fade", 100, 100);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(timer.isStarted() && !timer.isFadeOutStarted()){
        timer.fadeOut();
    }else if(timer.isFinished()){
        timer.start();
    }
}
```

## Notes

- `fadeout_sec` can be `-1.0f` (minus value), means no fadeout.
- You can also get `rateEasing` using `[](float alpha, float rateEasing){}` for `alpha()`, or `[](float delta, float alpha, float rateEasing)` for `delta()`.
- You can also get `rateTime` using `[](float alpha, float rateEasing, float rateTime){}` for `alpha()`, or `[](float delta, float alpha, float rateEasing, float rateTime)` for `delta()`.

## TODOs

- add advanced example

## License

Dual licensed under WTFPL and/or 0BSD.