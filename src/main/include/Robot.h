// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/PWMSparkMax.h>
#include <frc/SpeedControllerGroup.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  //drive base
  frc::PWMSparkMax FrontLeft{99};
  frc::PWMSparkMax BackLeft{99};
  frc::SpeedControllerGroup m_left = frc::SpeedControllerGroup(FrontLeft, BackLeft);

  frc::PWMSparkMax FrontRight{99};
  frc::PWMSparkMax BackRight{99};
  frc::SpeedControllerGroup m_right = frc::SpeedControllerGroup(FrontRight, BackRight);

};
