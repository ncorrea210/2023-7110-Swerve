

#include "commands/OpenClampCMD.h"

OpenClampCMD::OpenClampCMD(ClampSubsystem* Clamp) : m_Clamp(Clamp) {
  AddRequirements(Clamp);
}

void OpenClampCMD::Execute() {
  m_Clamp->Run(-1);
}

void OpenClampCMD::IsFinished() {
  if(m_Clamp->GetCurrent() > 20) {
    m_Clamp->Set(0);
    return true;
  } else return false;
}