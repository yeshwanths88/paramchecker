
bool vitalsAreOk(float bpm, float spo2, float respRate) {
  bool return_val = true;
  if(bpm < 70 || bpm > 150) {
    return false;
  } 
  if(spo2 < 80) {
    return false;
  } 
  if(respRate < 30 || respRate > 60) {
    return false;
  }
  return return_val;
}
