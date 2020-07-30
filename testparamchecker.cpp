#include "paramchecker.h"
#include <gtest/gtest.h>
 
TEST(VitalsTest, when_a_vital_is_in_range_vital_range_check_is_ok) {
    VitalRangeCheck vitalChecker(60, 100);
    ASSERT_EQ(vitalChecker.measurementIsOk(70), normal);
}

TEST(VitalsTest, when_a_vital_is_off_limit_it_is_reported_with_vital_id) { 
    std::vector<Measurement> measurements = {
        {bpm, 100},
        {spo2, 50},
        {respRate, 50},
    };
    auto results = vitalsAreOk(measurements);
    ASSERT_EQ(results.size(), sizeof(measurements)/sizeof(measurements[0]));
    ASSERT_EQ(results[spo2], low);
    ASSERT_EQ(results[bpm], normal);
    ASSERT_EQ(results[respRate], normal);
}

TEST(VitalsTest, check_for_vital_alert_all_is_well) {
  std::vector<Measurement> measurements = {
        {bpm, 100},
        {spo2, 90},
        {respRate, 50},
    };
    auto results = vitalsAreOk(measurements);
    auto result = vitalAlerts(measurements, results);
    ASSERT_EQ(result, all_is_well);
}

TEST(VitalsTest, check_for_vital_alert_lung_failure) {
  std::vector<Measurement> measurements = {
        {bpm, 100},
        {spo2, 50},
        {respRate, 80},
    };
    auto results = vitalsAreOk(measurements);
    auto result = vitalAlerts(measurements, results);
    ASSERT_EQ(result, lung_failure);
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
