
bool vitalsAreOk(float bpm, float spo2, float respRate) {
  bool return_val = true;
  if(bpm < 70 || bpm > 150) {
    return_val = false;
  } else if(spo2 < 80) {
    return_val = false;
  } else if(respRate < 30 || respRate > 60) {
    return_val = false;
  }
  return return_val;
}
