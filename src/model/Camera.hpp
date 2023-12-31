#pragma once

#include "SyncMarker.hpp"
#include "data/MediaSource.hpp"
#include <optional>
#include <vector>

class VideoRecording
{
public:
    VideoRecording(std::string videoFilename);

    std::string getName() const;

    std::shared_ptr<MediaSource> pVideo_;
    std::optional<SyncMarker> syncMarker_;

    int64_t tStart_ns_; // gamelog t=0 to video t=0
    int64_t frontGap_ns_; // gap between this recording and the previous one
};

class Camera
{
public:
    Camera(std::string name);

    std::string getName() const { return name_; }
    int64_t getTotalDuration_ns() const;
    AVFrame* getAVFrame(int64_t timestamp_ns);

    float getFrameDeltaTime() const;

    void addVideo(std::string name);

    std::vector<std::shared_ptr<VideoRecording>>& getVideos() { return pVideos_; }

    bool exportCut_;
    bool exportGoals_;
    bool exportArchive_;

private:
    std::string name_;
    std::vector<std::shared_ptr<VideoRecording>> pVideos_;
};
