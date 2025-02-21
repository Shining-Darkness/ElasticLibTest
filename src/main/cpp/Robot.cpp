// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <wpi/print.h>

Robot::Robot() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);


  ntTable = nt::NetworkTableInstance::GetDefault().GetTable("/ElasticInterface");
  
  gyroAnglePub = ntTable->GetDoubleTopic("gyroAngle").Publish();
  elevatorHeightPub = ntTable->GetDoubleTopic("elevatorHeight").Publish();
  coralAnglePub = ntTable->GetDoubleTopic("coralAngle").Publish();
  coralVelPub = ntTable->GetDoubleTopic("coralVel").Publish();
  algaeAnglePub = ntTable->GetDoubleTopic("algaeAngle").Publish();
  algaeVelPub = ntTable->GetDoubleTopic("algaeVel").Publish();

  frc::SmartDashboard::PutData("Field", &field2d);

  frc::SmartDashboard::PutData("Swerve Drive", &m_swerveWidget);

}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {

  gyroAnglePub.Set(180);
  elevatorHeightPub.Set(15);
  coralAnglePub.Set(20);
  coralVelPub.Set(3000);
  algaeAnglePub.Set(54);
  algaeVelPub.Set(2500);

  field2d.SetRobotPose(frc::Pose2d());

  frc::SwerveModuleState testModuleState;

  testModuleState.angle = frc::Rotation2d(100_deg);
  testModuleState.speed = 1_fps;

  wpi::array<frc::SwerveModuleState, 4U> exampleModuleStates = {testModuleState, frc::SwerveModuleState(), frc::SwerveModuleState(), frc::SwerveModuleState()};

  m_swerveWidget.Update(exampleModuleStates, frc::Rotation2d(units::angle::degree_t(frc::GetTime().value())));
  

}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  wpi::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
