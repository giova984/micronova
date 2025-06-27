#pragma once

#include "esphome/components/micronova/micronova.h"
#include "esphome/components/sensor/sensor.h"

namespace esphome {
namespace micronova {

class MicroNovaSensor : public sensor::Sensor, public MicroNovaSensorListener {
 public:
  MicroNovaSensor(MicroNova *m) : MicroNovaSensorListener(m) {}
  void dump_config() override { LOG_SENSOR("", "Micronova sensor", this); }

  void request_value_from_stove() override {
    this->micronova_->request_address(this->memory_location_, this->memory_address_, this);
  }
  void process_value_from_stove(int value_from_stove) override;

  void set_fan_speed_offset(uint8_t f) { this->fan_speed_offset_ = f; }
  uint8_t get_set_fan_speed_offset() { return this->fan_speed_offset_; }
  void set_water_temp_mult_factor(float f) { this->water_temp_mult_factor_ = f; }
  float get_water_temp_mult_factor() { return this->water_temp_mult_factor_; }

 protected:
  int fan_speed_offset_ = 0;
  float water_temp_mult_factor_ = 1.0;
};

}  // namespace micronova
}  // namespace esphome
