#include "dzstatistics.h"
#include <QtCore/qstring.h>

DzRenderStatistics::DzRenderStatistics(
  const QString engine, const int nodes, DzCamera* camera, RenderStatisticsLogger* logger
) : RenderStatistics(engine.toStdString(), nodes)
{
  this->logger = logger;

  if (camera->inherits("DzBasicCamera")) {
    this->camera = dynamic_cast<DzBasicCamera*>(camera);
    logger->log(
      QString("Saving reference to camera %1.").arg(this->camera->getName())
    );
  } else {
    this->camera = nullptr;
    logger->log(
      QString("Can not cast the camera %1 to DzBasicCamera. No reference will be saved.").arg(camera->getName())
    );
  }

}
