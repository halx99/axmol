/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 https://axmolengine.github.io/

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "WindowTest.h"

#if (AX_TARGET_PLATFORM == AX_PLATFORM_MAC || AX_TARGET_PLATFORM == AX_PLATFORM_WIN32 || \
     AX_TARGET_PLATFORM == AX_PLATFORM_LINUX)
USING_NS_AX;

WindowTests::WindowTests()
{
    ADD_TEST_CASE(WindowTestWindowed1);
    ADD_TEST_CASE(WindowTestWindowed2);
    ADD_TEST_CASE(WindowTestFullscreen1);
    ADD_TEST_CASE(WindowTestFullscreen2);
    ADD_TEST_CASE(WindowTestFullscreen3);
}

std::string WindowTest::title() const
{
    return "Window Test";
}

void WindowTestWindowed1::onEnter()
{
    WindowTest::onEnter();
    GLViewImpl* view = (GLViewImpl*)Director::getInstance()->getGLView();
    view->setWindowed(480, 320);
}

std::string WindowTestWindowed1::subtitle() const
{
    return "Windowed 480x320";
}

void WindowTestWindowed2::onEnter()
{
    WindowTest::onEnter();
    GLViewImpl* view = (GLViewImpl*)Director::getInstance()->getGLView();
    view->setWindowed(960, 640);
}

std::string WindowTestWindowed2::subtitle() const
{
    return "Windowed 960x640";
}

bool WindowTestFullscreen1::init()
{
    // @remark: Set full screen before layout renderer elements to ensure VisibleRect is
    // correct with full screen window size
    GLViewImpl* view = (GLViewImpl*)Director::getInstance()->getGLView();
    view->setFullscreen();
    return WindowTest::init();
}

std::string WindowTestFullscreen1::subtitle() const
{
    return "Fullscreen";
}

bool WindowTestFullscreen2::init()
{
    GLViewImpl* view = (GLViewImpl*)Director::getInstance()->getGLView();
    view->setFullscreen(1);
    return WindowTest::init();
}

std::string WindowTestFullscreen2::subtitle() const
{
    return "Fullscreen Monitor 2 (if present)";
}

bool WindowTestFullscreen3::init()
{
    GLViewImpl* view = (GLViewImpl*)Director::getInstance()->getGLView();
    view->setFullscreen(2);
    return WindowTest::init();
}

std::string WindowTestFullscreen3::subtitle() const
{
    return "Fullscreen Monitor 3 (if present)";
}

#endif
