#pragma once

#include "Application.hpp"

#include "model/Project.hpp"
#include "gui/ImageComposer.hpp"
#include "gui/AScoreBoard.hpp"
#include "gui/FieldVisualizer.hpp"
#include "util/ShaderProgram.hpp"
#include "data/MediaSource.hpp"
#include "model/VideoProducer.hpp"

class TigersClav : public Application
{
public:
    TigersClav();

    void render() override;

private:
    void createGamestateTextures();
    void drawGameLogPanel();
    void drawVideoPanel();
    void drawProjectPanel();
    void drawSyncPanel();

    std::unique_ptr<Project> pProject_;
    std::unique_ptr<ImageComposer> pImageComposer_;
    std::unique_ptr<AScoreBoard> pScoreBoard_;
    std::unique_ptr<FieldVisualizer> pFieldVisualizer_;
    std::unique_ptr<VideoProducer> pVideoProducer_;

    std::string lastFileOpenPath_;

    float gameLogTime_s_;
    bool gameLogAutoPlay_;
    bool gameLogSliderHovered_;

    int recordingIndex_;
    float recordingTime_s_;
    bool recordingAutoPlay_;
    bool recordingSliderHovered_;

    std::map<std::string, float> bufferedRecordingTimes_;

    char camNameBuf_[128];
    char markerNameBuf_[128];

    GLuint scoreBoardTexture_;
    GLuint fieldVisualizerTexture_;

    bool exportScoreBoardCut_;
    bool exportScoreBoardGoals_;
    bool exportScoreBoardArchive_;

    bool exportUseHwDecoder_;
    bool exportUseHwEncoder_;
};
