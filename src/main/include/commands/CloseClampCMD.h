#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ClampSubsystem.h"

class CloseClampCMD
    : public frc2::CommandHelper<frc2::CommandBase, CloseClampCMD> {
 public:
  CloseClampCMD(ClampSubsystem* Clamp);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
    ClampSubsystem* m_Clamp
};
