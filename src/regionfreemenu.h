//
// Created by cpasjuste on 21/01/2020.
//

#ifndef RETRODREAM_REGIONFREEMENU_H
#define RETRODREAM_REGIONFREEMENU_H

#include "flash/systempartition.h"

class RegionFreeMenu : public Menu {

public:

    enum MainOption {
        Country = 0,
        Broadcast,
        Backup
    };

    explicit RegionFreeMenu(RetroDream *rd, const c2d::FloatRect &rect);

    void setVisibility(c2d::Visibility visibility, bool tweenPlay = false) override;

    bool onInput(c2d::Input::Player *players) override;

private:
    SystemPartition partition;
    c2d::Io *io = nullptr;
    std::string backupPath;
};

#endif //RETRODREAM_REGIONFREEMENU_H
