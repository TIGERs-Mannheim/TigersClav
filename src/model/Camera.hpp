#pragma once

#include "SyncMarker.hpp"
#include "data/Video.hpp"

class VideoRecording
{
public:
    VideoRecording(std::string videoFilename);

    std::string getName() const;

    std::shared_ptr<Video> pVideo_;
    SyncMarker syncMarker_;

    int64_t offsetToGameLog_ns_; // gamelog t=0 to video t=0

    int64_t frontGap_ns_; // gap between this recording and the previous one
};

class Camera
{
public:
    Camera(std::string name);

    std::string getName() const { return name_; }
    int64_t getTotalDuration_ns() const;
    AVFrame* getAVFrame(int64_t timestamp_ns);

    const Video::CacheLevels& getLastCacheLevels() const { return lastCacheLevels_; }

    float getFrameDeltaTime() const;

    void addVideo(std::string name);

    std::list<std::shared_ptr<VideoRecording>>& getVideos() { return pVideos_; }

private:
    std::string name_;
    std::list<std::shared_ptr<VideoRecording>> pVideos_;

    Video::CacheLevels lastCacheLevels_;
};