#ifndef H_RENDERSTATISTICS_DZSTATISTICS
#define H_RENDERSTATISTICS_DZSTATISTICS

#include "logger.h"
#include "statistics.h"
#include <dzbasiccamera.h>
#include <dzcamera.h>

class DzRenderStatistics : public RenderStatistics {

public:
  DzRenderStatistics(
    const QString engine, const int nodes, DzCamera* camera, RenderStatisticsLogger* logger
  );

  ~DzRenderStatistics() = default;

  DzBasicCamera* getCamera() { return camera; }

private:
  RenderStatisticsLogger* logger;
  DzBasicCamera* camera;

};

#endif
