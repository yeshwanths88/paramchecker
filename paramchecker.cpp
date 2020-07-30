#include "paramchecker.h"
#include <vector>
#include <iostream>

IVitalCheck* vitalCheckers[] = {
  [bpm] = new VitalRangeCheck(70, 150),
  [spo2] = new VitalRangeCheck(80, 100),
  [respRate] = new VitalRangeCheck(30, 60),
  [avgECG] = new VitalValueCheck(0),
};

std::vector<VITAL_STATUS> vitalsAreOk(const std::vector<Measurement>& measurements) {
  std::vector<VITAL_STATUS> results;
  for(auto t = measurements.begin(); t != measurements.end(); t++) {
    VITAL_STATUS vitalResult = vitalCheckers[t->id]->measurementIsOk(t->measured_value);
    std::cout << "Vital-check result is " << vitalResult << std::endl;
    results.push_back(vitalResult);
  }
  return results;
}

VITAL_ALERT vitalAlerts(const std::vector<Measurement>& measurements, const std::vector<VITAL_STATUS>& vital_status) {
  //TODO: add logic
  return all_is_well;
}

