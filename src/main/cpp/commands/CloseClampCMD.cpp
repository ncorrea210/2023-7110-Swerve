
#include "commands/CloseClampCMD.h"

CloseClampCMD::CloseClampCMD(ClampSubsystem* Clamp) : m_Clamp(Clamp) {
  AddRequirements(Clamp);
}

void CloseClampCMD::Execute() {
  m_Clamp->Run(1);
}

void CloseClampCMD::IsFinished() {
  if(m_Clamp->GetCurrent() > 20) {
    m_Clamp->Set(0);
    return true;
  } else return false;
}