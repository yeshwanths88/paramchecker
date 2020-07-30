#include <vector>
#include <cmath>

enum VITAL_ID {
  bpm,
  spo2,
  respRate,
  avgECG
};

enum VITAL_STATUS {
  low,
  normal,
  high
};

enum VITAL_ALERT {
  all_is_well,
  lung_failure
};

struct Measurement{
    VITAL_ID id;
    float measured_value;
};

class IVitalCheck {
  public:
    virtual VITAL_STATUS measurementIsOk(float measurement) = 0; //pure virtual
};

class VitalRangeCheck: public IVitalCheck {
  public:
    explicit VitalRangeCheck(float lower, float upper) {
      m_lower = lower;
      m_upper = upper;
    }
    virtual VITAL_STATUS measurementIsOk(float measurement) {
      VITAL_STATUS v_status;
      if(measurement < m_lower)
      {
        v_status = low;
      }
      else if(measurement > m_upper)
      {
        v_status = high;
      }
      else
      {
        v_status = normal;
      }
      return v_status;
    }
  private:
    float m_lower;
    float m_upper;
};

class VitalValueCheck: public IVitalCheck {
  public:
    explicit VitalValueCheck(float alarmValue) {
      m_alarmValue = alarmValue;
    }
    virtual VITAL_STATUS measurementIsOk(float measurement) {
      VITAL_STATUS v_status;
      if(std::abs(measurement - m_alarmValue) < 0.001)
      {
        v_status = normal;
      }
      else if((measurement - m_alarmValue) < 0)
      {
        v_status = low;
      }
      else
      {
        v_status = high;
      }
    }
  private:
    float m_alarmValue;
};

std::vector<VITAL_STATUS> vitalsAreOk(const std::vector<Measurement>& measurements);
VITAL_ALERT vitalAlerts(const std::vector<Measurement>& measurements, const std::vector<VITAL_STATUS>& vital_status);

