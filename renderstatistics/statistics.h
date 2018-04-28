#ifndef H_RENDERSTATISTICS
#define H_RENDERSTATISTICS

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/posix_time/ptime.hpp>
#include <chrono>
#include <string>

#define DATE_FACET_FORMAT "%m/%d/%Y"
#define DURATION_DISPLAY_PRECISION 3
#define TIME_FACET_FORMAT "%H:%M"

using namespace std;
using namespace std::chrono;
using namespace boost::gregorian;
using namespace boost::posix_time;

/*
 * Class: RenderStatistics
 * Description: Data class for keeping track of render statistics.
 */
class RenderStatistics {

public:
  RenderStatistics(const string engine, const int nodes);
  ~RenderStatistics() = default;

  void setCounter(const int counter);
  void setRenderImage(const string renderImage);
  void stopClock();

  string toString();

  string getEngine() { return engine; };
  int getNodes() { return nodes; }
  int getCounter() { return counter; };
  string getRenderImage() { return renderImage; };

  string getDurationInSeconds();
  string getStartDate();
  string getStartTime();

private:
  string engine;
  int nodes;
  int counter;
  bool finished;
  string renderImage;

  high_resolution_clock::time_point startTime;
  high_resolution_clock::time_point endTime;
  duration<double> renderingDuration;

  ptime startDateTime;
  time_facet* timeFacet;
  date_facet* dateFacet;

  duration<double> calculateDuration();
};
#endif