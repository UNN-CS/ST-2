// Copyright 2024 Khramov Ivan
#include <memory>
#include "../include/tasks.h"
#include "../include/circle.h"

double EarthAndRopeSolve(double earthRadius,
                        double increase) {
    std::unique_ptr<Circle> earth = std::make_unique<Circle>(earthRadius);
    std::unique_ptr<Circle> rope = std::make_unique<Circle>(earthRadius);
    rope->SetFerence(rope->GetFerence() + increase);
    return rope->GetRadius() - earth->GetRadius();
}

double SwimmingPoolSolve(double poolRadius,
                        double trackWidth,
                        double meterTrackPrice,
                        double meterFencePrice) {
    auto swPool = std::make_unique<Circle>(poolRadius);
    auto swPoolnTrack = std::make_unique<Circle>(poolRadius + trackWidth);
    double trackArea = swPoolnTrack->GetArea() - swPool->GetArea();
    double trackPrice = trackArea * meterTrackPrice;
    double fencePrice = swPoolnTrack->GetFerence() * meterFencePrice;
    return trackPrice + fencePrice;
}

