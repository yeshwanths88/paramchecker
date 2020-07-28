#define BPM_MIN 70
#define BPM_MAX 150
#define SPO2_MIN 80
#define RESP_RATE_MIN 30
#define RESP_RATE_MAX 60

bool isLower(float val, float maxVal) {
  return (val < maxVal);
}

bool isGreater(float val, float minVal) {
  return (val > minVal);
}

bool isInBetween(float val, float minVal, float maxVal) {
  return (isLower(val, maxVal) && isGreater(val, minVal));
}

bool bpmOk(float bpm) {
  return isInBetween(bpm, BPM_MIN, BPM_MAX);
}

bool spo2Ok(float spo2) {
  return isGreater(spo2, SPO2_MIN);
}

bool respRateOk(float respRate) {
  return isInBetween(respRate, RESP_RATE_MIN, RESP_RATE_MAX);
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return (bpmOk(bpm) && spo2Ok(spo2) && respRateOk(respRate));
}
