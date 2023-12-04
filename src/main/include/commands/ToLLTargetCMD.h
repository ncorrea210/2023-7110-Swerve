// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/controller/PIDController.h>
#include <frc/Timer.h>

#include "subsystems/DriveSubsystem.h"
#include "utils/Limelight.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class ToLLTargetCMD
    : public frc2::CommandHelper<frc2::CommandBase, ToLLTargetCMD> {
 public:
  ToLLTargetCMD(DriveSubsystem* drive);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
 
 private:
  DriveSubsystem* m_drive;
  frc::PIDController m_xController{0.25, 0, 0.001};
  frc::PIDController m_yController{0.5, 0, 0};
  frc::Timer m_timer;
};
