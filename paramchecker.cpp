
bool vitalsAreOk(float bpm, float spo2, float respRate) {
  bool bpm_ok, spo2_ok, respRate_ok;
  bpm_ok = bpmOk(bpm);

  spo2_ok = spo2Ok(spo2);

  respRate_ok = respRateOk(respRate);

  return bpm_ok && spo2_ok && respRate_ok;
}

bool bpmOk(float bpm) {
  if(bpm < 70 || bpm > 150) {
    return false;
  }
  return true;
}

bool spo2Ok(float spo2) {
  if(spo2 < 70 || spo2 > 150) {
    return false;
  }
  return true;
}

bool respRateOk(float respRate) {
  if(respRate < 70 || respRate > 150) {
    return false;
  }
  return true;
}
