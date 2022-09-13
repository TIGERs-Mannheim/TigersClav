#pragma once

#include "blend2d.h"
#include "ssl_gc_referee_message.pb.h"
#include <memory>
#include <optional>

class ScoreBoard
{
public:
    ScoreBoard();

    void update(const std::shared_ptr<Referee>& pRef);

    BLImageData getImageData();

private:
    enum class CardColor
    {
        YELLOW,
        RED
    };

    void drawCard(CardColor color, unsigned int amount, BLPoint pos, BLSize size = BLSize(36, 50));

    void drawTeamNames(const std::string& team1, const std::string& team2, BLPoint pos1, BLPoint pos2, BLSize maxSize);
    void drawStage(Referee::Stage stage, Referee::Command command, std::optional<int> actionTimeLeft_us);

    void centeredText(const BLPoint &pos, const char *str, const BLFontFace &face, float size, const BLRgba32 &color);

    static void refereeStageToString(Referee::Stage stage, Referee::Command &standard, std::string &stageText);
    static void refereeCommandToTextAndColor(Referee::Command command, std::string& commandText, BLRgba32& bgColor, BLRgba32& textColor);

    static bool hasStageTimeLeft(Referee::Stage stage);
    static bool hasActionTimeLeft(Referee::Command command);

    BLFontFace regularFontFace_;
    BLFontFace boldFontFace_;

    BLImage gamestateImage_;
    BLContext ctx_;
};
