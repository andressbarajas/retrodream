//
// Created by cpasjuste on 15/01/2020.
//

#ifndef RETRODREAM_MAIN_H
#define RETRODREAM_MAIN_H

#include "cfg.h"
#include "filer.h"
#include "header.h"
#include "preview.h"
#include "optionmenu.h"
#include "filemenu.h"
#include "statusbox.h"
#include "utility.h"
#include "infobox.h"

#define FONT_SIZE 24
#define FONT_SIZE_SMALL 16

class RetroDream : public c2d::RoundedRectangleShape {

public:

    explicit RetroDream(c2d::Renderer *renderer, const c2d::Vector2f &size, float outlineThickness);

    c2d::Renderer *getRender() {
        return render;
    }

    Header *getHeader() {
        return header;
    }

    Preview *getPreview() {
        return preview;
    }

    Filer *getFiler() {
        return filer;
    }

    FileMenu *getFileMenu() {
        return fileMenu;
    }

    OptionMenu *getOptionMenu() {
        return optionMenu;
    }

    void showStatus(const std::string &title, const std::string &msg);

    RetroConfig *getConfig();

    InfoBox *infoBox = nullptr;
    bool quit = false;

private:

    bool onInput(c2d::Input::Player *players) override;

    void onDraw(c2d::Transform &transform, bool draw = true) override;

    c2d::Renderer *render = nullptr;
    c2d::C2DClock timer;
    Filer *filer = nullptr;
    Filer *filerLeft = nullptr;
    //Filer *filerRight = nullptr;
    Header *header = nullptr;
    Preview *preview = nullptr;
    OptionMenu *optionMenu = nullptr;
    FileMenu *fileMenu = nullptr;
    StatusBox *statusBox = nullptr;
    c2d::RectangleShape *blurLayer = nullptr;
    int inputDelay;
    unsigned int oldKeys;
};

#endif //RETRODREAM_MAIN_H
