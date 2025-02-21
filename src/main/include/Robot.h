// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "elasticlib.h"

#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include <networktables/DoubleTopic.h>
#include <networktables/StringTopic.h>

#include <frc/smartdashboard/Mechanism2d.h>
#include <frc/smartdashboard/MechanismObject2d.h>
#include <frc/smartdashboard/MechanismRoot2d.h>
#include <frc/smartdashboard/MechanismLigament2d.h>

#include <frc/geometry/Pose2d.h>
#include <frc/smartdashboard/Field2d.h>

#include <wpi/sendable/Sendable.h>
#include <wpi/sendable/SendableBuilder.h>

#include "SwerveWidget.h"


class Robot : public frc::TimedRobot {
 public:
  Robot();
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;
  void SimulationInit() override;
  void SimulationPeriodic() override;

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  std::shared_ptr<nt::NetworkTable> ntTable;

  nt::DoublePublisher gyroAnglePub;
  nt::DoublePublisher elevatorHeightPub;
  nt::DoublePublisher coralAnglePub;
  nt::DoublePublisher coralVelPub;
  nt::DoublePublisher algaeAnglePub;
  nt::DoublePublisher algaeVelPub;

  frc::Field2d field2d;

  SwerveWidget m_swerveWidget;

};
